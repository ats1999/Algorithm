#include<bits/stdc++.h>
using namespace std;
 
int main(){
    // FILE I/O
    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    cout<<"START\n";
    int t,n,k,ar[n];
    cin>>t;
    cout<<t;
    // INPUT
     while(t--){
         cin>>n>>k;
         for(int i=0;i<n;i++)
             cin>>ar[i];
     }

     // LOGIC
     for(int i=0;i<n;i++){
         for(int j=i;j<n;j++){
         	cout<<"\nSub Array\n";
             for(int k=i;k<=j;k++){
                 cout<<ar[k]<<" ";
             }
             cout<<endl;
         }
     }
    cout<<"\nEND";
    return 0;
}
