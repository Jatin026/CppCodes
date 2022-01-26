#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person{
    protected:
        int age;
        string name;
    public:
        virtual void getdata()=0;
        virtual void putdata()=0;
};
class Professor: public Person{
    int publications;
    static int cur_id;
    public:
        // Professor(){
        //     cur_id+=1;
        // }
        void getdata(){
            int p;
            int a;
            string n;
            cin>>n>>a>>p;
            publications=p;
            name=n;
            age=a;}
        void putdata(){
            cur_id+=1;
            cout<<name<<" "<<age<<" "<<publications<<" "<<cur_id<<endl;
        }
};
int Professor::cur_id=0;
class Student:public Person{
    int marks[6];
    static int cur_id;
    int sum;
    public:
        // Student(){
        //     cur_id+=1; 
        // }
        void getdata(){
                
                int a;
                string n;
                cin>>n>>a;
                for(int i=0; i<6;i++){
                    cin>>marks[i];
                    sum+=marks[i];
                } 
                name=n;
                age=a;
                }
            void putdata(){
                cur_id+=1;
                cout<<name<<" "<<age<<" "<<sum<<" "<<cur_id<<endl;
            }
};
int Student :: cur_id=0;
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
