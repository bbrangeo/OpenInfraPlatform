/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcPhysicalComplexQuantity.h"
#include "include/IfcPhysicalQuantity.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcPhysicalComplexQuantity 
		IfcPhysicalComplexQuantity::IfcPhysicalComplexQuantity() { m_entity_enum = IFCPHYSICALCOMPLEXQUANTITY; }
		IfcPhysicalComplexQuantity::IfcPhysicalComplexQuantity( int id ) { m_id = id; m_entity_enum = IFCPHYSICALCOMPLEXQUANTITY; }
		IfcPhysicalComplexQuantity::~IfcPhysicalComplexQuantity() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPhysicalComplexQuantity::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcPhysicalComplexQuantity> other = dynamic_pointer_cast<IfcPhysicalComplexQuantity>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_HasQuantities = other->m_HasQuantities;
			m_Discrimination = other->m_Discrimination;
			m_Quality = other->m_Quality;
			m_Usage = other->m_Usage;
		}
		void IfcPhysicalComplexQuantity::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPHYSICALCOMPLEXQUANTITY" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_HasQuantities );
			stream << ",";
			if( m_Discrimination ) { m_Discrimination->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Quality ) { m_Quality->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Usage ) { m_Usage->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPhysicalComplexQuantity::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPhysicalComplexQuantity::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPhysicalComplexQuantity, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcPhysicalComplexQuantity, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReferenceList( args[2], m_HasQuantities, map );
			m_Discrimination = IfcLabel::readStepData( args[3] );
			m_Quality = IfcLabel::readStepData( args[4] );
			m_Usage = IfcLabel::readStepData( args[5] );
		}
		void IfcPhysicalComplexQuantity::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcPhysicalQuantity::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcPhysicalComplexQuantity> ptr_self = dynamic_pointer_cast<IfcPhysicalComplexQuantity>( ptr_self_entity );
			if( !ptr_self ) { throw IfcBridgeException( "IfcPhysicalComplexQuantity::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_HasQuantities.size(); ++i )
			{
				if( m_HasQuantities[i] )
				{
					m_HasQuantities[i]->m_PartOfComplex_inverse.push_back( ptr_self );
				}
			}
		}
		void IfcPhysicalComplexQuantity::unlinkSelf()
		{
			IfcPhysicalQuantity::unlinkSelf();
			for( int i=0; i<m_HasQuantities.size(); ++i )
			{
				if( m_HasQuantities[i] )
				{
					std::vector<weak_ptr<IfcPhysicalComplexQuantity> >& PartOfComplex_inverse = m_HasQuantities[i]->m_PartOfComplex_inverse;
					std::vector<weak_ptr<IfcPhysicalComplexQuantity> >::iterator it_PartOfComplex_inverse;
					for( it_PartOfComplex_inverse = PartOfComplex_inverse.begin(); it_PartOfComplex_inverse != PartOfComplex_inverse.end(); ++it_PartOfComplex_inverse)
					{
						shared_ptr<IfcPhysicalComplexQuantity> self_candidate( *it_PartOfComplex_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							PartOfComplex_inverse.erase( it_PartOfComplex_inverse );
							break;
						}
					}
				}
			}
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
