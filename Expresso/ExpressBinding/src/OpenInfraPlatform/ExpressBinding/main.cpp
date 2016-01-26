#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

int yyparse();
extern FILE *yyin;

#include "Schema.h"

int main(int, char**)
{
	// open a file handle to a particular file:
	
	FILE *myfile = fopen("C:/dev/CMakeDemos/Expresso/IFC4_edit.exp", "r");
	//FILE *myfile = fopen("C:/dev/CMakeDemos/Expresso/IFC4_ADD1.exp", "r");
	// make sure it is valid:
	if (!myfile) {
		cout << "I can't open file!" << endl;
		return -1;
	}
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;

	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));

	std::ostream& out = std::cout;

	out << "SCHEMA " << oip::Schema::getInstance().getName() <<  ";" << std::endl << std::endl;

	for (int i = 0; i < oip::Schema::getInstance().getTypeCount(); i++)
	{
		auto& type = oip::Schema::getInstance().getTypeByIndex(i);

		out << "TYPE " << type.getName();
		out << " = ";

		if (type.getSimpleType() == OpenInfraPlatform::ExpressBinding::eSimpleType::Binary)
		{
			out << "BINARY";
		}
		else if (type.getSimpleType() == OpenInfraPlatform::ExpressBinding::eSimpleType::Boolean)
		{
			out << "BOOLEAN";
		}
		else if (type.getSimpleType() == OpenInfraPlatform::ExpressBinding::eSimpleType::Real)
		{
			out << "REAL";
		}
		else if (type.getSimpleType() == OpenInfraPlatform::ExpressBinding::eSimpleType::Integer)
		{
			out << "INTEGER";
		}
		else if (type.getSimpleType() == OpenInfraPlatform::ExpressBinding::eSimpleType::Number)
		{
			out << "NUMBER";
		}
		else if (type.getSimpleType() == OpenInfraPlatform::ExpressBinding::eSimpleType::Logical)
		{
			out << "LOGICAL";
		}
		else if (type.getSimpleType() == OpenInfraPlatform::ExpressBinding::eSimpleType::String)
		{
			out << "STRING";
		}
		else if (type.getSimpleType() == OpenInfraPlatform::ExpressBinding::eSimpleType::List)
		{
			out << "LIST [" << type.getContainerCardinalityMin() << ":" << type.getContainerCardinalityMax() << "] OF "
				<< oip::Schema::getInstance().getTypeByIndex(i).getContainerType();

		}
		else if (type.getSimpleType() == OpenInfraPlatform::ExpressBinding::eSimpleType::Array)
		{
			out << "ARRAY [" << type.getContainerCardinalityMin() << ":" << type.getContainerCardinalityMax() << "] OF " 
				<< oip::Schema::getInstance().getTypeByIndex(i).getContainerType();
		}
		else if (type.getSimpleType() == OpenInfraPlatform::ExpressBinding::eSimpleType::Set)
		{
			out << "SET [" << type.getContainerCardinalityMin() << ":" << type.getContainerCardinalityMax() << "] OF " 
				<< oip::Schema::getInstance().getTypeByIndex(i).getContainerType();
		}
		else if (type.getSimpleType() == OpenInfraPlatform::ExpressBinding::eSimpleType::Enumeration)
		{
			out << "ENUMERATION OF " << std::endl << "\t(";

			for (int i = 0; i < type.getTypes().size(); i++)
			{
				out << type.getTypes()[i];

				if (i + 1 < type.getTypes().size())
					out << std::endl << "\t,";
			}
			
			out << ")";
		}
		else if (type.getSimpleType() == OpenInfraPlatform::ExpressBinding::eSimpleType::Select)
		{
			out << "SELECT " << std::endl << "\t(";

			for (int i = 0; i < type.getTypes().size(); i++)
			{
				out << type.getTypes()[i];

				if (i + 1 < type.getTypes().size())
					out << std::endl << "\t,";
			}

			out << ")";
		}
		else
		{
			out << type.getUnderlyingTypeName();
		}

		out << ";" << std::endl << "END_TYPE;" << std::endl << std::endl;
	}

	for (int i = 0; i < oip::Schema::getInstance().getEntityCount(); i++)
	{
		auto entity = oip::Schema::getInstance().getEntityByIndex(i);

		out << "ENTITY " << entity.getName() << std::endl;

		if (entity.getSubtypeCount() > 0)
		{
			out << "\tSUBTYPE OF (";

			for (int k = 0; k < entity.getSubtypeCount(); k++)
			{
				out << entity.getSubtypeByIndex(k);
			}

			out << ")";
		}

		out << "END_ENTITY" << std::endl << std::endl;
	}

	out << "END_SCHEMA;";

	system("pause");
}

extern int line_num;

void yyerror(const char *s) 
{
	cout << "Parse error!  Message: " << s << endl;
	cout << "Line number: " << line_num << endl;
	// might as well halt now:
	exit(-1);
}