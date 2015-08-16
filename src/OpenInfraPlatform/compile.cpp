/*! \verbatim
 *  \copyright      Copyright (c) 2015 Julian Amann. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the BlueFramework.
 *  \endverbatim
 */

#include "OpenInfraPlatform/Infrastructure/IfcPL/Parser.h"
#include "OpenInfraPlatform/Infrastructure/IfcPL/Interpreter.h"

using namespace OpenInfraPlatform::Infrastructure;

void compile()
{
	Lexer::Ptr lexer = std::make_shared<Lexer>(
		"C:/Users/no68koc/Desktop/code1.txt");

	std::cout << "##### Tokens: " << "#######################################" << std::endl;

	for (int i = 0; i < lexer->getTokenCount(); i++)
	{
		std::cout << lexer->getTokens()[i] << std::endl;
	}

	auto tokens = lexer->getTokens();

	Parser::Ptr parser = std::make_shared<Parser>(lexer);
	auto ast = parser->parse();

	std::cout << "##### Ast: " << "##########################################" << std::endl;

	std::cout << ast << std::endl;

	std::cout << "##### Program Output: " << "###############################" << std::endl;

	Interpreter::Ptr interpreter = std::make_shared<Interpreter>();
	interpreter->execute(ast);

	system("pause");
}