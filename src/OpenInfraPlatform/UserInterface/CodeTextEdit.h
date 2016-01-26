/*! \verbatim
 *  \copyright      Copyright (c) 2015 Julian Amann. All rights reserved.
 *  \author         Julian Amann <dev@vertexwahn.de> (http://vertexwahn.de/)
 *  \brief          This file is part of the BlueFramework.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_UserInterface_CodeTextEdit_5a1d54d3_7a91_40dc_8452_7bc0041964da_h
#define OpenInfraPlatform_UserInterface_CodeTextEdit_5a1d54d3_7a91_40dc_8452_7bc0041964da_h

#include <boost/noncopyable.hpp>
#include <QMainWindow>
#include <QListWidgetItem>
#include <QTextEdit>
#include <QUrl>
#include <QTextStream>
#include <QDropEvent>
#include <QMimeData>
#include "highlighter.h"
#include <iostream>

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		class CodeTextEdit : public QTextEdit
		{
			Q_OBJECT;

		public:
			CodeTextEdit();

			void wheelEvent(QWheelEvent *e);

		public Q_SLOTS:
			void makeDrag();

		protected:
			void dropEvent(QDropEvent *de);
		};
	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::UserInterface::CodeTextEdit;
}

#endif // end define OpenInfraPlatform_UserInterface_CodeTextEdit_5a1d54d3_7a91_40dc_8452_7bc0041964da_h