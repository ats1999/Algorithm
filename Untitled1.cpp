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


// A utility function to find the subset of an element i  
int find(int parent[], int i)  
{  
    if (parent[i] == -1)  
        return i;  
    return find(parent, parent[i]);  
}  
  
// A utility function to do union of two subsets  
void Union(int parent[], int x, int y)  
{  
    int xset = find(parent, x);  
    int yset = find(parent, y);  
    if(xset != yset) 
    {  
    	cout<<"Included "<<x<<" "<<y<<endl;
        parent[xset] = yset;  
    }  else cout<<"Not Included "<<x<<" "<<y<<endl;
}  

// driver code
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
// Allocate memory for creating V subsets  
    int parent[8]={0};  
  
    for(int i=0;i<8;i++)
    	parent[i]=-1;
    int src []={1,2,4,6,1,2,4,3,2,3,5,5};
	int dest[]={2,3,5,7,4,5,7,5,4,6,7,6};
		
		for(int i=0;i<12;i++){
			Union(parent,src[i],dest[i]);
		}
}
