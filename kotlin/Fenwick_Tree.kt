class Fenwick_Tree(var n:Int)
{
	var bit=Array(n+1){0}
	fun lowbit(x:Int):Int{return x and (-x)}
	fun insert(xx:Int,v:Int)
	{
		var x=xx
		while(x<=n)
		{
			bit[x]+=v
			x+=lowbit(x)
		}
	}
	fun get(xx:Int):Int
	{
		var res=0
		var x=xx
		while(x>0)
		{
			res+=bit[x]
			x-=lowbit(x)
		}
		return res
	}
	fun ask(l:Int,r:Int):Int
	{
		return get(r)-get(l-1)
	}
}