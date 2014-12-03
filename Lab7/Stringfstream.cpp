#include "Stringfstream.h"


Stringfstream::Stringfstream()
{
}


Stringfstream::~Stringfstream()
{
}

Stringfstream& operator>>(Stringfstream& _in, string& _s)
{
	getline(_in, _s);
	return _in;
}