/* diamondClasses.cpp */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,3March04,pp	 written.
*/

/*
DESCRIPTION

Program to demonstrate the diamond classes arrangement and accessing the base
most class members.

In the test application Base1 and Base2 have virtual base class baseMost.
Class Derived has Base1 and Base2 as base classes. BaseMost Class has
function vFunction().VFunction is called through derived class member function ,
using scope resolution Base1::vFunction().

*/

#include <stdio.h>


class BaseMost
{	
		int i;
public:
		void vFunction()
		{
			printf("\n vFunction of BaseMost, Value of i = %d",i);
		}
		void SetI(int iArg)
		{
			i=iArg;
		}
};



class Base1 : public BaseMost
{

public:
		virtual void vF1()
		{
			printf("\n vF1 of Base1");
		}
};

class Base2:public BaseMost
{

public:
		virtual void vF2()
		{
			printf("\n vF2 of Base2");
		}
};

class Derived: public Base1,public Base2
{

public:
		virtual void vF1()
		{
			Base1::SetI(10); //Setting the first copy of i
			Base2::SetI(20); //Setting the second copy of i
			Base1::vFunction(); //Removes ambiguity
			Base2::vFunction(); //Removes ambiguity
			printf("\n vF1 of Derived");
		}
		virtual void vF2()
		{
			printf("\n vF2 of Derived");
		}
		
};


int tdfeTestCase32Execute()
{
Derived *pDerived;
pDerived=new Derived;
pDerived->vF1();
	return 0;
}
