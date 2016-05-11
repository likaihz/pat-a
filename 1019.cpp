#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int yes=1;
	int N, b;
	cin >> N >> b;
	vector<int> vec;
	
	do vec.push_back(N%b), N /= b;
	while(N != 0);
	
	if(vec.size() != 1){
		int i=-1, j=vec.size();
		while(j-i>2)
		{
			i++, j--;
			if(vec[i] != vec[j])
			{yes=0; break;}
		}
	}

	if(yes) cout << "Yes" << endl;
	else cout << "No"<< endl;

	for(int i =vec.size()-1; i > 0; i--)
		cout << vec[i] << ' ' ;

	cout << vec[0] << endl;
	
	
}
