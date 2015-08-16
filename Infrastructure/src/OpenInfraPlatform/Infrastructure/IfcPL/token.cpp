/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "token.h"

#include <iostream>

std::string OpenInfraPlatform::Infrastructure::tokenToString(const eTokenType::Enum type)
{
	std::string tokenTypes[] = {
		"UNKNOWN" /* = 0*/,
		"IDENTIFIER" /* = 1*/,
		"NUMERIC" /* = 2*/,
		"BOOL" /* = 3*/,
		"STRING" /* = 4*/,
		"IF" /* = 5*/,
		"ELSE" /* = 6*/,
		"BRACKET_OPEN" /* = 7*/,
		"BRACKET_CLOSE" /* = 8*/,
		"SEMICOLON" /* = 9*/,
		"ADD" /* = 10*/,
		"SUB" /* = 11*/,
		"MUL" /* = 12*/,
		"DIV" /* = 13*/,
		"AND" /* = 14*/,
		"OR" /* = 15*/,
		"NOT" /* = 16*/,
		"ASSIGN" /* = 17*/,
		"EQUAL" /* = 18*/,
		"UNEQUAL" /* = 19*/,
		"LT" /* = 20*/,
		"GT" /* = 21*/,
		"LEQ" /* = 22*/,
		"GEQ" /* = 23*/,
		"FCALL" /* = 24*/,
		"TRUE" /* = 25*/,
		"FALSE" /* = 26*/,
		"BRACE_OPEN" /* = 27*/,
		"BRACE_CLOSE" /* = 28*/,
		"COMMA" /* = 29*/,
		"SIGN" /* = 30*/,
		"STMNT" /* = 31*/,
		"PROGRAM" /* = 32*/,
		"COND" /* = 33*/,
		"END" /* = 34*/
	};

	return tokenTypes[type];
}

std::ostream& OpenInfraPlatform::Infrastructure::operator << (std::ostream& os, token& t)
{
	os << t.word.c_str() << "\t [" << tokenToString(t.type).c_str() << ",\t " << t.line << ",\t " << t.pos << "]";
	return os;
}