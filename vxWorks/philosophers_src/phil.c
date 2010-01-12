/***********************************************************************/
/**                             PHIL.C                                **/
/**                                                                   **/
/**                       (c) COPYRIGHT 1988                          **/
/**                       JAMES R. PICKERING                          **/
/**                       ALL RIGHTS RESERVED                         **/
/**                                                                   **/
/** Jim Pickering               || (n)   ..csustan!polyslo!rducky!jrp **/
/**                             || (s)   ..sdsu!polyslo!rducky!jrp    **/
/** Arroyo Grande, CA 93420     ||       jrp@rducky.UUCP              **/
/** (805) 473-1037                                                    **/
/**                                                                   **/
/**  DESCRIPTION:  This file contains a program which demonstrates    **/
/**  Dijkstra's Dining Philosophers Problem* (see "Cooperating        **/
/**   Sequential Processes," Technical Report EWD-123, Technological  **/
/**   University, Eindhoven, The Netherlands, (1965)).  It is con-    **/
/**   sidered a classic process synchronization *problem.  It is      **/
/**   implemented using SVR2 semaphores and curses.  With this as an  **/
/**   example, you may be able to figure out how to use SV semaphores.**/
/**                                                                   **/
/**   PROBLEM DESCRIPTION:  Five philosophers spend their lives       **/
/**   thinking and eating.  They share a common table.  Each has his/ **/
/**   her own chair.  At the center of the table is a bowl of rice.   **/
/**   The table is laid with five chopsticks (see figure below).  When**/
/**   a philosopher thinks, he/she (the hell with this he/she crap ...**/
/**   all philosophers referenced furthur are hermaphrodites and will **/
/**   be refered to as 'he') does not eat, and vice versa. When a     **/
/**   philosopher is hungry he tries to pick up the two chopsticks    **/
/**   that are closest to him.  He may only pick up one stick at a    **/
/**   time.  When he has both chopsticks, he eats without releasing   **/
/**   his chopsticks.  When he is finished eating, he puts down both  **/
/**   chopsticks and starts thinking.                                 **/
/**                                                                   **/
/**                        PHIL1    |    PHIL2                        **/
/**                   \                           /                   **/
/**                                                                   **/
/**                PHIL5          (rice)           PHIL3              **/
/**                                                                   **/
/**                                                                   **/
/**                     /         PHIL4        \                      **/
/**                                                                   **/
/**  COMPILE:  cc -O -s -o phil phil.c -lcurses                       **/
/***********************************************************************/
/**  FUNCTIONS:                                                       **/
/**               void clean_die()                                    **/
/**               void die()                                          **/
/**               void sleeper()                                      **/
/**               void hungry(p_num)                                  **/
/**                       int p_num;                                  **/
/**               void thinking(p_num)                                **/
/**                       int p_num;                                  **/
/**               void eating(p_num)                                  **/
/**                       int p_num;                                  **/
/**               void killit(semid,array_ptr)                        **/
/**                       int semid, *array_ptr;                      **/
/**               void cleanup()                                      **/
/**               void printit(p_num,action)                          **/
/**                       int p_num, action;                          **/
/**               bool V_semaphore(sem_num)                           **/
/**                    int sem_num;                                   **/
/**               bool P_semaphore(sem_num,block)                     **/
/**                    int sem_num;                                   **/
/**                    bool block;                                    **/
/***********************************************************************/

/*
static char philc[] = "@(#)phil1.c 1.1 JAMES R. PICKERING 3/23/88";
*/

#include <vxWorks.h>
#include <stdio.h>
#include <stdlib.h>
#include <taskLib.h>
#include <semLib.h>
#include <string.h>
#include <ioLib.h>

typedef	int	bool;

#define     NUM_CHILDREN     5     /* number of dining philosophers  */
                                   /* don't change this!!!!!!!!!!!!  */
                                   /* the display routines depend on */
                                   /* this.                          */

#define     SLEEP_TIME       10    /* maximum amount of time (minus 1)
                                      in seconds the child processes
                                      eat and think.                   */

#define     EATING           1
#define     THINKING         2
#define     HAS_ONE          3
#define     HUNGRY           4

#define	LINES	25
#define	COLS	80
#define	ESC	27

void die();
void clean_die();
void sleeper();
void hungry();
void thinking();
void eating();
void printit();
bool V_semaphore();
bool P_semaphore();
void philTask(int id);

SEM_ID  sems[NUM_CHILDREN];
static use_curse = 1;		/* set to 0 when the curse feature should not
				   be used */

isatty(int i) { return(1);}	/* XXX kludge for now -md */

int main(int argc, char * argv[])
{
	int i;

	/*****************************************************/
	/* check whether we should not use the curse feature */
	/*****************************************************/

        /* VxWorks has no curse pkg by default: so set use_curse to 0 (FALSE) */

	use_curse = 0;

	if (argc > 1)
	    {
	    use_curse = 1;

	    if (argv[1] != NULL)
		if (!strcmp (argv[1],"no_curse"))
		    use_curse = 0;
	    }

        /***********************************/
        /*get a semaphore set from the O.S.*/
        /***********************************/
        /************************************************/
        /*initialize the five semaphores in the set to 1*/
        /************************************************/

	for (i=0; i<NUM_CHILDREN; i++) {
	    if ((sems[i] = semBCreate (0, SEM_FULL)) == NULL) {
		printf("Error creating semaphore\n");
		exit(1);
	    }
	}

	if (use_curse) {
	    /* clear screen */
	    printf("%c[2J\n", ESC);
	}

        /**********************************************/
        /*fork off five *dining **philosophers* (children)*/
        /**********************************************/

	taskSpawn ("phil-1", 251, 0, 5000, (FUNCPTR)philTask, 1,
		   1, 2, 3, 4, 5, 6, 7, 8, 9);
	taskDelay(30);
	taskSpawn ("phil-2", 252, 0, 5000, (FUNCPTR)philTask, 2,
		   1, 2, 3, 4, 5, 6, 7, 8, 9);
	taskDelay(30);
	taskSpawn ("phil-3", 253, 0, 5000, (FUNCPTR)philTask, 3,
		   1, 2, 3, 4, 5, 6, 7, 8, 9);
	taskDelay(30);
	taskSpawn ("phil-4", 254, 0, 5000, (FUNCPTR)philTask, 4,
		   1, 2, 3, 4, 5, 6, 7, 8, 9);
	taskDelay(30);
	taskSpawn ("phil-5", 255, 0, 5000, (FUNCPTR)philTask, 5,
		   1, 2, 3, 4, 5, 6, 7, 8, 9);
	
	taskSuspend(0);
}

void philTask(int id)
{
    int fd;
    int seed = 0;
    char val[32];
    char *p;

    fd = open("/proc/kernel/time", O_RDONLY, 0);

    if (fd > 0) {
	read(fd, val, sizeof(val));
	for (p=val; *p != NULL; p++) {
	    if (*p == ' ') {
		p++;
		break;
	    }
	}
	seed = atoi(p);
	close (fd);
    }

#ifdef	XXX
    srand((unsigned)time((long *)0));
#endif
    srand(seed);

    /**************************************************************/
    /*philosopher (child) thinks, becomes hungry, eats, thinks ...*/
    /**************************************************************/

    while(TRUE) {
	thinking(id);
	hungry(id);
	eating(id);
    }
}


/**********************************************************************/
/**FUNCTION:  sleeper()                                              **/
/**                                                                  **/
/**DESCRIPTION:  This function randomly sleeps from 0 to             **/
/** (SLEEP_TIME-1) seconds.                                          **/
/**                                                                  **/
/**GLOBAL VARIABLES:  none                                           **/
/**                                                                  **/
/**GLOBAL CONSTANTS:  SLEEP_TIME                                     **/
/**                                                                  **/
/**CALLS:  none                                                      **/
/**                                                                  **/
/**RETURNS: none                                                     **/
/**********************************************************************/ 
void sleeper()
{
        (void)taskDelay((rand() % SLEEP_TIME) * 60);
}


/**********************************************************************/
/**FUNCTION:  hungry()                                               **/
/**                                                                  **/
/**DESCRIPTION:   This function is representative of a philosopher   **/
/** being hungry.                                                    **/
/**                                                                  **/
/**GLOBAL VARIABLES:  none                                           **/
/**                                                                  **/
/**GLOBAL CONSTANTS:  HUNGRY                                         **/
/**                                                                  **/
/**CALLS:  printit()                                                 **/
/**                                                                  **/
/**RETURNS: none                                                     **/
/**********************************************************************/ 
void hungry(p_num)
        int p_num;
{
        printit(p_num,HUNGRY);
}


/**********************************************************************/
/**FUNCTION:   thinking()                                            **/ 
/**                                                                  **/
/**DESCRIPTION:   This function is representative of a philosopher   **/
/** thinking for a random amount of time.                            **/
/**                                                                  **/
/**GLOBAL VARIABLES:  none                                           **/
/**                                                                  **/
/**GLOBAL CONSTANTS:  THINKING                                       **/
/**                                                                  **/
/**CALLS:  printit(), sleeper(),                                     **/
/**                                                                  **/
/**RETURNS: none                                                     **/
/**********************************************************************/ 
void thinking(p_num)
        int p_num;
{
        printit(p_num,THINKING);
        sleeper();
}


/**********************************************************************/
/**FUNCTION:  eating()                                               **/ 
/**                                                                  **/
/**DESCRIPTION:   This function is representative of a philosopher   **/
/** eating for a random amount of time.                              **/
/**                                                                  **/
/**GLOBAL VARIABLES:  none                                           **/
/**                                                                  **/
/**GLOBAL CONSTANTS:  NUM_CHILDREN, EATING, HAS_ONE                  **/
/**                                                                  **/
/**CALLS:  printit(), P_semaphore(), V_semaphore(), sleeper(),       **/
/**                                                                  **/
/**RETURNS: none                                                     **/
/**********************************************************************/ 
void eating(p_num)
        int p_num;
{
        int n = NUM_CHILDREN;

        if (!(p_num % 2))

        /************************************************/
        /*even philosopher--choose right chopstick first*/
        /* to prevent deadlock                          */
        /************************************************/

        {

        /******************************/
        /*P(right chopstick) operation*/
        /******************************/

                if (!P_semaphore(p_num-1,TRUE))
                {
                     exit(0);
                }
                printit(p_num,HAS_ONE);

        /*****************************/
        /*P(left chopstick) operation*/
        /*****************************/

                if (!P_semaphore(p_num%n,TRUE))
                {
                     (void)V_semaphore(p_num-1);
                     exit(0);
                }
        
        /***************************************/
        /*philosopher's critical section begins*/
        /***************************************/

                printit(p_num,EATING);
                sleeper();

        /*************************************/
        /*Philosopher's critical section ends*/
        /*************************************/


        /******************************/
        /*V(right chopstick) operation*/
        /******************************/

                if(!V_semaphore(p_num-1))
                {
                     exit(0);
                }

        /*****************************/
        /*V(left chopstick operation)*/
        /*****************************/

                if(!V_semaphore(p_num%n))
                {
                     exit(0);
                }
        }
        else

        /**********************************************/
        /*odd philosopher--choose left chopstick first*/
        /* to prevent deadlock                        */
        /**********************************************/

        {

        /*****************************/
        /*P(left chopstick operation)*/
        /*****************************/

                if (!P_semaphore(p_num%n,TRUE))
                {
                     exit(0);
                }
                printit(p_num,HAS_ONE);

        /*****************************/
        /*P(right chopstick operation*/
        /*****************************/

                if (!P_semaphore(p_num-1,TRUE))
                {
                     (void)V_semaphore(p_num%n);
                     exit(0);
                }

        /***************************************/
        /*philosopher's critical section begins*/
        /***************************************/

                printit(p_num,EATING);
                sleeper();

        /*************************************/
        /*philosopher's critical section ends*/
        /*************************************/


        /*****************************/
        /*V(left chopstick) operation*/
        /*****************************/

                if(!V_semaphore(p_num%n))
                {
                     exit(0);
                }

        /*****************************/
        /*V(right chopstick) operation*/
        /*****************************/

                if(!V_semaphore(p_num-1))
                {
                     exit(0);
                }
        }
}


/**********************************************************************/
/**FUNCTION:   printit()                                             **/ 
/**                                                                  **/
/**DESCRIPTION:  This function print the childrens' actions.         **/
/**                                                                  **/
/**GLOBAL VARIABLES:  none                                           **/
/**                                                                  **/
/**GLOBAL CONSTANTS:  EATING, THINKING, HAS_ONE, HUNGRY              **/
/**                                                                  **/
/**CALLS:  none                                                      **/
/**                                                                  **/
/**RETURNS: none                                                     **/
/**********************************************************************/ 
void printit(p_num,action)
        int p_num, action;
{
        int x, y;
        char string[128];
	int len;

        switch(action)
        {
                 case EATING : len=sprintf(string,"Philosopher %d is %c%seating%c%s...",p_num, ESC, "[7m", ESC, "[0m");
				len-=8;
                          break;
                 case THINKING : len=sprintf(string,"Philosopher %d is thinking...",p_num);
                          break;
                 case HAS_ONE : if(!(p_num % 2))
                               len=sprintf(string,"Philosopher %d is %c%shungry%c%s (left)...",p_num, ESC, "[1m", ESC, "[0m");
                          else
                               len=sprintf(string,"Philosopher %d is %c%shungry%c%s (right)...",p_num, ESC, "[1m", ESC, "[0m");
			  len-=8;
                          break;
                 case HUNGRY : len=sprintf(string,"Philosopher %d is %c%shungry%c%s...",p_num, ESC, "[1m", ESC, "[0m");
			  len-=8;
                          break;
                default : return;
        }
        switch(p_num)
        {
                 case 1:  y = 4;
			  x = 6;
                          break;
                 case 2 : y = 5;
                          x = COLS - len - 6;
                          break;
                 case 3 : y = LINES/2+1;
                          x = COLS - len - 2;
                          break;
                 case 4 : y = LINES - 2;
                          x = COLS/2 - len/2;
                          break;
                 case 5 : y = LINES/2;
                          x = 2;
                          break;
                default : return;
        }
/*
        move(0,0);
        refresh();
        move(y,0);
        clrtoeol();
        mvaddstr(y,x,string);
        refresh();
*/

	if (use_curse) {
	    /* clear to end of line */
	    printf("%c[%02d;%02dH", ESC, y, 0);
	    printf("%c[K", ESC);

	    /* print message */
	    printf("%c[%02d;%02dH", ESC, y, x);
	}
	printf("%s\n", string);
}


/*************************************************************************/
/**FUNCTION: V_semaphore()                                              **/ 
/**                                                                     **/
/**DESCRIPTION:   This function releases the named semaphore in the set.**/
/**   It is called after a process leaves its critical section which is **/
/**   associated with 'sem_num'.                                        **/
/**                                                                     **/
/**GLOBAL VARIABLES:  semid                                             **/
/**                                                                     **/
/**GLOBAL CONSTANTS:  NUM_CHILDREN                                      **/
/**                                                                     **/
/**CALLS:  cleanup()                                                    **/
/**                                                                     **/
/**RETURNS:  TRUE on success, otherwise FALSE.                          **/
/*************************************************************************/ 
bool V_semaphore(sem_num)
     int sem_num;
{

    if (sem_num > NUM_CHILDREN) {
	printf("bad semid: %d\n", sem_num);
	return (FALSE);
    } else {
	semGive(sems[sem_num]);
    }
    return (TRUE);
}


/*************************************************************************/
/**FUNCTION: P_semaphore()                                              **/ 
/**                                                                     **/
/**DESCRIPTION:   This function waits on the named semaphore in the set.**/
/**   It either blocks or not depending on 'block'.  It is called       **/
/**   before a process enters its critical section which is associated  **/
/**   with 'sem_num'.                                                   **/
/**                                                                     **/
/**GLOBAL VARIABLES:  semid                                             **/
/**                                                                     **/
/**GLOBAL CONSTANTS:  NUM_CHILDREN                                      **/
/**                                                                     **/
/**CALLS:   cleanup()                                                   **/
/**                                                                     **/
/**RETURNS:  TRUE on success, FALSE otherwise--if block; TRUE if got    **/
/** semaphore, FALSE if not or error--if !block.                        **/
/*************************************************************************/ 
bool P_semaphore(sem_num,block)
     int sem_num;
     bool block;
{
    if (sem_num > NUM_CHILDREN) {
	printf("bad semid: %d\n", sem_num);
	return (FALSE);
    } else {
	semTake(sems[sem_num], WAIT_FOREVER);
    }
    return (TRUE);
}
