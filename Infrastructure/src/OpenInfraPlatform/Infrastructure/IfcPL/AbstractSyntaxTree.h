/*! \verbatim
 *  \copyright      Copyright (c) 2015 Technische Universität München
 *                  Chair of Computational Modeling and Simulation. All rights reserved.
 *  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *  \brief          This file is part of the TUM Open Infra Platform.
 *  \endverbatim
 */

#pragma once
#ifndef OpenInfraPlatform_Infrastructure_AbstractSyntaxTree_1a5b5367_b29c_43b9_bfcd_1d0589827a60_h
#define OpenInfraPlatform_Infrastructure_AbstractSyntaxTree_1a5b5367_b29c_43b9_bfcd_1d0589827a60_h

#include "buw.BlueCore.h"
#include <boost/noncopyable.hpp>
#include "AbstractSyntaxTreeNode.h"

namespace OpenInfraPlatform
{
	namespace Infrastructure
	{
		class AbstractSyntaxTree
		{
		public:
			BLUE_DEFINE_SHARED_POINTER(AbstractSyntaxTree);

			AbstractSyntaxTree()
			{
				token mainToken;
				mainToken.type = eTokenType::PROGRAM;
				root_ = std::make_shared<AbstractSyntaxTreeNode>(mainToken, nullptr, nullptr);
			}

			AbstractSyntaxTree(AbstractSyntaxTreeNode::Ptr root)
			{
				root_ = root;
			}

			AbstractSyntaxTreeNode::Ptr	getRoot()
			{
				return root_;
			}

			void write(std::ostream& out)
			{
				out << "AST:" << std::endl;
				walk(out, root_);
			}

		private:	
			struct eBinaryTreePosition
			{
				enum Enum
				{
					Left,
					Right,
					Root				
				};
			};

			void walk(std::ostream& out, 
				AbstractSyntaxTreeNode::Ptr node, 
				int depth = 0,
				eBinaryTreePosition::Enum position = eBinaryTreePosition::Root)
			{
				if (node == nullptr)
				{
					return;
				}

				std::string strPosition;

				if (position == eBinaryTreePosition::Root)
				{
					strPosition = "-";
				}
				else
				{
					strPosition = (position == eBinaryTreePosition::Left) ? "Left" : "Right";
				}

				for (int i = 0; i < depth; i++)
				{
					out << "    ";
				}

				out << "[" << strPosition.c_str() << "]" << tokenToString(node->getTokenType()).c_str() << std::endl;

				if (node->left)
				{
					walk(out, node->left, depth + 1, eBinaryTreePosition::Left);
				}

				if (node->right)
				{
					walk(out, node->right, depth + 1, eBinaryTreePosition::Right);
				}
			}

		private:
			AbstractSyntaxTreeNode::Ptr	root_;
		};

		BLUEINFRASTRUCTURE_API std::ostream& operator << (std::ostream& os, AbstractSyntaxTree::Ptr& ast);
	} // end namespace Infrastructure
} // end namespace BlueFramework

namespace buw
{
	using OpenInfraPlatform::Infrastructure::AbstractSyntaxTree;
}

#endif // end define OpenInfraPlatform_Infrastructure_AbstractSyntaxTree_1a5b5367_b29c_43b9_bfcd_1d0589827a60_h
