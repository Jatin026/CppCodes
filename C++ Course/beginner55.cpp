#include<iostream>
using namespace std;
template <class T>
class vector{
    public:
        T *arr;
        int size; 
        vector(int m){
            size=m;
            arr=new T [size];
        }
        T dotProduct(vector &v){
            T d=0;
            for(int i=0;i<size;i++){
                d+=v.arr[i]*this->arr[i];
            }
            return d;
        }
};
int main(){
    vector<int> v1(3) , v2(3);
    v1.arr[0]=1;
    v1.arr[1]=5;
    v1.arr[2]=9;
    v2.arr[0]=4;
    v2.arr[1]=8;
    v2.arr[2]=6;
    int a= v2.dotProduct(v1);
    cout<<a<<endl;
    vector<float> v3(3) , v4(3);
    v3.arr[0]=1.75;
    v3.arr[1]=5.352;
    v3.arr[2]=9.6341;
    v4.arr[0]=4.1242;
    v4.arr[1]=8.01;
    v4.arr[2]=6.123;
    float b= v3.dotProduct(v4);
    cout<<b;
    return 0;
}