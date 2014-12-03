/**
 * The .cpp file for the STL stack-derived class
 * to store strings. It contains method implementations
 *
 * Created on: Nov 18 2014 13:07:58
 * Author: Icebreaker
 **/

#include "NumberCopy.h"


NumberCopy::NumberCopy()
{
}


NumberCopy::~NumberCopy()
{
}

void NumberCopy::Load(string& _filename)
{
	this->open(_filename.c_str(), ios::in);

	stringstream _SS;
	string _tmp;
	int _count = 1;

	//istream_iterator<string> _cur(*this);
	//istream_iterator<string> _eos;

	cout << "Opened NumberCopy" << endl;

	while (!this->eof())
	{
		*this >> _tmp;
		
		_SS << _count
			<< ": "
			<< _tmp
			<< endl;
		this->push(_SS.str());
		//_cur++;
		_SS.clear();
		_count++;
	}

	this->close();
}
