#include<iostream>
#include<vector>
using namespace std;
template<class T>
void display( vector<T> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector <int> vec1;
    int size;
    cout<<"Enter the size of the vector : ";
    cin>>size;
    int element;
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter the element : ";
        cin>>element;
        vec1.push_back(element);//Used for entering a data in a vector.
    }
    display(vec1);
    vec1.pop_back();//Removes the last entered value
    display(vec1);
    vector<int>::iterator iter=vec1.begin();
    vec1.insert(iter,512);
    display(vec1);
    return 0;
}