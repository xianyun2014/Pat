#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, t, s = 0, e, mx = 0, tmx = 0, ts, te; 
	cin >> n;
	vector<int> vec;
	bool flag = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		if (t>=0) flag = 1;
		if (mx >= 0)
		{
			mx += t;
			e = i;
		}
		else
		{
			mx = t;
			s = e = i;
		}
		if (mx > tmx || (mx == 0 && tmx == 0))
		{
			tmx = mx; 
			ts = s;
			te = e;
		}
		vec.push_back(t);
	}
	if (flag)
	{
		cout << tmx << " " << vec[ts] << " " << vec[te] << endl;
	}
	else
		cout << "0 " << vec[0] << " " << vec[vec.size() - 1] << endl;
	cin.get();
	cin.get();
	return 0;
}