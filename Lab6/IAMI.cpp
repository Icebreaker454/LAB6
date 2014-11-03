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
 * the Object_Number variables
 **/
template<class T>
void Countable_sort_by_objNum(Countable<T>* array, int _beg, int _end)
{
	int _tmpbeg = _beg, _tmpend = _end, _tmpmid = array[(_beg + _end) / 2].GetCurrentNumber();

	do
	{
		while (array[_tmpbeg] < _tmpmid)
	}
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
	 * Post - execution issues.
	 **/
	_getch();
	return 0;
}