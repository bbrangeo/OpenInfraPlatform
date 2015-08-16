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
#include "ui_CreateClothoid.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		//! \class CreateClothoid
		//! \brief brief description
		class CreateClothoidDialog : public QDialog
		{
			Q_OBJECT;

		public:
			//! Default constructor.
			CreateClothoidDialog(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~CreateClothoidDialog();
			bool clock;
			double R = 0, A = 0, L = 0;
			
		protected:
			virtual void changeEvent(QEvent* evt) override;

		private Q_SLOTS:
			void on_pushButtonGenerate_clicked();
			void on_pushButtonCancel_clicked();

		private:
			Ui::CreateClothoid*	ui_;
		}; // end class CreateClothoid
	} // end namespace UserInterface
} // end namespace OpenInfraPlatfom

namespace buw
{
	using OpenInfraPlatform::UserInterface::CreateClothoidDialog;
}

