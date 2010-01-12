/* Template4.cpp */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,26feb04,pp	 written.
*/


/* Description 
   This program demonstrates the usage of inline template functions in combination with the template classes.
*/

/* includes */

#include <iostream.h>


template <class type>
class TemplClass
{
	type m_data;
	public:

		TemplClass ()
		{

		}

		TemplClass (type tArg)
		{
			m_data = typeArg;
		}

		inline TemplClass <type> & operator = (TemplClass<type> &refObj)
		{
			m_data = refObj.m_data;
			return *this;
		}

		inline TemplClass <type> & operator = (const type &refArg)
		{
			m_data = refArg;
			return *this;
		}

		inline operator type ()
		{
			return m_data;
		}

		inline bool operator == (type &typeArg)
		{
			return m_data == typeArg;
		}
		
};


template<class type>
inline bool Compare (TemplClass <type> &clsObj , type typeArg)
{
	return claObj == typeArg;
}

void tdfeTestCase24Execute()
{
	TemplClass<int> templObj,templObj1;
	templObj = 10;

	cout <<"\n Data in first object = "<<templObj;

	templObj1 = templObj;
	cout <<"\n Data in Second object = "<<templObj1;
	templObj1 = 20;
	cout <<"\n Data in Second object after change= "<<templObj1;
	cout <<"\n Data in first object after change= "<<templObj;


	if (templObj==30)
	{
		cout<<"\n Equal";
	}
	else
	{
		cout<<"\n UnEqual";
	}

}
