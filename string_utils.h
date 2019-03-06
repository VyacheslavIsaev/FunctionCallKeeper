/*
 * string_utils.h
 *
 *  Created on: 5 Mar 2019
 *      Author: Viacheslav Isaev
 */

#ifndef STRING_UTILS_H_
#define STRING_UTILS_H_

#include <string>

const std::string whiteSpaces( " \f\n\r\t\v" );

/** Trimming space characters from the end of the string
 *
 */
void trimRight( std::string& str,
      const std::string& trimChars = whiteSpaces);

/** Trimming space characters from the begging of the string
 *
 */
void trimLeft( std::string& str,
      const std::string& trimChars = whiteSpaces);

/** Trimming space characters from the both ends
 *
 */
std::string trim(const std::string& str, const std::string& trimChars = whiteSpaces);

#endif /* STRING_UTILS_H_ */
