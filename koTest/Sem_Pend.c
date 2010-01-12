#include<vxWorks.h>
#include<semLib.h>
#include<semaphore.h>
#include<taskLib.h>

int f1();
int f2();

SEM_ID sem;
int tid1,tid2;
main()
{
	sem=semBCreate(SEM_Q_PRIORITY,SEM_FULL);
	tid1=taskSpawn("task1", 100, 0, 0x4000, f1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	tid2=taskSpawn("task2", 100, 0, 0x4000, f2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	semDelete(sem);
}

int f1()
{
	semTake(sem, WAIT_FOREVER);
}

int f2()
{
	semTake(sem, WAIT_FOREVER);
}
