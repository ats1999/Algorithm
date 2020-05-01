#include<bits/stdc++.h>
using namespace std;
//define 
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
typedef vector<pair<int,int>,int> vp;
typedef vector<string> vs;
/// pair
typedef pair<int,int> pi;

bool comp(pair<pair<int,int>,int>vp1,pair<pair<int,int>,int>vp2){
	return vp1.sc<vp2.sc;
}
// driver code
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	vector<pair<pair<int,int>,int>>vpi;
		vpi.pb(mp(mp(4,2),78));
	vpi.pb(mp(mp(3,4),56));
	vpi.pb(mp(mp(1,5),8));
	vpi.pb(mp(mp(1,2),100));

	
	
	for(auto it:vpi){
		cout<<it.fr.fr<<"->"<<it.fr.sc<<" ("<<it.sc<<")"<<endl;
	}
	
	line; line; line; line;
	
	sort(vpi.bg,vpi.en,comp);
	for(auto it:vpi){
		cout<<it.fr.fr<<"->"<<it.fr.sc<<" ("<<it.sc<<")"<<endl;
	}
}
