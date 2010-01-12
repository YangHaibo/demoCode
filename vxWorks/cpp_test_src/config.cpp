/* config.cpp - Test Application Configuration File */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,26jan04,pp	 written.
*/

/*
DESCRIPTION

Implements the Test Application Starting Routine
Defines the tunable configuration parameters.
*/

/* includes */



/* defines */

/* globals */

/*
 * NUMBER OF TIMES TESTCASES TO BE EXECUTED
 *
 * Initalize the value of the variable stressFactor
 */

int  stressFactor =1;   /* no of time test cases to be executed */


extern int tdfeTestCase1Execute(void);
extern int tdfeTestCase2Execute(void);
extern int tdfeTestCase3Execute(void);
extern int tdfeTestCase4Execute(void);
extern int tdfeTestCase5Execute(void);
extern int tdfeTestCase6Execute(void);
extern int tdfeTestCase7Execute(void);
extern int tdfeTestCase8Execute(void);
extern int tdfeTestCase9Execute(void);
extern int tdfeTestCase10Execute(void);
extern int tdfeTestCase11Execute(void);
extern int tdfeTestCase12Execute(void);
extern int tdfeTestCase13Execute(void);
extern int tdfeTestCase14Execute(void);
extern int tdfeTestCase15Execute(void);
extern int tdfeTestCase16Execute(void);
extern int tdfeTestCase17Execute(void);
extern int tdfeTestCase18Execute(void);
extern int tdfeTestCase19Execute(void);
extern int tdfeTestCase20Execute(void);
extern int tdfeTestCase21Execute(void);
extern int tdfeTestCase22Execute(void);
extern int tdfeTestCase23Execute(void);
extern int tdfeTestCase24Execute(void);
extern int tdfeTestCase25Execute(void);
extern int tdfeTestCase26Execute(void);
extern int tdfeTestCase27Execute(void);
extern int tdfeTestCase28Execute(void);
extern int tdfeTestCase29Execute(void);
extern int tdfeTestCase30Execute(void);
extern int tdfeTestCase31Execute(void);
extern int tdfeTestCase32Execute(void);
extern int tdfeTestCase33Execute(void);
extern int tdfeTestCase34Execute(void);
extern int tdfeTestCase35Execute(void);



/* locals */

/* Tunable configuration Parameters */

/*
 * TEST CASES TO BE EXECUTED
 *
 * insert the test cases numbers which are to be executed before 0 in the array
 * For example if only test cases 3 and 5 are to be executed
 * values in the array will be int tdfeConfigTestCases[] = {3,5,0}
 *
 */

/* execute all test cases */
#if 1

static int tdfeConfigTestCases[] ={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
									11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
									21,22,23,24,25,26,27,28,29,30,31,32,33,34,35, 
									0};

#else   /* execute a selective test case */ 

static int tdfeConfigTestCases[] ={21,22,23,24,25,26,27,28,29,30,31,32,33,34,35, 0 };

#endif

static int  (*tdfeConfigPf[])(void) =
    {
    /* General C++ features */
    tdfeTestCase1Execute, //Test References , References passed as parameter, functions returning References
    tdfeTestCase2Execute, //Test Inline functions
    tdfeTestCase3Execute, //Test static data member
    tdfeTestCase4Execute, //Test default parameters
    tdfeTestCase5Execute, //Test function overloading
    tdfeTestCase6Execute, //Test constant data member
    tdfeTestCase7Execute, //variable declaration
    tdfeTestCase8Execute, //scope resolution operator
    tdfeTestCase9Execute, //variable initialization
    tdfeTestCase10Execute,//Operator Overloading

    /* Exceptions related */
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
    
    /*Templates related*/
    tdfeTestCase21Execute,  //Template Instantiation ,Template Default parameters and Non-Type  Argument
    tdfeTestCase22Execute,  //Template class data member in another template class, Function overloading of template functions
    tdfeTestCase23Execute,  //Friend template function
    tdfeTestCase24Execute,  //Inline Template functions , operator overloading for template class
    tdfeTestCase25Execute,  //Nested Template
    
    /*Namespace related*/
    tdfeTestCase26Execute,  //namespace
    tdfeTestCase27Execute,  // unnamed namespace
    tdfeTestCase28Execute,  // namespace and overloading
    tdfeTestCase29Execute,  // namespaces are open, also namespace alias

    /*Inheritance related*/
    tdfeTestCase30Execute,  //Virtual function
    tdfeTestCase31Execute,  //Pure Virtual function
    tdfeTestCase32Execute,  //Diamond classes
    tdfeTestCase33Execute,  //Diamond Class - virtual base class to remove ambiguity


    /* Casting related */
    tdfeTestCase34Execute,  //Dynamic Cast - virtual base class
    tdfeTestCase35Execute   //Dynamic casting -non virtual base class
   
    };

/***************************************************************************
*
* tdfeConfigInit  - Test Application Starting Routine
*
* This is starting routine for test application, It executes the test
* cases specified in config file. The number of iterations are also
* specified in config file.
* 
*/


int main (void)
    {
    int * testcase = tdfeConfigTestCases;
   
    /*int noOfTestCases = 0; */

    

    
    while (*testcase)
	{
               
        for (int iteration =0; iteration < stressFactor;  iteration ++)
            tdfeConfigPf [(*testcase - 1)] ();

        
	testcase++;
        }

    return 0;
    }

#ifdef RTP_TESTING
int main(void)
    {
     test();
    }
#endif
