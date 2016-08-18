#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int N, pos=1;
    bool end=false;
    vector<string> vec;
    string tmp, res("");
    cin >> N;
    getline(cin, tmp);
    for(int i = 0; i < N; i++)
    {
        getline(cin, tmp);
        vec.push_back(tmp);
    }
    while(!end){
        char c = *((vec.begin() -> end())-pos);
        for(auto it = vec.begin(); it != vec.end(); it++)
        {
            if(*((it -> end())-pos) != c || pos > it -> length()) {
                end = true;
                break;
            }
        }
        if(!end)
            res = c+res, pos++;
    }
    if(res.empty()) cout << "nai" << endl;
    else cout << res << endl;
    return 0;
}
