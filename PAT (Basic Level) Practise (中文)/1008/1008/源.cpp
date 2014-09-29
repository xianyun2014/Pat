#include <iostream>
using namespace std;
int main()
{
	int n, m;
	int arr[101];
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; ++i)
			cin >> arr[i];
		m = m % n;
		for (int k = 1; k < n; ++k)
			cout << arr[(k + n - m - 1) % n + 1] <<" ";
		cout << arr[(n + n - m - 1) % n + 1] << endl;
	}
}