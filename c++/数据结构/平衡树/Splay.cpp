struct Splay
{
	#define type ll
	const type inf=LLINF;
	struct node
	{
		int ch[2],fa,sz,cnt;
		type v;
		node(){}
		node(type x,int _fa)
		{
			v=x;
			sz=cnt=1;
			fa=_fa;
			ch[0]=ch[1]=0;
		} 
	}t[MAX];
	int tot,root;
	void pushup(int id)  
	{  
		t[id].sz=t[t[id].ch[0]].sz+t[t[id].ch[1]].sz+t[id].cnt;  
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
	void find(type key)
	{
		int id=root;
		if(!id) return;
		while(t[id].ch[key>t[id].v] && t[id].v!=key)
		{
			id=t[id].ch[key>t[id].v];
		}
		splay(id,0);
	}
	int find_pre_id(type key)
	{
		find(key);
		if(t[root].v<key) return root;
		int id=t[root].ch[0];
		while(t[id].ch[1]) id=t[id].ch[1];
		splay(id,0);
		return id;
	}
	int find_nex_id(type key)
	{
		find(key);
		if(t[root].v>key) return root;
		int id=t[root].ch[1];
		while(t[id].ch[0]) id=t[id].ch[0];
		splay(id,0);
		return id;
	}
	void insert(type v)
	{
		int id,fa;
		id=root;
		fa=0;
		while(id&&t[id].v!=v)
		{
			fa=id;
			id=t[id].ch[v>t[id].v];
		}
		if(id) t[id].cnt++;
		else
		{
			id=++tot;
			t[id]=node(v,fa);
			if(fa) t[fa].ch[v>t[fa].v]=id;
		}
		splay(id,0);
	}
	void erase(type v)
	{
		int pre,nex,id;
		pre=find_pre_id(v);
		nex=find_nex_id(v);
		splay(pre,0);
		splay(nex,pre);
		id=t[nex].ch[0];
		if(t[id].cnt>1)
		{
			t[id].cnt--;
			splay(id,0);
		}
		else
		{
			t[nex].ch[0]=0;
			splay(nex,0);
		}
	}
	void init()
	{
		root=tot=0;
		t[0].sz=t[0].cnt=t[0].fa=0;
		memset(t[0].ch,0,sizeof t[0].ch);
		insert(-inf);
		insert(inf);
	}
	type kth(int k)//k small
	{
		k++;
		int id=root;
		while(id)
		{
			if(t[t[id].ch[0]].sz>=k) id=t[id].ch[0];
			else if(t[t[id].ch[0]].sz+t[id].cnt>=k) break;
			else
			{
				k-=t[t[id].ch[0]].sz+t[id].cnt;
				id=t[id].ch[1];
			}
		}
		splay(id,0);
		return t[id].v;
	}
	int upper_bound_count(type key) //the count <=key
	{
		insert(key);
		find(key);
		int res=t[t[root].ch[0]].sz-1+t[root].cnt-1;
		erase(key);
		return res;
	}
	int lower_bound_count(type key) //the count <key
	{
		insert(key);
		find(key);
		int res=t[t[root].ch[0]].sz-1;
		erase(key);
		return res;
	}
	int rank(type key){return lower_bound_count(key)+1;}
	type find_pre(type key){return t[find_pre_id(key)].v;}
	type find_nex(type key){return t[find_nex_id(key)].v;}
	int size(){return t[root].sz;}
	#undef type
}tr; //tr.init();
