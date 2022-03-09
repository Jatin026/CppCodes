#include <iostream>
#include <cmath>
using namespace std;
bool misCap(string s){
    for (int i = s.size()-1; i >0 ; --i)
    {
        if(islower(s[i])) return 0;
    }
    return 1;
}
int main()
{
	string s;
    cin>>s;
    if(misCap(s)){
        for (int i = 0; i < s.size(); i++)
        {
            if(islower(s[i])){
                s[i]=toupper(s[i]);
            }
            else{
                s[i]=tolower(s[i]);
            }
        }
        
    }
    cout<<s;
	return 0;
}