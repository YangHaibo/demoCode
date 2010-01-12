/* Template1.h */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,26feb04,pp	 written.
*/
   
/* 
Description

This file contains template class stack with default template arguments 
The template class stack also takes a non type argument size template class 
stack contains member function to push and pop the data to stack
The file shows how the member functions of template class are defined
They are used the same way as normal class member functions .
*/  	


#ifndef TEMPLATE_APP1_H
#define TEMPLATE_APP1_H

/* includes */

#include <iostream>
#include <new>

/* namespace */

using namespace std;

/********************************************************************************
* Stack Class
*/

template <class T = int,int size = 10> class stack   /*default argument to template*/
                                                     /*Non-Type argument*/ 
{
	private:
		T *stcksz; 			     /*stack size*/
		int tos; 		             /*top of stack*/
	public:
		stack (void) ; 		             /*constructor*/
		~stack (void);                       /*destructor*/ 
		void push (T data);
		T pop ();
};

/********************************************************************************
* Stack Constructor Function
*/

template <class T , int size> stack <T,size> :: stack (void)
{
	try
	{
		stcksz = new T[size];
	}
	catch(bad_alloc) 
	{
		cout<<"Not enough memory to allocate"<<endl;
	}
	tos = 0;
}

/********************************************************************************
*Stack Destructor Function
*/

template <class T , int size> stack <T , size> :: ~stack (void)
{
	delete [] stcksz;
}

/********************************************************************************
*Stack push Function
*/

template <class T , int size> void stack<T,size>::push (T data)
{
	if (tos == size)
	{
		cout<<"Stack is full"<<endl;
		return;
	}
	stcksz[tos] = data;
	tos ++;
}

/********************************************************************************
*Stack pop Function		
*/

template <class T , int size> T stack <T , size> :: pop ()
{
	if(tos == 0)
	{
		cout <<"Stack is empty"<<endl;
		return 0;
	}
	tos--;
	return stcksz[tos];
}

#endif
