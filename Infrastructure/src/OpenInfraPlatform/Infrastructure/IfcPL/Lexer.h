/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_Lexer_e79afd2d_748d_4cb3_a4f3_e9a7202770c4_h
#define OpenInfraPlatform_Infrastructure_Lexer_e79afd2d_748d_4cb3_a4f3_e9a7202770c4_h

#include "buw.BlueCore.h"
#include "buw.BlueEngine.h"
#include "OpenInfraPlatform/Infrastructure/BlueInfrastructure.h"
#include <boost/noncopyable.hpp>
#include "token.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class BLUEINFRASTRUCTURE_API Lexer
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(Lexer);

			Lexer(const std::string& filename) :
				frontIndex(0)
			{
				buw::SimpleLexer sl(filename.c_str());
				sl.SetIgnoreWhitespace(true);
				buw::Token token;

				int tokenCount = 0;

				// while (sl.ReadToken(token))
				// {
				//	std::cout << token.GetStringValue() << std::endl;
				// }

				// read tokens
				while(sl.ReadToken(token))
				{
					//  IDENTIFIER
					if ( token.GetType() == buw::eTokenType::Identifier )
					{
						OpenInfraPlatform::Infrastructure::token t;

						t.line = token.GetRow();
						t.pos = token.GetColumn();
						t.word = token.GetStringValue().toStdString();
						t.type = eTokenType::IDENTIFIER;

						if (t.word == std::string("if"))
						{
							t.type = eTokenType::IF;
						} 
						else if (t.word == std::string("else"))
						{
							t.type = eTokenType::ELSE;
						}
						else if (t.word == std::string("<="))
						{
							t.type = eTokenType::LEQ;
						}
						else if (t.word == std::string(">="))
						{
							t.type = eTokenType::GEQ;
						}
						else if (t.word == std::string("true"))
						{
							t.type = eTokenType::BOOL;
						}
						else if (t.word == std::string("false"))
						{
							t.type = eTokenType::BOOL;
						}

						tokens_.push_back(t);
						continue;
					}

					// NUMERIC
					if ( token.GetType() == buw::eTokenType::Integer )
					{
						OpenInfraPlatform::Infrastructure::token t;

						t.line = token.GetRow();
						t.pos = token.GetColumn();
						t.word = token.GetStringValue().toStdString();
						t.type = eTokenType::NUMERIC;

						if (t.word == std::string("-"))
						{
							t.type = eTokenType::SUB;
						}

						tokens_.push_back(t);
						continue;
					}

					if ( token.GetType() == buw::eTokenType::Float )
					{
						OpenInfraPlatform::Infrastructure::token t;

						t.line = token.GetRow();
						t.pos = token.GetColumn();
						t.word = token.GetStringValue().toStdString();
						t.type = eTokenType::NUMERIC;

						tokens_.push_back(t);
						continue;
					}

					if ( token.GetType() == buw::eTokenType::Left_Parenthesis)
					{
						OpenInfraPlatform::Infrastructure::token t;

						t.line = token.GetRow();
						t.pos = token.GetColumn();
						t.word = token.GetStringValue().toStdString();
						t.type = eTokenType::BRACKET_OPEN;

						tokens_.push_back(t);
						continue;
					}

					if ( token.GetType() == buw::eTokenType::Right_Parenthesis)
					{
						OpenInfraPlatform::Infrastructure::token t;

						t.line = token.GetRow();
						t.pos = token.GetColumn();
						t.word = token.GetStringValue().toStdString();
						t.type = eTokenType::BRACKET_CLOSE;

						tokens_.push_back(t);
						continue;
					}

					if ( token.GetType() == buw::eTokenType::Left_Brace)
					{
						OpenInfraPlatform::Infrastructure::token t;

						t.line = token.GetRow();
						t.pos = token.GetColumn();
						t.word = token.GetStringValue().toStdString();
						t.type = eTokenType::BRACE_OPEN;

						tokens_.push_back(t);
						continue;
					}

					if ( token.GetType() == buw::eTokenType::Right_Brace)
					{
						OpenInfraPlatform::Infrastructure::token t;

						t.line = token.GetRow();
						t.pos = token.GetColumn();
						t.word = token.GetStringValue().toStdString();
						t.type = eTokenType::BRACE_CLOSE;

						tokens_.push_back(t);
						continue;
					}

					if ( token.GetType() == buw::eTokenType::Unknown )
					{
						OpenInfraPlatform::Infrastructure::token t;

						t.line = token.GetRow();
						t.pos = token.GetColumn();
						t.word = token.GetStringValue().toStdString();

						if (t.word == std::string("="))
						{
							t.type = eTokenType::ASSIGN;
							tokens_.push_back(t);
							continue;
						}

						if (t.word == std::string("("))
						{
							t.type = eTokenType::BRACKET_OPEN;
							tokens_.push_back(t);
							continue;
						}

						if (t.word == std::string(")"))
						{
							t.type = eTokenType::BRACKET_CLOSE;
							tokens_.push_back(t);
							continue;
						}

						if (t.word == std::string(";"))
						{
							t.type = eTokenType::SEMICOLON;
							tokens_.push_back(t);
							continue;
						}

						if (t.word == std::string("+"))
						{
							t.type = eTokenType::ADD;
							tokens_.push_back(t);
							continue;
						}

						if (t.word == std::string("-"))
						{
							t.type = eTokenType::SUB;
							tokens_.push_back(t);
							continue;
						}

						if (t.word == std::string("*"))
						{
							t.type = eTokenType::MUL;
							tokens_.push_back(t);
							continue;
						}

						if (t.word == std::string("/"))
						{
							t.type = eTokenType::DIV;
							tokens_.push_back(t);
							continue;
						}

						if (t.word == std::string("{"))
						{
							t.type = eTokenType::BRACE_OPEN;
							tokens_.push_back(t);
							continue;
						}

						if (t.word == std::string("<"))
						{
							t.type = eTokenType::LT;
							tokens_.push_back(t);
							continue;
						}

						if (t.word == std::string(">"))
						{
							t.type = eTokenType::GT;
							tokens_.push_back(t);
							continue;
						}

						if (t.word == std::string("}"))
						{
							t.type = eTokenType::BRACE_CLOSE;
							tokens_.push_back(t);
							continue;
						}

						if (t.word == std::string("\""))
						{
							// extract string
							std::stringstream ss;

							// Lesen bis wieder " kommt
							bool firstRun = true;

							sl.SetIgnoreWhitespace(false); // whitespace are important now

							bool canRead = sl.ReadToken(token);
							assert(canRead);

							while (firstRun || token.GetStringValue() != "\"")
							{
								ss << token.GetStringValue();

								firstRun = false;

								bool canRead = sl.ReadToken(token);
								assert(canRead);
							} 

							t.type = eTokenType::STRING;
							t.word = ss.str();
							t.line = token.GetRow();
							t.pos = token.GetColumn();

							sl.SetIgnoreWhitespace(true); // whitespace are important now

							tokens_.push_back(t);
							continue;
						}

						assert(false);
					}
				}
			}

			void addToken(const std::string& word, 
				const eTokenType::Enum type, 
				const int line, 
				const int position)
			{
				OpenInfraPlatform::Infrastructure::token t;

				t.line = line;
				t.pos = position;
				t.word = word;
				t.type = type;

				tokens_.push_back(t);
			}

			std::vector<token> getTokens()
			{
				return tokens_;
			}

			int getTokenCount() const
			{
				return static_cast<int>(tokens_.size());
			}

			bool hasMoreTokens() const
			{
				if (frontIndex < tokens_.size())
				{
					return true;
				}
				else
					return false;
			}

			token peekToken() const
			{
				assert(tokens_.size() > 0);

				if (frontIndex < tokens_.size())
				{
					auto t = tokens_[frontIndex];
					return t;
				}
				else
				{
					token t;
					t.line = -1;
					t.pos = -1;
					t.word = "";
					t.type = eTokenType::END;

					return t;
				}
			}

			token peekNextToken()
			{
				assert(tokens_.size() > 1);

				auto t = tokens_[frontIndex+1];
				return t;
			}

			token nextToken()
			{
				assert(tokens_.size() > 0);
				token t = tokens_[frontIndex];
				frontIndex++;
				return t;
			}

		private:			
			int frontIndex;
			std::vector<token> tokens_;
		}; // end class Lexer
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::Lexer;
}

#endif // end define OpenInfraPlatform_Infrastructure_Lexer_e79afd2d_748d_4cb3_a4f3_e9a7202770c4_h
