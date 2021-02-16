int check(int k)
{
	
}

// for finding min in binary search
int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)>>1; // or use lo + (hi-lo)/2 in leetcode problems to avoid overflow
		if(check(mid))
			hi=mid;
		else
			lo= mid+1;
	}
	return lo;
}

// for finding max in binary search
int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)>>1;// makes 7-4, 8-4,3-2 ,1-1.. adding 1 dont forget
		if(check(mid))
			lo=mid;
		else
			hi=mid-1;
	}
	return lo;
}

