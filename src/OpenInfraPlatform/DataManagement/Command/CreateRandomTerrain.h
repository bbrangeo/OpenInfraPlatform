/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_DataManagement_Command_CreateRandomTerrain_h
#define OpenInfraPlatform_DataManagement_Command_CreateRandomTerrain_h

#include "../../Data/terrainDescription.h"
#include "BlueFramework/Core/Math/vector.h"
#include "BlueFramework/Application/DataManagement/Command/ICommand.h"
#include <boost/noncopyable.hpp>
#include <vector>

namespace OpenInfraPlatform
{
	namespace DataManagement
	{
		namespace Command
		{
			class CreateRandomTerrain : public buw::ICommand
			{
			public:
				CreateRandomTerrain(const buw::terrainDescription& td);

				virtual ~CreateRandomTerrain();
				
				//! Execute action.
				virtual void execute();

				//! Undo action 
				virtual void unexecute();

			private:
				buw::terrainDescription td_;
			};
		}
	}
}

namespace buw
{
	using OpenInfraPlatform::DataManagement::Command::CreateRandomTerrain;
}

#endif // end define OpenInfraPlatform_DataManagement_Command_CreateRandomTerrain_h
