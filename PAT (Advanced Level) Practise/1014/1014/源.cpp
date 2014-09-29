#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <queue>
using namespace std;
struct tagque
{
	int que_time, loc;
};
tagque tque;
queue<tagque> que[21];
int process_time[1001];//ÿ���ͻ���ʱ��
int que_time[21];//ÿ�����е�ǰʱ��
int final_time[1001];//ÿ���ͻ��뿪ʱ��
int N, M, K, Q;
int que_op() //Ѱ��һ�����ҵ���뿪����
{
	int i, min = 1;
	while (min < N && que[min].empty())
		++min;
	for (i = min + 1; i <= N; ++i)
	{
		if (que[i].size() > 0 && que[i].front().que_time + que_time[i] < que[min].front().que_time + que_time[min])
		{
			min = i;
		}
	}
	if (que[min].empty())
	{
		return false;
	}
	else
	{
		tque = que[min].front();
		que[min].pop();
		final_time[tque.loc] = que_time[min] + tque.que_time;
		que_time[min] += tque.que_time;
		return true;
	}
}
void insert(int val, int loc)//����һ���ͻ�������loc
{
	int i;
	int min = 1;
	for (i = 2; i <= N; ++i)
	{
		if (que[i].size() < M && que[i].size() < que[min].size())
			min = i;
	}

	if (1 == min && que[1].size() == M) //δ�ҵ�����λ���ٴ���һ��
	{
		que_op();
		insert(val, loc);
	}
	else
	{
		tque.que_time = val;
		tque.loc = loc;
		que[min].push(tque);
	}
}
int main()
{
	//freopen("d:\\1.txt", "r", stdin);
	memset(final_time, 0, sizeof(final_time));

	scanf("%d%d%d%d", &N, &M, &K, &Q);
	int i, val;
	for (i = 1; i <= N; ++i)
	{
		que_time[i] = 8 * 60;
	}
	for (i = 1; i <= K; ++i)
	{
		scanf("%d", &val);
		process_time[i] = val;
		insert(val, i);
	}
	while (que_op()) //������������
		continue;
	for (i = 1; i <= Q; ++i)
	{
		scanf("%d", &val);
		if (final_time[val] - process_time[val] >= 1020) //17*60 = 1020,17��00֮��ʼ�Ĳ�Sorry����ʼ������
			printf("Sorry\n");
		else
			printf("%02d:%02d\n", final_time[val] / 60, final_time[val] % 60);
	}
	return 0;
}