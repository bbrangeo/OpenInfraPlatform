/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/Ifc4EntityEnums.h"
#include "include/IfcLabel.h"
#include "include/IfcProductRepresentation.h"
#include "include/IfcRepresentation.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcProductRepresentation 
		IfcProductRepresentation::IfcProductRepresentation() { m_entity_enum = IFCPRODUCTREPRESENTATION; }
		IfcProductRepresentation::IfcProductRepresentation( int id ) { m_id = id; m_entity_enum = IFCPRODUCTREPRESENTATION; }
		IfcProductRepresentation::~IfcProductRepresentation() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcProductRepresentation::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcProductRepresentation> other = dynamic_pointer_cast<IfcProductRepresentation>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Representations = other->m_Representations;
		}
		void IfcProductRepresentation::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPRODUCTREPRESENTATION" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Representations );
			stream << ");";
		}
		void IfcProductRepresentation::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcProductRepresentation::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcProductRepresentation, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcProductRepresentation, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReferenceList( args[2], m_Representations, map );
		}
		void IfcProductRepresentation::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			shared_ptr<IfcProductRepresentation> ptr_self = dynamic_pointer_cast<IfcProductRepresentation>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc4Exception( "IfcProductRepresentation::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_Representations.size(); ++i )
			{
				if( m_Representations[i] )
				{
					m_Representations[i]->m_OfProductRepresentation_inverse.push_back( ptr_self );
				}
			}
		}
		void IfcProductRepresentation::unlinkSelf()
		{
			for( int i=0; i<m_Representations.size(); ++i )
			{
				if( m_Representations[i] )
				{
					std::vector<weak_ptr<IfcProductRepresentation> >& OfProductRepresentation_inverse = m_Representations[i]->m_OfProductRepresentation_inverse;
					std::vector<weak_ptr<IfcProductRepresentation> >::iterator it_OfProductRepresentation_inverse;
					for( it_OfProductRepresentation_inverse = OfProductRepresentation_inverse.begin(); it_OfProductRepresentation_inverse != OfProductRepresentation_inverse.end(); ++it_OfProductRepresentation_inverse)
					{
						shared_ptr<IfcProductRepresentation> self_candidate( *it_OfProductRepresentation_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							OfProductRepresentation_inverse.erase( it_OfProductRepresentation_inverse );
							break;
						}
					}
				}
			}
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
