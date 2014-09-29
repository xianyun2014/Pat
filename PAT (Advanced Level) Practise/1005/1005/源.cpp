#include <iostream>
#include <stack>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	char *str[10] = { "zero", "one", "two", "three", "four", "five",
		"six", "seven", "eight", "nine" };
	unsigned int sum = 0;
	char ch[101];
	cin >> ch;
	for (int i = 0; ch[i] != '\0'; i++)
	{
		sum += ch[i] - '0';
	}
	stack<int> res;
	if (sum == 0)
		res.push(0);
	while (sum)
	{
		res.push(sum % 10);
		sum /= 10;
	}
	cout << str[res.top()];
	res.pop();
	while (!res.empty())
	{
		cout << " " << str[res.top()];
		res.pop();
	}
	cout << endl;
	cin.get();
	cin.get();
	return 0;
}