/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_UserInterface_GenerateTerrain_c5f0677f_a918_44dc_9cee_e5eacc6e0c45_h
#define OpenInfraPlatform_UserInterface_GenerateTerrain_c5f0677f_a918_44dc_9cee_e5eacc6e0c45_h

#include <QDialog>
#include <boost/noncopyable.hpp>
#include "ui_GenerateTerrain.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		//! \class GenerateTerrain
		//! \brief brief description
		class GenerateTerrainDialog : public QDialog
		{
			Q_OBJECT;

		public:
			//! Default constructor.
			GenerateTerrainDialog(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~GenerateTerrainDialog();

		protected:
			virtual void changeEvent(QEvent* evt) override;

		private Q_SLOTS:
			void on_pushButtonGenerate_clicked();
			void on_pushButtonCancel_clicked();

		private:
			Ui::GenerateTerrain*	ui_;
		}; // end class GenerateTerrain
	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::UserInterface::GenerateTerrainDialog;
}

#endif // end define OpenInfraPlatform_UserInterface_GenerateTerrain_c5f0677f_a918_44dc_9cee_e5eacc6e0c45_h
