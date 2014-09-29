#include <stdio.h>
int main()
{
	int a, b;
	char arr[30], flag;
	arr[29] = '\0';
	while (scanf("%d%d", &a, &b) != EOF)
	{
		int k = 29;
		int s = a + b, t = 0;
		flag = 0;
		if (s < 0)
		{
			flag = 1;
			s *= -1;
		}
		if (s == 0)
			arr[--k] = '0';
		while (s)
		{
			arr[--k] =  '0' + s % 10;
			if (++t == 3)
			{
				t = 0;
				if (s >= 10)
					arr[--k] = ',';
			}
			s /= 10;
		}
		if (flag)
			arr[--k] = '-';
		printf("%s\n", arr + k);
	}
	return 0;
}