/*
 * ObjectKeeper.h
 *
 *  Created on: 9 May 2018
 *      Author: Viacheslav isaev
 */

#ifndef OBJECTKEEPER_H_
#define OBJECTKEEPER_H_

#include <map>
#include <string>

#include <boost/function.hpp>

/**
 * A class which holds Objects.
 * Object Id could be obtained through getPVId function.
 *
 * ObjectKeeper can be customized by the function which extract or compose names of the Objects.
 * That makes ObjectKeeper universal and allows use it for other applications.
 *
 */
template<class T>
class ObjectKeeper
{
public:

	typedef std::shared_ptr<T> TPtr;
	typedef std::shared_ptr<const T> TConstPtr;

	using PVMap =  std::map<std::string, TPtr>;
	using PVItr = typename PVMap::iterator;
	using GetKeyFunction = boost::function<const std::string& (const TConstPtr&)> ;

	/**
	 * Default constructor.
	 */
	ObjectKeeper();

	/**
	 * Parameterized Constructor.
	 * @param  nameExtractor - function to extract object name from the function call.
	 */
	ObjectKeeper(GetKeyFunction);
	virtual ~ObjectKeeper();

	ObjectKeeper(const ObjectKeeper&) = delete;
	ObjectKeeper& operator = (const ObjectKeeper&) = delete;

	/**
	 * Sets initial value for the counter
	 * @param startCounter - initial value for the counter
	 */
	void setStartCounter(int startCounter);

	/**
	 * Creates an Info object and registers it in database.
         *   ! Based on name !
	 * @param name - name of the
	 * @return
	 */
	TPtr& registerPV (const std::string& reason);

        /**
	 * Creates a Info object and registers it in database.
         *   ! Based on pv_name !
	 * @param name - name of the
	 * @return
	 */
	TPtr& registerPV (const std::string& reason, const std::string& pv_name);

	/**
	 * Finds a PV and returns asyn interrupt Id of the PV.
	 * Asyn interrupt Id is used for asynchronous PV notifications.
	 * @param name - Name of the PV in the databse.
	 * @return Returns asyn interrupt Id.
	 */
	int getPVId(const std::string& name);

	PVMap& getList(){ return pvlist; };

protected:
	PVMap pvlist;
	unsigned int pvcounter;
	GetKeyFunction getKey;

};

template<typename T>
ObjectKeeper<T>::ObjectKeeper()
	:pvcounter(0),
	 //getKey([](PVInfo* i) -> std::string { return i->Args[0]; })
	 getKey([](const TConstPtr& i) -> std::string { return i->getFullReason(); })
{

}

template<typename T>
ObjectKeeper<T>::ObjectKeeper(GetKeyFunction f)
:pvcounter(0),
 getKey(f)
{
}

template<typename T>
ObjectKeeper<T>::~ObjectKeeper()
{
	pvlist.clear();
}

template<typename T>
void ObjectKeeper<T>::setStartCounter(int startCounter)
{
	pvcounter = startCounter;
}

template<typename T>
std::shared_ptr<T>& ObjectKeeper<T>::register (const std::string& reason)
{
	TPtr info(new T(reason));

	auto key = getKey( std::const_pointer_cast<const T>(info));

	auto itr = pvlist.find(key);

	if ( itr != pvlist.end() )
	{
		return itr->second;
	}else
	{
		++pvcounter;

		info->setId( pvcounter );

		pvlist.insert(std::make_pair(key, info ));
		return pvlist[key];
	}
}

template<typename T>
std::shared_ptr<T>& ObjectKeeper<T>::register (const std::string& reason, const std::string& pv_name)
{
	TPtr info(new T(reason, pv_name));

	auto key = getKey( std::const_pointer_cast<const T>(info));

	auto itr = pvlist.find(key);

	if ( itr != pvlist.end() )
	{
		return itr->second;
	}else
	{
		++pvcounter;

		info->setId( pvcounter );

		pvlist.insert(std::make_pair(key, info ));
		return pvlist[key];
	}
}

template<typename T>
int ObjectKeeper<T>::getId(const std::string& name)
{
	PVItr itr = pvlist.find(name);

	if ( itr != pvlist.end() )
	{
		return itr->second->getId();
	}

	throw new std::out_of_range("Requested name is not found.");
}
#endif /* OBJECTKEEPER_H_ */
