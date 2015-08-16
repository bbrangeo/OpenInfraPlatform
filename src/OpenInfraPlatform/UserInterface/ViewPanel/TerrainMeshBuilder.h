/*! \verbatim
 *  \copyright		Copyright (c) 2015 Julian Amann. All rights reserved.
 *	\author			Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *	\brief			This file is part of the BlueFramework.
 *	\endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_TerrainMeshBuilder_8f09a1e6_a703_4b06_b449_092a6b800fe5_h
#define OpenInfraPlatform_TerrainMeshBuilder_8f09a1e6_a703_4b06_b449_092a6b800fe5_h

#include <boost/noncopyable.hpp>

#include "OpenInfraPlatform/Infrastructure/Import/LandXmlImport.h"
#include "buw.BlueEngine.h"

namespace OpenInfraPlatform
{
	BlueFramework::Engine::SimpleMesh::Ptr
		ConvertToSimpleMesh( 
		const buw::Surface* s );
	
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::ConvertToSimpleMesh;
}

#endif // end define OpenInfraPlatform_TerrainMeshBuilder_8f09a1e6_a703_4b06_b449_092a6b800fe5_h
