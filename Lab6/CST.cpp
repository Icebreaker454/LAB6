/**
* This is the .cpp file for the CST class
* It contains function declarations for
* the class.
*
* Created on: Nov 2 2014 13:27:48
* Author: Icebreaker
**/

#include "CST.h"

/**
 * The CST default constructor
 **/
CST::CST()
{
	cout << "A class instance of CST has been created." << endl;
}

/**
 * The CST parametral constructor
 **/
CST::CST(	unsigned PaydeskID, 
			unsigned TicketID,
			tm SellTime, 
			Route Rt, 
			string Passenger) :
/* - - - - - Initializators  - - - - - */
	PaydeskID(PaydeskID),
	TicketID(TicketID),
	SellTime(SellTime),
	Rt(Rt),
	Passenger(Passenger)
/* - - - - - - - - - - - - - - - - - - */
{
	cout << "A class instance of CST has been created." << endl;
}


/**
 * Copy constructor
 **/
CST::CST(const CST& _copyobj)
{
	this->PaydeskID = _copyobj.PaydeskID;
	this->TicketID = _copyobj.TicketID;
	this->Rt = _copyobj.Rt;
	this->SellTime = _copyobj.SellTime;
	this->Passenger = _copyobj.Passenger;
}


/**
 * A serializable interface method which converts an object to string
 **/
string CST::Serialize()
{
	stringstream Serialized;
	Serialized << this->PaydeskID
		<< "/*/"
		<< this->TicketID
		<< "/*/"
		<< mktime(&this->SellTime)
		<< "/*/"
		<< this->Rt.RtName
		<< "/*/"
		<< mktime(&(this->Rt.RtTime))
		<< "/*/"
		<< this->Rt.RtPrice
		<< "/*/"
		<< this->Passenger
		<< "/*/";
	string Serial;
	Serialized >> Serial;
	return Serial;
}


/**
 * A serializable interface method which converts a string
 * to CST object
 **/
void CST::DeSerialize(char* src)
{
	/**
	 * WARNING: SHIT CODE OCCURENCIES!
	 **/

	/**
	 * The delimiter string, defined by myself 
	 **/
	char* delim = "/*/";						

	char* entry = src;								/* Reading the PaydeskID field */
	char* temp = strstr(src, delim)+3;
	*(temp - 3) = 0;
	this->PaydeskID = atoi(src);

	entry = temp;									/* Reading the TicketID field */
	src = temp;
	temp = strstr(src, delim) + 3;
	*(temp - 3) = 0;
	this->TicketID = atoi(src);

	entry = temp;									/* Reading the SellTime field */
	src = entry;
	temp = strstr(src, delim) + 3;
	*(temp - 3) = 0;
	time_t timer = atoi(src);
	localtime_s(&(this->SellTime), &timer);

	entry = temp;									/* Reading the Rt.RtName field */
	src = temp;
	temp = strstr(src, delim) + 3;
	*(temp - 3) = 0;
	this->Rt.RtName = (src);

	entry = temp;									/* Reading the Rt.RtTime field */
	src = entry;
	temp = strstr(src, delim) + 3;
	*(temp - 3) = 0;
	timer = atoi(src);
	localtime_s(&(this->Rt.RtTime), &timer);

	entry = temp;									/* Reading the Rt.RtPrice field */
	src = temp;
	temp = strstr(src, delim) + 3;
	*(temp - 3) = 0;
	this->Rt.RtPrice = atoi(src);

	entry = temp;									/* Reading the Passenger field */
	src = entry;
	temp = strstr(src, delim);
	*temp = 0;
	this->Passenger = src;
}

/**
 * This function gets the Object_Number variable 
 * from the Countable interface
 **/
int CST::GetCurrentNumber()
{
	return this->Object_Number;
}

/**
 * This function gets the Objects_Created variable
 * from the Countable interface
 **/
int CST::Get_Objects_Created()
{
	return this->Objects_Created;
}


/**
 * This function gets the Objects_Alive variable
 * from the Countable interface
 **/
int CST::Get_Objects_Alive()
{
	return this->Objects_Alive;
}


/**
 * This operator outputs a CST object to the screen
 **/
ostream& operator <<(	ostream& cout, 
						const CST& a)
{
	if (&a)
	{
		char* tmptm = new char[100];
		asctime_s(tmptm, 100, &a.SellTime);

		cout << "############################################################" << endl
			 << "Ticket Info" << endl
			 << "------------------------------------------------------------" << endl
			 << "Paydesk ID: ";

		cout.fill('0');
		cout.width(8);

		cout << a.PaydeskID << endl
			 << "Ticket ID: ";

		cout.fill('0');
		cout.width(8);

		cout << a.TicketID << endl
			 << "SellTime: " 
			 << tmptm << endl
		     << a.Rt
		     << "Passenger: " 
			 << a.Passenger << endl
			 << "############################################################" << endl;
		return cout;
	}
	else
	{
		cout << "############################################################" << endl
			 << "There is no such a ticket" << endl
			 << "############################################################" << endl;
		return cout;
	}
}

/**
 * This operator inputs  a CST object from a file
 **/
ifstream& operator >>(	ifstream& IN, 
						CST& a)
{
	time_t Timer;
	IN  >> a.PaydeskID
		>> a.TicketID
		>> Timer;
	localtime_s(&a.SellTime, &Timer);

	IN  >> a.Rt.RtName
		>> Timer;
	localtime_s(&a.Rt.RtTime, &Timer);

	IN	>> a.Rt.RtPrice
		>> a.Passenger;
	
	
	return IN;
}


/**
 * This operator outputs a CST object to a file
 **/
ofstream& operator <<(	ofstream& Out, 
						 CST& a)
{

	Out << a.PaydeskID << endl
		<< a.TicketID << endl
		<< mktime(&a.SellTime) << endl
		<< a.Rt.RtName << endl
		<< mktime(&a.Rt.RtTime) << endl
		<< a.Rt.RtPrice << endl
		<< a.Passenger << endl;
	return Out;
}


/**
 * This operator outputs a Route structure to the
 * screen
 **/
ostream& operator <<(	ostream& os, 
						const Route& a)
{

	os << "------------------------------------------------------------" << endl
		<< "Name: " << a.RtName << endl
		<< "Time: " << asctime(&a.RtTime)
		<< "Price: " << a.RtPrice << endl
		<< "------------------------------------------------------------" << endl;
	return os;
}

