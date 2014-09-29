#include <stdio.h>
#include <math.h>
int is_prime(int n) //素数判断
{
	if (1 == n)
		return 0;
	int end = sqrt((double)n);
	for (int i = 2; i <= end; ++i)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}
int re(int a, int radix) //按radix进制反转
{
	int arr[20], loc = 0, s = 0, base = 1;
	while (a)
	{
		arr[loc++] = a % radix;
		a /= radix;
	}
	while (loc--)
	{
		s += arr[loc] * base;
		base *= radix;
	}
	return s;
}
int main()
{
	int a, b;
	while (scanf("%d", &a) && a > 0)
	{
		scanf("%d", &b);
		if (is_prime(a) && is_prime(re(a, b)))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}