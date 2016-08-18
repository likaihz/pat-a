#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

bool isLegal(string s){
	int pos = 0;
	if(s[pos] == '-' /*s[pos] == '+'*/) pos++;
	if(pos == s.length()) return false;
	int dotcnt = 0;
	for(int i = pos; i < s.length(); i++){
		if(s[i] == '.'){
			dotcnt++;
			if(dotcnt > 1) return false;
			if(s.length() - i - 1 > 2) return false;
		}
		else if(s[i] < '0' || s[i] > '9')
			return false;
	}
	double d;
	sscanf(s.c_str(), "%lf", &d);
	if(d > 1000.0 || d < -1000.0) return false;
	else return true;
}

int main(){
	int n;
	cin>>n;
	double sum = 0.0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		string s;
		cin>>s;
		if(isLegal(s)){
			double d;
			sscanf(s.c_str(), "%lf", &d);
			cnt++;
			sum += d;
		}else{
			cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
		}
	}

	if(cnt == 0){
		cout<<"The average of 0 numbers is Undefined"<<endl;
	}else if(cnt == 1)
		cout<<"The average of 1 number is "
		<<fixed<<setprecision(2)<<sum<<endl;
	else
		cout<<"The average of "<<cnt<<" numbers is "
		<<fixed<<setprecision(2)<<sum / cnt<<endl;
	
	return 0;
}
