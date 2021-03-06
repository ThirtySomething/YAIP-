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
 * \file	IniEntryList.h
 * \author	ThirtySomething
 * \date	2016-09-19
 * \brief	List of INI entries
 */
#ifndef _INIENTRYLIST_H_
#define _INIENTRYLIST_H_

#include "IniEntry.h"
#include "TIniElementList.h"

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
			 * List of INI entries
			 */
			class IniEntryList : public TIniElementList<IniEntryPtr>
			{
			public:
				/**
				 * We need to sort the own list
				 */
				virtual void sort(void) override;
			};
		}
	}
}

#endif
