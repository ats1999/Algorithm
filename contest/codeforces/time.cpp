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
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin); 
	    // Printing the Output to output.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    test(T){
        string str;
        cin>>str;

        int length=str.length();
        if(length<3)
            cout<<0<<endl;
        else{
            set<char>st;
            st.insert(str[0]);
            st.insert(str[1]);
            st.insert(str[2]);
            if(st.size()==3)
                cout<<3<<endl;
            else{
                int minLength=INT_MAX;
                st.clear();
                bool falg=false,full=false;
                int a1=0,a2=0,a3=0;
                for(int i=0;i<length;i++){
                    if(str[i]=='1')
                        a1=i;
                    else if(str[i]=='2')
                            a2=i;
                    else a3=i;
                    st.insert(str[i]);
                    if(st.size()==3)
                        full=true;
                    if(full)
                        minLength=min(minLength,(max(a1,(a2,a3))-min(a1,(a2,a3)))+1);
                }
                if(full)
                    cout<<minLength<<endl;
                cout<<0<<endl;
            }
        }

    }
	return 0;
}