#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<int, string> mp;
	string str;
	int n;
	scanf("%d", &n);
	int a, b, c;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		scanf("%d:%d:%d", &a, &b, &c);
		mp[a * 10000 + b * 100 + c] = str;
		scanf("%d:%d:%d", &a, &b, &c);
		mp[a * 10000 + b * 100 + c] = str;
	}
	cout << mp.begin()->second << " " << (--mp.end())->second << endl;
	return 0;
}