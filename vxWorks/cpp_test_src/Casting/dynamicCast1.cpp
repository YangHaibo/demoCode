

/* dynamicCast1.cpp */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,3March04,pp	 written.
*/

/*
DESCRIPTION
This program shows the use of dynamic casts.

An object of a virtual base class cannot be converted into its 
derived class object if you try to do this, you get a compile-time
error because the compiler does not have all the necessary information
to perform the conversion. The dynamic_cast() operator, however, solves
this problem because it performs the conversion at runtime

*/


#include <stdio.h>

/* class B1 declaration */

class B1 
{

public:
virtual void show()
{   
    printf( "B1 show \n");
}

};

/* class D1 declaration */

class D1:public virtual B1
{
public:

virtual void show()
{   
    printf("D1 show \n");

}
};



/* Test routine */

int tdfeTestCase34Execute()
{
    B1 a;
    D1 b;
    B1* pb=new D1;
/*  D1* pd1=(D1*)pb; */ // Does not compile as cannot cast up from virtual base class  
    D1* pd2=dynamic_cast<D1*>(pb); //ok
   pd2->show();
	return 0;
}


