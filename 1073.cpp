#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    char sign = getchar();
    char c;
    string num("");
    int exp;
    num += getchar();
    getchar();
    while((c = getchar()) != 'E')
        num += c;
    scanf("%d", &exp);
    int len = num.length();
    // cout << num << ' ' << exp;
    if(exp < 0)
    {
        if(sign == '-') cout << sign;
        cout << "0.";
        for(int i = 0; i < -exp-1; i++)
            cout << '0';
        cout << num << endl;
    }
    else if(exp >0){
        if(sign == '-') cout << sign;
        if(exp < num.length()-1){
            cout << num.substr(0, exp+1) << '.' << num.substr(exp+1, num.length()-exp) << endl;}
        else{
            cout << num;
            for(int i = 0; i < exp-len+1; i++)
                cout << '0';
            cout << endl;
        }
    }
    else{
        if(sign == '-') cout << sign;
        cout << num[0] << '.' << num.substr(1, len-1) << endl;
    }
    return 0;
}
