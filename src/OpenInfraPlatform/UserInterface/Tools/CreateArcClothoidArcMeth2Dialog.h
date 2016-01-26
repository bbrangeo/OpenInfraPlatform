/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#include "ui_CreateArcClothoidArcMeth2.h"
#include "functions.h"

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
			private Q_SLOTS:
			void on_pushButtonGenerate_clicked();
			void on_pushButtonCancel_clicked();

			public Q_SLOTS:
			void takePoints(std::vector<buw::vector3d> givenPoints, buw::vector2d givenOffset)
			{
				points_ = givenPoints;
				offset_ = givenOffset;
			};
		private:
			std::vector<buw::vector3d> points_;
			buw::vector2d offset_;
			Ui::CreateArcClothoidArcMeth2 *	ui_;
		}; // end class CreateArcClothoidArcMeth2Dialog 
	} // end namespace UserInterface
} // end namespace OpenInfraPlatfom

namespace buw
{
	using OpenInfraPlatform::UserInterface::CreateArcClothoidArcMeth2Dialog;
}

