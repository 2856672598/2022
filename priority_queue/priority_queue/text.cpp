#include "priority_queue.h"

void text1()
{
	//wkn::priority_queue<int>pq;
	wkn::priority_queue<int, vector<int>, greater<int>>pq;
	pq.push(10);
	pq.push(2);
	pq.push(34);
	pq.push(12);
	pq.push(6);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
}

void text2()
{
	vector<int>nums{ 1,5,3,89,23,0,4 };
	wkn::priority_queue<int>pq(nums.begin(), nums.end());
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
}
int main()
{
	text1();
	//text2();
	return 0;
}