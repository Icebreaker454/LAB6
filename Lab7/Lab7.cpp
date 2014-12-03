/**
 * The main source file for my Lab7, which contains the main function
 * and the necessary recources for the project.
 *
 * Created on: Nov 13 2014 12:23:21
 * Author: Icebreaker
 **/

#include "NumberCopy.h"



/**
 * Function that loads a file into a list
 **/
list<string>* load(ifstream& _in)
{
	list<string>* _ret = new list<string>;
	char* _buffer = new char[256];

	if (_in.is_open())
	{
		while (!_in.eof())
		{
			_in.getline(_buffer, 256);
			_ret->push_back(_buffer);
		}

		return _ret;
	}

	else return NULL;
}

/**
 * Function of file input using iterators
 **/
list<string>* OrthodoxIterLoad(ifstream& _in)
{
	list<string>* _ret = new list<string>;

	istream_iterator<line> _cur(_in);
	istream_iterator<line> _eos;
	
	while (_cur != _eos)
	{
		_ret->push_back(*_cur);
		_cur++;
		
	}

	return _ret;
}

/**
 * Function of file output using iterators
 **/
void IterOutput(list<string>* _src, ofstream& _out)
{
	ostream_iterator<string> _out_it(_out, "\n");

	copy(_src->begin(), _src->end(), _out_it);
}

/**
 * Main function
 **/
int main()
{
	/**
	 * Initializing our input file stream
	 **/
	ifstream Stream;
	Stream.open("1.txt", ios::in);


	/**
	 * Initializing the list and the iterator
	 **/
	list<string>* Loaded = OrthodoxIterLoad(Stream);

	Stream.close();

	list<string>::iterator _i;

	StringStack Cont1;

	/**
	 * Just a test to show the correct work
	 * of the iterator
	 **/

	cout << "Data from Loaded list, using OrthodoxIterLoad()"
		<< endl;
	for (_i = Loaded->begin(); _i != Loaded->end(); _i++)
	{
		cout << *_i
			<< endl;

		Cont1.push(*_i);

	}

	/**
	 * Reversing and outputing our stack
	 **/
	Cont1.Reverse();

	cout << "stack Cont1 after reversing:"
		<< endl;

	while (!Cont1.empty())
	{
		cout << Cont1.OutputRemoval() << endl;
	}

	/**
	 * Outputing our vector to file using iterators
	 **/
	ofstream OutStream;
	OutStream.open("e:/paul/2.txt", ios::out);

	IterOutput(Loaded, OutStream);

	/**
	 * Testing the ifstrean - derived class;
	 **/
	Stringfstream SFS;

	SFS.open("1.txt", ios::in | ios::out);
	cout << "Testing the Stringfstream in work..."
		<< endl;

	string s;

	SFS >> s;

	cout << s << endl;

	SFS.close();

	/**
	 * Testing the NumberCopy class
	 **/

	cout << "Testing the NumberCopy class..."
		<< endl;

	NumberCopy f1;

	string filename("1.txt");

	f1.Load(filename);

	cout << f1.top();
	/**
	 * Post-execution issues
	 **/
	_getch();
	return EXIT_SUCCESS;
}
