#include <iostream>
using namespace std;
class Shop
{
    float price;
    string name;

public:
    void setData(string s, float p)
    {
        name = s;
        price = p;
    }
    void getData()
    {
        cout << "The Name of item is : " << name << endl;
        cout << "The Price of item is : " << price << endl;
    }
};

int main()
{
    Shop *ptr = new Shop[3];
    for (int i = 0; i < 3; i++)
    {
        string s;
        float p;
        cin >> s;
        cin >> p;
        (ptr + i)->setData(s, p);
    }
    for (int i = 0; i < 3; i++)
    {
        (ptr + i)->getData();
    }
    return 0;
}