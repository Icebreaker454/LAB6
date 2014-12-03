/**
 * This is the .cpp file for the stack-based
 * string containing class. This file contains 
 * method implementations for the header file.
 *
 * Created on: Nov 16 2014 18:05:13
 * Author: Icebreaker
 **/

#include "StringStack.h"


StringStack::StringStack()
{
}


StringStack::~StringStack()
{
}

/**
 * The function to reverse the stack
 **/
void StringStack::Reverse()
{
	stack<string>* _tmp = new stack<string>;
	
	while (!this->empty())
	{
		_tmp->push(this->top());
		this->pop();
	}

	memcpy(this, _tmp, sizeof(StringStack));
}

/**
 * The function to get the top of the stack and
 * remove the top element simulateosly
 **/
string StringStack::OutputRemoval()
{
	string _ret = this->top();
	this->pop();
	return _ret;
}