struct Segment_Tree
{
	#define type int    //may need change
	#define NONE INF    //may need change
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	pair<type,type> a[MAX],mx[2][MAX<<2],mn[2][MAX<<2];
	pair<type,type> rmx[2],rmn[2];
	void upmx(int id)
	{
		type tx[4]={mx[0][id].fi,mx[1][id].fi,rmx[0].fi,rmx[1].fi};
		type tc[4]={mx[0][id].se,mx[1][id].se,rmx[0].se,rmx[1].se};
		int idx[4]={0,1,2,3},cnt=0;
		sort(idx,idx+4,[&](int a,int b){return tx[a]>tx[b];});
		for(int i=0;i<4&&cnt<2;i++)
		{
			if(i==0||tc[idx[i]]!=tc[idx[i-1]])
			{
				rmx[cnt].fi=tx[idx[i]];
				rmx[cnt++].se=tc[idx[i]];
			}
		}
		for(int i=cnt;i<2;i++) rmx[i]=MP(-NONE,-NONE);
	}
	void upmn(int id)
	{
		type tx[4]={mn[0][id].fi,mn[1][id].fi,rmn[0].fi,rmn[1].fi};
		type tc[4]={mn[0][id].se,mn[1][id].se,rmn[0].se,rmn[1].se};
		int idx[4]={0,1,2,3},cnt=0;
		sort(idx,idx+4,[&](int a,int b){return tx[a]<tx[b];});
		for(int i=0;i<4&&cnt<2;i++)
		{
			if(i==0||tc[idx[i]]!=tc[idx[i-1]])
			{
				rmn[cnt].fi=tx[idx[i]];
				rmn[cnt++].se=tc[idx[i]];
			}
		}
		for(int i=cnt;i<2;i++) rmn[i]=MP(NONE,-NONE);
	}
	void pushup(int id)
	{
		mx[0][id]=mx[0][ls];
		rmx[0]=mx[0][rs];
		mx[1][id]=mx[1][ls];
		rmx[1]=mx[1][rs];
		upmx(id);
		mx[0][id]=rmx[0];
		mx[1][id]=rmx[1];
		
		mn[0][id]=mn[0][ls];
		rmn[0]=mn[0][rs];
		mn[1][id]=mn[1][ls];
		rmn[1]=mn[1][rs];
		upmn(id);
		mn[0][id]=rmn[0];
		mn[1][id]=rmn[1];
	}
	void build(int l,int r,int id)
	{
		mx[1][id]=MP(-NONE,-NONE);
		mn[1][id]=MP(NONE,-NONE);
		if(l==r)
		{
			mx[0][id]=mn[0][id]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)//only l==r
	{
		mx[1][id]=MP(-NONE,-NONE);
		mn[1][id]=MP(NONE,-NONE);
		if(l>=ql&&r<=qr)
		{
			mx[0][id]=mn[0][id]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			upmx(id);
			upmn(id);
			return ;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r)
	{
		ql=l;
		qr=r;
		update(1,n,1);
	}
	void ask(int l,int r)
	{
		rmx[0]=rmx[1]=MP(-NONE,-NONE);
		rmn[0]=rmn[1]=MP(NONE,-NONE);
		ql=l;
		qr=r;
		query(1,n,1);
		
		// something
	}
	#undef type
	#undef NONE
	#undef ls
	#undef rs
}tr;
