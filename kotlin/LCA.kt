const val LOG=20
var fa=Array(1){IntArray(1)}
fun dfs(x:Int,pre:Int)
{
	fa[0][x]=pre
	for(i in 1..LOG-1) fa[i][x]=fa[i-1][fa[i-1][x]]
	for(to in mp[x])
	{
		if(to==pre) continue
		dfs(to,x)
	}
}
fun lca(xx:Int,yy:Int):Int
{
	var x=xx
	var y=yy
	if(dep[x]<dep[y]) x=y.also{y=x}
	var d=dep[x]-dep[y]
	for(i in 0..LOG-1)
	{
		if(((d shr i) and 1)==1) x=fa[i][x]
	}
	if(x==y) return x
	for(i in LOG-1 downTo 0)
	{
		if(fa[i][x]!=fa[i][y])
		{
			x=fa[i][x]
			y=fa[i][y]
		}
	}
	return fa[0][x]
}
