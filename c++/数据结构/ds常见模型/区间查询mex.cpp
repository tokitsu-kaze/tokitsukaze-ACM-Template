struct Range_Mex
{
	int root[MAX],ls[MAX<<5],rs[MAX<<5],mn[MAX<<5];
	int tot,qpos,qv,mxans;
	int copy_node(int x)
	{
		++tot;
		ls[tot]=ls[x];
		rs[tot]=rs[x];
		mn[tot]=mn[x];
		return tot;
	}
	void update(int l,int r,int &id,int pre)
	{
		if(!id) id=copy_node(pre);
		if(l==r)
		{
			mn[id]=qv;
			return;
		}
		int mid=(l+r)>>1;
		if(qpos<=mid) update(l,mid,ls[id]=0,ls[pre]);
		else update(mid+1,r,rs[id]=0,rs[pre]);
		mn[id]=min(mn[ls[id]],mn[rs[id]]);
	}
	int ask(int l,int r,int id,int pos)
	{
		if(l==r) return l;
		int mid=(l+r)>>1;
		if(mn[ls[id]]<pos) return ask(l,mid,ls[id],pos);
		else return ask(mid+1,r,rs[id],pos);
	}
	void work(int n,int *a)
	{
		int i;
		root[0]=0;
		ls[0]=rs[0]=mn[0]=tot=0;
		mxans=n;
		for(i=1;i<=n;i++)
		{
			if(a[i]>mxans)
			{
				root[i]=root[i-1];
				continue;
			}
			qpos=a[i];
			qv=i;
			update(0,mxans,root[i]=0,root[i-1]);
		}
	}
	int ask_mex(int l,int r){return ask(0,mxans,root[r],l);}
}rm;
/*
rm.work(n,a);  // a[1..n]
rm.ask_mex(l,r);
*/
