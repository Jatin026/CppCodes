#include<iostream>
#include<string>
using namespace std;

double CGPA(){
    int i,c,sum=0,n,t=0;
    cout<<"Enter the number of subjects"<<endl;
    cin>>n;
    for(i=1;i<=n;i++){
        string s;
        c=0;
        cout<<"Enter the number of credits of a subject"<<endl;
        cin>>c;
        cout<<"Enter the grade in that subject choosing from A+,A,B+,B,C,D and F"<<endl;
        cin.ignore();
        getline(cin,s);
        if(s=="A+") sum+=c*10;
        if(s=="A") sum= sum+ c*9;
        if(s=="B+") sum= sum+ c*8;
        if(s=="B")sum= sum+ c*7;
        if(s=="C") sum= sum+ c*6;
        if(s=="D") sum= sum+ c*5;
        if(s=="F") sum= sum+ c*0;

        t=t+c;
    }
    return (sum/t);
}
int main(){
    double CG = CGPA();
    cout<<CG;
}