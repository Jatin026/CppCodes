#include<iostream>
using namespace std;
class Student{
    protected:
        int roll_no;
    public:
        void set_rollno(int a){
            roll_no=a;
        }
        void get_rollno(){
            cout<<"The Roll number is : "<<roll_no<<endl;
        }
};
class Marks : virtual public Student{
    protected:
        int physics,maths;
    public:
        void set_marks(int m, int p){
            maths=m;
            physics=p;
        }
        void get_marks(){
            cout<<"Your marks in Maths is : "<<maths<<endl
            <<"Your marks in Physics is :"<<physics<<endl;
        }
};
class Sports : virtual public Student{
    protected:
        int score;
    public:
        void set_score(int s){
            score=s;
        }
        void get_score(){
            cout<<"Your score in PT is : "<<score<<endl;
        }    
};
class Result : public Sports,public Marks{
    int total;
    public:
        void get_total(){
            total=score+maths+physics;
            cout<<"Your total score is : "<<total<<endl;
        }
};
int main(){
    Result Shyam;
    Shyam.set_rollno(7);
    Shyam.set_marks(99,100);
    Shyam.set_score(100);
    Shyam.get_rollno();
    Shyam.get_marks();
    Shyam.get_score();
    Shyam.get_total();
    return 0;
}