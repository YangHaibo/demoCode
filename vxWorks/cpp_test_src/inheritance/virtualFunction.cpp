/* virtualFunction.cpp */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,3March04,pp	 written.
*/

/*
DESCRIPTION

This test application has class hierarchy of following classes
mentioned in oreder of hierarchy ( base class first, then derived class)

virtSwitch , virtSwitch1, virtSwitch2, virtSwitch3, virtSwitch4, virtSwitch5

They have a virtual function increment()

Objects of the above classes ( except virtswitch) are created , and base class
 pointer virtSwitch pointer point to the objects created , and virtual function 
 increment is invoked through base class pointer..

*/



class virtSwitch
{

  
public:
	virtual void increment(void) = 0;
    static int i;
};

int virtSwitch::i =0;

class virtSwitch1 : public virtSwitch
{
public:
    virtual void increment(void)
    {
	   ++i;
    }

};

class virtSwitch2 : public virtSwitch1
{
public:
    virtual void increment(void)
    {
	   i = i + 2;
    }
};

class virtSwitch3 : public virtSwitch2
{
public:
    virtual void increment(void)
    {
	    i = i + 3;
    }
};

class virtSwitch4 : public virtSwitch3
{
public:
    virtual void increment(void)
    {
	    i = i + 4;
    }
};

class virtSwitch5 : public virtSwitch4
{
public:
    virtual void increment(void)
    {
	    i = i + 5;
    }
};




virtSwitch *sw[5];


/* test routine */

int tdfeTestCase30Execute (void)				
{
    sw[0] = new virtSwitch1;
    sw[1] = new virtSwitch2;
    sw[2] = new virtSwitch3;
    sw[3] = new virtSwitch4;
    sw[4] = new virtSwitch5;

    sw[0]->increment();
    sw[1]->increment();
    sw[2]->increment();
    sw[3]->increment();
    sw[4]->increment();
	return 0;
}

