/*! \verbatim
 *  \copyright      Copyright (c) 2015 Julian Amann. All rights reserved.
 *  \author         Julian Amann <dev@vertexwahn.de> (http://vertexwahn.de/)
 *  \brief          This file is part of the BlueFramework.
 *  \endverbatim
 */

#include "CodeTextEdit.h"

OpenInfraPlatform::UserInterface::CodeTextEdit::CodeTextEdit()
{
	//setStyleSheet("font: 12pt \"Times New Roman\";");
}

void OpenInfraPlatform::UserInterface::CodeTextEdit::wheelEvent(QWheelEvent *e)
{
	if (e->modifiers() & Qt::ControlModifier)
	{
		const int delta = e->delta();
		if (delta < 0)
			zoomOut();
		else if (delta > 0)
		{
			zoomIn();
		}

		return;
	}

	QTextEdit::wheelEvent(e);
}

void OpenInfraPlatform::UserInterface::CodeTextEdit::makeDrag()
{

}

void OpenInfraPlatform::UserInterface::CodeTextEdit::dropEvent(QDropEvent *de)
{
	if (de->mimeData()->hasUrls())
	{
		QString url = de->mimeData()->urls()[0].toString();
		url = url.right(url.length() - 8);

		std::cout << url.toLatin1().data() << std::endl;

		QFile file(url.toLatin1().data());
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
			throw std::runtime_error("Could not open file.");

		QTextStream in(&file);
		QString line = in.readLine();
		while (!line.isNull())
		{
			this->append(line);
			line = in.readLine();
		}
	}
}
