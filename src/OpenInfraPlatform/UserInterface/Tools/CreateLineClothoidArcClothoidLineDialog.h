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
#include "ui_CreateLineClothoidArcClothoidLine.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		//! \class CreateLineClothoidArcClothoidLine
		//! \brief brief description
		class CreateLineClothoidArcClothoidLineDialog : public QDialog
		{
			Q_OBJECT;

		public:
			//! Default constructor.
			CreateLineClothoidArcClothoidLineDialog(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~CreateLineClothoidArcClothoidLineDialog();

			double R = 0, A1 = 0, A2 = 0;

		protected:
			virtual void changeEvent(QEvent* evt) override;

		private Q_SLOTS:
			void on_pushButtonGenerate_clicked();
			void on_pushButtonCancel_clicked();

		private:
			Ui::CreateLineClothoidArcClothoidLine*	ui_;
		}; // end class CreateLineClothoidArcClothoidLine
	} // end namespace UserInterface
} // end namespace OpenInfraPlatfom

namespace buw
{
	using OpenInfraPlatform::UserInterface::CreateLineClothoidArcClothoidLineDialog;
}

