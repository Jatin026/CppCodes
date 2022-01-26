
#include<iostream>
#include<climits>
#include<cfloat>
using namespace std;

int main()
{
	cout << "Size of char : " << sizeof(char)
	<< " byte" <<" Range of char is : "<<SCHAR_MIN <<" to "<<SCHAR_MAX<<endl;
    cout << "Size of int : " << sizeof(int)
	<< " byte" <<" Range of INT is : "<<INT_MIN <<" to "<<INT_MAX<<endl;
    cout << "Size of Unsigned INT : " << sizeof(char)
	<< " byte" <<" Range of Unsigned INT is : "<<0<<" to "<<UINT_MAX<<endl;
    cout << "Size of Unsigned char : " << sizeof(char)
	<< " byte" <<" Range of Unsigned Char is : "<<0<<" to "<<UCHAR_MAX<<endl;
    cout << "Size of FLOAT : " << sizeof(float)
	<< " byte" <<" Range of FLOAT is : "<<FLT_MIN<<" to "<<FLT_MAX<< endl <<endl;
    cout << "Size of long int : " << sizeof(long int)
       << " bytes" <<" Range of long int is : "<<LONG_MIN<<" to "<<LONG_MAX<< endl;
    cout << "Size of Unsigned long int : " << sizeof(signed long int)
       << " bytes" <<" Range of Unsigned long int is : "<<0<<" to "<<ULONG_MAX<< endl;
     
    cout << "Size of double : " << sizeof(double)
       << " bytes" <<" Range of double is : "<<DBL_MIN<<" to "<<DBL_MAX<< endl;  
    cout << "Size of Long double : " << sizeof(long double)
       << " bytes"<<" Range of double is : "<<LDBL_MIN<<" to "<<LDBL_MAX<< endl;   
	return 0;
}
