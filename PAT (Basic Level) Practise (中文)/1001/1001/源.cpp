#include <iostream>
using namespace std;

int main()
{
	int n, i;
	while (cin >>n)
	{
		i = 0;
		while (n != 1)
		{
			if (n % 2)
				n = (3 * n + 1) >> 1;
			else
				n /= 2;
			++i;
		}
		cout << i << endl;
	}
}