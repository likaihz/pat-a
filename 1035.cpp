#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<pair<string, string> > vec;
    int M;
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int flag = 0;
        string s1, s2;
        cin >> s1 >>s2;
        // cout << s1 << s2;
        for(auto it = s2.begin(); it != s2.end(); it++)
        {
            if(*it == '1')
            { it = s2.erase(it); s2.insert(it, 1, '@'); flag = 1;}
            else if(*it == 'l')
            { it = s2.erase(it); s2.insert(it, 1, 'L'); flag = 1;}
            else if(*it == '0')
            { it = s2.erase(it); s2.insert(it, 1, '%'); flag = 1;}
            else if(*it == 'O')
            { it = s2.erase(it); s2.insert(it, 1, 'o'); flag = 1;}
        }

        if(flag == 1)
            vec.push_back(make_pair(s1, s2));
    }

    if(vec.size() >= 1) {
        cout << vec.size() << endl;
        for(auto it = vec.begin(); it != vec.end(); it++)
            cout<< it -> first << ' ' << it -> second << endl;
        }
    else if(M==1)
        cout << "There is 1 account and no account is modified"<<endl;
    else
        cout << "There are " << M << " accounts and no account is modified" <<endl;
}
