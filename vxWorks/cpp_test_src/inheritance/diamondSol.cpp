/* diamondSol.cpp */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,3March04,pp	 written.
*/

/*
DESCRIPTION

Demonstrate the solving of diamond classes arrangement
by making a single copy of the base most class members

In the test application Base1 and Base2 have virtual base class baseMost.
Class Derived has Base1 and Base2 as base classes. BaseMost Class has
function vFunction().VFunction is called through derived class member
function , the call is not ambigious as baseMost is virtual base class
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



class Base1 : virtual public BaseMost
{

public:
		virtual void vF1()
		{
			printf("\n vF1 of Base1");
		}
};

class Base2:virtual public BaseMost
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
			Base1::SetI(10); //Setting the value of i
			Base2::SetI(20); //Results in overwriting the value of i as there is only one copy of i
			vFunction();  //No ambiguity in this case due to virtual inheritance
			printf("\n vF1 of Derived");
		}
		virtual void vF2()
		{
			printf("\n vF2 of Derived");
		}
		
};


int tdfeTestCase33Execute(void)
{
Derived *pDerived;
pDerived=new Derived;
pDerived->vF1();
	return 0;
}
