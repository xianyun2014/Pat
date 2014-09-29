#include <iostream>
using namespace std;
int main()
{
	int n, t, flat;
	int a[6], a4;
	while (cin >> n)
	{
		for (int k = 1; k <= 5; ++k)
			a[k] = 0;
		a4 = 0;
		flat = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> t;
			switch (t % 5)
			{
			case 0:
				if (t % 2 == 0)
					a[1] += t;
				break;
			case 1:
				if (flat == 0)
				{
					a[2] = t;
					flat = -1;
				}
				else if (flat == -1)
				{
					a[2] -= t;
					flat = 1;
				}
				else if (flat == 1)
				{
					a[2] += t;
					flat = -1;
				}
				break;
			case 2:
				++a[3];
				break;
			case 3:
				a[4] += t;
				a4++;
				break;
			case 4:
				if (t > a[5])
					a[5] = t;
			}
		}
		if (a[1])
			cout << a[1] << " ";
		else
			cout << "N ";
		if (flat != 0)
			cout << a[2] << " ";
		else
			cout << "N ";
		if (a[3])
			cout << a[3] << " ";
		else
			cout << "N ";
		if (a[4])
		{
			cout.setf(ios_base::fixed, ios_base::floatfield);
			cout.precision(1);
			cout << a[4] * 1.0 / a4 << " ";
		}
		else
			cout << "N ";
		if (a[5])
			cout << a[5];
		else
			cout << "N";
	}
}