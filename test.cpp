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
typedef vector<pair<int,int>> vp;
typedef vector<string> vs;
/// pair
typedef pair<int,int> pi;
void print(int ar[],int n){
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
	cout<<endl;
}
void merge(int ar[],int left[],int right[],int size,int l,int r){
	int i=0,j=0,k=0;
	cout<<"Left: ";
	print(left,1);
	cout<<"Right: ";
	print(right,1);
	// merge two array
	// at every iteration, insert minimum first element of the both array
	for(;i<size;i++){
		
		if(j<l&&k<r){
			if(left[j]<right[k]){
				ar[i]=left[j];
				cout<<"Assigning: left "<<left[j]<<endl;
				j++;
			}else if(k<r){
				ar[i]=right[k];
				cout<<"Assigning: right "<<right[k]<<endl;
				k++;
			}
		}else break;
	}
	
	// after insertion might be one array left with some element then insert it into ar[]
	for(;j<l;j++)
		{
			cout<<"Assigning: left "<<left[j]<<endl;
			ar[i]=left[j];
		}
		
	for(;k<r;k++){
	cout<<"Assigning: right "<<right[k]<<endl;
		ar[i]=left[k];
	}
}
// driver code
int main(){
	cout<<"Start\n";
    int ar[]={1,2,3};
    int i=0;
    cout<<endl;
	
}
