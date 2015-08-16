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
#include "ui_CreateLineClothoidClothoidLine.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		class CreateLineClothoidClothoidLineDialog : public QDialog
		{
			Q_OBJECT;

		public:
			//! Default constructor.
			CreateLineClothoidClothoidLineDialog(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~CreateLineClothoidClothoidLineDialog();

			double R=0,A1=0,A2=0;

		protected:
			virtual void changeEvent(QEvent* evt) override;

		private Q_SLOTS:
			void on_pushButtonGenerate_clicked();
			void on_pushButtonCancel_clicked();

		private:
			Ui::CreateLineClothoidClothoidLine*	ui_;
		}; // end class CreateLineClothoidClothoidLine
	} // end namespace UserInterface
} // end namespace OpenInfraPlatfom

namespace buw
{
	using OpenInfraPlatform::UserInterface::CreateLineClothoidClothoidLineDialog;
}

