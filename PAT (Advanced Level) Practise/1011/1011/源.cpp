#include <iostream>
using namespace std;
int main()
{
	double w[3], t[3], l[3];
	while (cin >> w[0] >> t[0] >> l[0] && !cin.eof())
	{
		cin >> w[1] >> t[1] >> l[1];
		cin >> w[2] >> t[2] >> l[2];
		double sum = 1;
		for (int i = 0; i < 3; i++)
		{
			char ch = 'W';
			if (w[i] < t[i])
				ch = 'T';
			if (l[i] > t[i])
				ch = 'L';
			if (l[i] < w[i])
				ch = 'W';
			switch (ch)
			{
			case 'W':
				sum *= w[i];
				break;
			case 'T':
				sum *= t[i];
				break;
			case 'L':
				sum *= l[i];
				break;
			}
			cout << ch << " ";
		}
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.precision(2);
		sum *= 0.65;
		sum -= 1.0;
		sum *= 2.0;
		cout << (float)sum << endl;
	}
}