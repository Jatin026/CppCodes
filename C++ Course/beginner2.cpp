#include <iostream>
using namespace std;
int glo =7;
void sum(){
    int a;
    cout <<"Example of A global variable  \n " <<glo;
    bool is_True=true, is_False=false;
    cout<<" \nExample of Boolean Character Type \n"<< is_True<<"\n";
    cout<<"Example of Boolean Character Type \n"<<is_False;

}
int main(){
    int glo=10;
    glo=18;
    sum();
    cout<<"\n Example of Preference of Local Variable over global variable \n "<<glo;
    cout<<"\n We can also show the value of global variable by using SCOPE RESOLUTION Operator (::) : "<<glo;
    return 0;
}