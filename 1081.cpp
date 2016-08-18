#include<cstdio>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Num {
public:
    long int numerator;
    long int denominator;
    Num(long int n, long int d): numerator(n), denominator(d) {
        long int com = GCD(numerator, denominator);
        numerator /= com;
        denominator /= com;
    };
    long int GCD(long int a, long int b);

    
};

long int Num::GCD(long int a, long int b)
{
    while(b != 0)
    {
        long int t = a%b;
        a = b;
        b = t;
    }
    return a;

}

    
int main()
{
    int N;
    vector<Num> vec;
    cin >> N;
    for(int i = 0; i < N; i++){
        long int n, d;
        scanf("%ld/%ld", &n, &d);
        Num t(n, d);
        vec.push_back(t);
    }
    return 0;
}
