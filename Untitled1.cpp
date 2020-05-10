#include<iostream>
using namespace std;
int main(){
	long long int abc[6];
	for(int i=0;i<6;i++){
		abc[i]=LLONG_MAX;
	}
	for(int i=0;i<6;i++){
		cout<<abc[i]%100<<endl;
	}
}
