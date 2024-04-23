class Dijkstra()
{
	data class node(var id:Int,var pre:Int,var bir:Int,var v:Int)
	lateinit var mp:Array<MutableList<node>>
	lateinit var dis:IntArray
	lateinit var ndis:IntArray
	lateinit var bir:IntArray
	lateinit var nbir:IntArray
	lateinit var vis:BooleanArray
	var n:Int
	fun init(_n:Int)
	{
		n=_n
		mp=Array(n+1){mutableListOf<node>()}
	}
	fun add_edge(x:Int,y:Int,v:Int){mp[x].add(node(y,0,0,v))}
	fun work(s:Int)
	{
		var q=PriorityQueue<node>(compareBy({it.v}))
		dis=IntArray(n+1){INF}
		ndis=IntArray(n+1){INF}
		bir=IntArray(n+1){-1}
		nbir=IntArray(n+1){-1}
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
				if(t.pre==to) continue
				var w=it.v
				var b:Int
				if(t.bir==-1&&t.id!=s) b=w
				else b=t.bir
				if(dis[to]>t.v+w)
				{
					ndis[to]=dis[to]
					nbir[to]=bir[to]
					dis[to]=t.v+w
					bir[to]=b
					q.add(node(to,t.id,bir[to],dis[to]))
				}
				else if(ndis[to]>t.v+w)
				{
					ndis[to]=t.v+w
					nbir[to]=b
					q.add(node(to,t.id,nbir[to],ndis[to]))
				}
			}
		}
	}
}
