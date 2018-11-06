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
 * \file	YAIP.h
 * \author	ThirtySomething
 * \date	2016-09-19
 * \brief	Header of Yet Another INI Parser
 */
#pragma once

#include "Convert.h"
#include "IniSection.h"
#include <ctype.h>
#include <functional>
#include <map>
#include <memory>
#include <regex>
#include <vector>

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
			 * This struct will be passed to each map and will ensure an alphabetical order of all keys
			 */
			struct StringCompareCaseLess : std::binary_function<std::string, std::string, bool>
			{
				/**
				 * Comparison of two strings represented by unsigned chars
				 */
				struct CompareCaseless : public std::binary_function<unsigned char, unsigned char, bool>
				{
					/**
					 * Operator for usage in string compare
					 * \param CharLeft Left character to check
					 * \param CharRight Right character to check
					 * \return true in case the left character is less than the right character
					 */
					bool operator() (const unsigned char& CharLeft, const unsigned char& CharRight) const
					{
						return (tolower(CharLeft) < tolower(CharRight));
					}
				};

				/**
				 * Operator for usage in string compare
				 * \param StringLeft Left string to check
				 * \param StringRight Right string to check
				 * \return true in case the left string is less than the right string
				 */
				bool operator() (const std::string & StringLeft, const std::string & StringRight) const
				{
					return std::lexicographical_compare(StringLeft.begin(), StringLeft.end(), StringRight.begin(), StringRight.end(), CompareCaseless());
				}
			};

			/**
			 * Convenience typedef for a map of strings.
			 * Used to represent keys and their corresponding values.
			 * Map will be sorted caseless.
			 */
			typedef std::map<std::string, std::string, StringCompareCaseLess> tMapStringString;

			/**
			 * Convenience typedef for a map of keys/values.
			 * Used to represent a section with their corrresponding keys/values storage.
			 * Map will be sorted caseless.
			 */
			typedef std::map<std::string, tMapStringString, StringCompareCaseLess> tMapStringMapStringString;

			/**
			 * Convenience typedef for a vector of strings.
			 * Used to represent the content of a INI file, a list of sections or a list of keys.
			 */
			typedef std::vector<std::string> tVectorString;

			typedef std::vector<IniSectionPtr> tSectionList;

			/**
			 * Class to manipulate INI files
			 */
			class YAIP
			{
			public:
				/**
				 * Default constructor
				 * \param commentSeperator Seperator character for comments, by default it's a semicolon
				 */
				YAIP(const char &commentSeperator = ';');

				/**
				 * Default destructor
				 */
				virtual ~YAIP(void);

				/**
				 * Delete given INI file
				 * \param Filename Full qualified filename of the INI file
				 * \return true if file is deleted otherwise false
				 */
				bool INIFileDelete(const std::string &Filename) const;

				/**
				 * Check if given INI file exists
				 * \param Filename Full qualified filename of the INI file
				 * \return true if file exists otherwise false
				 */
				bool INIFileExist(const std::string &Filename) const;

				/**
				 * Load and parse INI file into internal structures
				 * \param Filename Full qualified filename of the INI file
				 * \return true on success otherwise false
				 */
				bool INIFileLoad(const std::string &Filename);

				/**
				 * Save internal structures to INI file
				 * \param Filename Full qualified filename of the INI file
				 * \return true on success otherwise false
				 */
				bool INIFileSave(const std::string &Filename);

				/**
				 * Remove key completely from section of internal data structure
				 * \param Section Specified section
				 * \param Key Specified key
				 */
				void SectionKeyKill(const std::string &Section, const std::string &Key);

				/**
				 * Get all keys of a section of the INI file
				 * \param Section Specified section
				 * \return Vector with a std::strings for each key
				 */
				tVectorString SectionKeyListGet(const std::string &Section) const;

				/**
				 * Method to retrieve a value of the specified section/key combination for std::string
				 * \param Section Specified section
				 * \param Key Specified key
				 * \param Default Specified default value in case key does not exist
				 * \return Returns either the default value or the value of the existing section/key combination
				 */
				std::string SectionKeyValueGet(const std::string &Section, const std::string &Key, const std::string &Default) const;

				/**
				 * Templated method to retrieve a value of the specified section/key combination
				 * \param Section Specified section
				 * \param Key Specified key
				 * \param Default Specified default value in case key does not exist
				 * \return Returns either the default value or the value of the existing section/key combination
				 */
				template<typename VariableType>
				VariableType SectionKeyValueGet(const std::string &Section, const std::string &Key, const VariableType &Default) const
				{
					VariableType ValueReturn;
					std::string ValueDefault;
					Convert::ConvertTo(Default, ValueDefault);
					std::string ValueRaw = SectionKeyValueGet(Section, Key, ValueDefault);
					Convert::ConvertTo(ValueRaw, ValueReturn);
					return ValueReturn;
				}

				/**
				 * Method to set a value of the specified section/key combination for std:string
				 * \param Section Specified section
				 * \param Key Specified key
				 * \param Value Specified value to set
				 * \return true on success otherwise false
				 */
				bool SectionKeyValueSet(const std::string &Section, const std::string &Key, const std::string &Value);

				/**
				 * Templated method to set a value of the specified section/key combination
				 * \param Section Specified section
				 * \param Key Specified key
				 * \param Value Specified value to set
				 * \return true on success otherwise false
				 */
				template<typename VariableType>
				bool SectionKeyValueSet(const std::string &Section, const std::string &Key, const VariableType &Value)
				{
					std::string ValueString;
					Convert::ConvertTo(Value, ValueString);
					return SectionKeyValueSet(Section, Key, ValueString);
				}

				/**
				 * Check if section contains data
				 * \param Section Specified section
				 * \return true for empty section otherwise false
				 */
				bool SectionEmpty(const std::string &Section) const;

				/**
				 * Remove section completely from internal data structure
				 * \param Section Specified section
				 */
				void SectionKill(const std::string &Section);

				/**
				 * Get all sections of the INI file
				 * \return Vector with a std::strings for each section
				 */
				tVectorString SectionListGet(void) const;

				/**
				 * Drop all data to get a clean INI
				 */
				void Clear(void);

			protected:
				/**
				 * Internal map for all sections, each section represented by a map serving the key/value data
				 */
				tMapStringMapStringString m_IniData;

				/**
				 * List of all sections
				 */
				tSectionList m_Sections;

				/**
				 * Character for signaling of start of comments
				 */
				char CommentSeperator;

				/**
				 * Save given section into INI file
				 * \param Section Section to write
				 * \param IniFile INI file to read section to
				 */
				void INIFileSaveSection(std::string Section, std::ofstream &IniFile);

				/**
				 * Loop over file content to determine sections and key/values to populate internal storage
				 * \param FileContent The INI file as a vector of std::strings, each line a string
				 */
				void ParseFileContent(tVectorString FileContent);
			};
		}
	}
}
