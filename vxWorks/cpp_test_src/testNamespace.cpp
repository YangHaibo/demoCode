
/* testNamespace.cpp */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,13April04,pp	 written.
*/

/*
DESCRIPTION
The test cases in this file test the following C++ features -
 
    tdfeTestCase26Execute,  //namespace
    tdfeTestCase27Execute,  // unnamed namespace
    tdfeTestCase28Execute,  // namespace and overloading
    tdfeTestCase29Execute,  // namespaces are open, also namespace alias

*/



/*
C++ feature - namespace
------------------------

The variables declared within a namespace can be used using :: operator
In the test application there are two namespaces 'first'  and 'second'. 
Both have variables named ' a'  and ' b'. The function testNamespace1 
uses these variables of both the namespaces.
*/

namespace first
    {
    int a;
    int b;
    }

namespace second
    {
    double a;
    double b;
    }

int tdfeTestCase26Execute ()
    {
    double result =0;
    first::a = 2;
    first::b = 5;

    second::a = 6.453;
    second::b = 4.1e4;

    result = first::a + second::a ;
    result = first::b + second::b ;

    return (int)result;
    }




/*
C++ feature - Unnamed namespaces - section 8.2.5.1 Stroustrup
-----------------------------------------------------

it is often useful to wrap a set of declarations in a namespace simply to 
protect against the possibility of name clashes , the aim is to preserve 
the locality of code rather than present an interface to users */



namespace 
{
    int a1;
    void f1()
        {
        a1 ++ ;
        }
}

/* Above code is equivalent to following code 

namespace $$$
{
    int a1;
    void f1()
        {
        a1 ++ ;
        }
}

using namespace $$$;

*/

int tdfeTestCase27Execute (void )
    {
    a1 = 5;
    f1();
    return 0;
    }
    
    

/*
C++ feature - namespace and overloading
-----------------------------------------------------


two namespace are in scope , Both
 the namespaces have functions 
f() , which take different arguments */

#include <stdio.h>

namespace A1
    {
    void f(int a)
        {
        printf( " A1::f ");
        }

    }

namespace A2
    {
    void f(char a)
        {
        printf( " A2::f ");
        }

    }

using namespace A1;
using namespace A2;

int tdfeTestCase28Execute()
    {
    f('c');  // Calls A2::f
    f(5);    // Calls A1::f
    return 0;
    }
    
    
/*
C++ feature - namespaces are open, also namespace alias
-----------------------------------------------------
 namespaces are open ,section 8.2.9.3 Stroustrup
i.e you can add names to it through several declarations 
In the test application there is  namespaces 'third' . 
It is declared twice adding different names to the namespace. 
Alias flib is created   The function testNamespace4 uses the
namespace alias to refer to the namespace. 
*/

namespace third
    {
    int a2;         // now first has a member a1
    }


int play(void)
    {
    third::a2 =5;
    return 0;
    }

namespace third
    {
    int a3;          // now first has a member a1 and a2
    }

namespace flib = third; //alias created for namespace third

int tdfeTestCase29Execute ()
    {
    int result =0;
    play();
    third::a3 = 6;

    result = flib::a3 + flib::a2 ;
    return result;
    }
    

