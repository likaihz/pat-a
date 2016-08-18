#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<char, int> shop;
    char c;
    int shortage = 0, need = 0, supply = 0;
    
    while((c = getchar()) != '\n')
    {
        supply++;
        if(shop.find(c) == shop.end())
            shop[c] = 1;
        else shop[c] = shop[c] + 1;
    }
    while((c = getchar()) != '\n')
    {
        need++;
        if(shop.find(c) == shop.end())
            shortage ++;
        else if(shop[c] == 0) shortage++;
        else shop[c] = shop[c] - 1;
    }
    if(shortage == 0)
        cout << "Yes " << supply - need << endl;
    else
        cout << "No " << shortage << endl;
}
