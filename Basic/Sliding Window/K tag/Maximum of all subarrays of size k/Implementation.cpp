//Main Approach
/*
Key IDEA - Main the element in Dequeue in Sorted order(if item to be push is greater than than front of Dequeue , kick that item and push
           this one --> front will always contain the greatest element )
Time : O(n)
*/

vector<int> Solution::slidingMaximum(const vector<int> &ARR, int K) {
    //Pair for keeping track of index .           
    deque< pair<int, int> > window;
    
    for (int i = 0; i < ARR.size(); i++) {
    //Sorting condition(kicking condition)
      while (!window.empty() && window.back().first <= ARR[i])
         window.pop_back();
     
     window.push_back(make_pair(ARR[i], i));
     //Window front out of bound condition 
     while(window.front().second <= i - K)
       window.pop_front();
     //First Window Condition  
     if(i>=K-1)
          cout << (window.front().first) << ' ';
  }
  return {};
}

//Approach 2
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    
    vector<int> v;
    deque<int> dq;
        
    for(auto i=0; i<A.size(); i++)
    {
        if(!dq.empty() && dq.front() == i-B)
            dq.pop_front();
        
        while(!dq.empty() && A[i] >= A[dq.back()])
            dq.pop_back();
            
        dq.push_back(i);
        
        if(i >= B-1) 
            v.push_back(A[dq.front()]);
    }
    
    return v;
}
