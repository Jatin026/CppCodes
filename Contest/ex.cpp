#include<iostream>
using namespace std;
int factorial(int n){
	if(n==0){
		return 1;
	}else{
	return n*factorial(n-1);}
}
int main(){
	for(int num=100;num<150;num++){
	int c=num;
	int sum=0;
	while(c>0){
		int r=c%10;
		sum=sum+factorial(r);
		c=c/10;
	}
	if(num==sum){cout<<num<<" ";}
	else{continue;
	}
	}
    return 0;
    }