----------------------------------Adjacent difference in set-----------------------------
#include <iostream>
#include <iterator>
#include <vector>
 
int main() 
{
    std::vector<int> v{ 3, 1, 4 };
 
    auto it = v.begin();
 
    auto nx = std::next(it, 2);
 
    std::cout << *it << ' ' << *nx << '\n';
}
Output:

3 4

//
set<int> st;
set<int>::iterator it;
for (it=st.begin(); it!=st.end(); ++it)
{
    if(it + 1 != st.end() && *(it + 1)-*it==1) {  // << error
    //do something
    }
}

if(next(it) != st.end() && *(next(it))-*it==1) // correct statement to above error
 ------------------------use-------------
for (auto i = s.begin();i!=s.end();i++) {
    if(next(i)!=s.end() && abs(*next(i)-*i)!=1)
        return false;
 }
