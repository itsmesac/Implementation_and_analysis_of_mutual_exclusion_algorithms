#include<iostream>
#include<atomic>
#include<thread>

#define T_MAX 25

using namespace std;

class Lock_CAS
{
	atomic<bool> l;
public:
	Lock_CAS()
	{
		l = false;
	}
	~Lock_CAS()
	{
	}

	void lock()
	{
		while(1)
		{
			bool flag = false;
			if(l.compare_exchange_strong(flag,true))
				break;		
		}
	}

	void unlock()
	{
		l = false;
	}
};

int n;
Lock_CAS l;
FILE* fp;

void printNext()
{
	while(1)
	{
		l.lock();
		++n;
		//int n2 = n;
		if(n > 10000)
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
	thread* pThreads[T_MAX];

	fp = fopen("out.txt","a+");

	for(int i = 0; i < T_MAX; i++)
	{
		pThreads[i] = new thread(printNext);
	}

	for(int i = 0; i < T_MAX; i++)
	{
		pThreads[i]->join();
		delete(pThreads[i]);
	}

	fclose(fp);

	return 0;
}

