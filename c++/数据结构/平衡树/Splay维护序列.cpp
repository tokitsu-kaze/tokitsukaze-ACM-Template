struct Splay
{
	#define type int
	const type inf=INF;
	const type zero=0;
	struct node
	{
		int ch[2],fa,sz,cnt,rev,tag;
		type v;
	}t[MAX];
	int tot,root;
	type a[MAX];
	queue<int> pool;
	void init_null_node()
	{
		memset(t[0].ch,0,sizeof t[0].ch);
		t[0].sz=t[0].cnt=t[0].fa=0;
		t[0].v=zero;
		t[0].mnid=0;
	}
	void init()
	{
		root=tot=0;
		while(!pool.empty()) pool.pop();
		init_null_node();
		a[0]=a[1]=zero;
		root=build(0,1,0);
	}
	int newnode(type v,int fa)
	{
		int id;
		if(pool.size()>0)
		{
			id=pool.front();
			pool.pop();
		}
		else id=++tot;
		memset(t[id].ch,0,sizeof t[id].ch);
		t[id].fa=fa;
		t[id].sz=t[id].cnt=1;
		t[id].tag=t[id].rev=0;
		t[id].v=v;
		return id;
	}
	void pushup(int id)
	{
		int ls=t[id].ch[0];
		int rs=t[id].ch[1];
		t[id].sz=t[ls].sz+t[rs].sz+t[id].cnt;
		
		
	}
	void pushdown(int id)
	{
		int ls=t[id].ch[0];
		int rs=t[id].ch[1];
		if(t[id].tag)
		{
			if(ls)
			{
				
				t[ls].tag=1;
			}
			if(rs)
			{
				
				t[rs].tag=1;
			}
			t[id].tag=0;
		}
		if(t[id].rev)
		{
			t[ls].rev^=1;
			t[rs].rev^=1;
			swap(t[ls].ch[0],t[ls].ch[1]);
			swap(t[rs].ch[0],t[rs].ch[1]);
			t[id].rev=0;
		}
	}
	void insert(int pos,vector<int> nums)
	{
		int x,y,z,i;
		for(i=0;i<nums.size();i++) a[i+1]=nums[i];
		z=build(1,nums.size(),0);
		x=find(pos);
		y=find(pos+1);
		splay(x,0);
		splay(y,x);
		t[y].ch[0]=z;
		t[z].fa=y;
		pushup(y);
		pushup(x);
	}
	void rotate(int x)
	{
		int y,z,k;
		y=t[x].fa;
		z=t[y].fa;
		k=(x==t[y].ch[1]);
		t[y].ch[k]=t[x].ch[k^1];
		if(t[x].ch[k^1]) t[t[x].ch[k^1]].fa=y;
		t[x].ch[k^1]=y;
		t[y].fa=x;
		t[x].fa=z;
		if(z) t[z].ch[y==t[z].ch[1]]=x;
		pushup(y);
		pushup(x);
	}
	void splay(int x,int goal)
	{
		int y,z;
		while(t[x].fa!=goal)
		{
			y=t[x].fa;
			z=t[y].fa;
			if(z!=goal)
			{
				if((t[z].ch[0]==y)^(t[y].ch[0]==x)) rotate(x);
				else rotate(y);
			}
			rotate(x);
		}
		if(goal==0) root=x;
	}
	int kth(int k)//k small
	{
		int id=root;
		while(id)
		{
			pushdown(id);
			if(t[t[id].ch[0]].sz>=k) id=t[id].ch[0];
			else if(t[t[id].ch[0]].sz+t[id].cnt>=k) break;
			else
			{
				k-=t[t[id].ch[0]].sz+t[id].cnt;
				id=t[id].ch[1];
			}
		}
		splay(id,0);
		return id;
	}
	int find(int x){return kth(x+1);}
	int build(int l,int r,int fa)
	{
		if(l>r) return 0;
		int id,mid;
		mid=(l+r)>>1;
		id=newnode(a[mid],fa);
		t[id].ch[0]=build(l,mid-1,id);
		t[id].ch[1]=build(mid+1,r,id);
		pushup(id);
		return id;
	}
	void _del(int id)
	{
		if(!id) return;
		pool.push(id);
		_del(t[id].ch[0]);
		_del(t[id].ch[1]);
	}
	void erase(int l,int r)
	{
		int x,fa;
		x=split(l,r);
		fa=t[x].fa;
		t[fa].ch[0]=0;
		_del(x);
		pushup(fa);
		pushup(t[fa].fa);
	}
	int split(int l,int r)
	{
		int x,y;
		x=find(l-1);
		y=find(r+1);
		splay(x,0);
		splay(y,x);
		return t[y].ch[0];
	}
	void rev(int l,int r)
	{
		int x,fa;
		x=split(l,r);
		fa=t[x].fa;
		t[x].rev^=1;
		swap(t[x].ch[0],t[x].ch[1]);
		pushup(fa);
		pushup(t[fa].fa);
	}
	int ask(int l,int r)
	{
		int x=split(l,r);
		return ;
	}
	int size(){return t[root].sz-2;}
	#undef type
}tr; //tr.init();
