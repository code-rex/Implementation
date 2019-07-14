vector<int> Solution::slidingMaximum(const vector<int> &ARR, int K) {

    priority_queue< pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>> > window;
    
  for (int i = 0; i < ARR.size(); i++) {
     window.push(make_pair(-ARR[i], i));
     //Removing out of index element of current window
     while(window.top().second <= i - K)
       window.pop();
       
     if(i>=K-1)
      cout << (-window.top().first) << ' ';
  }
  return {};
}
