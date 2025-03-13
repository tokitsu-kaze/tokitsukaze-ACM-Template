struct Persistent_Segment_Tree
{
	#define type int
	int root[MAX],ls[MAX<<5],rs[MAX<<5],tot,ql,qr,n;
	type v[MAX<<5],qv,res;
	void init(int _n)
	{
		n=_n;
		root[0]=0;
		ls[0]=rs[0]=v[0]=tot=0;
	}
	int copy_node(int x)
	{
		++tot;
		ls[tot]=ls[x];
		rs[tot]=rs[x];
		v[tot]=v[x];
		return tot;
	}
	void update(int l,int r,int &id,int pre)
	{
		if(!id) id=copy_node(pre);
		v[id]+=qv;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id]=0,ls[pre]);
		else update(mid+1,r,rs[id]=0,rs[pre]);
	}
	void query_valsum(int l,int r,int id,int pre)
	{
		if(!id) return;
		if(l>=ql&&r<=qr)
		{
			res+=v[id]-v[pre];
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) query_valsum(l,mid,ls[id],ls[pre]);
		if(qr>mid) query_valsum(mid+1,r,rs[id],rs[pre]);
	}
	int kth_small(int l,int r,int id,int pre,int k)
	{
		if(l==r) return l;
		int mid=(l+r)>>1;
		int tmp=v[ls[id]]-v[ls[pre]];
		if(tmp>=k) return kth_small(l,mid,ls[id],ls[pre],k);
		else return kth_small(mid+1,r,rs[id],rs[pre],k-tmp);
	}
	void update_ver(int now_ver,int pre_ver,int pos,type v)
	{
		ql=qr=pos;
		qv=v;
		update(1,n,root[now_ver],root[pre_ver]);
	}
	void copy_ver(int now_ver,int pre_ver)
	{
		root[now_ver]=root[pre_ver];
	}
	void create_ver(int now_ver,int pre_ver,int pos,type v)
	{
		root[now_ver]=0;
		update_ver(now_ver,pre_ver,pos,v);
	}
	int ask_kth_small(int l,int r,int k)
	{
		return kth_small(1,n,root[r],root[l-1],k);
	}
	type ask_valsum(int pre_ver,int now_ver,int val_l,int val_r)
	{
		ql=val_l;
		qr=val_r;
		res=0;
		query_valsum(1,n,root[now_ver],root[pre_ver-1]);
		return res;
	}
	#undef type
}tr;
/*
tr.init(n);
tr.create_ver(now_ver,pre_ver,pos,v);
tr.copy_ver(now_ver,pre_ver);
tr.ask_kth_small(l,r,k);
tr.ask_valsum(l,r,val_l,val_r);
*/
