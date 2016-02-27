#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	string digit[10] = {"zero", "one", "two", "three", "four", 
						"five", "six", "seven", "eight", "nine"};
	char c;
	int res = 0;
	string print = "";
	while((c = getchar()) != '\n')
	{
		int tmp = c - '0';
		res += tmp;
	}
	if(res == 0)
		cout << digit[0] <<endl;
	else {
		int flag = 0;
		while(res != 0) {
			if(flag != 0)
				print =  digit[res % 10] + ' ' + print;
			else {
				print = digit[res % 10] + print;
				flag = 1;
			}
			res /= 10;
		}
		cout <<print<<endl;
	}

	return 0;

}
