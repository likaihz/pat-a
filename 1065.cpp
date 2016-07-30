#pragma warning (disable:4786)
#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int i = 0;i < T;i++)
    {
        long long int  a,b,c;
        cin>>a>>b>>c;

        cout<<"Case #"<<i+1<<": ";
        
        bool flag;
        long long ans =a+b;
        if(a>0 && b>0 && ans<=0)
            flag=true;
        else if(a<0 && b <0 && ans >= 0)
            flag=false;
        else
            flag = (ans > c);
        if(flag)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    return 0;
}
