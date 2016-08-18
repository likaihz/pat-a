#include<cstdio>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

class Time{
public:
    int hour, minute, second;
    bool earlierThan(Time &t);
    Time(string s);
};
Time::Time(string s)
{
    stringstream ss;
    string tmp(s.substr(0, 2));
    ss << tmp;
    ss >> hour;
    tmp = s.substr(3,2);
    ss.clear(); ss << tmp; ss >> minute;
    tmp = s.substr(6,2);
    ss.clear(); ss << tmp; ss >> second;
}
bool Time::earlierThan(Time& t)
{
    if(hour != t.hour)
        return hour < t.hour;
    else if(minute != t.minute)
        return minute < t.minute;
    else
        return second < t.second;
}
class Info{
public:
    string ID_number;
    Time Sign_in_time, Sign_out_time;
    Info(string id, string t1, string t2):ID_number(id), Sign_in_time(t1), Sign_out_time(t2) {};
};

int main()
{
    int M;
    string id, time1, time2;
    cin >> M;
    cin >> id >> time1 >> time2;
    Info earliest(id, time1, time2), latest(id, time1, time2);
    for(int i = 1; i < M; i++)
    {
        cin >> id >> time1 >> time2;
        Info tmp(id, time1, time2);
        if(tmp.Sign_in_time.earlierThan(earliest.Sign_in_time))
            earliest = tmp;
        if(latest.Sign_out_time.earlierThan(tmp.Sign_out_time))
            latest = tmp;
    }
    cout << earliest.ID_number << ' '<< latest.ID_number<<endl;
    return 0;
}
