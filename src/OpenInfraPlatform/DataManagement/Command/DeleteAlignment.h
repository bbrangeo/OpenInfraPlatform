/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_DataManagement_Command_DeleteAlignment_e71eafc3_7af8_4609_8b13_a1d1312a59fa_h
#define OpenInfraPlatform_DataManagement_Command_DeleteAlignment_e71eafc3_7af8_4609_8b13_a1d1312a59fa_h

#include "BlueFramework/Core/memory.h"
#include "OpenInfraPlatform/Data/terrainDescription.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/IAlignment3D.h"
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
			class DeleteAlignment : public buw::ICommand
			{
			public:
				BLUE_DEFINE_SHARED_POINTER(DeleteAlignment);

				//! Default constructor.
				DeleteAlignment(buw::ReferenceCounted<buw::IAlignment3D> alignment);

				//! Virtual destructor.
				virtual ~DeleteAlignment();

				//! Execute action.
				virtual void execute();

				//! Undo action 
				virtual void unexecute();

			private:
				buw::ReferenceCounted<buw::IAlignment3D> alignment_;
			}; // end class DeleteAlignment
		} // end namespace Action
	} // end namespace DataManagement
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::DataManagement::Command::DeleteAlignment;
}

#endif // end define OpenInfraPlatform_DataManagement_Command_DeleteAlignment_e71eafc3_7af8_4609_8b13_a1d1312a59fa_h
