/**
 * The header file for the STL stack-derived class
 * to store strings. It contains the class declaration
 *
 * Created on: Nov 18 2014 13:06:22
 * Author: Icebreaker
 */
#pragma once

#include "Stringfstream.h"
#include "StringStack.h"

/**
* Line class, in order to read a stream line by line.
* It simply is based on the overloaded operator >>.
**/
class line
{
	string _data;
public:
	friend istream& operator>>(istream& _is, line& _l) {
		getline(_is, _l._data);
		return _is;
	}
	operator string() const
	{
		return _data;
	}
};


class NumberCopy :
	public Stringfstream, public StringStack
{
public:
	void Load(string&);
	NumberCopy();
	~NumberCopy();
};

