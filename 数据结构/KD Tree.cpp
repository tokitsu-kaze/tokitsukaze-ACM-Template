namespace kd_tree
{
	const double alpha=0.75;
	const int dim=2;
	#define type int
	const type NONE=INF;   //初始值 
	struct kdtnode
	{
		bool exist;
		int l,r,sz,fa,dep,x[dim],mx[dim],mn[dim];
		type v,tag;
		kdtnode(){}
		void initval()
		{
			sz=exist;tag=v;
			if(exist) for(int i=0;i<dim;i++) mn[i]=mx[i]=x[i];
		}
		void null()
		{
			exist=sz=0;
			v=tag=NONE;
			for(int i=0;i<dim;i++)
			{
				mx[i]=-INF;
				mn[i]=INF;
			}
		}
		void newnode(int x0,int x1,type val=NONE)
		{
			x[0]=x0;
			x[1]=x1;
			l=r=fa=0;
			exist=1;
			v=val;
			initval();
		}
		kdtnode(int a,int b,type d=NONE){newnode(a,b,d);}
	};
	struct KDT
	{
		#define ls t[id].l
		#define rs t[id].r
		kdtnode t[MAX];
		int tot,idx,root;
		inline void pushup(int id)
		{
			t[id].initval();
			t[id].sz+=t[ls].sz+t[rs].sz;
			t[id].tag=min({t[ls].tag,t[rs].tag,t[id].tag});
			for(int i=0;i<dim;i++)
			{
				if(ls)
				{
					t[id].mx[i]=max(t[id].mx[i],t[ls].mx[i]);
					t[id].mn[i]=min(t[id].mn[i],t[ls].mn[i]);
				}
				if(rs)
				{
					t[id].mx[i]=max(t[id].mx[i],t[rs].mx[i]);
					t[id].mn[i]=min(t[id].mn[i],t[rs].mn[i]);
				}
			}
		}
		bool isbad(int id){return t[id].sz*alpha+3<max(t[ls].sz,t[rs].sz);}
		int st[MAX],top;
		void build(int &id,int l,int r,int fa,int dep=0)
		{
			id=0;if(l>r) return;
			int m=(l+r)>>1; idx=dep;
			nth_element(st+l,st+m,st+r+1,[&](int x,int y){return t[x].x[idx]<t[y].x[idx];});
			id=st[m];
			build(ls,l,m-1,id,(dep+1)%dim);
			build(rs,m+1,r,id,(dep+1)%dim);
			pushup(id);
			t[id].dep=dep;
			t[id].fa=fa;
		}
		inline void init(int n=0)
		{
			root=0;
			t[0].null();
			for(int i=1;i<=n;i++) st[i]=i;
			if(n) build(root,1,n,0);
			tot=n;
		}
		void travel(int id)
		{
			if(!id) return;
			if(t[id].exist) st[++top]=id;
			travel(ls);
			travel(rs);
		}
		void rebuild(int &id,int dep)
		{
			top=0;travel(id);
			build(id,1,top,t[id].fa,dep);
		}
		void insert(int &id,int now,int fa,int dep=0)
		{
			if(!id)
			{
				id=now;
				t[id].dep=dep;
				t[id].fa=fa;
				return;
			}
			if(t[now].x[dep]<t[id].x[dep]) insert(ls,now,id,(dep+1)%dim);
			else insert(rs,now,id,(dep+1)%dim);
			pushup(id);
			if(isbad(id)) rebuild(id,t[id].dep);
			t[id].dep=dep;
			t[id].fa=fa;
		}
		inline void insert(kdtnode x){t[++tot]=x;insert(root,tot,0,0);}
		inline void del(int id)
		{
			if(!id) return;
			t[id].null();
			int x=id;
			while(x)
			{
				pushup(x);
				x=t[x].fa;
			}
			if(isbad(id))
			{
				x=t[id].fa;
				rebuild(root==id?root:(t[x].l==id?t[x].l:t[x].r),t[id].dep);
			}
		}
		kdtnode q;
		ll dist(ll x,ll y){return x*x+y*y;}
		ll getdist(int id)//点q离区域t[id]最短距离 
		{
			if(!id) return LLINF;
			ll res=0;
			if(q.x[0]<t[id].mn[0]) res+=dist(q.x[0]-t[id].mn[0],0);
			if(q.x[1]<t[id].mn[1]) res+=dist(q.x[1]-t[id].mn[1],0);
			if(q.x[0]>t[id].mx[0]) res+=dist(q.x[0]-t[id].mx[0],0);
			if(q.x[1]>t[id].mx[1]) res+=dist(q.x[1]-t[id].mx[1],0);
			return res;
		}
		kdtnode a,b;
		inline int check(kdtnode &x)//x在矩形(a,b)内 
		{
			int ok=1;
			for(int i=0;i<dim;i++)
			{
				ok&=(x.x[i]>=a.x[i]);
				ok&=(x.x[i]<=b.x[i]);
			}
			return ok;
		}
		inline int allin(kdtnode &x)//x的子树全在矩形(a,b)内 
		{
			int ok=1;
			for(int i=0;i<dim;i++)
			{
				ok&=(x.mn[i]>=a.x[i]);
				ok&=(x.mx[i]<=b.x[i]);
			}
			return ok;
		}
		inline int allout(kdtnode &x)//x的子树全不在矩形(a,b)内 
		{
			int ok=0;
			for(int i=0;i<dim;i++)
			{
				ok|=(x.mx[i]<a.x[i]);
				ok|=(x.mn[i]>b.x[i]);
			}
			return ok;
		}
		type res;
		void query(int id)
		{
			if(!id) return;
			if(allout(t[id])||t[id].sz==0) return;
			if(allin(t[id]))
			{
				res=min(res,t[id].tag);
				return;
			}
			if(check(t[id])&&t[id].exist) res=min(res,t[id].v);
			int l,r;
			l=ls;
			r=rs;
			if(t[l].tag>t[r].tag) swap(l,r);
			if(t[l].tag<res) query(l);
			if(t[r].tag<res) query(r);
		}
		inline type query(kdtnode _a,kdtnode _b)
		{
			a=_a;b=_b;
			res=INF;
			query(root);
			return res;
		}
	}kd;
	#undef type
	#undef ls
	#undef rs
}
using namespace kd_tree;
