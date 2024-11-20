fun lower_bound_pos(a:MutableList<Long>,target:Long):Int
{
	if(a.size==0) return 0
	var l=0
	var r=a.size-1
	var mid:Int
	while(l<r)
	{
		mid=(l+r) shr 1
		if(a[mid]>=target) r=mid
		else l=mid+1
	}
    if(a[l]>=target) return l
    return a.size
}
fun upper_bound_pos(a:MutableList<Long>,target:Long):Int
{
	if(a.size==0) return 0
	var l=0
	var r=a.size-1
	var mid:Int
	while(l<r)
	{
		mid=(l+r) shr 1
		if(a[mid]<=target) l=mid+1
		else r=mid
	}
	if(a[l]>target) return l
    return a.size
}
