#include <iostream>
using namespace std;
int main()
{
	int a, b, first = 1;;
	while (cin >> a >> b)
	{
		if (a * b != 0)
		{
			if (!first)
				cout << " ";
			else
				first = 0;
			cout << a * b << " " << b - 1;
		}
	}
	if (first)
		cout << "0 0";
	cout << endl;
}