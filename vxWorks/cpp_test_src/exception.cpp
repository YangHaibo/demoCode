
/* Exception.cpp */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,26feb04,pp		 written.
*/

/*
DESCRIPTION
The test cases in this file test the following C++ features -
    tdfeTestCase11Execute, //exception and inheritance
    tdfeTestCase12Execute, //exception - no casting during exception handling
    tdfeTestCase13Execute, //exception and template
    tdfeTestCase14Execute, // exception thrown in constructor
    tdfeTestCase15Execute,  //rethrowing an exception
    tdfeTestCase16Execute,  //exception thrown in destructor
    tdfeTestCase17Execute,  //exception thrown in virtual function
    tdfeTestCase18Execute,  // exception thrown from inline function
    tdfeTestCase19Execute,  //exception thrown from static member function
    tdfeTestCase20Execute,   //exception thrown from friend function

*/


/*
C++ feature - exception and inheritance
----------------------------------------

CDerClass is derived from class CBaseClass . In tdfeTestCase11, 
separate  catch blocks are  there to catch exceptions thrown as
 derived class object and exceptions thrown as base class 
 object . Base class exception is thrown in the function ,Tester 
 should step through the try catch block
*/

#include <iostream>
using namespace std;
class CBaseClass
{
public:
};

class CDerClass: public CBaseClass
{
public:
};



void tdfeTestCase11Execute()
{
    try
    {
	CBaseClass *pBaseClass=new CBaseClass;
	throw pBaseClass;
    }

    catch(CDerClass *pDerArg)
    {
        cout << " derived class destructor ";
    }
    catch(CBaseClass *pBaseArg)
   {
       cout << " base class destructor ";
   }
}
    
    
/*
C++ feature -
--------------

This program demonstrates the feature that there is no
type casting (explicit nor implicit) hapenning whatsoever for
binding to appropriate catch handler .

tdfeTestCase12 function throws an exception of  object of class ExcepClass.
There is only one catch block in the flow which catches char exception .
Though the ExceptClass has overloaded operator for conversion to char ,
casting does not happen for binding to appropriate catch handler.
*/

class ExcepClass
    {
        int m_iVal;
    public:
        ExcepClass(int iArg)
            {
            m_iVal=iArg;
            }

        operator int ()
            {
            return m_iVal;
            }

        operator char ()
            {
            return m_iVal;
            }
    };

void tdfeTestCase12Execute()
{
    try
        {
        int iVal=10;
				ExcepClass expclsObj(iVal);

// The throw statements below would result in an unhandled exception
// at runtime.

				throw expclsObj;
        }
    catch(char cArg)
				{
				cout << "\n Caught a character exception "<<cArg;
				}
    catch(...)
    {
        cout << " caught the exception \n";
    }
}


/*
C++ feature - Exceptions and templates
----------------------------------------

tdfeTestCase13 throws an exception of template class CTemplClass .
There is a catch block to handle the exception

*/

template<class Type>
class CTemplClass
    {
    Type m_tVal;
    };


void tdfeTestCase13Execute()
    {
    try
        {
        CTemplClass<int> ctemplIObj;

/* This exception would be handled by catch(CTemplClass<int> &ref)*/
        throw ctemplIObj;
        }


    catch(CTemplClass<int> refArg)
        {
        cout << "\n exception";
        }
    }


/*
C++ feature - Exceptions and constructor
----------------------------------------
demonstrates the concept of throwing exceptions from constructors and its impact on
the Descturction of the objects.
*/


#include <stdexcept>

using namespace std;

class ClassA
    {
    public:
        ClassA()
            {
            cout << "\n ClassA Constructor";
            }

        ~ClassA()
            {
            cout << "\n ClassA Destructor";
				    }
    };

class ClassB
    {
    public:
        ClassB() throw(runtime_error)
            {
            cout << "\n ClassB constructor";
            throw runtime_error("Exception raised from ClassB constructor");
            }

        ~ClassB()
            {
            cout <<"\n Destructor of ClassB";
            }
    };


class ClassX
    {
    protected:
        ClassA m_aObj;
        ClassB m_bObj;
    public:
        // Exception would be thrown from ClassB
        ClassX() throw(int) : m_aObj(), m_bObj()
            {
            cout << "\n Constructor of ClassX";
            }

        ~ClassX()
            {
            cout << "\n Destructor of ClassX";
            }
    };


void tdfeTestCase14Execute()
    {
    try
        {
        ClassX xObj;
        cout<<"\n This statement is never executed";
        }
    catch(exception &eArg)
        {
        cout << "\n Handler in Main : " <<eArg.what()<<"\n";
        }
    
    }


/*
C++ feature - Rethrowing an exception
----------------------------------------

Function tdfeTestCase15Execute calls function  FirstFunction, which in
calls SecondFunction. the sceond function calls ThirdFunction.

Third function throws an exception, secondfunction   catches
the exception and throws it again .Finally the exception is handled by
firstfunction
*/


void SecondFunction();
void ThirdFunction();
void FirstFunction()
    {
    /* char cVal='F'; */
    try
        {
        SecondFunction();
        }
    catch(int iArg) //Handles the rethrown exception
        {
        cout << "\n Integer exception Handler";
        }
    }

void SecondFunction()
    {
    int iVal=10;
    try
        {
	ThirdFunction();
        }
    catch(float fArg)
        {
	cout << "\n Float exception Handler";
	throw iVal; //Rethrowing an Exception
	}
    }

void ThirdFunction()
    {
    float fVal=(float)10.29;
    cout << "\n Float Exception Raised";
    throw fVal; //Throwing an Exception
    }

void tdfeTestCase15Execute()
    {
    FirstFunction();
    }

/*
C++ feature -
-------------

Handling exceptions at the time of Destruction of an Object

Class CContainerClass has Class CDestExceptionTest object as data members .
Class CDestExceptionTest destructor throws an exception In the function
tdfeTestCase16Execute object of Class CContainerClass is created  and
then destroyed, which raises an exception while deleting  class
CDestExceptionTest data member .There is a catch block in
tdfeTestCase18Execute to handle the exception.

*/

void ProcessCleanUp()
    {
    int i=10;
    throw i;
    }

class CDestExceptionTest
{
public:
    ~CDestExceptionTest()
    {
    try
        {
	ProcessCleanUp();
	}
    catch(...)
	{
	cout << "\n ~CDestExceptionTest: Caught an exception ";
	throw ;
	}
    }
};

class CContainerClass
{
    CDestExceptionTest *m_pObj;
public:

    CContainerClass()
    {
    m_pObj=new CDestExceptionTest;
    }

    ~CContainerClass()
    {
    try
        {
	delete m_pObj;
        }
    catch(...)
	{
	cout<<"\n CContainerClass:Caught an Exception";
	}
    }

};


void tdfeTestCase16Execute()
{
    CContainerClass *pObject;
    pObject=new CContainerClass;
    delete pObject;
}


/*
C++ feature - Throwing exceptions from virtual functions
-------------------------------------------------------

The class CB is derived from Class CA. Class CA has a
virtual function Function() . Class CA versionof this function
throws an integer exception and Class CB version throws an char exception.
This virtual function is called from base class pointer pointing
to derived class object . The derived class versionof virtual function
gets called and throws char exception . There is a catch blocks to handle
then char and integer exceptions
 */

#include <iostream.h>

void ExceptionInt()
{
	int iVal=10;
	throw iVal;
}

void ExceptionChar()
{
	char cVal=10;
	throw cVal;
}

class CA
{
public:
		virtual void Function()
		{
			try
			{
				ExceptionInt();
			}
			catch(...)
			{
				cout<<"\n CA: Caught Integer Exception";
			}
		}

		virtual ~CA()
		{
		        cout<<"\n CA: Destructor ";
		}


};

class CB:public CA
{

public:

		void Function()
		{
			try
			{
				ExceptionChar();
			}
			catch(...)
			{
				cout<<"\n CB: Caught Character Exception";
			}

		}

		~CB()
		{
			cout<<"\n ~CB: Destructor";
		}
};

void tdfeTestCase17Execute()
{
	CA *pa;
	pa=new CB;
	pa->Function();
	delete pa;

}
/*
C++ feature - exception handling with inline function
-----------------------------------------------------

Class CInlineFunctionTest has RaiseExcep inline member function
The function RaiseExcep is called which throws an exception.
There is a catch block to handle the exception */



class CInlineFunctionTest
{
public:

    inline void RaiseExcep()
    {
        int iVal=10;
        throw iVal;
    }

};

void tdfeTestCase18Execute()
{
    CInlineFunctionTest Obj;
    try
    {
    Obj.RaiseExcep();
    }
    catch(int iArg)
    {
	cout<<"\n Caught an Exception: "<<iArg;
    }

}

/*
C++ feature - exception from static member function
---------------------------------------------------

Tescase demonstartes raising of exception from static member functions
Class CExcepClass has RaiseExcep static member function In the function
tdfeTestCase20Execute function RaiseExcep is called which throws an
exception. There is a catch block in tdfeTestCase20 to handle the
exception

*/

class CExcepClass
{
private:
    static int m_siVal;
public:
    static void RaiseExcep()
    {
        throw m_siVal;
    }
};

int CExcepClass::m_siVal=10;


void tdfeTestCase19Execute()
{
    CExcepClass Obj;
    try
    {
        Obj.RaiseExcep();
    }
    catch(int iArg)
    {
        cout<<"\n Caught Exception : "<<iArg;
    }
}

/*
C++ feature - Throwing Exception from a friend function
-------------------------------------------------------
*/

#include<string.h>


class CExcepClass1
{
    char m_strVal[100];
public:
    CExcepClass1(char *strArg)
    {
        strcpy(m_strVal,strArg);
    }
    char *What()
    {
        return m_strVal;
    }
    friend void RaiseExcep();
};

void RaiseExcep()
{
    CExcepClass1 clsObj("Raised Exception");
    throw clsObj;
}



void tdfeTestCase20Execute()
{
    try
    {
        RaiseExcep();
    }
    catch(CExcepClass1 &refObj)
    {
        cout<<"\n "<<refObj.What()<<"\n";
    }
}

