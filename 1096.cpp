#include<cmath>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int LIM = sqrt(n)+1;
    vector<int> res;

    res.push_back(n);

    vector<int> loc;

    for(int i = 2; i < LIM; i++){
        int tmp = n;
        int factor = i;
        loc.clear();

        while(tmp % factor == 0) {
            loc.push_back(factor);
            tmp /= factor++;
        }

        if(loc.size() > res.size())
            res = loc;
        else if(loc.size() == res.size())
            if(loc[0] < res[0])
                res  = loc;
    }

    cout << res.size() << endl;

    bool init = true;
    for (auto & f : res)
        if (init) {
            cout << f;
            init = false;
        }
        else cout <<'*' << f;
    cout << endl;
    return 0;
}
