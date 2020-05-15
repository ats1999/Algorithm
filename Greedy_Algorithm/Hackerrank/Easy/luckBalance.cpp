//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// ===========================================================================
// Description : most importent condition is, lenna can lose at most K important contest. 
//                So pick K importent contest with maximum luck and add it to the totelLuck. 
//                Now, traverse the array, if current contest is not importent then lenna can loose it, and add it's luck to the totelLuck.
//                if current contest is not importent contest then lenna has to win it, and subtract it from totelLcuk.
// ===========================================================================
// Link        : https://www.hackerrank.com/challenges/luck-balance/problem
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
// print integer and a new line every time.
#define pf(n) printf("%d ",n)
#define ps(s) printf("%s\n",s)
#define sd(n) scanf("%d",&n)
// new line
#define space printf(" ")
#define line printf("\n")
// vector
#define bg begin()
#define en end()
#define pb(n) push_back(n)
// pair
#define fr first
#define sc second
#define mp(a,b) make_pair(a,b)
// new line
#define e endl
// reading test case
#define test(n) int n; sd(n); while(n--)
// read and print array of integers
#define rd_ar_int(name,size) int name[size]; for(int i=0;i<size;i++){ sd(name[i]);}
#define print_ar(name,size,dele) for(int i=0;i<size;i++){ cout<<name[i]<<dele; }
// typedef
// vector
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
// vector pair
typedef vector<pair<int,int>> vp;
typedef vector<string> vs;
/// pair
typedef pair<int,int> pi;

bool comp(pi p1,pi p2){
    return p1.first>p2.first;
}
// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;
	
    #ifndef ONLINE_JUDGE 
	    // For getting input from input.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin); 
	    // Printing the Output to output.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    
        int n,k;
        cin>>n>>k; 
        
        vp luck;
        int numberOfImportentContest=0;
        long long int totelLuck=0;
        // read input
        for(int i=0;i<n;i++){
            int l,t;
            cin>>l>>t;
            // if current contest is importent then only keep it for the traversing later
            if(t)// t 0/1
            {
                numberOfImportentContest++;
                 luck.pb(mp(l,t));
            }
            else{
                totelLuck+=l;
            }
        }
        
        // sorting is needed only if number Of Importent Contest is greter than K
        if(numberOfImportentContest>k)
        sort(luck.bg,luck.en,comp);
        // LOGIC
        // add k max luck 
        for(auto pair:luck){
                if(k){
                    k--;
                    totelLuck+=pair.first;
                }else{
                    totelLuck-=pair.first;
                }
        }
        cout<<totelLuck;
	return 0;
}
