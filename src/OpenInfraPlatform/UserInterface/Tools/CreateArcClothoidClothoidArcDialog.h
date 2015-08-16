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
#include "ui_CreateArcClothoidClothoidArc.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		//! \class CreateArcClothoidClothoidArc
		//! \brief brief description
		class CreateArcClothoidClothoidArcDialog : public QDialog
		{
			Q_OBJECT;

		public:
			//! Default constructor.
			CreateArcClothoidClothoidArcDialog(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~CreateArcClothoidClothoidArcDialog();

			double R1 = 0, R2 = 0, phi1 = 0, phi2 = 0, A1 = 0, A2 = 0;
			bool s_form;
			
		protected:
			virtual void changeEvent(QEvent* evt) override;

		private Q_SLOTS:
			void on_pushButtonGenerate_clicked();
			void on_pushButtonCancel_clicked();

		private:
			Ui::CreateArcClothoidClothoidArc*	ui_;
		}; // end class CreateArcClothoidClothoidArc
	} // end namespace UserInterface
} // end namespace OpenInfraPlatfom

namespace buw
{
	using OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcDialog;
}

