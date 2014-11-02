/*
 * This is the header file for the COUNTABLE interface
 * It contains the interface declaration within a template.
 *
 * Created on: Nov 2 2014 13:05:11
 * Author: Icebreaker
 */

#pragma once
template <class T>
class Countable
{
public:
	Countable()
	{
		++Objects_Created;
		++Objects_Alive;
		Object_Number = Objects_Created;
	}
	virtual int GetCurrentNumber() = 0;
	virtual int Get_Objects_Created() = 0;
	virtual int Get_Objects_Alive() = 0;
protected:
	static int Objects_Created;
	static int Objects_Alive;
	int Object_Number;
	~Countable()
	{
		--Objects_Alive;
	}
};

template <class T> int Countable<T>::Objects_Alive = 0;
template <class T> int Countable<T>::Objects_Created = 0;