#include<iostream>
using namespace std;
class CWH{
    protected:
        float rating;
        string title;
    public:
        CWH(string t,float r){
            rating=r;
            title=t;
        }
        virtual void display()=0;//Example of a pure virtual function.
};
class CWHVideo:public CWH{
    float vlength;
    public:
        CWHVideo(string t, float l,float r):CWH(t,r){
            vlength=l;
        };
        void display(){
            cout<<"The name of the tutorial is : "<<title<<endl
            <<"The length of the video is : "<<vlength<<endl
            <<"The Rating of the Tutorial is : "<<rating<<endl;
        }
};
class CWHText:public CWH{
    long words;
    public:
        CWHText(string t, long w, float r):CWH(t,r){
            words=w;
        };
        void display(){
            cout<<"The name of the tutorial is : "<<title<<endl
            <<"The length of the tutorial in words  is : "<<words<<endl
            <<"The Rating of the Tutorial is : "<<rating<<endl;
        }
};
int main(){
    CWH* ptr[2];
    CWHVideo c("C++ Tutorial Video",40.37,4.67);
    CWHText d("C++ Tutorial Text",14252345,4.67);
    ptr[0]=&c;
    ptr[1]=&d;
    ptr[0]->display();
    ptr[1]->display();

    return 0;
}