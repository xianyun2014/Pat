#include <iostream>
using namespace std;

int main()
{
	int n, sn, size;
	while (cin >> n)
	{
		sn = size = 0;
		while (n)
		{
			sn = sn * 10 + n % 10;
			n /= 10;
			++size;
		}
		while (size)
		{
			n = sn % 10;
			sn /= 10;
			for (int i = 0; i < n; ++i)
			{
				if (size == 3)
					cout << "B";
				else if (size == 2)
					cout << "S";
				else
					cout << i + 1;
			}
			--size;
		}
		cout << endl;
	}
}