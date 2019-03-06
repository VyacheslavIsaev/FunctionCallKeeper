/*
 * utils.hpp
 *
 *  Created on: 14 May 2018
 *      Author: Viacheslav Isaev
 */

#ifndef UTILS_HPP_
#define UTILS_HPP_

/*
 * Functor to delete values in the map.
 */
template <class T>
void deleteMapObj(T& obj)
{
    if (obj.second)
        delete obj.second;
	obj.second = 0;
}



#endif /* UTILS_HPP_ */
