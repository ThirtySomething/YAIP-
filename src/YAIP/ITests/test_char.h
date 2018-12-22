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

#pragma once

#include "catch2\catch.hpp"
#include "YAIP.h"
#include <limits>

static const std::string S_FILE_INI_CHAR = "char.ini";
static const std::string S_SECTION_CHAR = "SECTION_CHAR";
static const std::string S_KEY_CHAR = "KEY_CHAR";
static const std::string S_KEY_INVALID_CHAR = "KEY_INVALID";
static const char S_VALUE_DEFAULT_CHAR = 'Y';

SCENARIO("Test YAIP with datatype char", "[char]")
{
	auto VALUE_CHAR = GENERATE(std::numeric_limits<char>::min(), std::numeric_limits<char>::max(), std::numeric_limits<char>::infinity());

	INFO("Current value [" << VALUE_CHAR << "]");

	GIVEN("An empty instance of the YAIP parser")
	{
		net::derpaul::yaip::YAIP sut;
		REQUIRE(sut.SectionListGet().empty());
		REQUIRE(sut.SectionKeyValueSet(S_SECTION_CHAR, S_KEY_CHAR, VALUE_CHAR));

		WHEN("Add a new section/key/value")
		{
			THEN("Count of section should be 1")
			{
				REQUIRE(false == sut.SectionListGet().empty());
				REQUIRE(1 == sut.SectionListGet().size());
				REQUIRE(1 == sut.SectionKeyListGet(S_SECTION_CHAR).size());
			}
		}

		WHEN("Save ini file")
		{
			REQUIRE(sut.INIFileSave(S_FILE_INI_CHAR));

			THEN("File exists")
			{
				REQUIRE(sut.INIFileExist(S_FILE_INI_CHAR));
			}
		}

		WHEN("Set value of key to empty")
		{
			REQUIRE(sut.SectionKeyValueClear(S_SECTION_CHAR, S_KEY_CHAR));

			THEN("Read value should return default")
			{
				char ini_value = sut.SectionKeyValueGet(S_SECTION_CHAR, S_KEY_CHAR, S_VALUE_DEFAULT_CHAR);
				REQUIRE(S_VALUE_DEFAULT_CHAR == ini_value);
			}
		}

		WHEN("Clear internal data")
		{
			sut.Clear();

			THEN("Section list should be empty")
			{
				REQUIRE(sut.SectionListGet().empty());
			}
		}

		WHEN("Reload from ini file")
		{
			REQUIRE(sut.INIFileExist(S_FILE_INI_CHAR));
			REQUIRE(sut.INIFileLoad(S_FILE_INI_CHAR));

			THEN("What you save is what you get")
			{
				auto SectionList = sut.SectionListGet();
				auto SectionKeyList = sut.SectionKeyListGet(S_SECTION_CHAR);

				REQUIRE(1 == SectionList.size());
				REQUIRE(1 == SectionKeyList.size());

				char ini_value = sut.SectionKeyValueGet(S_SECTION_CHAR, S_KEY_CHAR, S_VALUE_DEFAULT_CHAR);
				REQUIRE(VALUE_CHAR == ini_value);
			}
		}

		WHEN("Read from invalid key")
		{
			char ini_value = sut.SectionKeyValueGet(S_SECTION_CHAR, S_KEY_INVALID_CHAR, S_VALUE_DEFAULT_CHAR);

			THEN("We get the default value")
			{
				REQUIRE(S_VALUE_DEFAULT_CHAR == ini_value);
			}
		}

		WHEN("Cleanup and delete ini file")
		{
			REQUIRE(sut.INIFileExist(S_FILE_INI_CHAR));
			REQUIRE(sut.INIFileDelete(S_FILE_INI_CHAR));

			THEN("When the ini file is gone")
			{
				REQUIRE(false == sut.INIFileExist(S_FILE_INI_CHAR));
			}
		}
	}
}
