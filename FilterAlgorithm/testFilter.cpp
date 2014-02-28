#include<iostream>
#include<thread>
#include"filter.h"
#include<time.h>

using namespace std;

#define T_MAX 25

FILE* fp;
int n;

Lock_Filter l;

void printNext(int i)
{
	while(1)
	{
		l.lock(i);
		++n;
		//int n2 = n;
		if(n > 1000)
		{
			l.unlock(i);
			break;
		}
		//l.unlock(i);
		//l.lock(i);
		//printf("\n%d",n2);
		//fflush(stdout);
		fprintf(fp,"\n%d,",n);
		fflush(fp);
		l.unlock(i);
	}
}

int main()
{
	clock_t s,e;

	thread* pThreads[T_MAX];

	fp = fopen("out.txt","a+");

	s = clock();

	for(int i = 0; i < T_MAX; i++)
	{
		pThreads[i] = new thread(printNext,i);
	}

	for(int i = 0; i < T_MAX; i++)
	{
		pThreads[i]->join();
		delete(pThreads[i]);
	}

	e = clock();

	printf("\ne = %d, s = %d, Time taken = %f",e,s,((float)(e - s)) / CLOCKS_PER_SEC);
	fclose(fp);

	return 0;
}
