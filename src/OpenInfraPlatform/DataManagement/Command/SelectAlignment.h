/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_DataManagement_Command_ImportXYZ_c336b8aa_26da_42da_b795_6f27831713a2_h
#define OpenInfraPlatform_DataManagement_Command_ImportXYZ_c336b8aa_26da_42da_b795_6f27831713a2_h

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
			class SelectAlignment : public buw::ICommand
			{
			public:
				//! Default constructor.
				SelectAlignment(int selectedIndex);

				//! Virtual destructor.
				virtual ~SelectAlignment();

				//! Execute action.
				virtual void execute();

				//! Undo action 
				virtual void unexecute();

			private:
				int selectedIndex_;
				int prevSelectedIndex_;
			}; // end class SelectAlignment
		} // end namespace Action
	} // end namespace DataManagement
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::DataManagement::Command::SelectAlignment;
}

#endif // end define OpenInfraPlatform_DataManagement_Command_ImportXYZ_c336b8aa_26da_42da_b795_6f27831713a2_h
