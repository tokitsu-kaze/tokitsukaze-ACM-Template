//矩形面积并
struct node
{
	ll l,r,h;
	int tag;
	friend bool operator <(node a,node b)
	{
		return a.h<b.h;
	}
}seg[MAX<<1];//线段 
ll x[MAX<<1];//横坐标离散化 
struct Segment_Tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	ll n,ql,qr,qv;
	ll cover[MAX<<3],len[MAX<<3];//注意这里要开8倍 
	void build(ll _n)
	{
		mem(cover,0);
		mem(len,0);
		n=_n;
	}
	void callen(int id,int l,int r)
	{
		if(cover[id]) len[id]=x[r+1]-x[l];//被整段覆盖
		else if(l==r) len[id]=0;//不是一条线段
		else len[id]=len[ls]+len[rs];//是一条线段但又没有被整段覆盖 
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			cover[id]+=qv;//覆盖情况
			callen(id,l,r);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		callen(id,l,r);
	}
}tree;
int main()
{
	int n,i,tot,l,r,cnt;
	ll x1,y1,x2,y2,ans;
	while(~scanf("%d",&n)&&n)
	{
		tot=0;
		mem(x,0);
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
			//矩形的左下和右上坐标 
			x[tot]=x1;
			seg[tot].tag=-1; 
			seg[tot].l=x1;
			seg[tot].r=x2;
			seg[tot++].h=y1;
			//上边界 
			x[tot]=x2;
			seg[tot].tag=1;
			seg[tot].l=x1;
			seg[tot].r=x2;
			seg[tot++].h=y2;
			//下边界 
		}
		sort(seg,seg+tot);//线段按纵坐标升序 
		sort(x,x+tot);//横坐标升序
		cnt=unique(x,x+tot)-x;
		tree.build(cnt-1);
		ans=0;
		for(i=0;i<tot;i++)
		{
			if(i) ans+=(seg[i].h-seg[i-1].h)*tree.len[1];
			tree.ql=lower_bound(x,x+cnt-1,seg[i].l)-x;
			tree.qr=lower_bound(x,x+cnt-1,seg[i].r)-x-1;
			tree.qv=seg[i].tag;
			tree.update(0,cnt-1,1);
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
