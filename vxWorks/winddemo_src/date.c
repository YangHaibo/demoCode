/**************************************************************************
*
* Module:       Date.c
*
* Description:  Date handling routines. 
*
* Project:      Wind River Demonstration Program
*
*               Copyright (c) 2002 Wind River Systems, Inc.
*
****************************************************************************/
#include "stdio.h"
#include "float.h"
#include "strutils.h"

char months[12][4] = {
    "JAN","FEB","MAR",
    "APR","MAY","JUN",
    "JUL","AUG","SEP",
    "OCT","NOV","DEC"
};

typedef struct ttime {
    int year;
    char month[10];
    char *day;
    int hour;
    int minute;
    int second;
} TIME;

typedef struct division {
    float div;
    float quo;
    double result;
} DIVISION;

int index;

TIME clocker[1];
DIVISION division[1];

long send_month (char *sptr) 
{ 
    char *index = "Test" \
                  " Locals";
    if ((strcmp(sptr, index)) != 0) return 0;
    if ((strcmp(sptr, "MAR")) == 0) return 0;
    return 1;
}

char date() 
{
    TIME *full_time = (TIME *) &clocker ;
    DIVISION *ptr = (DIVISION *) &division;
    volatile long val = 0;
    index = 7;    

    val = send_month ( months[1]);

    
    full_time->year = 1996;

    strcpy (full_time->month, months[1]);

    full_time->day = "Friday";
    full_time->hour = 8;
    full_time->minute = 30;
    full_time->second = 15;

        
    ptr->quo = 12.02; 
    ptr->div = 12.45;
    ptr->result = 1.00357737;
   
    return 'A';
}

