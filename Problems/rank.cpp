#include<iostream>
using namespace std;

int main(){
    int t,N,M;
    cin>>t;
    while(t--){
        int n;
        cin>>N>>M;
        int college_rank[N+1];
        int colleges[N+1]={0};
        int college_choice[M+1][N+1];
        int rank_student[M+1];
        for (int i = 1; i < N+1; i++)
        {
            cin>>college_rank[i];
        }
        for (int i = 1; i < M+1; i++)
        {
            cin>>rank_student[i];
        }
        for (int i = 1; i < M+1; i++)
        {
            cin>>n;
            for (int j = 1; j < n+1; j++)
        {
            cin>>college_choice[i][j];
        }
        }
        if(rank_student[1]>N){
            cout<<0<<endl;
        }
        else{
            cout<<college_rank[rank_student[1]]<<endl;
        }
    }
    return 0;
}