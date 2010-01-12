/* Template3.h */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,26feb04,pp	 written.
*/
/* Description 
* This file contains template class TempFriend with friend template functions
* The friend template function of a template class must be declared before the template class  
* The ordinary friend function of a template class can be declared after the template class 
* If member function of a class, is a friend to a template class the class having the member function
* should be defined before the template class   
*/



#ifndef TEMPLATE_APP3_H
#define TEMPLATE_APP3_H

/* includes */

#include <iostream>
#include <new>
using namespace std;

template<class T>class TempFriend;


template <class T> void foo (TempFriend<T>);

// The class foobar and the function foo() do not have to be declared or defined in
// global before class template TempFriend declares them as friend.However
// class Foo must be defined before class TempFriend can declare one of its
// member as friend 

template <class T> class TempFriend
{
	private:
		T a;
	public:
		TempFriend (const T& data) : a (data){}
		~TempFriend(){}
		friend void foo<T>(TempFriend<T>);
	
		
};

/*void Foo :: bar ()
{
	cout<<"Executing function Foo::bar()"<<endl;
}
*/


/*void foo ()
{
	cout<<"Function foo () a friend of class TempFriend"<<endl;
}
*/

template <class T> void foo (TempFriend<T> dt)
{
	cout<<"Template function foo() a friend of class TempFriend with private data : "<<dt.a<<endl;
}


#endif
