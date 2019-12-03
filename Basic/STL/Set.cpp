1. Ordered set (Set is implemented as balanced tree structure)
	Consider we need a container with the following features:
	a. add an element, but do not allow duples [duplicates?]
	b. remove elements
	c. get count of elements (distinct elements)
	d. check whether elements are present in set
	
	Function: set<int>s 
	1) s.insert(42)
	2) s.erase(42)
	3) int n=s.size()
	4) Iteration
		Since set is not a linear container, it’s impossible to take the element in set by index. 
		Therefore, the only way to traverse the elements of set is to use iterators.

		// Calculate the sum of elements in set
		set< int > S;
		// ...
		int r = 0;
		for(set< int >::const_iterator it = S.begin(); it != S.end(); it++) {
		r += *it;
		}

		best way to iterate set,map(array too)
		for(auto i:s)
		r+=i;

	5) set< int > s;
		// ...
		if(s.find(42) != s.end()) {
		// 42 presents in set
		}
		else {
		// 42 not presents in set
		}
	6) set< int >::iterator it1, it2;
	
		it1 = s.find(10);
		it2 = s.find(100);
		// Will work if it1 and it2 are valid iterators, i.e. values 10 and 100 present in set.
		s.erase(it1, it2); // Note that 10 will be deleted, but 100 will remain in the container

		Set has an interval constructor:

		int data[5] = { 5, 1, 4, 2, 3 };
		set< int > S(data, data+5);
		It gives us a simple way to get rid of duplicates in vector, and sort it:

		vector< int > v;
		// …
		set< int > s(all(v));
		vector< int > v2(all(s));

		Here ‘v2′ will contain the same elements as ‘v’ but sorted in ascending order and with duplicates removed.
		
2. Unordered_set(unordered_set is implemented using hash table where keys are hashed into indices of this hash table so 
				it is not possible to maintain an order. All operation on unordered_set takes constant time O(1) on an 
				average which can go up to linear time in worst case which depends on the internally used hash function 
				but practically they perform very well and generally provide constant time lookup operation.)
				
3. Multi_set(It allows storage of multiple elements)

4. unordered_map does not preserve the order as they inserted.
	
5. lower and upper bound in set
	The set elements are: 1 2 4 5 6 
	The lower bound of key 2 is 2
	The lower bound of key 3 is 4
	The lower bound of key 8 is 5
