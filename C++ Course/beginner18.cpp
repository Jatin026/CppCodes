#include<iostream>
#include<string>
using namespace std;
class College{
    private:
        int rank;
    public:
        string Branch;
        string hobby;
        void setdata(int x);
        void getdata(){
            cout<<"The value of rank  is "<<rank<<endl;
            cout<<"The value of hobby  is "<<hobby<<endl;
            cout<<"The value of Branch  is "<<Branch<<endl;
        }

};
void College :: setdata(int x){
    rank=x;
}
int main(){
    College suresh;
    suresh.setdata(463);
    suresh.Branch=("CS");
    suresh.hobby=("Chess"); 
    suresh.getdata();
    return 0;
}
