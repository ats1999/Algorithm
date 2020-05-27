//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
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
// loop
#define f(i,n) for(int i=0;i<n;i++)
#define fa(i,a,n) for (int i=a;i<n;i++)
#define fn(i,n) for(int i=n;i>=0;i--)
#define fna(i,a,n) for(int i=n;i>=a;i--)
// new line
#define e endl
// reading test case
#define test(n) int n; sd(n); while(n--)
// read and print array of integers
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

// driver code
int main(){
	//cout<<"Started\n";
	// I/O
	IOS;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int gr[n],op[n];
    for(int i=0;i<n;i++){
        cin>>gr[i];
    }
    for(int i=0;i<n;i++){
        cin>>op[i];
    }

    sort(gr,gr+n);
    sort(op,op+n);

    // operation
    int count=0;
    int j=n-1;
    for(int i=n-1;i>=0&&j>=0;){
        if(gr[i]>op[j]){
            count++;
            i--;
        }
        j--;
    }
    cout<<count<<endl;
    }
	return 0;
}