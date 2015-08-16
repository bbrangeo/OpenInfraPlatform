/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcLabel.h"
#include "include/IfcLogical.h"
#include "include/IfcProductDefinitionShape.h"
#include "include/IfcProductRepresentationSelect.h"
#include "include/IfcRepresentationMap.h"
#include "include/IfcShapeAspect.h"
#include "include/IfcShapeModel.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcShapeAspect 
		IfcShapeAspect::IfcShapeAspect() { m_entity_enum = IFCSHAPEASPECT; }
		IfcShapeAspect::IfcShapeAspect( int id ) { m_id = id; m_entity_enum = IFCSHAPEASPECT; }
		IfcShapeAspect::~IfcShapeAspect() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcShapeAspect::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcShapeAspect> other = dynamic_pointer_cast<IfcShapeAspect>(other_entity);
			if( !other) { return; }
			m_ShapeRepresentations = other->m_ShapeRepresentations;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ProductDefinitional = other->m_ProductDefinitional;
			m_PartOfProductDefinitionShape = other->m_PartOfProductDefinitionShape;
		}
		void IfcShapeAspect::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSHAPEASPECT" << "(";
			writeEntityList( stream, m_ShapeRepresentations );
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ProductDefinitional ) { m_ProductDefinitional->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PartOfProductDefinitionShape ) { m_PartOfProductDefinitionShape->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcShapeAspect::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcShapeAspect::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcShapeAspect, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcShapeAspect, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_ShapeRepresentations, map );
			m_Name = IfcLabel::readStepData( args[1] );
			m_Description = IfcText::readStepData( args[2] );
			m_ProductDefinitional = IfcLogical::readStepData( args[3] );
			m_PartOfProductDefinitionShape = IfcProductRepresentationSelect::readStepData( args[4], map );
		}
		void IfcShapeAspect::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			shared_ptr<IfcShapeAspect> ptr_self = dynamic_pointer_cast<IfcShapeAspect>( ptr_self_entity );
			if( !ptr_self ) { throw IfcAlignmentP6Exception( "IfcShapeAspect::setInverseCounterparts: type mismatch" ); }
			shared_ptr<IfcProductDefinitionShape>  PartOfProductDefinitionShape_IfcProductDefinitionShape = dynamic_pointer_cast<IfcProductDefinitionShape>( m_PartOfProductDefinitionShape );
			if( PartOfProductDefinitionShape_IfcProductDefinitionShape )
			{
				PartOfProductDefinitionShape_IfcProductDefinitionShape->m_HasShapeAspects_inverse.push_back( ptr_self );
			}
			shared_ptr<IfcRepresentationMap>  PartOfProductDefinitionShape_IfcRepresentationMap = dynamic_pointer_cast<IfcRepresentationMap>( m_PartOfProductDefinitionShape );
			if( PartOfProductDefinitionShape_IfcRepresentationMap )
			{
				PartOfProductDefinitionShape_IfcRepresentationMap->m_HasShapeAspects_inverse.push_back( ptr_self );
			}
			for( int i=0; i<m_ShapeRepresentations.size(); ++i )
			{
				if( m_ShapeRepresentations[i] )
				{
					m_ShapeRepresentations[i]->m_OfShapeAspect_inverse.push_back( ptr_self );
				}
			}
		}
		void IfcShapeAspect::unlinkSelf()
		{
			shared_ptr<IfcProductDefinitionShape>  PartOfProductDefinitionShape_IfcProductDefinitionShape = dynamic_pointer_cast<IfcProductDefinitionShape>( m_PartOfProductDefinitionShape );
			if( PartOfProductDefinitionShape_IfcProductDefinitionShape )
			{
				std::vector<weak_ptr<IfcShapeAspect> >& HasShapeAspects_inverse = PartOfProductDefinitionShape_IfcProductDefinitionShape->m_HasShapeAspects_inverse;
				std::vector<weak_ptr<IfcShapeAspect> >::iterator it_HasShapeAspects_inverse;
				for( it_HasShapeAspects_inverse = HasShapeAspects_inverse.begin(); it_HasShapeAspects_inverse != HasShapeAspects_inverse.end(); ++it_HasShapeAspects_inverse)
				{
					shared_ptr<IfcShapeAspect> self_candidate( *it_HasShapeAspects_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasShapeAspects_inverse.erase( it_HasShapeAspects_inverse );
						break;
					}
				}
			}
			shared_ptr<IfcRepresentationMap>  PartOfProductDefinitionShape_IfcRepresentationMap = dynamic_pointer_cast<IfcRepresentationMap>( m_PartOfProductDefinitionShape );
			if( PartOfProductDefinitionShape_IfcRepresentationMap )
			{
				std::vector<weak_ptr<IfcShapeAspect> >& HasShapeAspects_inverse = PartOfProductDefinitionShape_IfcRepresentationMap->m_HasShapeAspects_inverse;
				std::vector<weak_ptr<IfcShapeAspect> >::iterator it_HasShapeAspects_inverse;
				for( it_HasShapeAspects_inverse = HasShapeAspects_inverse.begin(); it_HasShapeAspects_inverse != HasShapeAspects_inverse.end(); ++it_HasShapeAspects_inverse)
				{
					shared_ptr<IfcShapeAspect> self_candidate( *it_HasShapeAspects_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasShapeAspects_inverse.erase( it_HasShapeAspects_inverse );
						break;
					}
				}
			}
			for( int i=0; i<m_ShapeRepresentations.size(); ++i )
			{
				if( m_ShapeRepresentations[i] )
				{
					std::vector<weak_ptr<IfcShapeAspect> >& OfShapeAspect_inverse = m_ShapeRepresentations[i]->m_OfShapeAspect_inverse;
					std::vector<weak_ptr<IfcShapeAspect> >::iterator it_OfShapeAspect_inverse;
					for( it_OfShapeAspect_inverse = OfShapeAspect_inverse.begin(); it_OfShapeAspect_inverse != OfShapeAspect_inverse.end(); ++it_OfShapeAspect_inverse)
					{
						shared_ptr<IfcShapeAspect> self_candidate( *it_OfShapeAspect_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							OfShapeAspect_inverse.erase( it_OfShapeAspect_inverse );
							break;
						}
					}
				}
			}
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
