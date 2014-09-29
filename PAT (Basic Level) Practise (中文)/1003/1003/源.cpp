#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	int n, i, j, k;
	string str;
	cin >> n;
	while (n--)
	{
		cin >> str;
		i = str.find_first_not_of('A');
		if (i == string::npos || str[i] != 'P')
		{
			cout << "NO" << endl;
			continue;
		}
		j = str.find_first_not_of('A', i + 1);
		if (j == i + 1 || j == string::npos || str[j] != 'T')
		{
			cout << "NO" << endl;
			continue;
		}
		k = str.find_first_not_of('A', j + 1);
		if (k != string::npos)
		{
			cout << "NO" << endl;
			continue;
		}
		int e = str.length() - 1 - j - i;
		if (e == i*(j - i - 2))
		{
			cout << "YES" << endl;
			continue;
		}
		else
		{
			cout << "NO" << endl;
			continue;
		}
	}
	return 0;
}


