/* includes */

#include <vxWorks.h>
#include <semaphore.h>

 

/* forward declarations */
void syncTask (sem_t * pSem);

 

void unnameSem (void)
	{
	sem_t * pSem;

 

	/* reserve memory for semaphore */
	pSem = (sem_t *) malloc (sizeof (sem_t));

 

	/* initialize semaphore to unavailable */
	if (sem_init (pSem, 0, 0) == -1)
		{
		printf ("unnameSem: sem_init failed\n");  
		free ((char *) pSem);
		return;
		}

 

	/* create sync task */
	printf ("unnameSem: spawning task...\n");
	taskSpawn ("tSyncTask", 90, 0, 2000, syncTask, pSem);

 

	/* do something useful to synchronize with syncTask */

	/* unlock sem */
	printf ("unnameSem: posting semaphore - synchronizing action\n");
	if (sem_post (pSem) == -1)
		{
		printf ("unnameSem: posting semaphore failed\n");
		sem_destroy (pSem);
		free ((char *) pSem);
		return;
		}

 

	/* all done - destroy semaphore */
	if (sem_destroy (pSem) == -1)
	  {
	  printf ("unnameSem: sem_destroy failed\n");
	  return;
	  }
	free ((char *) pSem);
	}

 

void syncTask
	(
	sem_t * pSem
	)
	{
	/* wait for synchronization from unnameSem */
	if (sem_wait (pSem) == -1)
		{
		printf ("syncTask: sem_wait failed \n");
		return;
		}
	else
		printf ("syncTask:sem locked; doing sync'ed action...\n");

	/* do something useful here */
	}
