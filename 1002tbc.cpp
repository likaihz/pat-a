#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<pair<int, double> > vec[3];
    int k;
    int exp;
    double coe;
    for(int j = 0; j < 2; j++){
        cin >> k;
        for(int i = 0; i < k; i++){
            cin >> exp >> coe;
            vec[j].push_back(make_pair(exp, coe));
        }
    }
    auto end0 = vec[0].end(), end1 = vec[1].end();
    for(auto it0 = vec[0].begin(), it1 = vec[1].begin(); it0 != end0 || it1 != end1;){
        if(it0 == end0) vec[2].push_back(*(it1++));
        else if(it1 == end1) vec[2].push_back(*(it0++));
        else if(it0 -> first == it1 -> first)
        {
            vec[2].push_back(make_pair(it0 -> first, it0->second + it1->second));
            it0++; it1++;
        }
        else if(it0 -> first > it1 -> first)
        {
            vec[2].push_back(make_pair(it0 -> first, it0 -> second));
            it0 ++;
        }
        else
        {
            vec[2].push_back(make_pair(it1 -> first, it1 -> second));
            it1++;
        }
    }
    cout << vec[2].size();
    for(auto it = vec[2].begin(); it!=vec[2].end(); it++)
    {
        // cout << ' ' << it -> first << ' ' << it -> second;
        printf(" %d %.1f", it->first, it->second);
    }
    cout << endl;
    
    return 0;
}



