//Normal comparater wont work
1. Priority Queue Comparator (Structure can be declare above or inside the function (Yes, it work))
    struct comp{
      bool operator()(const Interval &a, const Interval &b) {
          return a.end > b.end; //This Condition Favours Min-Heap
      }  
    };

    OR
    struct comp{
      bool operator()( Interval &a, Interval &b) const{
          return a.end > b.end;
      }  
    };

    OR
    struct comp{
      bool operator()( Interval &a, Interval &b) {
          return a.end > b.end;
      }  
    };

    OR
    struct comp{
      bool operator()( Interval a, Interval b) {
          return a.end > b.end;
      }  
    };
For calling ->  priority_queue<Interval, vector<Interval>, comp>pq;
Provided By STL -> Default is Max-Heap, for Min-Heap use greater<int>   //(Yes, No bracket afre <int>)
    
2. Sorting Comparator (Anonymous Function or bool comparator)
    
    sort(intervals.begin(), intervals.end(),
            [](Interval &a, Interval &b) {  //Reference can be removed, const can be added but does not work with type 2 in priority queue
                     return a.start < b.start;
        });
    OR
    
    static bool cmp(const Interval &a, const Interval &b) { 
        return a.start < b.start;   //This condition favour ascending order sort
    }
    
Provided by STL ->greater<int>()
