/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_Parser_acc5a120_d82a_454c_8f5a_fb2950e11671_h
#define OpenInfraPlatform_Infrastructure_Parser_acc5a120_d82a_454c_8f5a_fb2950e11671_h

#include "buw.BlueCore.h"
#include "buw.BlueEngine.h"
#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include <boost/noncopyable.hpp>
#include "token.h"
#include "Lexer.h"
#include "AbstractSyntaxTree.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API Parser
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(Parser);

			Parser(Lexer::Ptr lex) :
				lexer(lex),
				astRoot(nullptr)
			{

			}

			virtual ~Parser()
			{
			}

			AbstractSyntaxTree::Ptr parse()
			{
				token mainToken;
				mainToken.type = eTokenType::PROGRAM;
				astRoot = std::make_shared<AbstractSyntaxTreeNode>(mainToken, nullptr, nullptr);

				ruleProgram();

				AbstractSyntaxTree::Ptr ast = std::make_shared<AbstractSyntaxTree>(astRoot);
				return ast;
			}

		private:
			void ruleProgram()
			{
				auto curNode = astRoot;

				// Leere Eingabe ist erlaubt:
				while(lexer->hasMoreTokens()) 
				{
					auto token = lexer->peekToken();

					// AST-Knoten, welcher lediglich als ein Baumstrukturelement zur Aneinanderkettung von
					// Anweisungen dient:
					auto stmnt = createStmntNode();

					// Den neuen Strukturknoten nun an den vorigen Elternknoten als linkes
					// Kind anhängen:
					addChildNode(curNode, stmnt);

					// Und nun den Strukturknoten als aktuellen Knoten übernehmen:
					curNode = stmnt;

					switch(token.type) 
					{
						// Funktionsaufruf oder Wertzuweisung:
					case eTokenType::IDENTIFIER:
						ruleStatement(curNode);
						break;

						// Oder if-Anweisung:
					case eTokenType::IF:
						ruleIf(curNode);
						break;

						// Ansonsten ungrammatisch:
					default:
						throw buw::Exception("Syntaxfehler");
					}
				}
			}

			// Regel für Anweisung oder Anweisungsblock {...}
			void ruleStatement(AbstractSyntaxTreeNode::Ptr node) 
			{
				if(lexer->peekToken().type == eTokenType::BRACE_OPEN)
				{
					auto stmnt = createStmntNode();
					addChildNode(node, stmnt);
					// Anweisungsblock entdeckt
					lexer->nextToken();
					ruleStatementList(stmnt);
					expectToken(eTokenType::BRACE_CLOSE);
				}
				else
				{
					// Einzelanweisung entdeckt
					ruleExprStatement(node);
					expectToken(eTokenType::SEMICOLON);
				}
			}

			void ruleStatementList(AbstractSyntaxTreeNode::Ptr node)
			{
				auto stmnt = createStmntNode();
				addChildNode(node, stmnt);
				ruleStatement(stmnt);

				if(lexer->peekToken().type != eTokenType::BRACE_CLOSE) 
				{
					ruleStatementList(stmnt);
				}
			}

			void  ruleExprStatement(AbstractSyntaxTreeNode::Ptr node) 
			{
				ruleExpr();
				auto child = operands.top();
				operands.pop();
				addChildNode(node, child);
			}

			// <Expr> -> <AssignExpr>, <Expr>
			// <Expr> -> <AssignExpr>
			void ruleExpr()
			{
				ruleAssignExpr();

				if(lexer->peekToken().type == eTokenType::COMMA)
				{
					operators.push(createNode(lexer->nextToken()));
					ruleExpr();
					createTermTree();
				}
			}

			// <AssignExpr> -> <Identifier> = <AssignExpr>
			// <AssignExpr> -> <OrExpr>
			void ruleAssignExpr() 
			{
				if(	lexer->peekToken().type == eTokenType::IDENTIFIER &&
					lexer->peekNextToken().type == eTokenType::ASSIGN) 
				{
					operands.push(createNode(lexer->nextToken()));
					operators.push(createNode(lexer->nextToken()));
					ruleAssignExpr();
					createTermTree();
					return;
				}

				ruleOrExpr();
			}

			// <OrExpr> -> <AndExpr> || <OrExpr>
			// <OrExpr> -> <AndExpr>
			void ruleOrExpr() 
			{
				ruleAndExpr();

				if(lexer->peekToken().type == eTokenType::OR) 
				{
					auto op = createNode(lexer->nextToken());
					operators.push(op);
					ruleOrExpr();
					createTermTree();
				}
			}

			// <AndExpr> -> <EqualExpr> && <AndExpr>
			// <AndExpr> -> <EqualExpr>
			void ruleAndExpr() 
			{
				ruleEqualExpr();

				if(lexer->peekToken().type == eTokenType::AND)
				{
					auto op = createNode(lexer->nextToken());
					operators.push(op);
					ruleAndExpr();
					createTermTree();
				}
			}

			// <EqualExpr> -> <RelExpr> == <RelExpr>
			// <EqualExpr> -> <RelExpr> != <RelExpr>
			// <EqualExpr> -> <RelExpr>
			void ruleEqualExpr() 
			{
				ruleRelExpr();

				auto token = lexer->peekToken();

				if(	token.type == eTokenType::EQUAL ||
					token.type == eTokenType::UNEQUAL) 
				{
					auto op = createNode(lexer->nextToken());
					operators.push(op);
					ruleRelExpr();
					createTermTree();
				}
			}

			// <RelExpr> -> <AddExpr> < <AddExpr>
			// <RelExpr> -> <AddExpr> > <AddExpr>
			// <RelExpr> -> <AddExpr> <= <AddExpr>
			// <RelExpr> -> <AddExpr> >= <AddExpr>
			// <RelExpr> -> <AddExpr>
			void ruleRelExpr()
			{
				ruleAddExpr();

				auto token = lexer->peekToken();

				if(	token.type == eTokenType::LT ||
					token.type == eTokenType::GT ||
					token.type == eTokenType::LEQ ||
					token.type == eTokenType::GEQ) 
				{
					auto op = createNode(lexer->nextToken());
					operators.push(op);
					ruleAddExpr();
					createTermTree();
				}
			}

			// <AddExpr> -> <MulExpr> + <AddExpr>
			// <AddExpr> -> <MulExpr> - <AddExpr>
			// <AddExpr> -> <MulExpr>
			void ruleAddExpr() 
			{
				ruleMulExpr();

				auto token = lexer->peekToken();

				if(	token.type == eTokenType::ADD ||
					token.type == eTokenType::SUB)
				{
					auto op = createNode(lexer->nextToken());
					operators.push(op);
					ruleAddExpr();
					createTermTree();
				}
			}

			// <MulExpr> -> <UnaryExpr> * <MulExpr>
			// <MulExpr> -> <UnaryExpr> / <MulExpr>
			// <MulExpr> -> <UnaryExpr>
			void ruleMulExpr() 
			{
				ruleUnaryExpr();

				auto token = lexer->peekToken();

				if( token.type == eTokenType::MUL ||
					token.type == eTokenType::DIV) 
				{
					auto op = createNode(lexer->nextToken());
					operators.push(op);
					ruleMulExpr();
					createTermTree();
				}
			}

			// <UnaryExpr> -> <Factor>
			// <UnaryExpr> -> - <Factor>
			// <UnaryExpr> -> ! <Factor>
			void ruleUnaryExpr() 
			{
				auto buildTerm = false;
				auto token = lexer->peekToken();

				if( token.type == eTokenType::SUB ||
					token.type == eTokenType::NOT) 
				{
					if(token.type == eTokenType::SUB) token.type = eTokenType::SIGN;
					auto unOp = createNode(token);
					lexer->nextToken();
					unOp->isUnary = true;
					operators.push(unOp);
					buildTerm = true;
				}

				ruleFactor();
				if(buildTerm) createTermTree();
			}

			// <Factor> -> <Identifier>
			// <Factor> -> <Identifier> ( <FCallArgs> )
			// <Factor> -> <Numeric>
			// <Factor> -> <String>
			// <Factor> -> true
			// <Factor> -> false
			// <Factor> -> (<Expr>)
			void ruleFactor()
			{
				auto token = lexer->nextToken();

				if(token.type == eTokenType::IDENTIFIER) 
				{
					if(lexer->peekToken().type == eTokenType::BRACKET_OPEN)
					{
						// Funktionsaufruf erkannt
						lexer->nextToken();
						OpenInfraPlatform::Infrastructure::token fcallToken;
						fcallToken.type = eTokenType::FCALL;
						auto fcall = createNode(fcallToken);
						ruleFCallArgs(fcall);
						addChildNode(fcall, createNode(token));
						operands.push(fcall);
						expectToken(eTokenType::BRACKET_CLOSE);
					} 
					else
					{
						// Variable erkannt
						operands.push(createNode(token));
					}
					return;
				}

				if(token.type == eTokenType::BRACKET_OPEN) 
				{
					// Geklammerter Ausdruck erkannt
					ruleExpr();
					expectToken(eTokenType::BRACKET_CLOSE);
					return;
				}

				if(	token.type == eTokenType::NUMERIC ||
					token.type == eTokenType::STRING ||
					token.type == eTokenType::BOOL)
				{
					// Token ist erlaubtes Literal
					operands.push(createNode(token));
				} 
				else 
				{
					// Token ist hier ungrammatisch, daher Fehler:
					error("Syntaxfehler im Ausdruck", token);
				}
			}

			void error(const std::string& message, token t)
			{
				std::cout << message << t << std::endl;
			}

			// <FCallArgs> -> <Expr>
			// <FCallArgs> -> ε
			void ruleFCallArgs(AbstractSyntaxTreeNode::Ptr node) 
			{
				auto token = lexer->peekToken();

				if(token.type == eTokenType::BRACKET_CLOSE) 
				{
					return;
				}

				ruleExprStatement(node);
			}

			// Regel für if-Anweisung
			void ruleIf(AbstractSyntaxTreeNode::Ptr node) 
			{
				auto ifNode = createNode(lexer->nextToken());
				token conditionToken;
				conditionToken.type = eTokenType::COND;
				auto condNode = createNode(conditionToken);
				addChildNode(node, ifNode);
				addChildNode(ifNode, condNode);
				expectToken(eTokenType::BRACKET_OPEN);
				ruleExprStatement(condNode);
				expectToken(eTokenType::BRACKET_CLOSE);
				ruleStatement(condNode);

				if(lexer->peekToken().type == eTokenType::ELSE) 
				{
					lexer->nextToken();
					ruleStatement(ifNode);
				}
			}

			void addChildNode(AbstractSyntaxTreeNode::Ptr parent, AbstractSyntaxTreeNode::Ptr child)
			{
				if(parent)
				{
					if(parent->right == nullptr) 
					{
						parent->right = child;
					} 
					else
					{
						if(parent->left == nullptr) 
						{
							parent->left = child;
						} 
						else
						{
							throw buw::Exception("Interner Fehler: Elternknoten hat bereits zwei Kinder!");
						}
					}
				} 
				else 
				{
					throw buw::Exception("Interner Fehler: Kein Elternknoten angegeben!");
				}
			}

			void createTermTree()
			{
				if(operators.size() > 0 && operands.size() > 0)
				{
					auto operator_ = operators.top(); operators.pop();
					auto operandA = operands.top(); operands.pop();
					addChildNode(operator_, operandA);

					if(!operator_->isUnary)
					{
						if(operands.size() > 0)
						{
							auto operandB = operands.top(); operands.pop();
							addChildNode(operator_, operandB);
						}
						else
						{
							throw buw::Exception("Interner Fehler: kann keinen Termbaum bilden. Zu wenige Operanden");
						}
					}

					operands.push(operator_);
				}
				else
				{
					throw buw::Exception("Interner Fehler: kann keinen Termbaum bilden. Zu wenige Argumente");
				}
			}

			// Erstellt einen leeren AST-Knoten zur Aneinanderkettung von Anweisungen
			AbstractSyntaxTreeNode::Ptr createStmntNode() 
			{
				token statementToken;
				statementToken.type = eTokenType::STMNT;
				return createNode(statementToken);
			}

			AbstractSyntaxTreeNode::Ptr createNode(const token& t)
			{
				return AbstractSyntaxTreeNode::create(t);
			}

			void expectToken(eTokenType::Enum typ) 
			{
				auto token = lexer->nextToken();

				if(token.type != typ) 
				{
					std::stringstream ss;
					ss << "Expected type " << tokenToString(typ);
					throw buw::Exception(ss.str());
				}
			}

		private:
			std::stack<AbstractSyntaxTreeNode::Ptr> operators;
			std::stack<AbstractSyntaxTreeNode::Ptr> operands;
			AbstractSyntaxTreeNode::Ptr				astRoot;
			Lexer::Ptr								lexer;
		};

	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::Parser;
}

#endif // end define OpenInfraPlatform_Infrastructure_Parser_acc5a120_d82a_454c_8f5a_fb2950e11671_h
