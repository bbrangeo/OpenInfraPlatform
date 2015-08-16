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
#include "ui_CreateArcClothoidClothoidArcMeth2.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		//! \class CreateArcClothoidClothoidArcMeth2
		//! \brief brief description
		class CreateArcClothoidClothoidArcMeth2Dialog : public QDialog
		{
			Q_OBJECT;

		public:
			//! Default constructor.
			CreateArcClothoidClothoidArcMeth2Dialog(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~CreateArcClothoidClothoidArcMeth2Dialog();

			double R1 = 0, R2 = 0, phi1 = 0, phi2 = 0, A1 = 0, A2 = 0, psi =0;
		private Q_SLOTS:
			void on_pushButtonGenerate_clicked();
			void on_pushButtonCancel_clicked();

		private:
			Ui::CreateArcClothoidClothoidArcMeth2*	ui_;
		}; // end class CreateArcClothoidClothoidArcMeth2
	} // end namespace UserInterface
} // end namespace OpenInfraPlatfom

namespace buw
{
	using OpenInfraPlatform::UserInterface::CreateArcClothoidClothoidArcMeth2Dialog;
}

