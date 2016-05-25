#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int height, width;
	height = (str.length() + 2) / 3;
	width =  str.length() - height * 2 + 2;
	//cout << height << ' ' << width << endl;
	auto head = str.begin(), rear = str.end()-1;
	for(int i =0; i < height-1; i++){
		cout<< *head;
		for(int j=0; j < width-2; j++) cout << ' ' ;
		cout << *rear<< endl;
		head++, rear--;
	}
	for(int i=0; i < width; i++, head++) cout << *head;
	cout <<endl;
}
