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
#include "include/IfcCoordinateOperation.h"
#include "include/IfcCoordinateReferenceSystem.h"
#include "include/IfcCoordinateReferenceSystemSelect.h"
#include "include/IfcGeometricRepresentationContext.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcCoordinateOperation 
		IfcCoordinateOperation::IfcCoordinateOperation() { m_entity_enum = IFCCOORDINATEOPERATION; }
		IfcCoordinateOperation::IfcCoordinateOperation( int id ) { m_id = id; m_entity_enum = IFCCOORDINATEOPERATION; }
		IfcCoordinateOperation::~IfcCoordinateOperation() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCoordinateOperation::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcCoordinateOperation> other = dynamic_pointer_cast<IfcCoordinateOperation>(other_entity);
			if( !other) { return; }
			m_SourceCRS = other->m_SourceCRS;
			m_TargetCRS = other->m_TargetCRS;
		}
		void IfcCoordinateOperation::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCOORDINATEOPERATION" << "(";
			if( m_SourceCRS ) { m_SourceCRS->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_TargetCRS ) { stream << "#" << m_TargetCRS->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCoordinateOperation::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCoordinateOperation::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCoordinateOperation, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcCoordinateOperation, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_SourceCRS = IfcCoordinateReferenceSystemSelect::readStepData( args[0], map );
			readEntityReference( args[1], m_TargetCRS, map );
		}
		void IfcCoordinateOperation::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			shared_ptr<IfcCoordinateOperation> ptr_self = dynamic_pointer_cast<IfcCoordinateOperation>( ptr_self_entity );
			if( !ptr_self ) { throw IfcAlignmentP6Exception( "IfcCoordinateOperation::setInverseCounterparts: type mismatch" ); }
			shared_ptr<IfcCoordinateReferenceSystem>  SourceCRS_IfcCoordinateReferenceSystem = dynamic_pointer_cast<IfcCoordinateReferenceSystem>( m_SourceCRS );
			if( SourceCRS_IfcCoordinateReferenceSystem )
			{
				SourceCRS_IfcCoordinateReferenceSystem->m_HasCoordinateOperation_inverse.push_back( ptr_self );
			}
			shared_ptr<IfcGeometricRepresentationContext>  SourceCRS_IfcGeometricRepresentationContext = dynamic_pointer_cast<IfcGeometricRepresentationContext>( m_SourceCRS );
			if( SourceCRS_IfcGeometricRepresentationContext )
			{
				SourceCRS_IfcGeometricRepresentationContext->m_HasCoordinateOperation_inverse.push_back( ptr_self );
			}
		}
		void IfcCoordinateOperation::unlinkSelf()
		{
			shared_ptr<IfcCoordinateReferenceSystem>  SourceCRS_IfcCoordinateReferenceSystem = dynamic_pointer_cast<IfcCoordinateReferenceSystem>( m_SourceCRS );
			if( SourceCRS_IfcCoordinateReferenceSystem )
			{
				std::vector<weak_ptr<IfcCoordinateOperation> >& HasCoordinateOperation_inverse = SourceCRS_IfcCoordinateReferenceSystem->m_HasCoordinateOperation_inverse;
				std::vector<weak_ptr<IfcCoordinateOperation> >::iterator it_HasCoordinateOperation_inverse;
				for( it_HasCoordinateOperation_inverse = HasCoordinateOperation_inverse.begin(); it_HasCoordinateOperation_inverse != HasCoordinateOperation_inverse.end(); ++it_HasCoordinateOperation_inverse)
				{
					shared_ptr<IfcCoordinateOperation> self_candidate( *it_HasCoordinateOperation_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasCoordinateOperation_inverse.erase( it_HasCoordinateOperation_inverse );
						break;
					}
				}
			}
			shared_ptr<IfcGeometricRepresentationContext>  SourceCRS_IfcGeometricRepresentationContext = dynamic_pointer_cast<IfcGeometricRepresentationContext>( m_SourceCRS );
			if( SourceCRS_IfcGeometricRepresentationContext )
			{
				std::vector<weak_ptr<IfcCoordinateOperation> >& HasCoordinateOperation_inverse = SourceCRS_IfcGeometricRepresentationContext->m_HasCoordinateOperation_inverse;
				std::vector<weak_ptr<IfcCoordinateOperation> >::iterator it_HasCoordinateOperation_inverse;
				for( it_HasCoordinateOperation_inverse = HasCoordinateOperation_inverse.begin(); it_HasCoordinateOperation_inverse != HasCoordinateOperation_inverse.end(); ++it_HasCoordinateOperation_inverse)
				{
					shared_ptr<IfcCoordinateOperation> self_candidate( *it_HasCoordinateOperation_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasCoordinateOperation_inverse.erase( it_HasCoordinateOperation_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
