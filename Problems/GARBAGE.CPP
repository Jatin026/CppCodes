#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
bool find8(string s){
    for(int i=0;i<s.size();i++){
        if((s[i])=='8'){
            return 1;
}
        
    }
    return 0;
}
int main(){
     int floor;
     cin>>floor;
     int temp=floor;
     if(floor<=0){
         cout<<8-floor;
     }
     else{
        temp++;
        string s=to_string(temp);
        while(find8(s)!=1){
            temp =stoi(s);
            temp++;
            s=to_string(temp);
        }
        cout<<(temp-floor);         
     }
    
    return 0;
}