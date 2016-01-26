/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_AbstractSyntaxTreeNode_17d40bab_f014_4c25_8fd3_6c18acd80a15_h
#define OpenInfraPlatform_Infrastructure_AbstractSyntaxTreeNode_17d40bab_f014_4c25_8fd3_6c18acd80a15_h

#include "buw.BlueCore.h"
#include <boost/noncopyable.hpp>
#include "token.h"
#include "variant.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		struct AbstractSyntaxTreeNode
		{
			BLUE_DEFINE_SHARED_POINTER(AbstractSyntaxTreeNode);

			static buw::ReferenceCounted<AbstractSyntaxTreeNode> create(const token& t)
			{
				return std::make_shared<AbstractSyntaxTreeNode>(t);
			}

			AbstractSyntaxTreeNode(
				const token& t)
			{
				this->token_ = t;
				this->left = nullptr;
				this->right = nullptr;
				isUnary = false;
			}

			AbstractSyntaxTreeNode(
				const token& t,
				buw::ReferenceCounted<AbstractSyntaxTreeNode> left,
				buw::ReferenceCounted<AbstractSyntaxTreeNode> right)
			{
				this->token_ = t;
				this->left = left;
				this->right = right;
				isUnary = false;
			}

			eTokenType::Enum getTokenType() const
			{
				return token_.type;
			}

			//eTokenType::Enum			type;
			buw::ReferenceCounted<AbstractSyntaxTreeNode> left;
			buw::ReferenceCounted<AbstractSyntaxTreeNode> right;
			bool						isUnary;

			// needed by interpreter
			VariantType					value;
			token						token_;
		};
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::AbstractSyntaxTreeNode;
}

#endif // end define OpenInfraPlatform_Infrastructure_AbstractSyntaxTreeNode_17d40bab_f014_4c25_8fd3_6c18acd80a15_h
