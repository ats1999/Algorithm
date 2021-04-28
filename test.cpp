#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
void print(vector<int>&ar){
    for(int i:ar)
        cout<<i<<" ";
    cout<<endl;
}
void solve(vector<int>&ar){
    int n = ar.size();
    for(int i=0; i<n; i++){
        vector<int>subar;
        for(int j=i; j<n; j++){
            subar.push_back(ar[j]);
            print(subar);
        }
    }
}
// driver code
int main(){
	// I/O
	IOS;
    vector<int>ar{2,3,6,7};
    solve(ar);
	return 0;
}