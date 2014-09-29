#include <stdio.h>
#include <memory.h>
char map[1000][1000];
char vis[1000];

void dfs(int a, int N)
{
	vis[a] = 1;
	for (int i = 1; i <= N; ++i)
	{
		if (0 == vis[i] && map[a][i])
			dfs(i, N);
	}
}
int main()
{
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	int a, b, i;
	for (i = 1; i <= M; ++i)
	{
		scanf("%d%d", &a, &b);
		map[a][b] = map[b][a] = 1;
	}
	for (i = 0; i < K; ++i)
	{
		scanf("%d", &a);
		
		memset(vis, 0, sizeof(vis));
		vis[a] = 1;
		b = 0;
		for (int j = 1; j <= N; ++j)
		{
			if (0 == vis[j])
			{
				dfs(j, N);
				++b;
			}
		}
		printf("%d\n", b-1);
	}
	return 0;
}