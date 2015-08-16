/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_UserInterface_ExportIfcZipDialog
#define OpenInfraPlatform_UserInterface_ExportIfcZipDialog

#include <ui_ExportIfczipDialog.h>
#include <QDialog>
#include "OpenInfraPlatform/DataManagement/IfcZipper.h"
#include <iostream>


namespace OpenInfraPlatform {
	namespace UserInterface {
		class ExportIfcZipDialog : public QDialog {
			Q_OBJECT;
		public:
			ExportIfcZipDialog(QWidget *parent = nullptr);			
			virtual ~ExportIfcZipDialog();
			OpenInfraPlatform::DataManagement::IfcZipper* zipper;

			

		private Q_SLOTS:
		void on_pushButtonCancel_clicked();
		void on_pushButtonExport_clicked();

		private:
			Ui::ExportIfcZipDialog* ui_;
		};
	}
}

namespace buw
{
	using OpenInfraPlatform::UserInterface::ExportIfcZipDialog;
}

#endif