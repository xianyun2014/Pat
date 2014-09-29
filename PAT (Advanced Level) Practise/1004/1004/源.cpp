#include <iostream>
#include <map>
#include <vector>
using namespace std;
int RES[100];
int lev = 0;
map<int, vector<int>> mp;
void dfs(int id, int level)
{
	if (mp[id].empty())
		RES[level]++;
	else
	{
		vector<int>::iterator it = mp[id].begin();
		for (; it != mp[id].end(); it++)
		{
			dfs(*it, level + 1);
		}
	}
	if (level > lev)
		lev = level;
}
int main()
{
	int n, m;
	cin >> n >> m;
	int id, num, chd;
	for (int i = 0; i < m; i++)
	{
		cin >> id >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> chd;
			mp[id].push_back(chd);
		}
	}
	dfs(1, 0);
	for (int i = 0; i < lev; i++)
	{
		cout << RES[i] << " ";
	}
	cout << RES[lev] << endl;
	cin.get();
	cin.get();
	return 0;
}