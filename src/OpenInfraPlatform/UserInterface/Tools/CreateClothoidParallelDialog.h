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
#include "ui_CreateClothoidParallel.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		//! \class CreateClothoidParallel
		//! \brief brief description
		class CreateClothoidParallelDialog : public QDialog
		{
			Q_OBJECT;

		public:
			//! Default constructor.
			CreateClothoidParallelDialog(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~CreateClothoidParallelDialog();
			bool exactly,sameA;
			double width = 0, distance = 0;
		private Q_SLOTS:
			void on_pushButtonGenerate_clicked();
			void on_pushButtonCancel_clicked();

		private:
			Ui::CreateClothoidParallel*	ui_;
		}; // end class CreateClothoidParallel
	} // end namespace UserInterface
} // end namespace OpenInfraPlatfom

namespace buw
{
	using OpenInfraPlatform::UserInterface::CreateClothoidParallelDialog;
}

