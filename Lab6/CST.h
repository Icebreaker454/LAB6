/**
 * This is the header file for the CST class
 * It contains the class declaration and the service
 * structure declaration.
 * 
 * Created on: Nov 2 2014 13:24:11
 * Author: Icebreaker
 **/

#pragma once
#include "Countable.h"
#include "Serializable.h"

/**
 * Route structure declaration
 **/
struct Route
{
	string RtName;
	tm RtTime;
	double RtPrice;
	friend ostream& operator <<(ostream &os, const Route& a);
};

/**
 * The CST class prtotype
 **/
class CST : public Serializable, public Countable<CST>
{
public:
	unsigned PaydeskID;
	unsigned TicketID;
	tm SellTime;
	Route Rt;
	string Passenger;
	string Serialize();
	void DeSerialize(char*);
	int GetCurrentNumber();
	int Get_Objects_Created();
	int Get_Objects_Alive();
	friend class Paydesk;
	friend ostream& operator <<(ostream&, const CST&);
	friend ifstream& operator >>(ifstream&, CST&);
	friend ofstream& operator <<(ofstream&, CST&);
	friend CST* LoadFromFile(ifstream&);
	CST(unsigned, unsigned, tm, Route, string);
	CST(void);
	CST(const CST&);
};

