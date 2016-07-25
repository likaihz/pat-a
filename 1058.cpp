#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
	long a[3];
	long b[3];
	scanf("%ld.%ld.%ld",&a[0],&a[1],&a[2]);
	scanf("%ld.%ld.%ld",&b[0],&b[1],&b[2]);
	int tmp;
	tmp=a[2]+b[2];
	if(tmp>=29){
		a[2]=tmp-29;
		a[1]++;
	}
	else
		a[2]=tmp;
	tmp=a[1]+b[1];
	if(tmp>=17){
		a[1]=tmp-17;
		a[0]++;
	}
	else
		a[1]=tmp;
	a[0]+=b[0];
	int i=0;
	cout<<a[0]<<"."<<a[1]<<"."<<a[2]<<endl;
	return 0;
}

