#include <iostream>
using namespace std;
class Compound
{
    int Principal;
    float years, rate, amount;

public:
    Compound(int p, int y, float r)
    {
        Principal = p;
        years = y;
        rate = r;
        amount = Principal;
        for (int i = 0; i < y; i++)
        {
            amount = amount * (1 + rate);
        }
    }
    void display(){
            cout<<"Your initial money was : "<<Principal
            <<" and now your money : "<<amount;
        }
    };
    int main()
    {
        Compound d(10000, 4, 0.09);
        d.display();
        return 0;
    }