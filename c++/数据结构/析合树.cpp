struct Permutation_Tree
{
	struct RMQ
	{
		#define type int
		int lg[MAX],bin[22];
		type mx[MAX][22],mn[MAX][22];
		void work(int n,type *v)
		{
			int i,j;
			for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
			for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
			for(i=1;i<=n;i++) mx[i][0]=mn[i][0]=v[i];
			for(j=1;1<<(j-1)<=n;j++)
			{
				for(i=1;i+bin[j]-1<=n;i++)
				{
					mx[i][j]=max(mx[i][j-1],mx[i+bin[j-1]][j-1]);
					mn[i][j]=min(mn[i][j-1],mn[i+bin[j-1]][j-1]);
				}
			}
		}
		type ask_max(int l,int r)
		{
			int t=lg[r-l+1];
			return max(mx[l][t],mx[r-bin[t]+1][t]);
		}
		type ask_min(int l,int r)
		{
			int t=lg[r-l+1];
			return min(mn[l][t],mn[r-bin[t]+1][t]);
		}
		#undef type
	}rmq;
	struct Segment_Tree
	{
		#define type int
		#define ls (id<<1)
		#define rs (id<<1|1)
		int n,ql,qr;
		type mn[MAX<<2],tag[MAX<<2],qv;
		void mdf(int id,type v){mn[id]+=v,tag[id]+=v;}
		void pushup(int id){mn[id]=min(mn[ls],mn[rs]);}
		void pushdown(int id)
		{
			if(!tag[id]) return;
			mdf(ls,tag[id]);
			mdf(rs,tag[id]);
			tag[id]=0;
		}
		void build(int l,int r,int id)
		{
			tag[id]=mn[id]=0;
			if(l==r) return;
			int mid=(l+r)>>1;
			build(l,mid,ls);
			build(mid+1,r,rs);
			pushup(id);
		}
		void update(int l,int r,int id)
		{
			if(l>=ql&&r<=qr){mdf(id,qv);return;}
			pushdown(id);
			int mid=(l+r)>>1;
			if(ql<=mid) update(l,mid,ls);
			if(qr>mid) update(mid+1,r,rs);
			pushup(id);
		}
		int query(int l,int r,int id)
		{
			if(l==r) return l;
			pushdown(id);
			int mid=(l+r)>>1;
			if(!mn[ls]) return query(l,mid,ls);
			else query(mid+1,r,rs);
		}
		void build(int _n){n=_n;build(1,n,1);}
		void upd(int l,int r,type v){ql=l;qr=r;qv=v;update(1,n,1);}
		type ask(int l,int r){ql=l;qr=r;return query(1,n,1);}
		#undef type
		#undef ls
		#undef rs
	}tr;
	bool check(int l,int r){return rmq.ask_max(l,r)-rmq.ask_min(l,r)==r-l;}
	int st[MAX],st1[MAX],st2[MAX],top,top1,top2,m[MAX];
	int tot,id[MAX],l[MAX],r[MAX],type[MAX];
	VI mp[MAX];
	void add_edge(int a,int b){mp[a].pb(b);}
	int build(int n,int *a)
	{
		int now,i,tmp;
		tr.build(n);
		rmq.work(n,a);
		for(i=0;i<=2*n;i++)
		{
			mp[i].clear();
			type[i]=0;
		}
		top=top1=top2=0;
		tot=0;
		for(i=1;i<=n;i++)
		{
			while(top1&&a[i]<=a[st1[top1]])
			{
				tr.upd(st1[top1-1]+1,st1[top1],a[st1[top1]]);
				top1--;
			}
			while(top2&&a[i]>=a[st2[top2]])
			{
				tr.upd(st2[top2-1]+1,st2[top2],-a[st2[top2]]);
				top2--;
			}
			tr.upd(st1[top1]+1,i,-a[i]);
			st1[++top1]=i;
			tr.upd(st2[top2]+1,i,a[i]);
			st2[++top2]=i;
			id[i]=++tot;
			l[tot]=r[tot]=i;
			tmp=tr.ask(1,n);
			now=tot;
			while(top&&l[st[top]]>=tmp)
			{
				if(type[st[top]]&&check(m[st[top]],i))
				{
					r[st[top]]=i;
					add_edge(st[top],now);
					now=st[top--];
				}
				else if(check(l[st[top]],i))
				{
					type[++tot]=1;
					l[tot]=l[st[top]];
					r[tot]=i;
					m[tot]=l[now];
					add_edge(tot,st[top--]);
					add_edge(tot,now);
					now=tot;
				}
				else
				{
					add_edge(++tot,now);
					do
					{
						add_edge(tot,st[top--]);
					}while(top&&!check(l[st[top]],i));
					l[tot]=l[st[top]];
					r[tot]=i;
					add_edge(tot,st[top--]);
					now=tot;
				}
			}
			st[++top]=now;
			tr.upd(1,i,-1);
		}
		return st[1];
	}
	void work(int n,int *a)// a[1..n]
	{
		int rt=build(n,a);
		
	}
}pt;// MAX must *2
