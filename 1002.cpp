#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int k[2];
    vector<pair<int, double> > vec[2];
    vector<pair<int, double> > res;
    for(int i = 0; i < 2; i++)
    {
        cin >> k[i];
        for(int j = 0; j < k[i]; j++)
        {
            int exp;
            double coe;
            cin >> exp >> coe;
            vec[i].push_back(make_pair(exp, coe));
        }
    }
    auto it0 = vec[0].begin(), it1 = vec[1].begin();
    auto end0 = vec[0].end(), end1 = vec[1].end();
    while(it0 != end0 || it1 != end1)
    {
        if(it0 == end0) res.push_back(*(it1++));
        else if(it1 == end1) res.push_back(*(it0++));
        else if(it0 -> first == it1 -> first)
            res.push_back(make_pair(it0 -> first, (it0++) -> second + (it1++) -> second));
        else if(it0 -> first > it1 -> first)
            res.push_back(*(it0++));
        else if(it0 -> first < it1 -> first)
            res.push_back(*(it1++));
    }

    cout << res.size();
    for(auto it = res.begin(); it != res.end(); it++)
    {
        if(it -> second != 0)
            printf(" %d %.1f", it -> first, it -> second);
    }

    cout << endl;
    return 0;
}
