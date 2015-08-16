/*! \verbatim
 *  \copyright      Copyright (c) 2015 Julian Amann. All rights reserved.
 *  \author         Julian Amann <dev@vertexwahn.de> (http://vertexwahn.de/)
 *  \brief          This file is part of the BlueFramework.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_ObjExport_b64d487c_2700_4abb_8aab_fc866636400a_h
#define OpenInfraPlatform_Infrastructure_ObjExport_b64d487c_2700_4abb_8aab_fc866636400a_h

#include <boost/noncopyable.hpp>

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class ObjExport : private boost::noncopyable
		{
		public:
			ObjExport();

			virtual ~ObjExport()
			{
			}

		private:
		}; // end class ObjExport
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::ObjExport;
}

#endif // end define OpenInfraPlatform_Infrastructure_ObjExport_b64d487c_2700_4abb_8aab_fc866636400a_h
