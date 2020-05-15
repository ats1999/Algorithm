//============================================================================
// Name        : cakewalk.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
// T.C         : O()
// A.S         : O()
// Link		   - https://www.hackerrank.com/challenges/marcs-cakewalk/problem
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
#define line printf("\n");
// read and print array of integers
#define red(ar,n) for(int i=0;i<n;i++){ sd(ar[i]);}
#define ped(ar,n) for(int i=0;i<n;i++){ pf(ar[i]); }
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

// typedef
// vector
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
// vector pair
typedef vector<pair<int,int>> vp;
typedef vector<string> vs;
/// pair
typedef pair<int,int> pi;
bool ignorCase(char a,char b){
	return tolower(a)<=tolower(b);
}
// driver code
int main(){
	//cout<<"Started\n";
	// fast I/O
	IOS;/*
     #ifndef ONLINE_JUDGE 
	     //For getting input from input.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin); 
	     //Printing the Output to output.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif  */
	string ar[]={"abc",
"def",
"aez",
"xyz"
,"zxy"};int n=5;   
for(int i=0;i<5;i++)
	if(is_sorted(ar[i].bg,ar[i].en,ignorCase))
		cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}

