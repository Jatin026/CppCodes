#include <iostream>
using namespace std;
class complex
{
    int a;
    int b;
    friend complex sum(complex o1, complex o2);//Individual friend making.

public:
    void getcomplex(int c1, int c2)
    {
        a = c1;
        b = c2;
    }
    void complexsum(complex o1, complex o2)
    {
        a = o1.a + o2.a;
        b = o1.b + o2.b;
    }
    void displaycomplex()
    {
        cout << "The complex number are : " << a << "+" << b << "i" << endl;
    }
};
//Use of friend function--> it is not a memmber of the class but it can access 
//the private information in it.
complex sum(complex o1, complex o2)
{
    complex o4;
    //For example of 6 , writing cout<<a ( Show up an error)because whose a it is not mentoined.
    o4.getcomplex((o1.a + o2.a), (o1.b + o2.b));//Example of Property 6.
    return o4;
}
int main()
{
    complex o1, o2, o3, o5;
    o1.getcomplex(1, 2);
    o1.displaycomplex();
    o2.getcomplex(3, 4);
    o2.displaycomplex();
    o3.complexsum(o1, o2);
    o3.displaycomplex();
    o5 = sum(o1, o2);
    o5.displaycomplex();
    return 0;
}
/*Properties of Friend Function
1. Not in scope of the class
2. As it is not in the scope of the class , the object of class can not call it.(Example--> o5.sum()==Invalid )
3. Can be invoked without the help of any object.
4. Usually contains objects as arguments("Example --> sum (o1,o2) ")
5. Can be declared in public or private section of the class.
6.To access members of the class , syntax: objectname.membername.
*/