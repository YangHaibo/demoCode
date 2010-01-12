/* Template2.cpp */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,26feb04,pp	 written.
*/

/* Description

 This is a implementation of Queue (FIFO) 
 The following function uses the template class Queue object for creating a link list
 for storing the template class QueueItem objects. 
 It uses template function display for displaying the data stored in template class QueueItem
 linked in class template Queue object
 It uses overloaded display function too  
*/

/* includes */

#include "template2.h"
#include <iostream>

using namespace std;

int tdfeTestCase22Execute()
{
	Type ty = 5.8;

	Queue <int> *pqi = new Queue <int>;

	for (int ival = 0; ival < 10 ; ++ival)
	{
		
		pqi->add(ival);
	}

	display<int>(*pqi);
	display ();
	display<Type>(ty);
	
	int errcnt = 0;

	for (int ival = 0; ival < 10; ++ival)
	{
		int pval = pqi->remove();
			if(pval != ival)
				errcnt++;
	}

	if (!errcnt)
		cout <<"Queue Executed ok"<<endl;
	else
		cout << "Problem with Queue execution\n Error Count = "<<errcnt<<endl;

	return 0;
}
