/* C++ program to implement 2D Binary Indexed Tree 

2D BIT is basically a BIT where each element is another BIT. 
Updating by adding v on (x, y) means it's effect will be found 
throughout the rectangle [(x, y), (max_x, max_y)], 
and query for (x, y) gives you the result of the rectangle 
[(0, 0), (x, y)], assuming the total rectangle is 
[(0, 0), (max_x, max_y)]. So when you query and update on 
this BIT,you have to be careful about how many times you are 
subtracting a rectangle and adding it. Simple set union formula 
works here. 

So if you want to get the result of a specific rectangle 
[(x1, y1), (x2, y2)], the following steps are necessary: 

Query(x1,y1,x2,y2) = getSum(x2, y2)-getSum(x2, y1-1) - 
					getSum(x1-1, y2)+getSum(x1-1, y1-1) 

Here 'Query(x1,y1,x2,y2)' means the sum of elements enclosed 
in the rectangle with bottom-left corner's co-ordinates 
(x1, y1) and top-right corner's co-ordinates - (x2, y2) 

Constraints -> x1<=x2 and y1<=y2 

	/\ 
y | 
	|		 --------(x2,y2) 
	|		 |	 | 
	|		 |	 | 
	|		 |	 | 
	|		 --------- 
	|	 (x1,y1) 
	| 
	|___________________________ 
(0, 0)				 x--> 

In this program we have assumed a square matrix. The 
program can be easily extended to a rectangular one. */

#include<bits/stdc++.h> 
using namespace std; 

#define N 4 // N-->max_x and max_y 

// A function to create an auxiliary matrix 
// from the given input matrix 
void constructAux(int mat[][N], int aux[][N+1]) 
{ 
	// Initialise Auxiliary array to 0 
	for (int i=0; i<=N; i++) 
		for (int j=0; j<=N; j++) 
			aux[i][j] = 0; 

	// Construct the Auxiliary Matrix 
	for (int j=1; j<=N; j++) 
		for (int i=1; i<=N; i++) 
			aux[i][j] = mat[N-j][i-1]; 

	return; 
} 

// A function to construct a 2D BIT 
void construct2DBIT(int mat[][N], int BIT[][N+1]) 
{ 
	// Create an auxiliary matrix 
	int aux[N+1][N+1]; 
	constructAux(mat, aux); 

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout<<aux[i][j]<<" ";
		}cout<<endl;
	}

	return; 
} 

// Driver program 
int main() 
{ 
	int mat[N][N] = {{1, 2, 3, 4}, 
					{5, 3, 8, 1}, 
					{4, 6, 7, 5}, 
					{2, 4, 8, 9}}; 

	// Create a 2D Binary Indexed Tree 
	int BIT[N+1][N+1]; 
	construct2DBIT(mat, BIT); 
	return(0); 
} 
