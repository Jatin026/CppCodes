#include <iostream>
using namespace std;
class Employee
{
    static int count;
    int ID;
    int Salary;

public:
    void setInfo()
    {
        cout << "Enter the value of ID : ";
        cin >> ID;
        cout << "Enter the value of Salary : ";
        cin >> Salary;
        count++;
    };
    void display()
    {
        cout << "The ID of person " << count  << " is " << ID << " His salary is " << Salary<<endl;
    }
    static void getcount()
    {
        cout<<count;//Static Function can only access static members, variables
    };
};
int Employee::count;

int main()
{
    Employee Suresh, Ramesh, Shyam;
    Suresh.setInfo();
    Suresh.display();
    Ramesh.setInfo();
    Ramesh.display();
    Shyam.setInfo();
    Shyam.display();
    Employee::getcount();

    return 0;
}