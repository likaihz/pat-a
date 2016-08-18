#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

string LOW[13] = {"", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string HIGH[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main()
{
    int N;
    vector<string> vec;
    string tmp;
    cin >> N;
    getline(cin, tmp);
    for(int i = 0; i < N; i++)
    {
        getline(cin, tmp);
        vec.push_back(tmp);
    }
    for(int i = 0; i < N; i++)
    {
        stringstream ss;
        if(vec[i].at(0) >= '0' && vec[i].at(0) <= '9')
        {
            int t;
            ss << vec[i];
            ss >> t;
            if(t == 0) cout << "tret" << endl;
            else {
                cout << HIGH[t/13];
                if(t/13 != 0 && t%13 != 0)
                    cout << ' ' ;
                cout << LOW[t%13] << endl;;}
        }
        else{
            int h = 0, l = 0, pos = 0;
            if(vec[i] == "tret"){
                cout << '0' <<endl;
                continue;
            }
            for(int j = 1; j < 13; j++)
                if(vec[i].substr(0, 3) == HIGH[j].substr(0, 3)){
                    h = j;
                    pos = 4;
                }
            if(h > 0 && vec[i].length() > 3 || h == 0)
                for(int j = 1; j < 13; j++)
                {
                    if(vec[i].substr(pos, 3) == LOW[j])
                        l = j;
                }
            cout << h*13+l << endl;
        }
    }
    return 0;
}
