//******************************************************************************
// Copyright 2016 ThirtySomething
//******************************************************************************
// This file is part of YAIP++.
//
// YAIP++ is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// YAIP++ is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
// more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with YAIP++. If not, see <http://www.gnu.org/licenses/>.
//******************************************************************************

#pragma once

#include "./../../externals/Catch/single_include/Catch2/catch.hpp"
#include "YAIP++.h"
#include <limits>
#include <vector>

static const std::string S_FILE_INI_STRING = "string.ini";
static const std::string S_SECTION_STRING = "SECTION_STRING";
static const std::string S_KEY_STRING = "KEY_STRING";

std::string testString("ABCDEFGHIJKLMNOPQRSTUVXYZ abcdefghijklmnopqrstuvxyz 0123456789 ., _ +- |");

SCENARIO("Processing of datatype [string]", "[net::derpaul::yaip::YAIP]")
{
	auto VALUE_STRING = testString;

	INFO("Current value [" << VALUE_STRING << "]");

	GIVEN("An empty instance of the YAIP parser")
	{
		net::derpaul::yaip::YAIP sut;
		REQUIRE(true == sut.SectionListGet().empty());
		REQUIRE(true == sut.SectionKeyValueSet(S_SECTION_STRING, S_KEY_STRING, VALUE_STRING));

		WHEN("Add a new section/key/value")
		{
			THEN("Count of section should be 1")
			{
				REQUIRE(false == sut.SectionListGet().empty());
				REQUIRE(1 == sut.SectionListGet().size());
				REQUIRE(1 == sut.SectionKeyListGet(S_SECTION_STRING).size());
			}
		}

		WHEN("Save ini file")
		{
			REQUIRE(true == sut.INIFileSave(S_FILE_INI_STRING));

			THEN("File exists")
			{
				REQUIRE(true == sut.INIFileExist(S_FILE_INI_STRING));
			}
		}

		WHEN("Clear internal data")
		{
			sut.Clear();

			THEN("Section list should be empty")
			{
				REQUIRE(true == sut.SectionListGet().empty());
			}
		}

		WHEN("Reload from ini file")
		{
			REQUIRE(true == sut.INIFileExist(S_FILE_INI_STRING));
			REQUIRE(true == sut.INIFileLoad(S_FILE_INI_STRING));

			THEN("What you save is what you get")
			{
				REQUIRE(1 == sut.SectionListGet().size());
				REQUIRE(1 == sut.SectionKeyListGet(S_SECTION_STRING).size());
				std::string ini_value = sut.SectionKeyValueGet(S_SECTION_STRING, S_KEY_STRING, "-=>DEFAULT<=-");
				REQUIRE(VALUE_STRING == ini_value);
			}
		}

		WHEN("Cleanup and delete ini file")
		{
			REQUIRE(true == sut.INIFileExist(S_FILE_INI_STRING));
			REQUIRE(true == sut.INIFileDelete(S_FILE_INI_STRING));

			THEN("When the ini file is gone")
			{
				REQUIRE(false == sut.INIFileExist(S_FILE_INI_STRING));
			}
		}
	}
}
