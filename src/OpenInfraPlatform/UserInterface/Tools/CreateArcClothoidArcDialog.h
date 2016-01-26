/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#include "ui_CreateArcClothoidArc.h"
#include "functions.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		//! \class CreateArcClothoidArc
		//! \brief brief description
		class CreateArcClothoidArcDialog : public QDialog
		{
			Q_OBJECT;

		public:
			//! Default constructor.
			CreateArcClothoidArcDialog(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~CreateArcClothoidArcDialog();
			
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
			Ui::CreateArcClothoidArc *	ui_;
		}; // end class CreateArcClothoidArcDialog 
	} // end namespace UserInterface
} // end namespace OpenInfraPlatfom

namespace buw
{
	using OpenInfraPlatform::UserInterface::CreateArcClothoidArcDialog;
}

