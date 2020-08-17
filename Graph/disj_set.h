//============================================================================
// Name        : disj_set.h
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implements Disjoints set data structure. 
//============================================================================


/**
* This claass repersents Disjoints set data structure.
*
* set			 : A array repersenting disjoint set. 
* size			 : an integer - size of set
* 
* DisjSet(int n) : this is a constuctor. 
*				- Constructs a new set containing the given number of singleton sets.
*				- For example, new DisjointSet(3) ? {{0}, {1}, {2}}.
* 
* printSet()		: print set elements alongs with their parent
* printSize()		: print set size.
*
* areInSameSet()	: returns true if both number in the same set false otherwise.	 
*					- areInSameSet(int elem1,int elem2)
*
* find(int num)	    : returns parent of the given element.
* getSize()			: returns size of set. (constant).
*
* unite()			: returns true and make union if both numbers belongs to different set, false otherwise/
*					- isUnion(int num1,int num2)
*/
//template<typename T>
class DisjSet{
	int *set=NULL,*size=NULL;
	int setSize=0;
	public:
		/**
		* This constructor creates a disjoint set of size n.
		*/
		DisjSet(int n){
			setSize=n+1;
			set = new int[n+1];
			size = new int[n+1];
	
			// initially every element is parent of itself
			for(int i = 0; i <= n; i++)
				set[i] = i;
			
			// initially size o every set is zero
			for(int i = 0; i <= n; i++)
				size[i] = 0;
		}
		
		/**
		* Print all value of the set at any time. 
		* Mainly used for debuging purpose. 
		*/
		void printSet(){
			printf("\n");
			for(int i=0;i<setSize;i++)
				printf("Set element: %d.. parent %d\n",i,set[i]);
		}
		
		/**
		* This function print size of all set.
		*/
		void printSize(){
			printf("\n");
			for(int i=0;i<setSize;i++){
				printf("Size of: %d\t%d\n",i,size[i]);
			}
		}
		
		/**
		* Tests whether the given two elements are members of the same set. 
		* Note that the arguments are orderless.
		* @param num1: an int - number 1 
		* @param num2: an int - number 2
		* @return bool : true denotes both number belongs to the same set, different set otherwise. 
		*/
		bool areInSameSet(int num1,int num2){
			return find(num1) == find(num2);
		}
		
		/**
		* This function returns parent of the given element.
		* @param elem: an element - whose set is to be find.
		* @return : root of the given element
		*/
		// A utility function to find the subset of an element i  
		int find(int i)  
		{  
			while(i != set[i])
				i = set[i];
			return i;
		}  
  
		
		/**
		* Merges together the sets that the given two elements belong to. 
		* This method is also known as �union� in the literature. 
		* If the two elements belong to different sets, then the two sets are merged and the method returns true. 
		* Otherwise they belong in the same set, nothing is changed and the method returns false.
		* Note that the arguments are orderless.
		* @param node1: first node.
		* @param node2: second node.  
		*/
		void unite(int node1,int node2){
			// find component of both nodes which these belongs
			int a = find(node1);
			int b = find(node2);

			// join both sets if they are disjoint
			if(size[a] < size[b]){
				swap(a,b);
			}

			size[a] += size[b];
			set[b] = a;
		   }
		
		/**
		* This function returns size of set. 
		* Size of set is constant for lifetime. 
		* @return size: an int - size of set. 
		*/
		int getSize(){
			return setSize;
		}
};


