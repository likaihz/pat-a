#include<cstdio>
using namespace std;

int main()
{
    int N;
    double sum = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        double x;
        scanf("%lf", &x);
        sum += x * (i+1) * (N-i);
    }
    // cout << sum << endl;
    printf("%.2f\n", sum);
    return 0;
}
