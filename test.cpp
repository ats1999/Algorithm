#include<bits/stdc++.h>
using namespace std;

int getCount(vector<int>&pr, int size, int B){
    int start = size, end = pr.size()-1;

    while(start <= end){
        int mid = (start+end)/2;
        
    }
    return 9;
}

int solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    
    vector<int>pre(A.begin(), A.end());
    for(int i=1; i<A.size(); i++){
        pre[i] = pre[i]+pre[i-1];
    }
    
    cout<<"Prefix: ";
    for(int i:pre){
        cout<<i<<" ";
    }cout<<endl;

    // for(int size=1; size<=A.size(); size++){
        getCount(pre,2,B);
    // }
    return 0;
}
// driver code
int main(){
    #ifndef ONLINE_JUDGE 
	    freopen("/home/rahul/Desktop/Algorithm/input.txt", "r", stdin);  
	    freopen("/home/rahul/Desktop/Algorithm/output.txt", "w", stdout); 
    #endif 
    vector<int>v{1,2,3,4,5};

    solve(v,4);
    return 0;
}
