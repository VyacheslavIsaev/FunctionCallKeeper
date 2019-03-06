/*
 * test_string_utils.cpp
 *
 *  Created on: 5 Mar 2019
 *      Author: Viacheslav Isaev
 */

#include "catch.hpp"

#include "string_utils.h"

SCENARIO( "Triming from the Right", "[StringUtils]" )
{
    GIVEN( "String with a space at the end." )
    {
    	std::string strTestSample("test");
    	std::string strTest= strTestSample + " ";

		WHEN( "trimRight applied" )
		{
			trimRight(strTest);
			THEN("Space is removed from the tail of the string.")
			{
				REQUIRE(strTestSample == strTest);
			}
		}
    }

    GIVEN( "String with a new line at the end." )
    {
    	std::string strTestSample("test");
    	std::string strTest= strTestSample + "\n";

		WHEN( "trimRight applied" )
		{
			trimRight(strTest);
			THEN("New line is removed from the tail of the string.")
			{
				REQUIRE(strTestSample == strTest);
			}
		}
    }

    GIVEN( "String with a tab at the end." )
    {
    	std::string strTestSample("test");
    	std::string strTest= strTestSample + "\t";

		WHEN( "trimRight applied" )
		{
			trimRight(strTest);
			THEN("TAB is removed from the tail of the string.")
			{
				REQUIRE(strTestSample == strTest);
			}
		}
    }

    GIVEN( "String with a return at the end." )
    {
    	std::string strTestSample("test");
    	std::string strTest= strTestSample + "\r";

		WHEN( "trimRight applied" )
		{
			trimRight(strTest);
			THEN("Return is removed from the tail of the string.")
			{
				REQUIRE(strTestSample == strTest);
			}
		}
    }

    GIVEN( "String with a some spaces at the end." )
    {
    	std::string strTestSample("test");
    	std::string strTest= strTestSample + " \n\r";

		WHEN( "trimRight applied" )
		{
			trimRight(strTest);
			THEN("Spaces are removed from the tail of the string.")
			{
				REQUIRE(strTestSample == strTest);
			}
		}
    }
}

SCENARIO( "Triming from the Right a string with spaces", "[StringUtils]" )
{
    GIVEN( "String with a some spaces at the end." )
    {
    	std::string strTestSample("t e s t");
    	std::string strTest= strTestSample + " \n\r";

		WHEN( "trimRight applied" )
		{
			trimRight(strTest);
			THEN("Spaces are removed.")
			{
				REQUIRE(strTestSample == strTest);
			}
		}
    }
}

SCENARIO( "Triming from the Left", "[StringUtils]" )
{
    GIVEN( "String with a space at the begging." )
    {
    	std::string strTestSample("test");
    	std::string strTest= " "+strTestSample;

		WHEN( "trimLeft applied" )
		{
			trimLeft(strTest);
			THEN("Space is removed.")
			{
				REQUIRE(strTestSample == strTest);
			}
		}
    }

    GIVEN( "String with a new line at the begging." )
    {
    	std::string strTestSample("test");
    	std::string strTest= "\n" + strTestSample;

		WHEN( "trimRight applied" )
		{
			trimLeft(strTest);
			THEN("New line is removed.")
			{
				REQUIRE(strTestSample == strTest);
			}
		}
    }

    GIVEN( "String with a tab at the begging." )
    {
    	std::string strTestSample("test");
    	std::string strTest= "\t" + strTestSample;

		WHEN( "trimRight applied" )
		{
			trimLeft(strTest);
			THEN("Tab is removed.")
			{
				REQUIRE(strTestSample == strTest);
			}
		}
    }

    GIVEN( "String with a return at the begging." )
    {
    	std::string strTestSample("test");
    	std::string strTest= "\r" + strTestSample;

		WHEN( "trimRight applied" )
		{
			trimLeft(strTest);
			THEN("Return is removed.")
			{
				REQUIRE(strTestSample == strTest);
			}
		}
    }

    GIVEN( "String with a some spaces at the begging." )
    {
    	std::string strTestSample("test");
    	std::string strTest= "\r\n "+strTestSample;

		WHEN( "trimRight applied" )
		{
			trimLeft(strTest);
			THEN("Spaces are removed.")
			{
				REQUIRE(strTestSample == strTest);
			}
		}
    }
}

SCENARIO( "Triming from the Left a string with spaces", "[StringUtils]" )
{
    GIVEN( "String with preface spaces and in between." )
    {
    	std::string strTestSample("t e s t");
    	std::string strTest= " \n\r " + strTestSample;

		WHEN( "trimRight applied" )
		{
			trimLeft(strTest);
			THEN("Spaces are removed.")
			{
				REQUIRE(strTestSample == strTest);
			}
		}
    }
}

SCENARIO( "Triming from the both ends a string with spaces", "[StringUtils]" )
{
    GIVEN( "String with preface spaces, tailing  spaces and spaces in between." )
    {
    	std::string strTestSample("t e s t");
    	std::string strTest= " \n\r " + strTestSample + "  \n\r\n\r";

		WHEN( "trim applied" )
		{
			std::string res = trim(strTest);
			THEN("Spaces are removed.")
			{
				REQUIRE(strTestSample == res);
			}
		}
    }
}
