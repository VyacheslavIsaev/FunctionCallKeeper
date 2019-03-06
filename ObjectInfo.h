/*
 * ObjectInfo.h
 *
 *  Created on: 9 May 2018
 *      Author: Vicheslav Isaev
 */

#ifndef OBJECT_INFO_H_
#define OBJECT_INFO_H_

#include <vector>
#include <string>
#include <memory>

#include "IArgumentParser.h"

class ObjectInfo;
typedef std::shared_ptr<ObjectInfo> ObjectInfoPtr;
typedef std::shared_ptr<const ObjectInfo> ObjectInfoConstPtr;

/**
 *  @brief Keeps function calls.
 *  @details It is expected that reason is formated as a function call.
 *  ObjectInfo parse the function signature and stores function name and the arguments
 *  separately.
 */
class ObjectInfo
{
public:
	ObjectInfo(IArgumentParserPtr parser, const std::string& reason);
	ObjectInfo(IArgumentParserPtr parser, const std::string& reason, const std::string& pvname);
	virtual ~ObjectInfo();

    /**
	 *
	 * @return Returns object name.
	 */
	const std::string& getName() const { return objectName; }

    /**
	 *
	 * Sets function name.
	 */
	void setFunctionName(const std::string& func) { functionName = func; }

	/**
	 *
	 * @return Returns function name from the reason.
	 */
	const std::string& getFunctionName() const { return functionName; }

	/**
	 *
	 * @return Returns full function call as is.
	 */
	const std::string& getFullReason() const { return functionCall; }

	// asyn interrupt Id for doCallbacks
	int getId() const { return id; }

	void setId(int val) { id=val; }

	int getArgsNum() const { return Args.size(); };

	/**
	 * Returns string representation of requested argument.
	 * @param idx - Index of the argument
	 * @return string representation of the argument value.
	 * @throws In case index out of range.
	 */
	const std::string& getStrArg(size_t idx) const;

protected:
	int id;

    IArgumentParserPtr ptrArgParser;
	std::string functionCall;

	/// Vector of function arguments
	std::vector<std::string> Args;

	std::string functionName;
    std::string objectName;


    void parseFunction(const std::string& command);
    void parseArguments(const std::string& arguments);
};

#endif /* OBJECT_INFO_H_ */
