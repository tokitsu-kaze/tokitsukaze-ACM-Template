class Disjoint_Set_Union()
{
	lateinit var pre:IntArray
	lateinit var sz:IntArray
	fun init(n:Int)
	{
		pre=IntArray(n+1){it}
		sz=IntArray(n+1){1}
	}
	fun find(x:Int):Int
	{
		if(pre[x]!=x) pre[x]=find(pre[x])
		return pre[x]
	}
	fun merge(a:Int,b:Int):Boolean
	{
		var ra=find(a)
		var rb=find(b)
		if(ra!=rb)
		{
			pre[ra]=rb
			sz[rb]+=sz[ra]
			return true
		}
		return false
	}
}
