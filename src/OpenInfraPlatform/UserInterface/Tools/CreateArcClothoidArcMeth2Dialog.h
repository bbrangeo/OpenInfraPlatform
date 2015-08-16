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
#include "ui_CreateArcClothoidArcMeth2.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		//! \class CreateArcClothoidArcMeth2
		//! \brief brief description
		class CreateArcClothoidArcMeth2Dialog : public QDialog
		{
			Q_OBJECT;

		public:
			//! Default constructor.
			CreateArcClothoidArcMeth2Dialog(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~CreateArcClothoidArcMeth2Dialog();

			double R1 = 0, R2 = 0, delta1 = 0, delta2 = 0, phi1 = 0, phi2 = 0;
			bool d1 = true;
		private Q_SLOTS:
			void on_pushButtonGenerate_clicked();
			void on_pushButtonCancel_clicked();

		private:
			Ui::CreateArcClothoidArcMeth2 *	ui_;
		}; // end class CreateArcClothoidArcMeth2Dialog 
	} // end namespace UserInterface
} // end namespace OpenInfraPlatfom

namespace buw
{
	using OpenInfraPlatform::UserInterface::CreateArcClothoidArcMeth2Dialog;
}

