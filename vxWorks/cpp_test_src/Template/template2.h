/* Template2.h */



/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,26feb04,pp	 written.
*/



/* Description
The following file contains template class Queue and template class QueueItem
The template class Queue contains pointer to object of type template class QueueItem
The QueueItem contains data member item and pointer to object of its own type
The template class Queue and QueueItem contains default template argument as int
Type has been typedef to double,but using same name Type as template argument does not imply
that template argument Type is double.Variables with same name as template parameter declared in
global scope there name is hidden
The same name of template parameter is used across class template declarations
The file contains overloaded template function display   
*/

/* includes */ 

#ifndef TEMPLATE_APP2_H
#define TEMPLATE_APP2_H

#include <iostream>
#include <new>

using namespace std;

/* typedef */

typedef double Type; // If variable with same name as the template parameter
                     // is declared in global scope that name is hidden

// The name of a template parameter can be reused across 
/*  class template declarations */

template <class T> class QueueItem;

template <class T> class Queue;

//error :: template <class Type, class Type> class Test;   //Template Parameter can be introduced
                                                           //only once within template parameter list

// The name of the template parameters can be different across 

// forward declarations and the definitions of the template class  

template <class Type = int> class QueueItem                //default template argument is int
{
	public:
		// item is not of type double
		Type item;
		//error :: typedef double Type;           // member cannot have same name as 
		                                          // template parameter
		QueueItem *next;                          // Each occurance of the QueueItem class template
						          // within the class template definition is a short 
						          // hand for QueueItem<Type>
		QueueItem (const Type &);
		~QueueItem ();
};


template <class Type = int> class Queue                   //default template argument is int
{
	//private:
	public:			
		QueueItem<Type> *front;
		QueueItem<Type> *back;                    // Since QueueItem is used as a type specifier 
							  // in another template definition full template
							  // parameter list must be specified	
	public:
		Queue():front(0),back(0){}
		~Queue();

		Type remove();
		void add (const Type &);
		bool is_empty () const
		{
			return front == 0;
		}
};


template <class Type> QueueItem<Type> :: QueueItem (const Type & ref) : item(ref)
{
	next = 0;	
}

template <class Type> QueueItem<Type> :: ~QueueItem ()
{
	//Do nothing destructor
}

template <class Type> Queue<Type> :: ~Queue ()
{
	while ( ! is_empty())
		remove();
}

template <class Type> void Queue<Type> :: add (const Type& data)
{ 
	QueueItem<Type> *pt = new QueueItem<Type>(data);
	if (is_empty())
		front=back=pt;
	else
	{
		back->next = pt;
		back = pt;
	}
	
} 

template <class Type> Type Queue<Type> :: remove ()
{
	if (is_empty())
	{
		cout<<"remove() on empty queue"<<endl;
		return -1;
	}

	QueueItem <Type> *pt = front;
	front = front->next;
	
	Type retval = pt->item;
	delete pt;
	return retval;
}

template <class Type> void display (Queue<Type> &add)
{
	Queue<Type> *pqi = &add;
	QueueItem<Type> *qi = pqi->front;
	while (qi->next != 0)
	{
		cout <<"Data"<<qi->item<<endl;
		qi = qi->next;
	}
	cout<<"Data"<<qi->item<<endl;
}

//Explicitly overloading a generic function : explicit specialization
template <class T> void display (T data)
{
	cout<<"Overloaded template function with data : " <<data<<endl;
	return;
}

void display ()
{
	cout<<"Non Template display function"<<endl; 
}

#endif
