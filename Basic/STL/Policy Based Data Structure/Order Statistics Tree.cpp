//References: https://codeforces.com/blog/entry/11080

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main()
{
    ordered_set X;
    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);

    cout<<*X.find_by_order(1)<<endl; // 2
    cout<<*X.find_by_order(2)<<endl; // 4
    cout<<*X.find_by_order(4)<<endl; // 16
    cout<<(end(X)==X.find_by_order(6))<<endl; // true

    cout<<X.order_of_key(-5)<<endl;  // 0
    cout<<X.order_of_key(1)<<endl;   // 0
    cout<<X.order_of_key(3)<<endl;   // 2
    cout<<X.order_of_key(4)<<endl;   // 2
    cout<<X.order_of_key(400)<<endl; // 5
  return 0;
}

/*
1. If we want to get map but not the set, as the second argument type must be used mapped type.
    Ex: 
 */
typedef tree< 
double, 
int, 
less<double>, 
rb_tree_tag, 
tree_order_statistics_node_update> map_t;
 
int main() { 
 
 
    map_t s; 
    s.insert(make_pair(12, 1012)); 
    s.insert(make_pair(505, 1505)); 
    s.insert(make_pair(30, 1030));
 
    cout << s.find_by_order(1)->second << '\n';
    return 0; 
 
}

2. find_by_order() - returns an iterator to the k-th largest element (counting from zero).
3. order_of_key() - the number of items in a set that are strictly smaller than our item.
