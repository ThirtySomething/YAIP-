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
 * \file	Convert.h
 * \author	ThirtySomething
 * \date	2016-09-19
 * \brief	Converter between different datatypes and std::string
 */
#ifndef _CONVERT_H_
#define _CONVERT_H_

#include <string>

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
			 * Class to convert data from and to std::string
			 * \see http://en.cppreference.com/w/cpp/language/types
			 * <table>
			 * <caption id="multi_row">Fundamental types</caption>
			 * <tr><th>Type</th><th>Done</th></tr>
			 * <tr><td>bool</td><td>x</td></tr>
			 * <tr><td>char</td><td>x</td></tr>
			 * <tr><td>double</td><td>x</td></tr>
			 * <tr><td>float</td><td>x</td></tr>
			 * <tr><td>int</td><td>x</td></tr>
			 * <tr><td>long</td><td>x</td></tr>
			 * <tr><td>short</td><td>x</td></tr>
			 * <tr><td>std::string</td><td>x</td></tr>
			 * <tr><td>unsigned char</td><td>x</td></tr>
			 * <tr><td>unsigned int</td><td>x</td></tr>
			 * <tr><td>unsigned long</td><td>x</td></tr>
			 * <tr><td>unsigned short</td><td>x</td></tr>
			 * </table>
			 */
			class Convert
			{
			public:
				/**
				 * Used as constant for bool
				 */
				static const std::string StringTrue;

				/**
				 * Used as constant for bool
				 */
				static const std::string StringFalse;

				/**
				 * Convert bool to std::string
				 * \param Value Value to convert from
				 * \param ValueString Value to convert to
				 */
				static void ConvertTo(const bool &Value, std::string &ValueString);

				/**
				 * Convert std::string to bool
				 * \param ValueString Value to convert from
				 * \param Value Value to convert to
				 */
				static void ConvertTo(const std::string &ValueString, bool &Value);

				/**
				 * Convert char to std::string
				 * \param Value Value to convert from
				 * \param ValueString Value to convert to
				 */
				static void ConvertTo(const char &Value, std::string &ValueString);

				/**
				 * Convert std::string to char
				 * \param ValueString Value to convert from
				 * \param Value Value to convert to
				 */
				static void ConvertTo(const std::string &ValueString, char &Value);

				/**
				 * Convert double to std::string
				 * \param Value Value to convert from
				 * \param ValueString Value to convert to
				 */
				static void ConvertTo(const double &Value, std::string &ValueString);

				/**
				 * Convert std::string to double
				 * \param ValueString Value to convert from
				 * \param Value Value to convert to
				 */
				static void ConvertTo(const std::string &ValueString, double &Value);

				/**
				 * Convert float to std::string
				 * \param Value Value to convert from
				 * \param ValueString Value to convert to
				 */
				static void ConvertTo(const float &Value, std::string &ValueString);

				/**
				 * Convert std::string to float
				 * \param ValueString Value to convert from
				 * \param Value Value to convert to
				 */
				static void ConvertTo(const std::string &ValueString, float &Value);

				/**
				 * Convert int to std::string
				 * \param Value Value to convert from
				 * \param ValueString Value to convert to
				 */
				static void ConvertTo(const int &Value, std::string &ValueString);

				/**
				 * Convert std::string to int
				 * \param ValueString Value to convert from
				 * \param Value Value to convert to
				 */
				static void ConvertTo(const std::string &ValueString, int &Value);

				/**
				 * Convert long to std::string
				 * \param Value Value to convert from
				 * \param ValueString Value to convert to
				 */
				static void ConvertTo(const long &Value, std::string &ValueString);

				/**
				 * Convert std::string to long
				 * \param ValueString Value to convert from
				 * \param Value Value to convert to
				 */
				static void ConvertTo(const std::string &ValueString, long &Value);

				/**
				 * Convert short to std::string
				 * \param Value Value to convert from
				 * \param ValueString Value to convert to
				 */
				static void ConvertTo(const short &Value, std::string &ValueString);

				/**
				 * Convert std::string to short
				 * \param ValueString Value to convert from
				 * \param Value Value to convert to
				 */
				static void ConvertTo(const std::string &ValueString, short &Value);

				/**
				 * Convert unsigned char to std::string
				 * \param Value Value to convert from
				 * \param ValueString Value to convert to
				 */
				static void ConvertTo(const unsigned char &Value, std::string &ValueString);

				/**
				 * Convert std::string to unsigned char
				 * \param ValueString Value to convert from
				 * \param Value Value to convert to
				 */
				static void ConvertTo(const std::string &ValueString, unsigned char &Value);

				/**
				 * Convert unsigned int to std::string
				 * \param Value Value to convert from
				 * \param ValueString Value to convert to
				 */
				static void ConvertTo(const unsigned int &Value, std::string &ValueString);

				/**
				 * Convert std::string to unsigned int
				 * \param ValueString Value to convert from
				 * \param Value Value to convert to
				 */
				static void ConvertTo(const std::string &ValueString, unsigned int &Value);

				/**
				 * Convert unsigned long to std::string
				 * \param Value Value to convert from
				 * \param ValueString Value to convert to
				 */
				static void ConvertTo(const unsigned long &Value, std::string &ValueString);

				/**
				 * Convert std::string to unsigned long
				 * \param ValueString Value to convert from
				 * \param Value Value to convert to
				 */
				static void ConvertTo(const std::string &ValueString, unsigned long &Value);

				/**
				 * Convert unsigned int to std::string
				 * \param Value Value to convert from
				 * \param ValueString Value to convert to
				 */
				static void ConvertTo(const unsigned short &Value, std::string &ValueString);

				/**
				 * Convert std::string to unsigned short
				 * \param ValueString Value to convert from
				 * \param Value Value to convert to
				 */
				static void ConvertTo(const std::string &ValueString, unsigned short &Value);
			};
		}
	}
}

#endif
