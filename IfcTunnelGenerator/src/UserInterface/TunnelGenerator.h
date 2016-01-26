/*! \verbatim
*  \copyright      Copyright (c) 2015 Technische Universität München
*                  Chair of Computational Modeling and Simulation. All rights reserved.
*  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de)
*  \brief          This file is part of the TUM Open Infra Platform.
*  \endverbatim
*/
#ifndef TUNNELGENERATOR_H
#define TUNNELGENERATOR_H
#pragma once
#include <QWindow>
#include "ui_TunnelGenerator.h"
#include "src/Ifc4FileFactory.h"
namespace Ui
{
	class TunnelGeneratorWindow;
}

	namespace UserInterface
	{
		
		class TunnelGenerator : public QMainWindow
		{
			Q_OBJECT;

		public:
			//! Default constructor.
			TunnelGenerator(QWidget *parent = nullptr);

			//! Virtual destructor.
			virtual ~TunnelGenerator() {};
			std::string SpaceName[14];
			std::string  saveName;			
			std::vector <t_part> t_parts; // t_part has the elements current, previous, father_pos, aggregate_pos and openName
		protected:

			private Q_SLOTS:
			void on_pushButtonSave_ifc4_clicked();
			void on_pushButtonSave_tunnel_clicked();
			void on_pushButtonOpen_clicked();

		private:
			Ui::TunnelGeneratorWindow*	ui_;
		}; // end class TunnelGenerator
	} // end namespace UserInterface

#endif
