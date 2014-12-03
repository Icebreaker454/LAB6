#pragma once
#include "Header.h"

class Stringfstream :
	public fstream
{
public:
	friend Stringfstream& operator >> (Stringfstream&, string&);
	Stringfstream();
	~Stringfstream();
};

