/* 
 * This example sets the O_NONBLOCK flag and examines message queue
 * attributes.
 */

/* includes */
#include <vxWorks.h>
#include <mqueue.h>
#include <fcntl.h>
#include <errno.h>
#include<stdio.h>

 

/* defines */
#define MSG_SIZE    16

 

int attrEx
	(
	char * name
	)
	{
	mqd_t           mqPXId;            /* mq descriptor */
	struct mq_attr  attr;              /* queue attribute structure */
	struct mq_attr  oldAttr;           /* old queue attributes */
	char            buffer[MSG_SIZE];
	int             prio;

 

	/* create read write queue that is blocking */

	attr.mq_flags = 0;
	attr.mq_maxmsg = 1;
	attr.mq_msgsize = 16;
	if ((mqPXId = mq_open (name, O_CREAT | O_RDWR , 0, &attr)) 
		== (mqd_t) -1)
		return (ERROR);
	else
		printf ("mq_open with non-block succeeded\n");

 

	/* change attributes on queue - turn on non-blocking */

	attr.mq_flags = O_NONBLOCK; 
	if (mq_setattr (mqPXId, &attr, &oldAttr) == -1)
		return (ERROR);
	else
		{
		/* paranoia check - oldAttr should not include non-blocking. */
		if (oldAttr.mq_flags & O_NONBLOCK) 
			return (ERROR);
		else
			printf ("mq_setattr turning on non-blocking succeeded\n");
		}

 

	/* try receiving - there are no messages but this shouldn't block */

	if (mq_receive (mqPXId, buffer, MSG_SIZE, &prio) == -1)
		{
		if (errno != EAGAIN)
			return (ERROR);
		else
			printf ("mq_receive with non-blocking didn't block on empty queue\n");
		}
	else
		return (ERROR);

 

	/* use mq_getattr to verify success */

	if (mq_getattr (mqPXId, &oldAttr) == -1)
		return (ERROR);
	else
		{
		/* test that we got the values we think we should */
		if (!(oldAttr.mq_flags & O_NONBLOCK) || (oldAttr.mq_curmsgs != 0))
			return (ERROR);
		else
		    
			printf ("queue attributes are:\n\tblocking is %s\n\t message size is: %d\n\t max messages in queue: %d\n\t no. of current msgs in queue: %d\n",	oldAttr.mq_flags & O_NONBLOCK ? "on" : "off",oldAttr.mq_msgsize, oldAttr.mq_maxmsg,oldAttr.mq_curmsgs);
			}

 

	/* clean up - close and unlink mq */

	if (mq_unlink (name) == -1)
		return (ERROR);
	if (mq_close (mqPXId) == -1)
		return (ERROR);
	return (OK);
	}

