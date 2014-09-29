#include <iostream>
using namespace std;

int main()
{
	int perm[100000];
	int p = 0, s;
	for (int i = 2; i < 100000; ++i)
	{
		s = 1;
		for (int j = 2; j*j <= i; ++j)
		{
			if (i % j == 0)
			{
				s = 0;
				break;
			}	
		}
		if (s)
			perm[++p] = i;
	}

	int n, size;
	while (cin >> n)
	{
		size = 0;
		for (int k = 1; n >= perm[k + 1]; ++k)
		{
			if (perm[k] + 2 == perm[k + 1])
				++size;
		}
		cout << size << endl;
	}
	
	cin.get();
	return 0;

}
