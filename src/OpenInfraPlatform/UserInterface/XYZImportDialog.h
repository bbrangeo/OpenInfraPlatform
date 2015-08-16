/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_UserInterface_XYZImport_38da791c_994f_450a_abc1_6676bdf555c4_h
#define OpenInfraPlatform_UserInterface_XYZImport_38da791c_994f_450a_abc1_6676bdf555c4_h

#include <QDialog>
#include <boost/noncopyable.hpp>
#include "ui_XYZImportDialog.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		//! \class XYZImport
		//! \brief brief description
		class XYZImportDialog : public QDialog
		{
			Q_OBJECT;

		public:
			//! Default constructor.
			XYZImportDialog(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~XYZImportDialog();

		protected:
			virtual void changeEvent(QEvent* evt) override;

		private Q_SLOTS:
			void on_pushButtonBrowse_clicked();
			void on_pushButtonImport_clicked();

		private:
			Ui::XYZImportDialog*	ui_;
		}; // end class XYZImport
	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::UserInterface::XYZImportDialog;
}

#endif // end define OpenInfraPlatform_UserInterface_XYZImport_38da791c_994f_450a_abc1_6676bdf555c4_h
