#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	string chinese[10] = { "ling", "yi", "er", "san",
		"si", "wu", "liu", "qi", "ba", "jiu" };
	char str[101];
	int sum, i;
	while (cin >> str)
	{
		sum = 0;
		for (i = 0; i < strlen(str); ++i)
			sum += str[i] - '0';
		strcpy(str, "0");
		i = 0;
		while (sum)
		{
			str[i++] = sum % 10;
			
			sum /= 10;
		}
		for (int k = i - 1; k > 0; --k)
			cout << chinese[str[k]] << " ";
		cout << chinese[str[0]] << endl;
	}
	
	return 0;
}