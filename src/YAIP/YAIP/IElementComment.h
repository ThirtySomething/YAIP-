//******************************************************************************
// Copyright 2016 ThirtySomething
//******************************************************************************
// This file is part of YAIP.
//
// YAIP is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// YAIP is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
// more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with YAIP. If not, see <http://www.gnu.org/licenses/>.
//******************************************************************************

/**
 * \file	IElementComment.h
 * \author	ThirtySomething
 * \date	2016-09-19
 * \brief	Interface for getting and setting element comments
 */
#pragma once

 /**
  * Namespace of YAIP
  */
namespace net
{
	/**
	 * Namespace of YAIP
	 */
	namespace derpaul
	{
		/**
		 * Namespace of YAIP
		 */
		namespace yaip
		{
			/**
			 * Interface for common access the comment of INI objects
			 */
			class IElementComment
			{
			public:
				/**
				 * Set the INI object comment
				 * \param ElementComment Comment of INI object
				 */
				virtual void ElementCommentSet(const std::string &ElementComment) = 0;

				/**
				 * Get the INI object comment
				 * \return Comment of INI object
				 */
				virtual std::string ElementCommentGet(void) = 0;
			};
		}
	}
}