#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e4+10;
struct Treap
{
	#define type int
	#define inf INF
	struct node
	{
		int ch[2],fix,sz,cnt;
		type v;
		node(){}
		node(type x,int _sz)
		{
			v=x;
			fix=rand();
			sz=cnt=_sz;
			ch[0]=ch[1]=0;
		} 
	}t[MAX*40];
	int tot,root[MAX<<2],rt;
	void init(int n=1)
	{
		for(int i=0;i<=n;i++) root[i]=0;
		rt=1;
		srand(time(0));
		tot=0;
		t[0].sz=t[0].cnt=0;
		memset(t[0].ch,0,sizeof t[0].ch);
	}
	void pushup(int id)  
	{  
		t[id].sz=t[t[id].ch[0]].sz+t[t[id].ch[1]].sz+t[id].cnt;  
	}  
	void rotate(int &id,int k)
	{
		int y=t[id].ch[k^1];
		t[id].ch[k^1]=t[y].ch[k];
		t[y].ch[k]=id;
		pushup(id);
		pushup(y);
		id=y;
	}
	void _insert(int &id,type v,int cnt)
	{
		if(!id)
		{
			id=++tot;
			t[id]=node(v,cnt);
			return;
		}
		if(t[id].v==v) t[id].cnt+=cnt;
		else
		{
			int tmp=(v>t[id].v);
			_insert(t[id].ch[tmp],v,cnt);
			if(t[t[id].ch[tmp]].fix>t[id].fix) rotate(id,tmp^1);
		}
		pushup(id);
	}
	void _erase(int &id,type v,int cnt)
	{
		if(!id) return;
		if(t[id].v==v)
		{
			cnt=min(t[id].cnt,cnt);
			if(t[id].cnt>cnt)
			{
				t[id].cnt-=cnt;
				pushup(id);
				return;
			}
			if(!(t[id].ch[0]&&t[id].ch[1]))
			{
				id=t[id].ch[0]+t[id].ch[1];
				return;
			}
			else
			{
				int tmp=(t[t[id].ch[0]].fix>t[t[id].ch[1]].fix);
				rotate(id,tmp);
				_erase(t[id].ch[tmp],v,cnt);
				pushup(id);
			}
		}
		else
		{
			_erase(t[id].ch[v>t[id].v],v,cnt);
			pushup(id);
		}
	}
	int _find(type key,int f)
	{
		int id=root[rt],res=0;
		while(id)
		{
			if(t[id].v<key)
			{
				res+=t[t[id].ch[0]].sz+t[id].cnt;
				if(f&&key==t[id].v) res-=t[id].cnt;
				id=t[id].ch[1];
			}
			else id=t[id].ch[0];
		}
		return res;
	}
	type find_by_order(int k)//k small
	{
		int id=root[rt];
		if(id==0) return 0;
		while(id)
		{
			if(t[t[id].ch[0]].sz>=k) id=t[id].ch[0];
			else if(t[t[id].ch[0]].sz+t[id].cnt>=k) return t[id].v;
			else
			{
				k-=t[t[id].ch[0]].sz+t[id].cnt;
				id=t[id].ch[1];
			}
		}
	}
	int count(type key)
	{
		int id=root[rt];
		while(id)
		{
			if(t[id].v<key)
			{
				if(key==t[id].v) return t[id].cnt;
				id=t[id].ch[1];
			}
			else id=t[id].ch[0];
		}
		return 0;
	}
	type find_pre(type key)
	{
		type res=-inf;
		int id=root[rt];
		while(id)
		{
			if(t[id].v<key)
			{
				res=t[id].v;
				id=t[id].ch[1];
			}
			else id=t[id].ch[0];
		}
		return res;
	}
	type find_nex(type key)
	{
		type res=inf;
		int id=root[rt];
		while(id)
		{
			if(t[id].v>key)
			{
				res=t[id].v;
				id=t[id].ch[0];
			}
			else id=t[id].ch[1];
		}
		return res;
	}
	Treap &operator[](const int _rt){this->rt=_rt;return *this;}
	void insert(type v,int sz=1){_insert(root[rt],v,sz);}
	void erase(type v,int sz=1){_erase(root[rt],v,sz);}
	int upper_bound_count(type key){return _find(key,0);}//the count <=key
	int lower_bound_count(type key){return _find(key,1);}//the count <key
	int order_of_key(type key){return lower_bound_count(key)+1;}
	int size(){return t[root[rt]].sz;}
}treap;
struct Segment_Tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type qv;
	void update(int l,int r,int id)
	{
		if(qop==1) treap[id].insert(qv);
		else treap[id].erase(qv);
		if(l>=ql&&r<=qr) return;
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
	}
	vector<int> treap_id;
	void dfs(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			treap_id.push_back(id);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) dfs(l,mid,ls);
		if(qr>mid) dfs(mid+1,r,rs);
	}
	void get_treap_id(int l,int r)
	{
		ql=l;
		qr=r;
		treap_id.clear();
		dfs(1,n,1);
	}
	void build(int _n){n=_n;treap.init(n<<2);}
	void insert(int pos,type v)
	{
		ql=qr=pos;
		qop=1;
		qv=v;
		update(1,n,1);
	}
	void erase(int pos,type v)
	{
		ql=qr=pos;
		qop=2;
		qv=v;
		update(1,n,1);
	}
	int ask_rank(int l,int r,type v)
	{
		get_treap_id(l,r);
		int res=1;
		for(auto &rt:treap_id) res+=treap[rt].order_of_key(v)-1;
		return res;
	}
	int ask_kth(int l,int r,int k)
	{
		get_treap_id(l,r);
		l=0;
		r=1e8;
		while(l<r)
		{
			int mid=(l+r)>>1,now=1;
			for(auto &rt:treap_id) now+=treap[rt].order_of_key(mid+1)-1;
			if(now<=k) l=mid+1;
			else r=mid;
		}
		return l;
	}
	type find_pre(int l,int r,type v)
	{
		get_treap_id(l,r);
		type res=-inf;
		for(auto &rt:treap_id) res=max(res,treap[rt].find_pre(v));
		if(res==-inf) return -2147483647;
		return res;
	}
	type find_nex(int l,int r,type v)
	{
		get_treap_id(l,r);
		type res=inf;
		for(auto &rt:treap_id) res=min(res,treap[rt].find_nex(v));
		if(res==inf) return 2147483647;
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
int a[MAX];
int main()
{
	int n,m,i,op,l,r,k;
	scanf("%d%d",&n,&m);
	tr.build(n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		tr.insert(i,a[i]);
	}
	while(m--)
	{
		scanf("%d%d",&op,&l);
		if(op==3) scanf("%d",&k);
		else scanf("%d%d",&r,&k);
		if(op==1) printf("%d\n",tr.ask_rank(l,r,k));
		else if(op==2) printf("%d\n",tr.ask_kth(l,r,k));
		else if(op==3)
		{
			tr.erase(l,a[l]);
			a[l]=k;
			tr.insert(l,a[l]);
		}
		else if(op==4) printf("%d\n",tr.find_pre(l,r,k));
		else if(op==5) printf("%d\n",tr.find_nex(l,r,k));
	}
	return 0;
}
