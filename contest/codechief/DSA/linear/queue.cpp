

// https://www.codechef.com/LRNDSA02/problems/CHFQUEUE

#include<bits/stdc++.h>
using namespace std;
int getIOfMin(int ar[],int n,int i1){
    for(int i=i1+1;i<n;i++){
        if(ar[i]<ar[i1])
            return i;
    }
    return -1;
}
long long int solve(int ar[],int n,int k){
    long long int pod=1;
    
    for(int i=0;i<n;i++){
        int index=getIOfMin(ar,n,i);
        if(index==-1)
            continue;
        
        pod*=index-i+1;
        pod%=1000000007;
    }
    return pod;
}
int main(){
    int n,k;
    cin>>n>>k;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
        
    cout<<solve(ar,n,k)<<endl;
}