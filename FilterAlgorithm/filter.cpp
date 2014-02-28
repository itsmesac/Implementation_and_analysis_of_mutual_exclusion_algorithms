#include"filter.h"
#include<iostream>
#include<thread>
#include<string.h>
#include<unistd.h>
using namespace std;

Lock_Filter::Lock_Filter()
{
	cThreads = 0;

	memset(levels,0,sizeof(int) * MAX);
	memset(victims,0,sizeof(int) * MAX);
}

Lock_Filter::~Lock_Filter()
{
}

void Lock_Filter::lock(int me)
{
	//printf("\nlock(%d),tid=%u",me,this_thread::get_id());
	for(int l = 1; l < MAX; l++)
	{
		levels[me] = l;
		victims[l] = me;

		while(1)
		{
			int k = 0;
			int loop = 0;
			for(k = 0; k < MAX; k++)
			{
				if(k == me)
				{
					continue;
				}

				if((levels[k] >= l) &&
					(victims[l] == me))
				{
					loop = 1;
					break;
				}
				else
				{
					loop = 0;
				}
			}
			
			if(k == MAX)
				break;

			if(loop)
			{
				while((levels[k] >= l) && 
					(victims[l] == me));
				loop = 0;
			}
		}

	}
}

void Lock_Filter::unlock(int me)
{
	//printf("\nunlock(%d),tid=%u",me,this_thread::get_id());
	levels[me] = 0;
}

