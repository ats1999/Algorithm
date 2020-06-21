/**
 * Print the given array to the console.
 * @param ar input array
 * @param n size of ar[]
 */
void printAr(int ar[],int n){
	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";
		cout<<endl;
}

/**
 * Print the given array to the console.
 * @param ar input bool array
 * @param n size of ar[]
 */
void printArBool(bool ar[],int n){
	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";
}

/**
 * Print the given vector to the console.
 * @param vect input vector
 */
void printVector(vector<int>&vect){
	for(int i:vect)
		cout<<i<<" ";
		cout<<endl;
}
/**
 * Print the given vector to the console.
 * @param vect input 2D vector
 */
void printVectTwoD(vector<vector<int>>&vect){
	for(auto it:vect)
		{
			for(int i:it)
				cout<<i<<" ";
			cout<<endl;
		}
		cout<<endl;
}

