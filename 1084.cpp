#include<iostream>
#include<string>

using namespace std;


int main()
{
    string in, out;
    string lostkey="";

    cin >> in >> out;
    auto iit = in.begin();
    auto oit = out.begin();
    while(iit != in.end())
    {
        if(*iit == *oit) oit++;
        else{
            char buf;
            if(*iit >= 'a' && *iit <= 'z')
                buf = 'A' + (*iit - 'a');
            else buf = *iit;

            if(lostkey.find(buf, 0) == string::npos)
                lostkey = lostkey + buf;
            
        }
        iit++;
    }

    cout << lostkey << endl;
}
