#include<iostream>
#include<sstream>

using namespace std;

int main()
{
    int K;
    int in[55];
    string res[55];
    string tmp[55];
    for(int i = 1; i <= 13; i++){
        stringstream ss;
        ss << 'S' << i;
        ss >> res[i];
    }
    for(int i = 1; i <= 13; i++) {
        stringstream ss;
        ss << 'H' << i;
        ss >> res[i+13]; 
    }
    for(int i = 1; i <= 13; i++){
        stringstream ss;
        ss << 'C' << i;
        ss >> res[i+26];
    }
    for(int i = 1; i <= 13; i++){
        stringstream ss;
        ss << 'D' << i;
        ss >> res[i+39];
    }
    res[53] = "J1"; res[54] = "J2";
    
    cin >> K;
    for(int i=1; i < 55; i++) cin >> in[i];
    
    for(int i = 0; i < K; i++)
    {
        for(int j = 1; j < 55; j++)
            tmp[in[j]] = res[j];

        for(int j = 1; j < 55; j++)
            res[j] = tmp[j];
    }

    cout << res[1];
    for(int i = 2; i < 55; i++)
        cout << ' ' << res[i];
    
    cout <<endl;
}
