//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.codechef.com/JUNE20B/problems/EOEO
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
// Loop
#define FOR(n) for(int i=0;i<n;i++)
#define FORA(a,n) for(int i=a;i<n;i++)
// reading test case
#define test(n) int n; sd(n); while(n--)
// read and print array of integers
#define deb(x) cout<<"#X: "<<x<<"\n";
#define dar(ar,n) for(int i=0;i<n;i++) {cout<<"#."<<i<<ar[i]<<",";cout<<endl;}
#define d2d(ar,n) for(int i=0;i<n;i++) {for(int j=0;j<n;j++){cout<<ar[i][j]<<" ";}cout<<endl; }
#define rd_ar_int(name,size) int name[size]; for(int i=0;i<size;i++){ sd(name[i]);}
#define print_ar(name,size,dele) for(int i=0;i<size;i++){ cout<<name[i]<<dele; }
// 2D array
#define twoD(row,col,name) int **name=new int*[row];for(int i=0;i<row;i++){name[i]=new int[col];}
// typedef
// vector
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
// vector pair
typedef vector<pair<int,int>> vp;
typedef vector<string> vs;
/// pair
typedef pair<int,int> pi;

/**
 * This function returns the number of times jerry wins. 
 * @param ts strength of TS.
 * @return int number of times JS wins. 
 */
long long int numJSWin(long long int ts){

    // devide ts by 2 untill ts is even
    // idea is that, jerry can win only when JS is even and TS is odd. 
    // till TS is even jerry can't win

    // 0.25 sec
    while((ts%2==0)&&ts>1)
        ts/=2;

    /*
    0.17 sec
    while((!(ts&1))&&ts>1)
        ts/=2;

    0.19 seec
    ts=ts>>1


    */
    if(ts<=1)
        return 0;
    return ts/2;
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
    test(t){
        long long int ts;
        cin>>ts;
        cout<<numJSWin(ts)<<endl;
    }
	return 0;
}