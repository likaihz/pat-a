#include<iostream>
#include<string>
using namespace std;

int main()
{
    int k;
    cin >> k;
    string out, stucked(""), not_stucked(""), res("");
    cin >> out;
    for(auto it = out.begin(); it != out.end(); it++)
    {
        int flag = 1;
        for(int i = 0; i < k; i++)
        {
            if(it+i == out.end() || *it != *(it + i)){
                flag = 0;
                break;
            }
        }
        if(flag == 0 && not_stucked.find(*it) == string::npos)
            not_stucked += *it;
        else if (flag == 1){
            if(stucked.find(*it) == string::npos)
                stucked += *it;
            it += (k-1);
        }

    }

    for(auto it = stucked.begin(); it != stucked.end(); it++)
        if(not_stucked.find(*it) == string::npos){
            cout << *it;
            res += *it;}
    cout << endl;
    for(auto it = out.begin(); it != out.end(); it++)
    {
        if(res.find(*it) != string::npos) it += (k-1);
        cout << *it;
    }
    cout << endl;
    return 0;
}
