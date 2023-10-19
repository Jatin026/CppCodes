#include <iostream>
using namespace std;

int main(){
    int y = 2;
    if(y & (y = 2)) {
        cout <<  (y = 3);
    }
    else {
        cout << "false";
    }
    // cout << y << endl;
}