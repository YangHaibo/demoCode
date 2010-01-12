/* Template3.cpp */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,26feb04,pp	 written.
*/

/* Description 
*This function uses the friend template function of a template class 
*to access the private data member of the template class
*It also shows overloaded friend functions
*/

/* includes */

#include <iostream>
#include "template3.h"

using namespace std;

int tdfeTestCase23Execute()
{
	TempFriend<float> data1(8.9);

	foo <float>(data1);
	return 0;
}
