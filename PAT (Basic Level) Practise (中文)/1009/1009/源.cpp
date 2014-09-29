#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char str[81];
	int b, e;
	while (cin.getline(str, 81))
	{
		e = strlen(str) - 1;
		for (int i = strlen(str) - 1; i >= 0; --i)
		{
			if (str[i] == ' ' || i == 0)
			{
				if (i == 0)
					b = 0;
				else
					b = i + 1;
				for (int k = b; k <= e; ++k)
					cout << str[k];
				if (i != 0)
					cout << " ";
				e = i - 1;
			}
		}
		cout << endl;
	}
}