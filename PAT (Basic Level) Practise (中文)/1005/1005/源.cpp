#include <iostream>
using namespace std;
bool over(int a, int b)
{
	while (a != 1)
	{
		
		if (a % 2)
			a = (a * 3 + 1) / 2;
		else
			a /= 2;
		if (a == b)
			return true;
	}
	return false;
}
int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int n, size, has = 0;
	int arr[101];
	while (cin >> n)
	{
		size = n;
		while (n--)
		{
			cin >> arr[n];
		}
		qsort(arr, size, sizeof(int), cmp);
		for (int i = size - 1; i >= 0; --i)
		{
			bool s = 1;
			for (int k = 0; k < size; ++k)
			{
				if (k != i && over(arr[k], arr[i]))
				{
					s = 0;
					break;
				}
			}
			
			if (s)
			{
				if (!has)
					has = 1;
				else
					cout << " ";
				cout << arr[i];
			}	
		}
		cout << endl;
	}
}