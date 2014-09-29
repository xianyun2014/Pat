#include <iostream>

using namespace std;
typedef struct
{
	char name[20];
	char id[20];
	int score;
}STUDENT;

int main()
{
	STUDENT stu[300];
	int n;
	cin >> n;
	int min = n - 1, max = n - 1;
	while (n--)
	{
		cin >> stu[n].name;
		cin >> stu[n].id;
		cin >> stu[n].score;
		if (stu[min].score > stu[n].score)
			min = n;
		if (stu[max].score < stu[n].score)
			max = n;
	}
	cout << stu[max].name << " " << stu[max].id << endl;
	cout << stu[min].name << " " << stu[min].id << endl;
	return 0;
}