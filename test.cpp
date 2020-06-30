
#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif

    int a[] = {1,8,77,10}; 
    int size = sizeof(a)/sizeof(a[0]);
    sort(a,a+size,[](int a,int b){
        return a<b;
    });

    for(int i=0;i<4;i++)
        cout<<a[i]<<" ";
}