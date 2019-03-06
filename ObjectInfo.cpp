/*
 * ObjectInfo.cpp
 *
 *  Created on: 9 May 2018
 *      Author: Viacheslav Isaev
 */

#include <string>
#include <stdexcept>

#include "ObjectInfo.h"
#include "string_utils.h"

ObjectInfo::ObjectInfo(IArgumentParserPtr parser, const std::string& val):
		ptrArgParser(parser),
		functionCall(val)
{
	parseFunction( val );
}

ObjectInfo::ObjectInfo(IArgumentParserPtr parser,
		const std::string& val,
		const std::string& name):
		ptrArgParser(parser),
		functionCall(val),
		objectName(name)
{
	parseFunction( val );
}

void ObjectInfo::parseFunction(const std::string& inp)
{
	std::string command = trim(inp);
	size_t idxStart = command.find("(");
	size_t idxEnd   = command.find(")");

	if ( idxStart != std::string::npos
			&& idxEnd != std::string::npos
			&& idxStart < idxEnd
			&& idxStart > 0 )
	{
		functionName = trim(command.substr(0, idxStart));
		if ( idxEnd-idxStart > 1)
		{
			std::string arguments = command.substr(idxStart+1, idxEnd-idxStart-1);
			parseArguments(arguments);
		}
	}else
	{
		functionName = command;
	}
}

void ObjectInfo::parseArguments(const std::string& arguments)
{
	ptrArgParser->parse(arguments, Args);
}

ObjectInfo::~ObjectInfo()
{
	Args.clear();
}

const std::string& ObjectInfo::getStrArg(size_t idx) const
{
	if (idx >= Args.size())
	{
		throw std::out_of_range("Index is out of range.");
	}
	return Args[idx];
}
