#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, float> m1, m2, m3;
	int k, n;
	float a;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n >> a;
		m1[n] = a;
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n >> a;
		m2[n] = a;
	}
	for (map<int, float>::iterator it1 = m1.begin(); it1 != m1.end(); it1++)
	{
		for (map<int, float>::iterator it2 = m2.begin(); it2 != m2.end(); it2++)
		{
			m3[it1->first + it2->first] += it1->second * it2->second;
		}
	}
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(1);
	for (map<int, float>::iterator it = m3.begin(); it != m3.end(); it++)
	{
		if (it->second == 0.0f)
			m3.erase(it);
	}
	cout << m3.size();
	for (map<int, float>::reverse_iterator it = m3.rbegin(); it != m3.rend(); it++)
	{
			cout <<" "<< it->first << " " << it->second;
	}
	cout << endl;
	return 0;
}
