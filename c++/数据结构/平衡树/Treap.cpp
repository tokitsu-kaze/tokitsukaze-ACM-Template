struct Treap
{
	#define type int
	const type inf=INF;
	struct node
	{
		int ch[2],fix,sz,cnt;
		type v;
		node(){}
		node(type x)
		{
			v=x;
			fix=rand();
			sz=cnt=1;
			ch[0]=ch[1]=0;
		} 
	}t[MAX];
	int tot,root;
	void init()
	{
		srand(time(0));
		root=tot=0;
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
	void insert(int &id,type v)
	{
		if(!id)
		{
			id=++tot;
			t[id]=node(v);
			return;
		}
		if(t[id].v==v) t[id].cnt++;
		else
		{
			int tmp=(v>t[id].v);
			insert(t[id].ch[tmp],v);
			if(t[t[id].ch[tmp]].fix>t[id].fix) rotate(id,tmp^1);
		}
		pushup(id);
	}
	void erase(int &id,type v)
	{
		if(!id) return;
		if(t[id].v==v)
		{
			if(t[id].cnt>1)
			{
				t[id].cnt--;
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
				erase(t[id].ch[tmp],v);
				pushup(id);
			}
		}
		else
		{
			erase(t[id].ch[v>t[id].v],v);
			pushup(id);
		}
	}
	type kth(int k)//k small
	{
		int id=root;
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
	int find(type key,int f)
	{
		int id=root,res=0;
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
	type find_pre(type key)
	{
		type res=-inf;
		int id=root;
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
		int id=root;
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
	void insert(type v){insert(root,v);}
	void erase(type v){erase(root,v);}
	int upper_bound_count(type key){return find(key,0);}//the count <=key
	int lower_bound_count(type key){return find(key,1);}//the count <key
	int rank(type key){return lower_bound_count(key)+1;}
	int size(){return t[root].sz;}
	#undef type
}tr; //tr.init();
