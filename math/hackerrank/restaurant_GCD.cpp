//============================================================================
// Name        : Restaurant
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Link        : https://www.hackerrank.com/challenges/restaurant/problem
// T.C         : O()
// A.S         : O()
// Description  :========================================================================
//                In the given problem, you have to cut a rectangular bread having size l * b into squares of equal dimension such that no piece of original bread is left over. So we have to make cuts only vertically or horizontally. Hence we can conclude that if the length of a side of the square is a, both l and b both has to be divisible by a.
//                Now, there's another constraint. a has to be as large as possible.
 //               The problem reduces to finding an integer whose value is maximum as well as divisible by both l & b which is equivalent to finding the greatest common divisor (gcd) of l & b.
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

// print integer and a new line every time.
#define pf(n) printf("%d ",n)
#define ps(s) printf("%s",s)
#define sd(n) scanf("%d",&n)
// new line
#define line printf("\n");
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

// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;
    
    #ifndef ONLINE_JUDGE 
	    // For getting input from input.txt file 
	    freopen("input.txt", "r", stdin); 
	    // Printing the Output to output.txt file 
	    freopen("output.txt", "w", stdout); 
    #endif 


    test(n){
        int l,b,area;
        sd(l); sd(b);
        pf((l*b)/(__gcd(l,b)*__gcd(l,b)));
    }
	return 0;
}