Reference : https://www.topcoder.com/community/competitive-programming/tutorials/power-up-c-with-the-standard-template-library-part-2/
            https://codeforces.com/blog/entry/6311
            http://codeforces.com/blog/entry/6058

1) Inserter
    Merging lists
Another common task is to operate with sorted lists of elements. Imagine you have two lists of elements — A and B, both ordered. 
You want to get a new list from these two. There are four common operations here:
‘union’ the lists, R = A+B
intersect the lists, R = A*B
set difference, R = A*(~B) or R = A-B
set symmetric difference, R = A XOR B

STL provides four algorithms for these tasks: set_union(…), set_intersection(…), set_difference(…) and set_symmetric_difference(…). 
They all have the same calling conventions, so let’s look at set_intersection. A free-styled prototype would look like this:

end_result = set_intersection(begin1, end1, begin2, end2, begin_result);

Here [begin1,end1] and [begin2,end2] are the input lists. The 'begin_result' is the iterator from where the result will be written. 
But the size of the result is unknown, so this function returns the end iterator of output (which determines how many elements are 
in the result). See the example for usage details:

int data1[] = { 1, 2, 5, 6, 8, 9, 10 };
int data2[] = { 0, 2, 3, 4, 7, 8, 10 };

vector< int > v1(data1, data1+sizeof(data1)/sizeof(data1[0]));
vector< int > v2(data2, data2+sizeof(data2)/sizeof(data2[0]));

vector< int > tmp(max(v1.size(), v2.size());

vector< int > res = vector< int > (tmp.begin(), set_intersection(all(v1), all(v2), tmp.begin());

Look at the last line. We construct a new vector named 'res'. It is constructed via interval constructor, 
and the beginning of the interval will be the beginning of tmp. The end of the interval is the result of the 
set_intersection algorithm. This algorithm will intersect v1 and v2 and write the result to the output iterator, 
starting from 'tmp.begin()'. Its return value will actually be the end of the interval that forms the resulting dataset.

One comment that might help you understand it better: If you would like to just get the number of elements in set 
intersection, use int cnt = set_intersection(all(v1), all(v2), tmp.begin()) – tmp.begin();

Actually, I would never use a construction like ' vector< int > tmp'. I don't think it's a good idea to 
allocate memory for each set_*** algorithm invoking. Instead, I define the global or static variable of 
appropriate type and enough size. See below:

set< int > s1, s2;
for(int i = 0; i < 500; i++) {
s1.insert(i*(i+1) % 1000);
s2.insert(iii % 1000);
} 

static int temp[5000]; // greater than we need 

vector< int > res = vi(temp, set_symmetric_difference(all(s1), all(s2), temp));
int cnt = set_symmetric_difference(all(s1), all(s2), temp) – temp;

Here 'res' will contain the symmetric difference of the input datasets.

Remember, input datasets need to be sorted to use these algorithms. So, another important thing to remember is that, 
because sets are always ordered, we can use set-s (and even map-s, if you are not scared by pairs) as parameters for these algorithms.

These algorithms work in single pass, in O(N1+N2), when N1 and N2 are sizes of input datasets.
  
