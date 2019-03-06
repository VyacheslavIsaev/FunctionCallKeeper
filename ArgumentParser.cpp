/*
 * ArgumentParser.cpp
 *
 *  Created on: 6 Mar 2019
 *      Author: Viacheslav Isaev
 */

#include "ArgumentParser.h"
#include "string_utils.h"

ArgumentParser::~ArgumentParser()
{
}

ArgumentParser::ArgumentParser(const std::string& d)
	:delim(d)
{
}

void ArgumentParser::parse(const std::string& arguments,
			std::vector<std::string>& args)
{
	size_t idxStart=0;
	size_t length = arguments.length();
	size_t found  = arguments.find_first_of(delim);

	while ( found != std::string::npos )
	{
		size_t idxEnd = found+1;
		length = found - idxStart;

		args.push_back( trim(arguments.substr(idxStart, length)) );

		found  = arguments.find_first_of(delim, idxEnd);
		idxStart = idxEnd;
	}

	if (arguments.length() - idxStart > 0)
	{
		length = arguments.length() - idxStart;
		args.push_back( trim(arguments.substr(idxStart, length)) );
	}
}
