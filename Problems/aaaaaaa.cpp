#include<iostream>
#include<iomanip>
using namespace std;
float determinant( float p[],float q[],float r[]);
float solution(float p[],float q[],float r[],float s[]);
int main(){
    cout<<"Enter the variables of the linear equation in three variable: "<<endl;
    float x[3],y[3],z[3],b[3];
    for(int i=0;i<3;i++){
    cout<<"Enter the x,y and z coefficient of the equation "<<i+1<<" and enter the numerical value:  ";
    cin>>x[i]>>y[i]>>z[i]>>b[i];
    cout<<"Equation "<<i+1<<": \t"<<showpos<<x[i]<<"x"<<y[i]<<"y";
    cout<<z[i]<<"z="<<b[i]<<resetiosflags(ios::showpos)<<endl;}
    solution(x,y,z,b);
    cout<<"Value of x: "<<x[1]<<endl;
    cout<<"Value of y: "<<y[1]<<endl;
    cout<<"Value of z: "<<z[1]<<endl;

    return 0;
}
float solution(float p[],float q[],float r[],float s[]){
     int d1,dx,dy,dz;
     d1=determinant(p,q,r);
    dx=determinant(s,q,r);
    dy=determinant(p,s,r);
    dz=determinant(p,q,s);
     if(d1!=0){
        cout<<"System of equation has unique solution"<<endl;
        cout<<"Value of x: "<<dx/d1<<endl;
        cout<<"Value of y: "<<dy/d1<<endl;
        cout<<"Value of z: "<<dz/d1<<endl;
        return (dx/d1,dy/d1,dz/d1,0);    
    }
     if(d1==0 && dx==0 && dy==0 && dz==0){
         for(int i=0;i<2;i++){
             if((p[i]/p[i+1])!=(q[i]/q[i+1])!=(r[i]/r[i+1])){
                break;}
                break;}
          cout<<"System of equation has infinite number of solution"<<endl;      
         }
     else
        cout<<"System of equation has no solution";

}
float determinant( float p[],float q[],float r[]){
    float result;
    result= p[0]*(q[1]*r[2]-q[2]*r[1])-p[1]*(q[0]r[2]-q[2]*r[0])+p[2]+p[2]*(q[0]*r[1]-q[1]*r[0]);
    return result;
}
#include<bits/stdc++.h>
using namespace std;
int func(){
    return(5,6);
}
int main(){
    int x,y;
    x,y=func();
    cout<<x<<y;
    return 0;
}