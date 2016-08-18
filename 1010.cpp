#include<iostream>
#include<cstring>
#include<string>

using namespace std;

string SET = "0123456789abcdefghijklmnopqrstuvwxyz";
long long toDecimal(string, long long);
int main()
{
    string N1, N2;
    int tag;
    long long radix, target, low = 2, high;

    cin >> N1 >> N2 >> tag >> radix;
    if(tag == 2) swap(N1, N2);    //确保radix是N1的基
    target = toDecimal(N1, radix);
    for(auto it = N2.begin(); it != N2.end(); it++)
    {
        int tmp = SET.find(*it);
        if(tmp >= low)
            low = tmp+1;
    }    //二分查找下界

    high = target + 1;    //二分查找上界
    long long mid;
    bool flag = false;
    while(low <= high || flag)
    {
        mid = (low + high) / 2;
        long long tmp = toDecimal(N2, mid);
        if(tmp > target)
            high = mid -1;
        else if(tmp < target)
            low = mid +1;
        else flag = true;
    }
    if(flag) cout << mid << endl;
    else cout << "Impossible"  << endl;
    return 0;
}

long long toDecimal(string s, long long r)
{
    
}
