/*简单题。。。*/
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

bool isSame(int x)
{
    if(x%10 == x/10%10 && x%10 == x/100%10 && x%10 == x/1000)
        return true;
    return false;
}

int incOrder(int x)
{
    int d[4] = {x%10, x/10%10, x/100%10, x/1000};
    sort(d, d+4);
    return d[0]*1000 + d[1]*100 + d[2] *10 + d[3];
}

int decOrder(int x)
{
    int d[4] = {x%10, x/10%10, x/100%10, x/1000};
    sort(d, d+4);
    return d[3]*1000 + d[2]*100 + d[1] *10 + d[0];
}
int main()
{
    int N;

    cin >> N;
    if(isSame(N)) {
        printf("%04d - %04d = 0000\n", N, N);
        return 0;
    }
    N = incOrder(N);
    while(N != 6174){
        int dif = decOrder(N) - incOrder(N);
        printf("%04d - %04d = %04d\n", decOrder(N), incOrder(N), dif);
        N = dif;
    }

    return 0;
}
