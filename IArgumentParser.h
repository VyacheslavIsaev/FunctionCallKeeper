/*
 * IArgumentParser.h
 *
 *  Created on: 6 Mar 2019
 *      Author: Viacheslav Isaev
 */

#ifndef IARGUMENTPARSER_H_
#define IARGUMENTPARSER_H_

#include <string>
#include <vector>
#include <memory>

class IArgumentParser;
using IArgumentParserPtr = std::shared_ptr<IArgumentParser>;

class IArgumentParser
{
public:
	virtual ~IArgumentParser(){}

	virtual void parse(const std::string&, std::vector<std::string>&) = 0;
};

#endif /* IARGUMENTPARSER_H_ */
