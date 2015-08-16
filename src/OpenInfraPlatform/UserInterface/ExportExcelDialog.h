/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_UserInterface_ExportExcelDialog_84eafb57_f094_44d1_8067_add4302b6b7e_h
#define OpenInfraPlatform_UserInterface_ExportExcelDialog_84eafb57_f094_44d1_8067_add4302b6b7e_h

#include "ui_ExportExcel.h"
#include <QDialog>

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		class ExportExcelDialog : public QDialog
		{
			Q_OBJECT;

		public:
			ExportExcelDialog(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~ExportExcelDialog();

		protected:
			virtual void changeEvent(QEvent* evt) override;

		private Q_SLOTS:
			void on_pushButtonCancel_clicked();

			void on_pushButtonExport_clicked();

		private:
			Ui::ExportExcelDialog*	ui_;
		}; // end class ExportExcelDialog
	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::UserInterface::ExportExcelDialog;
}

#endif // end define OpenInfraPlatform_UserInterface_ExportExcelDialog_84eafb57_f094_44d1_8067_add4302b6b7e_h
