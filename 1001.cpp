#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int sum = a+b;
	int t = abs(sum);
	stringstream buf;
	string tmp, res("");
	if(sum < 0) res += '-';
	buf << t;
	buf >> tmp;
	if(tmp.length() >3) {
		int rmd = tmp.length() %3;
		res += tmp.substr(0, rmd);
		if(rmd != 0) res += ',';
		for(int i = rmd ; i < tmp.length(); i += 3)
		{
			res += tmp.substr(i, 3);
			if(i != tmp.length()-3) res += ',';
		}
	}
	else res += tmp;

	cout << res << endl;
	return 0;
	
}
