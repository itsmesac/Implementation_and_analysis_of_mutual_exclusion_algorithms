#define MAX 30

#include<thread>

class Lock_Filter
{
private:
	std::thread::id tids[MAX];
	int cThreads;
	int levels[MAX];
	int victims[MAX];
public:

	Lock_Filter();
	~Lock_Filter();

	void lock(int me);
	void unlock(int me);


	int put_me(std::thread::id myId);
	int get_me(std::thread::id myId);
};
