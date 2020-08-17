
#include<bits/stdc++.h>
using namespace std;
bool isbeautifulSubArray(vector<int>subArray,int l,int r,int k){
    int m=ceil(float(k)/((r-l)+1));

    // sort subarray
    sort(subArray.begin(),subArray.end());

    // find x 
    int x = subArray[((subArray.size()*k)/k)-1];
    
    // find frequency of f in subarray
    int f = count(subArray.begin(),subArray.end(),x);
    
    // check if f is persent or not in the subarray
    if(binary_search(subArray.begin(),subArray.end(),f)){
        return true;
    }
    return false;
}
int soln(){
    int m,k;
    int ans=0;
    cin>>m>>k;
    int ar[m];
    for(int i=0;i<m;i++)
        cin>>ar[i];
    for(int i=0;i<m;i++){
        for(int j=i;j<m;j++){
                vector<int>subArray;
            for(int k=i;k<=j;k++){
                subArray.push_back(ar[k]);
            }
            if(isbeautifulSubArray(subArray,i,j,k))  {
                    ans++; 
                    //cout<<"Y\n";
            } 
                
        }
    }
    
    return ans;
} 
int main(){
    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    int t;
    cin>>t;
    while(t--){
        int ans = soln();
        cout<<ans<<endl;
    }
    //double d=float(3)/2;
    //cout<<d;
}
