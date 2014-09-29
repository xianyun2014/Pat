#include <stdio.h>
#define MAX 0x7fffffff
int map[500][500];
int team_num[500];
int city_num;
int dis[500];
int meet_team[500];
char visit[500];
int npath[500];
int extern_min()
{
	int min = MAX;
	int result = -1;
	for (int i = 0; i < city_num; i++)
	{
		if (!visit[i] && dis[i] < min)
		{
			result = i;
			min = dis[i];
		}
	}
	return result;
}
void dijkstra(int s, int e)
{
	for (int i = 0; i < city_num; i++)
		dis[i] = MAX;
	
	dis[s] = 0;
	npath[s] = 1;
	meet_team[s] = team_num[s];
	while (1)
	{
		s = extern_min();
		if (-1 == s || s == e)
		{
			return;
		}
		else
		{
			visit[s] = 1;
			for (int j = 0; j < city_num; j++)
			{
				if (visit[j] || map[s][j] == 0)
					continue;
				if (dis[j] > dis[s] + map[s][j])
				{
					dis[j] = dis[s] + map[s][j];
					npath[j] = npath[s];
					meet_team[j] = meet_team[s] + team_num[j];
				}
				else if (dis[j] == dis[s] + map[s][j])
				{
					npath[j] += npath[s];
					if (meet_team[j] < meet_team[s] + team_num[j])
						meet_team[j] = meet_team[s] + team_num[j];
				}
			}
		}
	}
}
int main()
{
	int iroad, s, e;
	int i, k, j, m;
	scanf("%d%d%d%d", &city_num, &iroad, &s, &e);
	for (i = 0; i < city_num; i++)
		scanf("%d", &team_num[i]);
	for (k = 0; k < city_num; k++)
	{
		for (j = 0; j < city_num; j++)
			map[k][j] = 0;
	}
	for (i = 0; i < iroad; i++)
	{
		scanf("%d%d%d", &k, &j, &m);
		map[k][j] = map[j][k] = m;
	}
	dijkstra(s, e);
	printf("%d %d\n", npath[e], meet_team[e]);
	scanf("%*d");
	return 0;
}