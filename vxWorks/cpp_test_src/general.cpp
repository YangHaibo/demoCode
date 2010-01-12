/* general.cpp */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,26Feb04,pp		 written.
*/

/*
DESCRIPTION
   Tests the following C++ features -
   - use of references, references as arguments,function returning references
   - use of inline functions
   - static data member
   - function with default parameters
   - function overloading
   - constant data member
   - variable declaration
   - scope resolution operator
   - variable initialization
   - Operator Overloading

*/



/*
C++ feature - REFERENCE
------------------------
*/


/* references as arguments */

void change (double &r, double &s)
    {
    r = 100;
    s = 200;
    }

/* function returning references */

double &biggest (double &r, double &s)
    {
    if (r > s) return r;
    else       return s;
    }


/*
DESCRIPTION
   This function shows the various usage of references
*/

int tdfeTestCase1Execute ()
    {
    double a = 3.1415927;
    double result = 0;
    double &b = a;                            // b is reference

    b = 2;
    result = a;
    /* a, result should be 2 now */

    double k = 1;
    double m = 2;

    change (k, m); // k should be 100,m 200 now
    biggest (k, m) = 10; // m should become 10

    return int(result);
    }



/*
C++ feature - inline functions
------------------------------
*/



inline double add (double a, double b)
{
    return ( a + b);
}

int tdfeTestCase2Execute ()
{
    double k = 6, m = 9;

    double result = add( k, m);

    return 0;
}



/*
C++ feature - static data member
--------------------------------

A class' variable can be declared static. Then only one instance of
that variable exists, shared by all instances of the class. It
must be initialised outside the class declaration
*/

class vector1
{
    public:

    double x;
    double y;
    static int count;

    vector1 (double a = 0, double b = 0)
    {
        x = a;
        y = b;
        count++;
    }

    ~vector1()
    {
        count--;
    }
};


int vector1::count = 0;


    int tdfeTestCase3Execute ()
    {
        int result = 0;
        vector1 a;
        vector1 b;
        vector1 *r, *u;

        r = new vector1;
        u = new vector1;
        result = a.count; //value of result  should be 4
        result = b.count; //value of result  should be 4

        delete r;
        delete u;

        result = a.count; //value of result  should be 2
        return result;
    }



/*
C++ feature - function with default parameters
----------------------------------------------
*/


/* define default parameters for functions */
double minus (double a, double b = 7)
{
    return a - b;
}

int tdfeTestCase4Execute()
{
    double result;
    result = minus (20, 5);
    result = minus (20) ;

    return int(result);
}

/*
C++ feature - function overloading
-----------------------------------
Function overloading Different functions can have the same name provided
something allows to distinguish between them: number of parameters, type of parameters... */

double func (double a, double b)
{
    return a + b;
}

int func (int a, int b)
{
    return a - b;
}

int tdfeTestCase5Execute ()
{
    double   m = 7,  n = 4;
    int      k = 5,  p = 3;

    func(m, n) ;
    func(k, p) ;

    return 0;
}

/*
C++ feature - constant data member
-----------------------------------

verifies the behaviour of constant data member in a class

 there is is a class  'cylinder '  which has constant member 'pi'.

*/

/* Prashant : Start : For testing DebuggerFrontEndBreakpointsViewWiproTC1 */
class StaticMemberInClass
{
	public :
	static int iCounter ;
	static void IncrementCounter ( void )
	{
		iCounter ++ ;
	}
} ;
/* Prashant : End : For testing DebuggerFrontEndBreakpointsViewWiproTC1 */
int StaticMemberInClass::iCounter = 0; 
class cylinder
{
    public:

        double x;
        double y;
        const static double pi ;

        cylinder (double a = 0, double b = 0)
								{
            x = a;
            y = b;
        }

        double cilinder_volume ()
        {
            return x * x / 4 * pi * y;
        }
};

const double cylinder::pi = 3.1415927;

int tdfeTestCase6Execute()
{
    /*double pi;*/
    double result;

    cylinder k (3, 4);

    /* pi = cylinder::pi; */
    result = k.cilinder_volume() ;

	/* Prashant : Start : For testing DebuggerFrontEndBreakpointsViewWiproTC1 */
	{
		StaticMemberInClass objStaticMemberInClass ;
		for ( int p = 0 ; p < 10 ; p ++ )
		{
			objStaticMemberInClass.IncrementCounter ( ) ;	// Will make value of iCounter 6
		}
	}
	/* Prashant : End : For testing DebuggerFrontEndBreakpointsViewWiproTC1 */

    return (int)result;
}


/*
C++ feature -
--------------

   In C ++ variables can be declared in middle of the block unlike 'C'  .
   This program verifies that variables declared in middle of the block
   are shown correctly in local view in IDE .
*/
int tdfeTestCase7Execute ()
{
    double a = 1;


/* C++ allows declaration not in the beginning of the block */
    double c;

    c = a * 5 + 1;

    int i, j;

    i = 0;
    j = i + 1;

    return (int)c + j;
}


/*
C++ feature - scope resolution operator
---------------------------------------

In C ++  global variables can be accessed using scope resolution operator
This program test case verifies if local variable is having same name as global
variable , the value of local variable and global variable using scope
resolution are displayed correctly in local view in IDE .
*/



/*A global variable can be accessed using scope resolution operator */
double a = 1;

int tdfeTestCase8Execute ()
{
    double a = 2;
    double result =0;
    result = ::a + a;
    /* result should have value 3 now*/

    return (int)result;
}


/*
C++ feature -
------------
   In C ++ variables can be initialized using calculations of other variables.
   This test case verifies that such variables after initialization are shown
   with correct values  in local view in IDE .
*/



int tdfeTestCase9Execute ()
{
    double a = 12 * 3.25;
    double b = a + 1.112;
    a = a * 2 + b;
    double c = a + b * a;
    return (int)c;
}


/*
C++ feature - operator overloading
-----------------------------------

   This test case verifies that functions with operator overloading can be debugged in IDE .
   there is a class 'vector' . The vector class has overloaded operators +, -,  <<
*/



#include <iostream>
#include <cmath>
using namespace std;

class vector
{
public:

   double x;
   double y;

   vector (double = 0, double = 0);

   vector operator + (vector);
   vector operator - (vector);
   vector operator - ();
   vector operator * (double a);
   double module();
   void set_length (double = 1);
};

vector::vector (double a, double b)
{
   x = a;
   y = b;
}

vector vector::operator + (vector a)        //+ operator overloaded
{
   return vector (x + a.x, y + a.y);
}

vector vector::operator - (vector a)       // - operator overloaded
{
   return vector (x - a.x, y - a.y);
}

vector vector::operator - ()
{
   return vector (-x, -y);
}

vector vector::operator * (double a)
{
   return vector (x * a, y * a);
}

double vector::module()
{
   return sqrt (x * x + y * y);
}

void vector::set_length (double a)
{
   double length = this->module();

   x = x / length * a;
   y = y / length * a;
}

ostream& operator << (ostream& o, vector a)
{
   o << "(" << a.x << ", " << a.y << ")";
   return o;
}
int RecursiveFunction ( int iCnt );
int tdfeTestCase10Execute ()
{
   vector a;
   vector b;
   vector c (3, 5);

   a = c * 3;
   a = b + c;
   c = b - c + a + (b - a) * 7;
   c = -c;

   cout << "The module of vector c: " << c.module() << endl;

   cout << "The content of vector a: " << a << endl;
   cout << "The oposite of vector a: " << -a << endl;

   c.set_length(2);            // Transforms c in a vector of size 2.

   a = vector (56, -3);
   b = vector (7, c.y);

   b.set_length();             // Transforms b in an unitary vector.

   cout << "The content of vector b: " << b << endl;

   double k;
   k = vector(1, 1).module();  // k will contain 1.4142.
   cout << "k contains: " << k << endl;

   RecursiveFunction ( 0 ) ;

   return 0;
}

/* Prashant : Start : Testing of multiple lines expression, recursion etc */
int RecursiveFunction ( int iCnt )
{
	if ( iCnt >= 10 )
	{
		return iCnt ;
	}
	else
	{
		RecursiveFunction ( ++ iCnt ) ;
	}

	int a = 10 , b = 20 , c = 30 ;
	int p = ( a + b ) * ( ( b - 2 ) / c ) +  	\
				( a + b + c ) + 				\
				( c - a ) +						\
				( a + a ) -						\
				100 ;
	return p;
}
/* Prashant : End : Testing of multiple lines expression, recursion etc */
