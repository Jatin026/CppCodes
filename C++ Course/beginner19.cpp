#include <iostream>
#include <string>
using namespace std;
class binary
{
private:
    string bina;
    void chk_bin(void);
public:
    void read(void);
    void ones_compliment(void);
    void display(void);
};
void binary ::read()
{
    cout << "Enter the binary number you want to input : ";
    cin >> bina;
}
void binary ::chk_bin()
{
    for (int i = 0; i < bina.length(); i++)
    {
        /* code */
        if (bina.at(i) != '1' && bina.at(i) != '0')
        {
            cout << "Please enter a valid binary number";
            exit(0);
        }
    }
}
void binary ::ones_compliment(void)
{
    chk_bin(); //function nesting
    for (int i = 0; i < bina.length(); i++)
    {
        if (bina.at(i) == '1')
        {
            bina.at(i) = '0';
        }
        else
        {
            bina.at(i) = '1';
        }
    }
}
void binary ::display()
{
    cout << "Displaying your binary number : ";
    for (int i = 0; i < bina.length(); i++)
    {
        cout << bina.at(i);
    }
    cout << endl;
    //cout<<bina;(The binary number can also be printed through this)
    //cout<<endl;
}
int main()
{
    binary a;
    a.read();
    //a.chk_bin();//an error will show up , because we have declared binary checking as private , no other can use it
    a.display();
    a.ones_compliment();
    a.display();
    return 0;
}