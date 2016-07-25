#include<iostream>
#include<cstdio>

using namespace std;

string DAY[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
    string s1, s2, s3, s4;
    int day = -1, hour = -1, min = -1;
    cin >> s1 >> s2 >> s3 >> s4;
    for(auto it1 = s1.begin(), it2 = s2.begin(); it1 != s1.end() && it2 != s2.end(); it1++, it2++){
        if(*it1 == *it2) {   
            if(day < 0  && *it1 >= 'A' && *it1 <= 'G')
                day = *it1 - 'A' ;
            else if(day >= 0 && ((*it1 >= 'A' && *it1 <= 'N') ||( *it1 >= '0' && *it1 <= '9')))
            {
                if(*it1 >= '0' && *it1 <= '9')
                    hour = *it1 - '0' ;
                else hour = *it1 - 'A'+ 10;
            }
        }

        if(day >= 0 && hour >= 0) break;
    }

    for(int it3 = 0, it4 = 0; it3 != s3.length() && it4 != s4.length(); it3++, it4++){
        if(s3.at(it3) == s4.at(it4) && ((s3.at(it3) >= 'a' && s3.at(it3) <= 'z')|| (s3.at(it3) >= 'A' && s3.at(it3) <= 'Z')))
            min = it3;

        if(min >= 0) break;
    }

    printf("%s %02d:%02d\n",DAY[day].c_str(), hour, min);
    return 0;
}
