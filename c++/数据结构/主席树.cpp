struct president_tree
{
	#define type int
	int root[MAX],ls[40*MAX],rs[40*MAX],tot,ql,qr;
	type sum[40*MAX],qv;
	void init()
	{
		mem(root,0);
		tot=1;
		ls[0]=rs[0]=sum[0]=0;
	}
	int newnode(int x)
	{
		ls[tot]=ls[x];
		rs[tot]=rs[x];
		sum[tot]=sum[x];
		return tot++;
	}
	void insert(int l,int r,int &id,int pre) //set(ql,ql,v)
	{
		id=newnode(pre);
		sum[id]+=qv;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(ql<=mid) insert(l,mid,ls[id],ls[pre]);
		else insert(mid+1,r,rs[id],rs[pre]);
	}
	int kindcnt(int l,int r,int id) //set(ql,qr)
	{
		if(ql<=l&&r<=qr) return sum[id]; 
		int mid=(l+r)>>1;
		int res=0;
		if(ql<=mid) res+=kindcnt(l,mid,ls[id]);
		if(qr>=mid+1) res+=kindcnt(mid+1,r,rs[id]);
		return res;
	}
	int kthsmall(int l,int r,int id,int pre,int k)
	{
		if(l==r) return l;
		int mid=(l+r)>>1;
		int temp=sum[ls[id]]-sum[ls[pre]];
		if(temp>=k) return kthsmall(l,mid,ls[id],ls[pre],k);
		else return kthsmall(mid+1,r,rs[id],rs[pre],k-temp);
	}
	int kthbig(int l,int r,int id,int pre,int k)
	{
		if(l==r) return l;
		int mid=(l+r)>>1;
		int temp=sum[rs[id]]-sum[rs[pre]];
		if(temp>=k) return kthbig(mid+1,r,rs[id],rs[pre],k);
		else return kthbig(l,mid,ls[id],ls[pre],k-temp);
	}
	void set(int l,int r,type v=0){ql=l;qr=r;qv=v;}
}pt;
