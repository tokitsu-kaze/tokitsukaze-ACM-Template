data class node(var x:Int,var y:Int)
var dir=arrayOf(
arrayOf(0,1),
arrayOf(1,0),
arrayOf(0,-1),
arrayOf(-1,0)
)
var dis=Array(1){IntArray(1)}
fun bfs(n:Int,m:Int,sx:Int,sy:Int,mp:Array<CharArray>)
{
	dis=Array(n){IntArray(m){INF}}
	dis[sx][sy]=0
	val q:Queue<node> = LinkedList()
	q.offer(node(sx,sy))
	while(!q.isEmpty())
	{
		var t=q.peek()
		q.poll()
		for(i in 0..3)
		{
			var nex=t.copy()
			nex.x+=dir[i][0]
			nex.y+=dir[i][1]
			if(nex.x<0||nex.x>=n||nex.y<0||nex.y>=m) continue
			if(mp[nex.x][nex.y]=='#') continue
			if(dis[nex.x][nex.y]>dis[t.x][t.y]+1)
			{
				dis[nex.x][nex.y]=dis[t.x][t.y]+1
				q.offer(nex)
			}
		}
	}
}
