#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int hs[256] ={0};
    char cs[10001];
    gets(cs);
    string st = cs;
    char c;
    while ((c = getchar()) != '\n') 
        hs[c] = 1;

    for (int i=0; i<st.size(); i++) {
        if (hs[st[i]] == 0)
            printf("%c", st[i]);
    }

    return 0;
}
