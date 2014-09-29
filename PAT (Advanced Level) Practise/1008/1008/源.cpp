#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int t = 0, f;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		f = t;
		cin >> t;
		if (t - f > 0)
			sum += 6 * (t - f);
		else if (t - f < 0)
			sum += 4 * (f - t);
		sum += 5;
	}
	cout << sum << endl;
	return 0;
}