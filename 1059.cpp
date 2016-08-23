#include<cmath>
#include<iostream>
#include<vector>

using namespace std;

class Factor{
public:
    int p, k;
    Factor(int a, int b):p(a), k(b) {};
};
bool isPrime(long int x)
{
    if(x == 1) return false;
    int max = sqrt(x)+1;
    for(int i = 2; i < max; i++)
        if(x%i == 0)
            return false;
    return true;
}
int main()
{
    vector<Factor> vec;
    long int num;
    cin >> num;
    long int buf = num,  max = sqrt(num)+1;
 
    if(isPrime(num) || num == 1) cout << num << '=' << num << endl;
    else {
        for(int i = 2; i < max && buf != 1; i++)
        {
            long int cnt = 0;
            while(buf % i == 0)
            {
                buf /= i;
                cnt++;
            }
            if(cnt != 0)
            {
                Factor fac(i, cnt);
                vec.push_back(fac);
            }
        }
        if(buf != 1){
            Factor fac(buf, 1);
            vec.push_back(fac);
        }
        cout << num << '=';
        cout << vec.begin() -> p;
        if(vec.begin() -> k != 1) cout << '^' << vec.begin() -> k;
        for(auto it = vec.begin()+1; it != vec.end(); it++)
        {
            cout << '*';
            cout << it -> p;
            if(it -> k != 1) cout << '^' << it -> k;
        }
        cout << endl;       
    }
    return 0;
}
