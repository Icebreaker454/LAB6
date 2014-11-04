/**
 * The main source file for my LAB6, which contains the main function 
 * and the necessary recources for the project.
 *
 * Created on: Nov 2 2014 13:02:21
 * Author: Icebreaker
 **/

#include "CST.h"


/**
 * Polymorph function which sorts an array of Countable Objects by 
 * the Object_Number variables. The function uses the QSort algorithm.
 **/
template<class T>
void Countable_sort_by_objNum(vector<Countable<T>*>& array, int _beg, int _end)
{

	int _tmpbeg = _beg, _tmpend = _end, _tmpmid = array[(_beg + _end) / 2]->GetCurrentNumber();

	do
	{
		while (array[_tmpbeg]->GetCurrentNumber() < _tmpmid) _tmpbeg++;
		while (array[_tmpend]->GetCurrentNumber() > _tmpmid) _tmpend--;

		if (_tmpbeg <= _tmpend)
		{
			if (array[_tmpbeg]->GetCurrentNumber() > array[_tmpend]->GetCurrentNumber())
			{
				Countable<T> *temp = static_cast<Countable<T>*>(array[_tmpbeg]);
				array[_tmpbeg] = array[_tmpend];
				array[_tmpend] = temp;
			}
			_tmpbeg++;
			_tmpend--;
		}
	} while (_tmpbeg <= _tmpend);

	if (_tmpbeg < _end) Countable_sort_by_objNum(array, _tmpbeg, _end);
	if (_beg < _tmpend) Countable_sort_by_objNum(array, _beg, _tmpend);
}


/**
 * The polymorph Serializable operator which outputs a Serializable
 * object as a string to the OutputStream.
 **/
ostream& operator <<(ostream& _out, Serializable* _szbl_obj)
{
	_out << _szbl_obj->Serialize();
	return _out;
}

/**
 * Main function
 **/
int main()
{
	/**
	 * Getting current time.
	 **/
	tm* CurrentTime = new tm;
	time_t timer = time(NULL);
	localtime_s(CurrentTime, &timer);

	/**
	 * Making a Route.
	 **/
	Route Rt = {
		"LVIV-KYIV",	/* NAME */
		*CurrentTime,	/* TIME */
		300				/*PRICE*/
	};

	/**
	 * Testing the Countable interface.
	 **/
	cout << "Countable interface testing."
		<< endl;

	CST ticket1(1488, 1, *CurrentTime, Rt, "Paul"); /* Creating a new CST */

	cout << "Object_Number: "						/* Outputing the Object_Number */
		<< ticket1.GetCurrentNumber()
		<< endl;

	cout << "Objects_Created: "						/* Outputing the Countable interface info */
		<< ticket1.Get_Objects_Created()
		<< endl
		<< "Objects_Alive: "
		<< ticket1.Get_Objects_Alive()
		<< endl;


	CST ticket2;									/* Creating a new CST */

	cout << "Object_Number: "						/* Outputing the Object_Number */
		<< ticket2.GetCurrentNumber()
		<< endl;

	cout << "Objects_Created: "						/* Outputing the Countable interface info */
		<< ticket1.Get_Objects_Created()
		<< endl
		<< "Objects_Alive: "
		<< ticket1.Get_Objects_Alive()
		<< endl;

	CST *ticket3 = new CST();						/* Creating a new CST pointer */

	cout << "Object_Number: "						/* Outputing the Object_Number */
		<< ticket3->GetCurrentNumber()
		<< endl;

	cout << "Objects_Created: "						/* Outputing the Countable interface info */
		<< ticket1.Get_Objects_Created()
		<< endl
		<< "Objects_Alive: "
		<< ticket1.Get_Objects_Alive()
		<< endl;

	delete ticket3;									/* Removing the new CST pointer */

	cout << "Ticket 3 has beem removed!"			/* Outputing the delete message */
		<< endl;

	cout << "Objects_Created: "						/* Outputing the Countable interface info */
		<< ticket1.Get_Objects_Created()
		<< endl
		<< "Objects_Alive: "
		<< ticket1.Get_Objects_Alive()
		<< endl;


	/**
	 * Testing the Serializable interface
	 **/
	cout << "Serializable interface testing."
		<< endl;

	string s = ticket1.Serialize();					/* Serializing the object */

	cout << s										/* Outputing the result */
		<< endl;

	char* src = new char[s.length() + 1];			/* Copying the Serialize() result to a char array*/
	strcpy(src, s.c_str());

	ticket2.DeSerialize(src);						/* DeSerializing the CST */

	cout << ticket2									/* Outputing the CST */
		<< endl;


	/**
	 * Testing the Sort polymorph function
	 **/

	cout << "Testing the Sort polymorph function" << endl;

	CST  ticket4, ticket5, ticket6;					/* Creating new class instances */
	
	vector<Countable<CST>*> arr;					/* Adding them to our vector. This is actually
													 * a pure example of shitcode, but i simply
													 * don't know how to make template polymorphism
													 * work.
													 */
	arr.push_back(&ticket5);
	arr.push_back(&ticket6);
	arr.push_back(&ticket1);
	arr.push_back(&ticket2);
	arr.push_back(&ticket4);

	cout << "Unsorted:"
		<< endl;

	for (int i = 0; i < 5; i++)						/* Outputing the unsorted element numbers */
		cout << arr[i]->GetCurrentNumber()
			<< endl;

	Countable_sort_by_objNum(arr, 0, 4);			/* Sorting out array */

	cout << "Sorted:"
		<< endl;

	for (int i = 0; i < 5; i++)						/* Outputing the sorted element numbers */
		cout << arr[i]->GetCurrentNumber()
		<< endl;

	/**
	 * Testing the Serializable polymorph operator
	 **/

	cout << "Testing the Serializable polymorph function" << endl;

	cout << &ticket1 << endl;

	/**
	 * Post - execution issues.
	 **/
	_getch();
	return 0;
}