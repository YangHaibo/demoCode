/* dynamicCast2.cpp */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,3March04,pp	 written.
*/

/*
DESCRIPTION
This program shows the use of dynamic casts.

With the dynamic_cast() operator, a program can determine at runtime 
which of the several known derived types a base-class reference or pointer 
refers to. This feature is very often used to make some runtime decisions
during program execution. This feature can also be used to implement virtual
functions in a hierarchy.

For example, in a class hierarchy in this program ( class C derived from clas B,
class B derived from Class A) it is quite possible that a derived B object has
 the unique requirement of interface f1()
 
Such a requirement is not shared by all derived  A objects. Therefore, it seems to
 be a good idea to avoid  the virtual function f1() in the base A class.
 Instead, by applying dynamic_cast(), a A class pointer can be cast to a 
B pointer, and the function f1() can be invoked. 


If the object is not a B or of a class derived from B,
 the cast returns a 0 value, and the program can decide not 
to call the function f1().

 
*/




#include <stdio.h>

/* Declaration of Class A */

class A 
{
public:
    virtual void show()
    {/*...*/}

};

/* Declaration of Class B */

class B:public A
{
public:
    virtual void f1()
    {
        printf(" class B function ");
    }
};


/* Declaration of Class C */
class C:public B
{
/*...*/
};




void f(A* pw)
{
    B* pd=dynamic_cast<B*>(pw);

    if (pd)
        pd->f1();
    else
	printf("unwanted object type ");
}


/*test routine

The function f() is invoked three times. In the first invocation,
the pointer pw points to an object of type A. In this case, because pw does not
 actually point to a B or a class derived from B, dynamic_cast() fails and returns 0.

In the second and the third invocations of f(), however, pw actually points to a
B and a C (respectively). In these cases, dynamic_cast()
succeeds, and the program invokes the virtual function f1().


*/

int tdfeTestCase35Execute()
{
    f(new A);
    f(new B);
    f(new C);

    return 0;

}


