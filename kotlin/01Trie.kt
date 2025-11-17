class Trie
{
	var LOG=30
	var K=LOG+2
	var rt=0
	var root=IntArray(MAX){0}
	var tot=0
	var ch=Array(MAX*K){IntArray(2){0}}
	var v=LongArray(MAX*K){0L}
	fun newnode():Int
	{
		tot++
		ch[tot][0]=0
		ch[tot][1]=0
		v[tot]=0
		return tot
	}
	fun init()
	{
		var n=1 //
		ch[0][0]=0
		ch[0][1]=0
		v[0]=0L
		tot=1
		for(i in 0..n) root[i]=0
		rt=1
	}
	fun insert(x:Long,qv:Long)
	{
		if(root[rt]==0) root[rt]=newnode()
		var id=root[rt]
		for(i in LOG downTo 0)
		{
			v[id]+=qv
			var t=((x shr i) and 1).toInt()
			if(ch[id][t]==0) ch[id][t]=newnode()
			id=ch[id][t]
		}
		v[id]+=qv
	}
	fun count_y(x:Long,limt:Long):Long // count y: x xor y <= limt
	{
		if(root[rt]==0) return 0
		var id=root[rt]
		var res=0L
		for(i in LOG downTo 0)
		{
			var t=((x shr i) and 1).toInt()
			if((limt shr i) and 1 > 0)
			{
				res+=v[ch[id][t]]
				id=ch[id][t xor 1]
			}
			else id=ch[id][t]
		}
		res+=v[id]
		return res
	}
}
