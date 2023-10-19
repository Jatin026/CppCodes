#include<bits/stdc++.h>
using namespace std;
class People{
    public:
        virtual ~People(){
            puts("Destructor People");
        }
        virtual void react() = 0;
        
};
class Citizen : public People{
    public:
        ~Citizen(){
            puts("Destructor Citizen");
        }
        void react(){
            puts("Cit");
        }
};
class Police : public Citizen{
    public:
        ~Police(){
            puts("Destructor Police");
        }
        void react(){
            puts("Shoot");
        }
};
void stimulus(People *p){
    p->react();
}

int main(){
    // People *p = new People;
    People *c = new Citizen;
    Police *p = new Police;
    stimulus(c);stimulus(p);
    delete c; delete p;
    return 0;
}