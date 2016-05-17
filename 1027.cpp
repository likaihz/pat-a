#include <iostream>
#include <string>

using namespace std;

string convert(int dec)
{
	char nset[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	string res("");
	do {
		res=nset[dec%13]+res;
		dec /= 13;
	}while(dec!=0);
	
	if(res.length()==1)
		res = '0' + res;
	return res;
	
}
int main()
{
	int R_10, G_10, B_10;
	cin >> R_10 >> G_10 >> B_10;
	cout<<'#'<<convert(R_10)<<convert(G_10)<<convert(B_10)<<endl;

}
