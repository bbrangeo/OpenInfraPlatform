/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#include "CodeEditorWindow.h"

#include "OpenInfraPlatform/Infrastructure/IfcPL/Parser.h"
#include "OpenInfraPlatform/Infrastructure/IfcPL/Interpreter.h"

OpenInfraPlatform::UserInterface::CodeEditorWindow::CodeEditorWindow( QWidget *parent /*= nullptr*/ ) :
	ui_(new Ui::CodeEditorWindow)
{
	ui_->setupUi(this);

	setupEditor();
	ui_->verticalLayout->addWidget(editor);
}

void OpenInfraPlatform::UserInterface::CodeEditorWindow::changeEvent(QEvent* evt)
{
	if (evt->type() == QEvent::LanguageChange)
	{
		ui_->retranslateUi(this);
	}
	else
	{
		QWidget::changeEvent(evt);
	}
}

void OpenInfraPlatform::UserInterface::CodeEditorWindow::setupEditor()
{
	QFont font;
	font.setFamily("Courier");
	font.setFixedPitch(true);
	font.setPointSize(10);

	editor = new MyTextedit;
	editor->setFont(font);

	highlighter = new Highlighter(editor->document());

	QFile file("mainwindow.h");

	if(file.open(QFile::ReadOnly | QFile::Text))
		editor->setPlainText(file.readAll());

	editor->setPlainText(
		"print(\"Hello World!\");"
	);
}

void OpenInfraPlatform::UserInterface::CodeEditorWindow::on_actionExit_triggered()
{
	close();
}

void OpenInfraPlatform::UserInterface::CodeEditorWindow::on_actionExample1_triggered()
{
	editor->setPlainText(
		"A = input(\"Geben Sie eine Zahl ein: \");"
	);
}

void OpenInfraPlatform::UserInterface::CodeEditorWindow::on_pushButtonExecute_clicked()
{
	system("cls");

	using namespace OpenInfraPlatform::Infrastructure;

	QFile file("code1.txt");
	file.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream out(&file);
	out << editor->toPlainText().toStdString().c_str();
	file.close(); 
	
	Lexer::Ptr lexer = std::make_shared<Lexer>("code1.txt");

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
}

void OpenInfraPlatform::UserInterface::CodeEditorWindow::on_actionHello_World_triggered()
{
	editor->setPlainText(
		"print(\"Hello World!\");"
	);
}

void OpenInfraPlatform::UserInterface::CodeEditorWindow::on_actionEuclidean_triggered()
{
	editor->setPlainText(
		"print(\"Euclidean\");"								"\n"
		"a = input(\"Type a number (a): \");"				"\n"
		"b = input(\"Type a number (b): \");"				"\n"
		"print(a + b);"										"\n"
		);
}
