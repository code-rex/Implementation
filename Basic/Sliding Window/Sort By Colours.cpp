int low=0,mid=0,high=n-1;
	while(mid<=high)
	{
		if(a[mid]==0)
			swap(a[mid],a[low++]);
		if(a[mid]==2)
			swap(a[mid],a[high--]);
		mid++;
	}
