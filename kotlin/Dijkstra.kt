class Dijkstra()
{
	data class node(var id:Int,var v:Long)
	lateinit var mp:Array<MutableList<node>>
	lateinit var dis:LongArray
	lateinit var vis:BooleanArray
	var n=0
	fun init(_n:Int)
	{
		n=_n
		mp=Array(n+1){mutableListOf<node>()}
	}
	fun add_edge(x:Int,y:Int,v:Long){mp[x].add(node(y,v))}
	fun work(s:Int)
	{
		var q=PriorityQueue<node>(compareBy({it.v}))
		dis=LongArray(n+1){LLINF}
		vis=BooleanArray(n+1){false}
		dis[s]=0;
		q.add(node(s,0L))
		while(q.size>0)
		{
			var t=q.peek()
			q.poll()
			if(t.v>dis[t.id]) continue
			for(it in mp[t.id])
			{
				var to=it.id
				var w=it.v
				if(dis[to]>t.v+w)
				{
					dis[to]=t.v+w
					q.add(node(to,dis[to]))
				}
			}
		}
	}
}
