/* Template1.cpp */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,26feb04,pp	 written.
*/

/*
* Description 
* This function shows template instantiations
* Instances of template class stack is created with different data types
* Template class stack is instantiated with default template parameters too
* It shows what all values can be passed to non type template arguments as the 
* non type template argument expression should be constant and determined at compile time
*/

/* includes */

#include "template1.h"
#include <iostream>

using namespace std;

/******************************************************************************************
* testTemplate1
*/

int tdfeTestCase21Execute()
{
	int sz_val = 20;
	const int cons_sz_val = 20;
	
	//error :: stack<int,sz_val> stack1; // The sz_val cannot be evaluated at compile time
	
	stack <int,cons_sz_val> stack2; 		// ok
	stack <int,sizeof(sz_val)> stack3; 		//ok
	
	stack<int,12> stack4;				//ok

	//stack type = int, size = 15
	stack<int,15> int_stack; 			// The expression to non type parameter size
						        // must be a constant expression
	int_stack.push(5);
	int_stack.push(89);
	int_stack.push(56);
	cout<< int_stack.pop()<<endl;
	cout<< int_stack.pop()<<endl;

	//stack type = float, size = (12-4) = 8
	stack<float,12-4> float_stack;
	float_stack.push(8.9);
	cout<<float_stack.pop()<<endl;                  
			
	//stack type = char*, size = 10
	stack<char*,10> string_stack;
	string_stack.push("Sunay");
	cout<<string_stack.pop()<<endl;

	//stack type = int, default size = 10
	stack<int> default_size_stack;
	default_size_stack.push(67);
	cout<<default_size_stack.pop()<<endl;

	//default stack type = int,default size = 10
	stack<> default_stack;
	default_stack.push(34);
	cout<<default_stack.pop()<<endl;
	return sz_val;
}
