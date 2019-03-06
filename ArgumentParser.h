/*
 * ArgumentParser.h
 *
 *  Created on: 6 Mar 2019
 *      Author: Viacheslav Isaev
 */

#ifndef ARGUMENTPARSER_H_
#define ARGUMENTPARSER_H_

#include "IArgumentParser.h"

/**
 * @brief Parsing argument's string
 */
class ArgumentParser: public IArgumentParser
{
public:
	ArgumentParser(const std::string& d=",");
	virtual ~ArgumentParser();

	void parse(const std::string&, std::vector<std::string>&);
protected:
	std::string delim;
};

#endif /* ARGUMENTPARSER_H_ */
