#include <iostream>
using namespace std;
class Student
{
protected:
    int roll_number;

public:
    void set_roll_number(int r)
    {
        roll_number = r;
    }
    void get_roll_number()
    {
        cout << "The roll number is : " << roll_number << endl;
    }
};
class Exam : public Student
{
protected:
    int physics;
    int maths;

public:
    void set_marks(int p, int m)
    {
        physics = p;
        maths = m;
    }
    void get_marks()
    {
        cout << "Your marks in physics is :" << physics << endl;
        cout << "Your marks in maths is :" << maths << endl;
    }
};
class Result : public Exam
{
protected:
    int percentage;

public:
    void set_percentage()
    {
        percentage = (physics + maths) / 2;
    }
    void get_percentage()
    {
        cout << "Your percentage in this exam  was : " << percentage << "%" << endl;
    }
};
int main()
{
    Result keshu;
    keshu.set_roll_number(16);
    keshu.get_roll_number();
    keshu.set_marks(99, 95);
    keshu.get_marks();
    keshu.set_percentage();
    keshu.get_percentage();
    return 0;
}