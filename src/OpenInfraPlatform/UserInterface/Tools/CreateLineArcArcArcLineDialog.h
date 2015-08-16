/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#include <QDialog>
#include "ui_CreateLineArcArcArcLine.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		//! \class CreateLineArcArcArcLine
		//! \brief brief description
		class CreateLineArcArcArcLineDialog : public QDialog
		{
			Q_OBJECT;

		public:
			//! Default constructor.
			CreateLineArcArcArcLineDialog(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~CreateLineArcArcArcLineDialog();

			double R2 = 0;
			bool ral, r213;

		protected:
			virtual void changeEvent(QEvent* evt) override;

		private Q_SLOTS:
			void on_pushButtonGenerate_clicked();
			void on_pushButtonCancel_clicked();

		private:
			Ui::CreateLineArcArcArcLine*	ui_;
		}; // end class CreateLineArcArcArcLine
	} // end namespace UserInterface
} // end namespace OpenInfraPlatfom

namespace buw
{
	using OpenInfraPlatform::UserInterface::CreateLineArcArcArcLineDialog;
}

