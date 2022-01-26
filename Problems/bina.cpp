 #include<iostream>
 #include<bitset>
 #include<string>
 #include<vector>
 #include<algorithm>
 using namespace std;
 int main(){
    long n;
    vector<int>v;
    cin>>n;
    int count;
    string str= bitset <64> (n).to_string();
    for(int i=0; i<str.size();i++){
        if(str[i]=='1'){
            count+=1;
            if(i==(str.size()-1)){
                v.push_back(count);
            }
        }
        else{
            v.push_back(count);
            count=0;
        }
    }
    sort(v.begin(),v.end());
    cout<<v[v.size()-1]; 
    return 0;
 }