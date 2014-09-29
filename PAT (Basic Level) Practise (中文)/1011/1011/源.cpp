#include <iostream>
using namespace std;
int main()
{
	long a, b, c;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a >> b >> c;
		cout << "Case #" << i << ": ";
		if (a + b > c)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
}