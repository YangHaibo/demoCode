
/* pureVirtual.cpp */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,3March04,pp	 written.
*/

/*
DESCRIPTION

In the test application Data is abstract class , having pure 
virtual function show(). Data1 is concrete class derived from
base class Data
*/

#include <stdio.h>

class Data
{
public:
    virtual ~Data(){}
    virtual void Show() = 0;
};


/* pure virtual function can be implimented , though declared pure virtual */
void Data::Show()
{
    printf("\nThis is your data. - Data \n");
}

class Data1 :public Data
{
public:
    virtual void Show();
};



void Data1::Show()
{
    Data::Show();  // invoked using the scoping operator
    printf("\nThis is your data. - Data1 \n");
}

int tdfeTestCase31Execute()
{

    Data1 b;

    b.Show();
    return 0;
}


