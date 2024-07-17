class Dijkstra()
{
	data class node(var id:Int,var v:Int)
	lateinit var mp:Array<MutableList<node>>
	lateinit var dis:IntArray
	lateinit var vis:BooleanArray
	var n:Int
	fun init(_n:Int)
	{
		n=_n
		mp=Array(n+1){mutableListOf<node>()}
	}
	fun add_edge(x:Int,y:Int,v:Int){mp[x].add(node(y,v))}
	fun work(s:Int)
	{
		var q=PriorityQueue<node>(compareBy({it.v}))
		dis=IntArray(n+1){INF}
		vis=BooleanArray(n+1){false}
		dis[s]=0;
		q.add(node(s,0,-1,0))
		while(q.size>0)
		{
			var t=q.peek()
			q.poll()
			if(t.v>ndis[t.id]) continue
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
