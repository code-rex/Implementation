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

  vec.erase(vec.begin() + index); //for n element its O(N) because array will reshift each time
  vec.erase(vec.begin()+k,vec.end());
  
  for removing duplicate with constant space it is preffered to move all duplicate to RHS then resize the vector in O(1) rather than 
  erasing the element.
   
  vec.clear() //for full clear
  
3.Erasing elements by value

  vec.erase(remove(vec.begin(),vec.end(),8),vec.end);

4. 


 
