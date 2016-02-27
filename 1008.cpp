#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int pre = 0, now = 0;
	int time = 0;
	for(int i = 0; i < n; i++)
	{
		pre = now;
		cin >> now;
		int diff = now - pre;
		time += ((diff > 0)?6:-4) * diff;
	}
	time += n * 5;
	cout << time << endl;
	return 0;
}
