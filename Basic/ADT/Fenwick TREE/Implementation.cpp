// https://www.hackerearth.com/practice/notes/binary-indexed-tree-or-fenwick-tree/
// https://kartikkukreja.wordpress.com/2013/12/02/range-updates-with-bit-fenwick-tree/
// https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees/

int BIT[1000], a[1000], n;
void update(int x, int delta)
{
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int main()
{
     scanf(“%d”, &n);
     int i;
     for(i = 1; i <= n; i++)
     {
           scanf(“%d”, &a[i]);
           update(i, a[i]);
     }
     printf(“sum of first 10 elements is %d\n”, query(10));
     printf(“sum of all elements in range [2, 7] is %d\n”, query(7) – query(2-1));
     return 0;
}

1.Point Updates and Range Queries 
query(a, b):
    return query(b) - query(a-1)
    
2. Range Updates and Point queries
  # Add v to A[a...b] 
  update(a, b, v):     
  update(a, v)     
  update(b + 1, -v) 
