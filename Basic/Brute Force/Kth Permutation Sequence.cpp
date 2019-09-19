/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3 ) :

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"
Given n and k, return the kth permutation sequence.

For example, given n = 3, k = 4, ans = "231"
*/

string Solution::getPermutation(int A, int B) {
    vector<int>a(A);
    for(int i=0;i<A;i++)
        a[i]=i+1;
    for(int i=0;i<B-1;i++)
    {
        next_permutation(a.begin(),a.end());
        //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    }
    string ans="";
    for(int i=0;i<A;i++)
        ans+=to_string(a[i]);
    return ans;
}
