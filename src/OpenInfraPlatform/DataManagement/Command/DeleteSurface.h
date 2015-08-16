/*! \verbatim
 *  \copyright      Copyright (c) 2015 Julian Amann. All rights reserved.
 *  \author         Julian Amann <dev@vertexwahn.de> (http://vertexwahn.de/)
 *  \brief          This file is part of the BlueFramework.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_DataManagement_Command_DeleteSurface_8481e70d_b71a_4983_bef4_224c6281e73a_h
#define OpenInfraPlatform_DataManagement_Command_DeleteSurface_8481e70d_b71a_4983_bef4_224c6281e73a_h

#include "OpenInfraPlatform/Data/terrainDescription.h"
#include "OpenInfraPlatform/Infrastructure/DigitalElevationModel/Surface.h"
#include "BlueFramework/Application/DataManagement/Command/ICommand.h"
#include "BlueFramework/Core/Math/vector.h"
#include <boost/noncopyable.hpp>
#include <vector>

namespace OpenInfraPlatform
{
	namespace DataManagement
	{
		namespace Command
		{
			class DeleteSurface : public buw::ICommand
			{
			public:
				BLUE_DEFINE_SHARED_POINTER(DeleteSurface);

				DeleteSurface(buw::Surface::Ptr surface);

				virtual ~DeleteSurface();

				//! Execute action.
				virtual void execute();

				//! Undo action 
				virtual void unexecute();

			private:
				buw::Surface::Ptr surface_;

			}; // end class DeleteSurface
		} // end namespace Command
	} // end namespace DataManagement
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::DataManagement::Command::DeleteSurface;
}

#endif // end define OpenInfraPlatform_DataManagement_Command_DeleteSurface_8481e70d_b71a_4983_bef4_224c6281e73a_h
