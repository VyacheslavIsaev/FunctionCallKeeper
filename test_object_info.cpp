/*
 * test_object_info.cpp
 *
 *  Created on: 6 Mar 2019
 *      Author: Viacheslav Isaev
 */

#include "catch.hpp"

#include "ObjectInfo.h"
#include "ArgumentParser.h"

class TestObjectInfo: public ObjectInfo
{
public:

	using ObjectInfo::ObjectInfo;

	void testParseFunction(const std::string& command)
	{
		parseFunction(command);
	}

	void testParseArguments(const std::string& arguments)
	{
		parseArguments(arguments);
	}
};

SCENARIO( "Creating ObjectInfo", "[ObjectInfo]" )
{
    GIVEN( "Nothing" )
    {
		WHEN( "Creating ObjectInfo" )
		{
			ObjectInfo info(std::make_shared<ArgumentParser>(" "), "name(arg1, arg2, arg3)");
			THEN("ObjectInfo created.")
			{
				REQUIRE(true);
			}
		}
    }
}

SCENARIO( "Creating TestObjectInfo", "[ObjectInfo]" )
{
    GIVEN( "Nothing" )
    {
		WHEN( "Creating ObjectInfo" )
		{
			TestObjectInfo info(std::make_shared<ArgumentParser>(" "), "name(arg1, arg2, arg3)");
			THEN("ObjectInfo created.")
			{
				REQUIRE(true);
			}
		}
    }
}

SCENARIO( "Parsing function call", "[ObjectInfo]" )
{
    GIVEN( "Nothing" )
    {
		WHEN( "Creating ObjectInfo without arguments." )
		{
			std::string funcName("function");

			TestObjectInfo info(std::make_shared<ArgumentParser>(" "), funcName);
			THEN("ObjectInfo created.")
			{
				REQUIRE(info.getFunctionName() == funcName);
				REQUIRE(info.getArgsNum() == 0);
			}
		}
    }

    GIVEN( "Nothing" )
    {
		WHEN( "Creating ObjectInfo with one argument." )
		{
			std::string arg1("arg1");
			TestObjectInfo info(std::make_shared<ArgumentParser>(" "), "name(" + arg1 + ")");
			THEN("ObjectInfo created.")
			{
				REQUIRE(info.getArgsNum() == 1);
				REQUIRE(info.getStrArg(0) == arg1);
			}
		}
    }

    GIVEN( "Nothing" )
    {
		WHEN( "Creating ObjectInfo with 2 arguments." )
		{
			std::string arg1("arg1");
			std::string arg2("arg2");
			TestObjectInfo info(std::make_shared<ArgumentParser>(" "), "name(" + arg1 + " "+ arg2 + ")");
			THEN("ObjectInfo created.")
			{
				REQUIRE(info.getArgsNum() == 2);
				REQUIRE(info.getStrArg(0) == arg1);
				REQUIRE(info.getStrArg(1) == arg2);
			}
		}
    }
}

SCENARIO( "Parsing wierd calls", "[ObjectInfo]" )
{
    GIVEN( "Nothing" )
    {
		WHEN( "Creating ObjectInfo with 2 arguments." )
		{
			std::string arg1("arg1");
			std::string arg2("arg2");
			TestObjectInfo info(std::make_shared<ArgumentParser>(","), "name(" + arg1 + ", "+ arg2 + ")");
			THEN("ObjectInfo created.")
			{
				REQUIRE(info.getArgsNum() == 2);
				REQUIRE(info.getStrArg(0) == arg1);
				REQUIRE(info.getStrArg(1) == arg2);
			}
		}
    }

    GIVEN( "Nothing" )
    {
		WHEN( "Creating ObjectInfo with a lot of spaces arguments." )
		{
			std::string arg1("arg1");
			std::string arg2("arg2");
			std::string funName("funName");
			TestObjectInfo info(std::make_shared<ArgumentParser>(","), funName+"  (  " + arg1 + " , "+ arg2 + "  )   ");
			THEN("ObjectInfo created.")
			{
				REQUIRE(info.getFunctionName() == funName);
				REQUIRE(info.getArgsNum() == 2);
				REQUIRE(info.getStrArg(0) == arg1);
				REQUIRE(info.getStrArg(1) == arg2);
			}
		}
    }

    GIVEN( "Nothing" )
    {
		WHEN( "Creating ObjectInfo with a lot of spaces arguments." )
		{
			std::string funName("funName");
			TestObjectInfo info(std::make_shared<ArgumentParser>(","), funName+"  (  " +  " , "  + "  )   ");
			THEN("ObjectInfo created.")
			{
				REQUIRE(info.getFunctionName() == funName);
				REQUIRE(info.getArgsNum() == 2);
				REQUIRE(info.getStrArg(0) == "");
				REQUIRE(info.getStrArg(1) == "");
			}
		}
    }
}
