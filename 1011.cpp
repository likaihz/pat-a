#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	char res[3] = {'W', 'T', 'L'};
	float g[3][3];
	int option[3];
	for(int i = 0; i < 3; i++) {
		double tmp = 0;
		for(int j = 0; j < 3; j++) {
			cin >> g[i][j];
			if(g[i][j] > tmp) option[i] = j, tmp = g[i][j];
		}
	}
	double max;
	max = (g[0][option[0]] * g[1][option[1]] * g[2][option[2]] * 0.65 -1.0) * 2.0;
	for(int i = 0; i < 3; i++)
		cout << res[option[i]] << ' ' ;
	///cout << max << endl;
	printf("%.2f\n", max);
	return 0;
	
}


//到现在才知道输出格式控制的时候%.2f是四舍五入的。。。。
