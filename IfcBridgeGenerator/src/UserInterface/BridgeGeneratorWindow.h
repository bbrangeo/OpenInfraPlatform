//! \verbatim
//! ##############################################################################
//! # Copyright (c) 2013 Julian Amann
//! # All rights reserved.
//! #
//! # Technical University of Munich, Arcisstraﬂe 21, 80333 Munich (Germany)
//! ##############################################################################
//!
//!         created by : Julian Amann (julian.amann@tum.de)
//!         created on : 2013-02-11 21:58
//!   last modification: 2013-02-11 21:58
//!           generator: stub generated using BlueCompany CodeMonkey
//!    additional docs :
//!     responsibility : 1. Julian Amann
//!
//! \endverbatim
//! \file 
//! \brief Canonical include file

#pragma once

#include <iostream>

#include "buw.BlueCore.compiler.h"

BLUE_DROP_COMPILER_LEVEL_TO_3
#include <QtGui>
#include <QMainWindow>
BLUE_RESTORE_COMPILER_WARNING_LEVEL

namespace Ui 
{
	class BridgeGeneratorWindow;
}

namespace BlueIfcBridgeViewer
{
	namespace UserInterface
	{
		//! \class MainWindow
		//! \brief brief description
		class BridgeGeneratorWindow : public QMainWindow
		{
			Q_OBJECT

		public:
			//! Default constructor.
			BridgeGeneratorWindow(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~BridgeGeneratorWindow()
			{

			}

		public Q_SLOTS:
			void on_pushButtonSaveAs_clicked();

		private:
		

			

		private:
			Ui::BridgeGeneratorWindow *ui_;
		}; // end class MainWindow
	}
}