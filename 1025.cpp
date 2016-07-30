#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;


class Student {
public:
    char RegNum[14];
    int Score;
    int Loc;
    int LocRank;

    Student(char r[], int s, int l, int lr) {
        strcpy(RegNum, r);
        Score = s;
        Loc = l; LocRank = lr;
    }
};

bool cmp(Student &a, Student &b){
    if(a.Score != b.Score) return a.Score > b.Score;
    else return strcmp(a.RegNum, b.RegNum)<0;
}

int main()
{
    int N;
    vector<Student> vec;
    cin >> N;
    
    for(int i = 0; i < N; ++i)
    {
        vector<Student> tmp;
        int K;
        cin >> K;

        for(int j = 0; j < K; j++)
        {
            char reg[14];
            int scr;
            cin >> reg >> scr;
            Student stu(reg, scr, i+1, 1);
            tmp.push_back(stu);
        }
        sort(tmp.begin(), tmp.end(), cmp);
        vec.push_back(*tmp.begin());
        int cnt = 2;
        for(auto it = tmp.begin()+1; it != tmp.end(); it++, cnt++)
        {
            if(it -> Score ==  (it-1) -> Score)
                it -> LocRank = (it - 1) -> LocRank;
            else it -> LocRank =  cnt;
            vec.push_back(*it);
        }
    }

    sort(vec.begin(), vec.end(), cmp);
    cout << vec.size() << endl;
    int cnt = 1, rank = 1;
    cout << (vec.begin()) -> RegNum << ' ' <<  rank << ' ' << (vec.begin()) -> Loc << ' '<< (vec.begin()) -> LocRank << endl;

    cnt++;
    for(auto it = vec.begin()+1; it != vec.end(); it++, cnt++)
    {
        if(it -> Score !=  (it-1) -> Score)
            rank = cnt;
        cout << it -> RegNum << ' ' << rank << ' ' << it -> Loc << ' ' << it-> LocRank << endl;
    }
    return 0;
}

