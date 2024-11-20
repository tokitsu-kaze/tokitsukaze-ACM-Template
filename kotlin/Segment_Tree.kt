class Segment_Tree<T:Number>()
{
	class node<Long>(){
		var v=0L
	}
	var t=Array<node<Long>>(1){node()}
	var tag=LongArray(1)
	var n:Int=0
	var ql:Int=0
	var qr:Int=0
	var qv=0L
	var qop:Int=0
	
	fun merge(x:node<Long>,y:node<Long>):node<Long>
	{
		var res=node<Long>()
		res.v=max(x.v,y.v)
		return res
	}
	fun pushup(id:Int){t[id]=merge(t[id shl 1],t[id shl 1 or 1])}
	fun pushdown(l:Int,r:Int,id:Int)
	{
		if(tag[id]==0L) return
		var mid=(l+r) shr 1
		var ls=id shl 1
		var rs=id shl 1 or 1
		t[ls].v+=tag[id]
		t[rs].v+=tag[id]
		tag[ls]+=tag[id]
		tag[rs]+=tag[id]
		tag[id]=0L
	}
	fun build(l:Int,r:Int,id:Int)
	{
		tag[id]=0L
		t[id].v=0L
		if(l==r) return
		var mid=(l+r) shr 1
		build(l,mid,id shl 1)
		build(mid+1,r,id shl 1 or 1)
		pushup(id)
	}
	fun update(l:Int,r:Int,id:Int)
	{
		if(l>=ql&&r<=qr)
		{
			if(qop==1)
			{
				tag[id]+=qv
				t[id].v+=qv
			}
			else
			{
				t[id].v=max(t[id].v,qv)
			}
			return
		}
		pushdown(l,r,id)
		var mid=(l+r) shr 1
		if(ql<=mid) update(l,mid,id shl 1)
		if(qr>mid) update(mid+1,r,id shl 1 or 1)
		pushup(id)
	}
	fun query(l:Int,r:Int,id:Int):node<Long>
	{
		if(l>=ql&&r<=qr) return t[id]
		pushdown(l,r,id)
		var mid=(l+r) shr 1
		if(qr<=mid) return query(l,mid,id shl 1)
		if(ql>mid) return query(mid+1,r,id shl 1 or 1)
		return merge(query(l,mid,id shl 1),
                     query(mid+1,r,id shl 1 or 1))
	}
	fun build(_n:Int)
	{
		n=_n;
		t=Array<node<Long>>((n+5) shl 2){node()}
		tag=LongArray((n+5) shl 2)
		build(1,n,1)
	}
	fun upd(l:Int,r:Int,v:T,op:Int)
	{
		if(l>r) return
		ql=l
		qr=r
		qv=v.toLong()
		qop=op
		update(1,n,1)
	}
	fun ask(l:Int,r:Int):T
	{
		if(l>r) return 0 as T
		ql=l
		qr=r
		return query(1,n,1).v as T
	}
}
