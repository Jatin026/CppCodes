#include <iostream>
using namespace std;
class Employee
{
    int id;
    int salary;

public:
    void setID()
    {
        cout << "Enter the id : ";
        cin >> id;
        cout << "Enter the Salary : ";
        cin >> salary;
    }
    void getID()
    {
        cout << "The id of the person is : " << id << " and salary is " << salary << endl;
    }
};
int main()
{
    Employee shop[3];
    for (int i = 0; i < 3; i++)
    {
        shop[i].setID();
        shop[i].getID();
    }

    return 0;
}