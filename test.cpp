#include <bits/stdc++.h>
using namespace std;
int const MAX = 1e5;
int ar[MAX+1];

long long getMax(list<int>Q){
    Q.sort([](int a, int b){
        return a>b;
    });
    
    long long c3=0,sum=0;
    for(int i:Q){
        if(c3==3) break;
        sum+=i; c3++;
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
	#ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    //freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++) cin>>ar[i];
        
        // create a list to store current friends
        list<int>Q;
        
        // pust first five friends
        Q.push_back(ar[0]); Q.push_back(ar[1]); Q.push_back(ar[2]); 
        Q.push_back(ar[3]);
        long long SUM = 0;
        
        for(int i=4; i<n; i++){
            Q.push_back(ar[i]);
            SUM = max(SUM,getMax(Q));
            Q.pop_front();
        }
        cout<<endl;
        // calculate rest of the circle
        for(int i=0; i<5; i++){
            Q.push_back(ar[i]);
            SUM = max(SUM,getMax(Q));
            Q.pop_front();
        }
        cout<<SUM<<endl;
    }
	return 0;
}
