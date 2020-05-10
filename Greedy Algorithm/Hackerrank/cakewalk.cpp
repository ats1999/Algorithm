//============================================================================
// Name        : cakewalk.cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
// T.C         : O()
// A.S         : O()
// Link		    https://www.hackerrank.com/challenges/marcs-cakewalk/problem
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

// driver code
int main(){
	//cout<<"Started\n";
	// fast I/O
	IOS;
    
    int n;
    sd(n);
    int cal[n];
    // read input
	for(int i=0;i<n;i++){
		sd(cal[i]);
	}
	
	// Sort the given calories in reverse order
	// start from 2^0 to 2^n-1
	// multiply eaach cal[i] with 2^i and add result to the totel .  . . 
	int pow=1;
	long long totel=0;
	sort(cal,cal+n,greater<int>());
//	cout<<"\n\nOUTPUT....\n\n";
	// Logic
	for(int i=0;i<n;i++){
		totel+=cal[i]*pow;
		pow*=2;
		cout<<"Totel: "<<totel<<endl;
	}
	cout<<totel;
	return 0;
}

