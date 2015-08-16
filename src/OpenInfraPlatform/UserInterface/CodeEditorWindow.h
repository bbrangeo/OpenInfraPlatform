/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_UserInterface_CodeEditorWindow_5f48a20a_6127_4e9c_b8b9_01b44ac3c30a_h
#define OpenInfraPlatform_UserInterface_CodeEditorWindow_5f48a20a_6127_4e9c_b8b9_01b44ac3c30a_h

#include "ui_CodeEditorWindow.h"
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
		class MyTextedit : public QTextEdit
		{
			Q_OBJECT;

		public Q_SLOTS:
			void makeDrag()
			{

			}

		protected:
			void dropEvent(QDropEvent *de)
			{
				if (de->mimeData()->hasUrls()) 
				{
					QString url = de->mimeData()->urls()[0].toString();
					url = url.right( url.length() - 8 );

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
			void dragMoveEvent(QDragMoveEvent *de)
			{
				// The event needs to be accepted here
				de->accept();
			}
			void dragEnterEvent(QDragEnterEvent *event)
			{
				// Set the drop action to be the proposed action.
				event->acceptProposedAction();
			}
		};

		//! \class CodeEditorWindow
		//! \brief brief description
		class CodeEditorWindow : public QMainWindow
		{
			Q_OBJECT

		public:
			//! Default constructor.
			CodeEditorWindow(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~CodeEditorWindow()
			{
			}

		public Q_SLOTS:
			void on_actionExit_triggered();
			void on_actionExample1_triggered();
			void on_pushButtonExecute_clicked();
			void on_actionHello_World_triggered();
			void on_actionEuclidean_triggered();

		protected:
			virtual void changeEvent(QEvent* evt) override;

		private:
			void setupEditor();

		private:
			Ui::CodeEditorWindow *ui_;

			MyTextedit *editor;
			Highlighter *highlighter;
		private:
		}; // end class CodeEditorWindow
	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::UserInterface::CodeEditorWindow;
}

#endif // end define OpenInfraPlatform_UserInterface_CodeEditorWindow_5f48a20a_6127_4e9c_b8b9_01b44ac3c30a_h
