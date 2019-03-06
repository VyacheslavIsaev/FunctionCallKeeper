/*
 * string_utils.cpp
 *
 *  Created on: 5 Mar 2019
 *      Author: Viacheslav Isaev
 */


#include "string_utils.h"

void trimRight( std::string& str,
      const std::string& trimChars )
{
   std::string::size_type pos = str.find_last_not_of( trimChars );
   str.erase( pos + 1 );
}

void trimLeft( std::string& str,
      const std::string& trimChars )
{
   std::string::size_type pos = str.find_first_not_of( trimChars );
   str.erase( 0, pos );
}

std::string trim(const std::string& str, const std::string& trimChars)
{
   std::string result(str);
   trimRight( result, trimChars );
   trimLeft( result, trimChars );
   return result;
}
