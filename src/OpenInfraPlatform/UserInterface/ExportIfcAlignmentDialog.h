/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_UserInterface_ExportP6AlginmentDialog_84f19553_085c_4888_88c3_3ffee5176b52_h
#define OpenInfraPlatform_UserInterface_ExportP6AlginmentDialog_84f19553_085c_4888_88c3_3ffee5176b52_h

#include "ui_ExportIfcAlignmentDialog.h"
#include "OpenInfraPlatform/DataManagement/IfcZipper.h"
#include <QDialog>
#include <iostream>

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		class ExportIfcAlignmentDialog : public QDialog
		{
			Q_OBJECT;

		public:
			ExportIfcAlignmentDialog(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~ExportIfcAlignmentDialog();

		protected:
			virtual void changeEvent(QEvent* evt) override;

		private Q_SLOTS:
			void on_pushButtonCancel_clicked();

			void on_pushButtonExport_clicked();

		private:
			Ui::ExportP6AlignmentDialog*	ui_;
		}; // end class ExportP6AlginmentDialog
	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::UserInterface::ExportIfcAlignmentDialog;
}

#endif // end define OpenInfraPlatform_UserInterface_ExportP6AlginmentDialog_84f19553_085c_4888_88c3_3ffee5176b52_h
