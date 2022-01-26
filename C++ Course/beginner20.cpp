#include <iostream>
using namespace std;
class Shop
{
    int itemID[100];
    int itemPrice[100];
    int counter;

public:
    void incounter(void)
    {
        counter = 0;
    }
    void setInfo(void);
    void displayPrice();
};
void Shop ::setInfo(void)
{
    cout << "Enter the Item ID of item " << counter + 1 << " is : ";
    cin >> itemID[counter];
    cout << "Enter the Item Price : ";
    cin >> itemPrice[counter];
    counter++;
}
void Shop ::displayPrice(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The Price of item with Id " << itemID[i] << " is " << itemPrice[i] << endl;
    }
}

int main()
{
    Shop dukaan;
    dukaan.incounter();
    dukaan.setInfo();
    dukaan.setInfo();
    dukaan.setInfo();
    dukaan.displayPrice();
    return 0;
}