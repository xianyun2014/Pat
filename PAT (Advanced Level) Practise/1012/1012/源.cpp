#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
class CJ
{
public:
	int c, m, e, a;
	int cp, mp, ep, ap;
	CJ(){
		cp = mp = ep = ap = 0;
	}
};

int main()
{
	map<string, CJ> mp;
	map<int, string> mpb;
	int n, m;
	while (!cin.eof() && cin >> n >> m)
	{
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			CJ cj;
			cin >> cj.c >> cj.m >> cj.e;
			cj.a = (cj.c + cj.m + cj.e) / 3;
			mp[str] = cj;
		}
		for (int j = 0; j < m; ++j)
		{
			string str;
			cin >> str;
			mpb[j] = str;
		}
		for (map<string, CJ>::iterator ipi = mp.begin();
			ipi != mp.end(); ipi++)
		{
			for (map<string, CJ>::iterator ipj = ipi;
				ipj != mp.end(); ipj++)
			{
				if (ipi == ipj)
					continue;
				if (ipi->second.c < ipj->second.c)
					ipi->second.cp++;
				else if (ipi->second.c > ipj->second.c)
					ipj->second.cp++;
				if (ipi->second.m < ipj->second.m)
					ipi->second.mp++;
				else if (ipi->second.m > ipj->second.m)
					ipj->second.mp++;
				if (ipi->second.e < ipj->second.e)
					ipi->second.ep++;
				else if (ipi->second.e > ipj->second.e)
					ipj->second.ep++;
				if (ipi->second.a < ipj->second.a)
					ipi->second.ap++;
				else if (ipi->second.a > ipj->second.a)
					ipj->second.ap++;
			}
		}
		for (map<int, string>::iterator ip = mpb.begin();
			ip != mpb.end(); ip++)
		{
			if (mp.find(ip->second) != mp.end())
			{
				int arr[4] = { mp[ip->second].ap, mp[ip->second].cp, mp[ip->second].mp, mp[ip->second].ep };
				int max = 0;
				for (int i = 1; i < 4; i++)
				{
					if (arr[i] < arr[max])
						max = i;
				}
				cout << arr[max] + 1 << " ";
				char ch;
				switch (max)
				{
				case 0:
					ch = 'A';
					break;
				case 1:
					ch = 'C';
					break;
				case 2:
					ch = 'M';
					break;
				case 3:
					ch = 'E';
				}
				cout << ch << endl;
			}
			else
				cout << "N/A" << endl;
		}
	}
	cin.get();
	cin.get();
	return 0;
}