#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

class Stu{
public:
    string ID;
    int C, M, E, A;
    int C_rank, M_rank, E_rank, A_rank;
    Stu(string i, int c, int m, int e): ID(i), C(c), M(m), E(e){
        A = (C+M+E)/3;
    };
    int theBestRank();
    char theBestSub();
};
int Stu::theBestRank()
{
    int bst = E_rank;
    if(bst >= M_rank) bst = M_rank;
    if(bst >= C_rank) bst = C_rank;
    if(bst >= A_rank) bst = A_rank;
    return bst;
    
}
char Stu::theBestSub()
{
    int bst = E_rank;
    char sub = 'E';
    if(bst >= M_rank) {bst = M_rank; sub = 'M';}
    if(bst >= C_rank) {bst = C_rank; sub = 'C';}
    if(bst >= A_rank) {bst = A_rank; sub = 'A';}
    return sub;
}
bool cmpC(Stu& a, Stu& b) { return a.C > b.C; }
bool cmpM(Stu& a, Stu& b) { return a.M > b.M; }
bool cmpE(Stu& a, Stu& b) { return a.E > b.E; }
bool cmpA(Stu& a, Stu& b) { return a.A > b.A; }
int main()
{
    int N;    //total number
    int M;    //the number of students who would check their ranks
    vector<Stu> vec;
    vector<string> checkVec;

    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        string id;
        int c, m, e;
        cin >> id >> c >> m >> e;
        Stu stu(id, c, m, e);
        vec.push_back(stu);
    }
    sort(vec.begin(), vec.end(), cmpC);
    int rank = 1, cnt = 1;
    vec.begin() -> C_rank = rank;
    for(auto it = vec.begin()+1; it != vec.end(); it++){
        cnt++;
        if(it -> C != (it-1) -> C) rank = cnt;
        it -> C_rank = rank;
    }
    
    sort(vec.begin(), vec.end(), cmpM);
    rank = 1, cnt = 1;
    vec.begin() -> M_rank = rank;
    for(auto it = vec.begin()+1; it != vec.end(); it++){
        cnt++;
        if(it -> M != (it-1) -> M) rank = cnt;
        it -> M_rank = rank;
    }
    
    sort(vec.begin(), vec.end(), cmpE);
    rank = 1, cnt = 1;
    vec.begin() -> E_rank = rank;
    for(auto it = vec.begin()+1; it != vec.end(); it++){
        cnt++;
        if(it -> E != (it-1) -> E) rank = cnt;
        it -> E_rank = rank;
    }
    
    sort(vec.begin(), vec.end(), cmpA);
    rank = 1, cnt = 1;
    vec.begin() -> A_rank =rank;
    for(auto it = vec.begin()+1; it != vec.end(); it++){
        cnt++;
        if(it -> A != (it-1) -> A) rank = cnt;
        it -> A_rank = (rank++);
    }
    
    for(int i = 0; i < M; i++)
    {
        string tmp;
        cin >> tmp;
        checkVec.push_back(tmp);
    }
    for(int i = 0; i < M; i++)
    {
        bool found = false;
        string id = checkVec[i];
        for(auto it = vec.begin(); it != vec.end(); it++)
            if(it -> ID == id)
            {
                cout << it -> theBestRank() << ' ' << it -> theBestSub() << endl;
                found = true;
                break;
            }
        if(!found) cout << "N/A" << endl;
    }
}
