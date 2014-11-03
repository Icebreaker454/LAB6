/**
 * This is the header file for the SERIALIZABLE interface
 * It contains the interface declaration.
 *
 * Created on: Nov 2 2014 13:12:27
 * Author: Icebreaker
 **/

#pragma once
#include "Header.h"

/**
 * The Serializable interface prototype
 **/
class Serializable
{

public:
	virtual string Serialize() = 0;
	virtual void DeSerialize(char*) = 0;
};


