/* Templetes_Nested.cpp */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,26feb04,pp	 written.
*/

/*
* Description 
* Program demonstrates the concept of Template containment 
*/

/* includes */

#include <iostream.h>

template <class type /*Container Type*/ , class type1 /*Contained Type*/ >
class OuterTemplClass 					/*Container Template Class */
{
		template <class type2>
		class InnerTemplate 			/*Contained template class */
		{
			type2 m_type1Var;
			
		public: 
			void Set (type2 typeArg)
			{
				m_type1Var = typeArg;
			}
			
			type2 Get ()
			{
				return m_type1Var;        
			}
		};
		
		type m_typeVar;
		
		InnerTemplate<type1> m_innerTypeVar;
		
	public:
		
		
		void Set (type typeArg)
		{
			m_typeVar = typeArg;
		}
		
		type Get()
		{
			return m_typeVar;
		}
		
		InnerTemplate<type1> & GetContained ()
		{
			return m_innerTypeVar;
		}
};

/******************************************************************************************
* 
*
*This function tries to instantiate the outer template class and assign values to its member data 
*and also to its contained class object.
*
* Returns N/A
*/

void tdfeTestCase25Execute()
{
	OuterTemplClass<int,char> TempObj;

								//Outer Object handling(Setting and getting value)
	TempObj.Set(10);
	cout<<"\n Value assigned to outer : "<<TempObj.Get();

								//Inner Object handling(Setting and getting value)
	TempObj.GetContained().Set('d');
	cout<<"\n Value assigned to inner : "<<TempObj.GetContained().Get();

}
