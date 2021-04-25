#include <bits/stdc++.h>
using namespace std;

void permutation(map<vector<int>,int>&hash, vector<int>&cur, int n, int size){
    if(n==1){
        vector<int>v(cur.begin(),cur.end());
        if(hash.find(v) == hash.end()){
            hash[v] = 1;
        }
        return;
    }

    for(int i=0; i<n; i++){
        swap(cur[i],cur[n-1]);
        permutation(hash,cur,n-1,size);
        swap(cur[i],cur[n-1]);
    }
}

int main(){
    int n = 3;
    vector<int>ar{1,1,2};
    vector<vector<int>>res;
    map<vector<int>,int>hash;
    
    permutation(hash,ar, n, n);
    sort(res.begin(),res.end());
    for(auto vect:hash){
        for(int a:vect.first)
            cout<<a<<" ";

        cout<<endl;
    }
}
