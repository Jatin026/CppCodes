#include<iostream>
using namespace std;
class BankDeposit{
    int Principal;
    int years;
    float interest,amount;
    public:
        BankDeposit(int p,int y , float r){
            Principal=p;
            years=y;
            interest=r;
            amount=Principal*(1+interest*years);
        }
        void display(){
            cout<<"Your initial money was : "<<Principal
            <<" and now your money : "<<amount;
        }
};
int main(){
    BankDeposit d(10000,4,0.09);
    d.display();
    return 0;
}