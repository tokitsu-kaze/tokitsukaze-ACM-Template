struct President_Tree
{
	#define type int
	int root[MAX],ls[MAX<<5],rs[MAX<<5],tot,ql,qr,n;
	type v[MAX<<5],tag[MAX<<5],qv;
	void init(int _n)
	{
		n=_n;
		ls[0]=rs[0]=v[0]=tag[0]=tot=0;
	}
	int copy_node(int x)
	{
		tot++;
		ls[tot]=ls[x];
		rs[tot]=rs[x];
		v[tot]=v[x];
		tag[tot]=v[x];
		return tot;
	}
	void update(int l,int r,int &id,int pre)
	{
		if(!id) id=copy_node(pre);
		v[id]+=qv*(min(r,qr)-max(l,ql)+1);
		if(l>=ql&&r<=qr)
		{
			tag[id]+=qv;
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id],ls[pre]);
		if(qr>mid) update(mid+1,r,rs[id],rs[pre]);
	}
	void create_ver(int now_ver,int pre_ver,int l,int r,type v)
	{
		root[now_ver]=0;
		upd_ver(now_ver,pre_ver,l,r,v);
	}
	void update_ver(int now_ver,int pre_ver,int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,root[now_ver],root[pre_ver]);
	}
}tr;
/*
tr.init(n);
tr.create_ver(now_ver,pre_ver,l,r,v);
tr.update_ver(now_ver,pre_ver,l,r,v);
*/

