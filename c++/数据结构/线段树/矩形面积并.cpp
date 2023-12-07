#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=4e5+10;
struct Discretization
{
	#define type ll
	#define pb push_back
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.pb(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return lower_bound(all(a),x)-a.begin()+1;}
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef pb
	#undef all
}dz;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type a[MAX],v[MAX<<2],mn[MAX<<2],tag[MAX<<2],cntmn[MAX<<2],qv;
	void pushup(int id)
	{
		mn[id]=min(mn[ls],mn[rs]);
		if(mn[ls]==mn[rs]) cntmn[id]=cntmn[ls]+cntmn[rs];
		else cntmn[id]=(mn[ls]<mn[rs]?cntmn[ls]:cntmn[rs]);
		v[id]=v[ls]+v[rs];
	}
	void maintain(int pre,int now,int id)
	{
		if(pre==0&&now>0) v[id]+=cntmn[id];
		if(pre>0&&now==0) v[id]-=cntmn[id];
	}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		maintain(mn[ls],mn[ls]+tag[id],ls);
		maintain(mn[rs],mn[rs]+tag[id],rs);
		mn[ls]+=tag[id];
		mn[rs]+=tag[id];
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		if(l==r)
		{
			mn[id]=0;
			cntmn[id]=dz.get_val(l)-dz.get_val(l-1);
			v[id]=0;
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			maintain(mn[id],mn[id]+qv,id);
			mn[id]+=qv;
			tag[id]+=qv;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	type res;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res+=v[id];
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)//init res
	{
		ql=l;
		qr=r;
		res=0;
		query(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
struct node{int pos,l,r,v;};
ll work(vector<node> &res)
{
	int i,j,pos;
	ll ans;
	sort(res.begin(),res.end(),[&](node x,node y){
		if(x.pos==y.pos) return x.v>y.v;
		return x.pos<y.pos;
	});
	ans=0;
	pos=1;
	tr.build(dz.size());
	for(i=0;i<res.size();i++)
	{
		if(i) ans+=tr.ask(1,dz.size())*(res[i].pos-pos);
		tr.upd(dz.get_pos(res[i].l),dz.get_pos(res[i].r),res[i].v);
		pos=res[i].pos;
	}
	ans+=tr.ask(2,dz.size())*(res[i].pos-pos);
	return ans;
}
int main()
{
	int n,i,a,b,c,d;
	scanf("%d",&n);
	vector<node> x;
	dz.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		dz.add(b);
		dz.add(b-1);
		dz.add(d-2);
		dz.add(d-1);
		x.push_back({a,b,d-1,1});
		x.push_back({c,b,d-1,-1});
	}
	dz.work();
	printf("%lld\n",work(x));
	return 0;
}

