#include <stdio.h>

int main()
{
	int  k, i, r;
	char check[1001];
	float arr[1001], tmp;
	while (scanf("%d", &i) != EOF)
	{
		for (r = 0; r < 1001; ++r)
			check[r] = arr[r] = 0;
		for (; i > 0; --i)
		{
			scanf("%d", &k);
			scanf("%f", &arr[k]);
			check[k] = 1;
		}
		scanf("%d", &i);
		for (; i > 0; --i)
		{
			scanf("%d", &k);
			scanf("%f", &tmp);
			if (check[k])
				arr[k] += tmp;
			else
				arr[k] = tmp;
			check[k] = 1;
		}
		i = 0;
		for (r = 0; r < 1001; r++)
		{
			if (check[r] && arr[r] != 0)
				i++;
		}
		printf("%d", i);
		if (i)
			printf(" ");
		for (r = 1000; r >= 0; r--)
		{
			if (check[r] && arr[r] != 0)
			{
				printf("%d %.1f", r, arr[r]);
				if (--i)
					printf(" ");
			}
		}
		printf("\n");
	}
	
}