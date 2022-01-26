#include<iostream>
#include<vector>
using namespace std;
long int index_find( int arr[],long int element,long int size){
    long int index;
    for (int i = 0; i < size; i++)
    {
        if(element<=arr[i]){
            index=i+1;
            break;
        }
    }
    return index;
}
 
int main(){
    long int npile;
    cin>>npile;
    vector<int> v;
    long long ele,sum=0;
    for (int i = 0; i < npile; i++)
    {
        cin>>ele;
        sum+=ele;
        v.push_back(sum);
    }
    long int n;
    cin>>n;
    int index_arr[n];
    for (int i = 0; i < n ; i++)
    {
        cin>>ele;
        index_arr[i]=lower_bound(v.begin(),v.end(),ele)-v.begin()+1;
    }
    for (int i = 0; i < n ; i++)
    {
        cout<<index_arr[i]<<endl;
    }
    return 0;
}