#include<iostream>
#include<atomic>
#include<thread>
#include<time.h>

#define T_MAX 25

using namespace std;

class Lock_TNS
{
	atomic_flag isSet;
public:
	Lock_TNS()
	{
//		isSet = ATOMIC_FLAG_INIT;
	}
	~Lock_TNS()
	{
	}

	void lock()
	{
		while(isSet.test_and_set());
	}

	void unlock()
	{
		isSet.clear();
	}
};

int n;
Lock_TNS l;
FILE* fp;

void printNext()
{
	while(1)
	{
		l.lock();
		++n;
		//int n2 = n;
		if(n > 1000)
		{
			l.unlock();
			break;
		}
		//l.unlock();
		//l.lock();
		//printf("\n%d",n2);
		//fflush(stdout);
		fprintf(fp,"\n%d,",n);
		fflush(fp);
		l.unlock();
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
		pThreads[i] = new thread(printNext);
	}

	for(int i = 0; i < T_MAX; i++)
	{
		pThreads[i]->join();
		delete(pThreads[i]);
	}

	e = clock();

	printf("\ns = %d, e = %d, Time taken = %f",s,e,((float)(e - s))/CLOCKS_PER_SEC);
	fclose(fp);

	return 0;
}

