#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long strtol(string &str, long long rdx)
{
	long long re = 0;
	long long n = 1;
	char ch;
	int t;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		ch = str[i];
		if (ch <= '9')
			t = ch - '0';
		else
			t = ch - 'a' + 10;
		re += t * n;
		n *= rdx;
	}
	return re;
}
int cmp(string str, long long rdx, long long n1)
{
	long long sum = 0;
	long long n = 1;
	char ch;
	int t;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		ch = str[i];
		if (ch <= '9')
			t = ch - '0';
		else
			t = ch - 'a' + 10;
		sum += t * n;
		n *= rdx;
		if (sum > n1)
			return 1;
	}
	if (sum < n1)
		return -1;
	else if (sum > n1)
		return 1;
	else
		return 0;
}
long long binarysearch(string str, long long min, long long max, long long n)
{
	long long mid = min;
	while (min <= max)
	{
		int i = cmp(str, mid, n);
		if (i == 0)
			return mid;
		else if (i == 1)
			max = mid - 1;
		else
			min = mid + 1;
		mid = (min + max) / 2;
	}
	return -1;
}
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	long long i, radix;
	cin >> i >> radix;
	if (i == 2)
	{
		str1.swap(str2);
	}
	long long n1 = strtol(str1, radix);

	if (n1 == 1 && str2 == "1") //这两条奇葩的条件！！
	{
		cout << "2" << endl;
		return 0;
	}
	else if (str1 == str2)
	{ 
		cout << radix << endl;
		return 0;
	}

	char crds = *max_element(str2.begin(), str2.end());
	int redx;
	if (crds <= '9')
		redx = crds - '0' + 1;
	else
		redx = crds - 'a' + 10 + 1;
	int dx = (redx > n1) ? redx : n1 ;
	i = binarysearch(str2, redx, dx, n1);
	if (i == -1)
		cout << "Impossible" << endl;
	else
		cout << i << endl;
	return 0;
}