/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de/en)
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#include "ui_CreateLineArcArcArcLine.h"
#include "functions.h"

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
			
		protected:
			virtual void changeEvent(QEvent* evt) override;

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
			buw::vector2d offset_;			Ui::CreateLineArcArcArcLine*	ui_;
		}; // end class CreateLineArcArcArcLine
	} // end namespace UserInterface
} // end namespace OpenInfraPlatfom

namespace buw
{
	using OpenInfraPlatform::UserInterface::CreateLineArcArcArcLineDialog;
}

