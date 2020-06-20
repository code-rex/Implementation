1.Removing Duplicate element

  (i) Just using vector, sort + unique

    sort( vec.begin(), vec.end() );
    vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
  
  (ii) Convert to unordered_set (manually)

      unordered_set<int> s;
      for (int i : vec)
      s.insert(i);
      vec.assign( s.begin(), s.end() );
      sort( vec.begin(), vec.end() );
      
  (iii)Convert to set(manually)
      
      set<int> s;
      for (int i : vec)
      s.insert(i);
      vec.assign( s.begin(), s.end() );
      
    In case of set/unordered set manually is preferred constructor slows down;
    speed : ii>i>iii
    ref :https://stackoverflow.com/questions/1041620/whats-the-most-efficient-way-to-erase-duplicates-and-sort-a-vector
  
2.Erasing element by index 

  vec.erase(vec.begin() + index); //for n element its O(N) because array will reshift each time (0-indexing)
  vec.erase(vec.begin()+k,vec.end()); //deletes from kth index to last index
  vec.erase(vec.begin()+k,vec.begin()+m); //delete from kth index to mth index
  
  (i) For removing by index in the vector in O(1) ->Order of element does not mattter
     -> swap last index element with the to_remove index element
     -> vector.pop_back()
    
 (ii) For removing by index in the vector in O(1) -> order of element matter
    -> you can use linked list for O(1) but you have to know the previous index before hand otherwise traversal which will cost O(n)
    -> 
  
  Duplicate removal -> 
  For removing duplicate with constant space it is preffered to move all duplicate to RHS then resize the vector in O(1) rather than 
  erasing the element.
  vec.resize(count);
   
  vec.clear() //for full clear
  
3.Erasing elements by value

  vec.erase( remove(vec.begin(),vec.end(),8) ,vec.end);

4. BASIC
    int max=*max_element(a.begin(),a.end());  //for values
    int min=*min_element(a.begin(),a.end());  //for values
    int pos = max_element(a.begin(), a.end()) - a.begin();  //for position
    int sum=accumulate(a.begin(),a.end(),p);

5. BINARY SEARCH
    binary_search(arr.begin(), arr.end(), 15) //results true of false
    a) upper bound -  upper_bound(arr1.begin(), arr1.end(), 20) - arr1.begin();
    b) lower bound - lower_bound(arr1.begin(), arr1.end(), 20)  - arr1.begin();

    1 20 20 20 40 50 
   -----------------Lower and upper bound--------------------------------
     lower bound for 20 is index 1(0 indexing )
     upper bound for 20 is index 4 (40)
       
     (i)Lower bound
        1. Item is present - return the first position of element in 0 indexing.
        2. Item is not present - return the index of first element which is greater than this value.
        3. if search value is greater than last index value - it goes out of bound(handle by !=vec.end()) (array size is 7 it return 8)
          
     (ii)upper bound
        1. Item is present - return the first position of just greater than value in 0 indexing.
        2. Item is not present - return the index of first element which is greater than this value.
        3. if search value is greater than last index value - it goes out of bound(handle by !=vec.end()) (array size is 7 it return 8)
          
       Ex. 1. search -10 lower & upper return 0
           2. search 60 lower & upper return 6
           3. search 15 lower & upper return 1
     (iii) Equal range - just lower and upper bound in one line
           auto equal=std::equal_range (v.begin(), v.end(), 15); //          ^                   ^

          std::cout << "lower_bound at position " << (equal.first- v.begin()) << '\n';//1
          std::cout << "upper_bound at position " << (equal.second - v.begin()) << '\n';//1
        
 6. Fastest Way to reset value in vector
    fill(v.begin(), v.end(), 0);
    //references https://stackoverflow.com/questions/8848575/fastest-way-to-reset-every-value-of-stdvectorint-to-0
    other Options:memset,assign,manual,initiliazation
    a.assign(n,0);
    memset(a,0,sizeof(a));
     
 
 
