#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcBridge/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcBridge/model/IfcBridgeObject.h"

// TYPE IfcBridgeSubstructureElementType = ENUMERATION OF (ABUTMENT, PIER, FOUNDATION);
class IfcBridgeSubstructureElementType : public OpenInfraPlatform::IfcBridge::IfcBridgeAbstractEnum, public OpenInfraPlatform::IfcBridge::IfcBridgeType
{
public:
	enum IfcBridgeSubstructureElementTypeEnum
	{
		ENUM_ABUTMENT,
		ENUM_PIER,
		ENUM_FOUNDATION
	};

	IfcBridgeSubstructureElementType();
	IfcBridgeSubstructureElementType( IfcBridgeSubstructureElementTypeEnum e ) { m_enum = e; }
	~IfcBridgeSubstructureElementType();
	virtual const char* classname() const { return "IfcBridgeSubstructureElementType"; }
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
	static shared_ptr<IfcBridgeSubstructureElementType> readStepData( std::string& arg );
	IfcBridgeSubstructureElementTypeEnum m_enum;
};

