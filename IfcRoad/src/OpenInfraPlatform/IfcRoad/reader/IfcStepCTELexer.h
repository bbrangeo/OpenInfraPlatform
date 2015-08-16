#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <memory>

namespace IfcStepCTE
{
	struct eTokenTypes
	{
		enum Enum
		{
			OpenBracket,
			CloseBracket,
			Integer,
			Comma,
			Minus,
			Dollar,
			Invalid
		};
	};

	struct token
	{
		eTokenTypes::Enum type;
		int value;
	};

	class Lexer
	{
	public:
		typedef std::shared_ptr<Lexer> Ptr;

		std::vector<token> getTokens(const std::string& str);

	private:
		void createOpenBracketToken();

		void createCloseBracketToken();

		void createCommaToken();

		void createMinusToken();

		void createDollarToken();

		void createInvalidToken();

		void createIntegerToken(const int value);

	private:
		std::vector<token> tokenList;
	};

	/*
	Terminals:
	<OpenBracket>
	<CloseBracket>
	<Integer>
	<Comma>
	<Minus>

	<ListOfListOfIntegers>			::= <OpenBracket> <ListOfListOfIntegersIntern> <CloseBracket>
	<ListOfListOfIntegersIntern>	::= "" | <OpenBracket> <ListOfIntegers> <CloseBracket>
	<ListOfIntegers>                ::= <Integer> | <Integer> <Comma> <ListOfIntegers>
	
	class Parser
	{
	public:
		Parser(Lexer::Ptr lexer) :
			lexer_(lexer)
		{

		}

		~Parser()
		{

		}

		void parse(const std::string& str)
		{

			const std::vector<token> tokens = lexer_->getTokens(str);

		}

	private:
		Lexer::Ptr lexer_;
	};*/

	void readListOfListOfIntegers(const std::string& str, std::vector<std::vector<int>>& vec);
}
