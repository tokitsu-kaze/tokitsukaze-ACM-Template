struct Treap
{
	#define type ll
	struct node
	{
		int ch[2],fix,sz,w;
		type v;
		node(){}
		node(type x)
		{
			v=x;
			fix=rand();
			sz=w=1;
			ch[0]=ch[1]=0;
		} 
	}t[MAX];  
	int tot,root,tmp;
	void init()
	{
		srand(unsigned(new char));
		root=tot=0;
		t[0].sz=t[0].w=0;
		mem(t[0].ch,0);
	}
	inline void maintain(int k)  
	{  
		t[k].sz=t[t[k].ch[0]].sz+t[t[k].ch[1]].sz+t[k].w ;  
	}  
	inline void rotate(int &id,int k)
	{
		int y=t[id].ch[k^1];
		t[id].ch[k^1]=t[y].ch[k];
		t[y].ch[k]=id;
		maintain(id);
		maintain(y);
		id=y;
	}
	void insert(int &id,type v)
	{
		if(!id) t[id=++tot]=node(v);
		else
		{
			if(t[id].sz++,t[id].v==v)t[id].w++;
			else if(insert(t[id].ch[tmp=v>t[id].v],v),t[t[id].ch[tmp]].fix>t[id].fix) rotate(id,tmp^1);
	    }
	}
	void erase(int &id,type v)
	{
		if(!id)return;
		if(t[id].v==v)
		{
			if(t[id].w>1) t[id].w--,t[id].sz--;
			else
			{
				if(!(t[id].ch[0]&&t[id].ch[1])) id=t[id].ch[0]|t[id].ch[1];
				else
				{
					rotate(id,tmp=t[t[id].ch[0]].fix>t[t[id].ch[1]].fix);
					t[id].sz--;
					erase(t[id].ch[tmp],v);
				}
			}
		}
		else
		{
			t[id].sz--;
			erase(t[id].ch[v>t[id].v],v);
		}
	}
	type kth(int k)//k small
	{
		int id=root;
		if(id==0) return 0;
		while(id)
		{
			if(t[t[id].ch[0]].sz>=k) id=t[id].ch[0];
			else if(t[t[id].ch[0]].sz+t[id].w>=k) return t[id].v;
			else
			{
				k-=t[t[id].ch[0]].sz+t[id].w;
				id=t[id].ch[1];
			}
		}
	}
	int find(type key,int f)
	{
		int id=root,res=0;
		while(id)
		{
			if(t[id].v<=key)
			{
				res+=t[t[id].ch[0]].sz+t[id].w;
				if(f&&key==t[id].v) res-=t[id].w;
				id=t[id].ch[1];
			}
			else id=t[id].ch[0];
		}
		return res;
	}
	type find_pre(type key)
	{
		type res=-LLINF;
		int id=root;
		while(id)
		{
			if(t[id].v<key)
			{
				res=max(res,t[id].v);
				id=t[id].ch[1];
			}
			else id=t[id].ch[0];
		}
		return res;
	}
	type find_suc(type key)
	{
		type res=LLINF;
		int id=root;
		while(id)
		{
			if(t[id].v>key)
			{
				res=min(res,t[id].v);
				id=t[id].ch[0];
			}
			else id=t[id].ch[1];
		}
		return res;
	}
	void insert(type v){insert(root,v);}
	void erase(type v){erase(root,v);}
	int upper_bound_count(type key){return find(key,0);}//the count >=key
	int lower_bound_count(type key){return find(key,1);}//the count >key
	int rank(type key){return lower_bound_count(key)+1;}
	#undef type
}t; //t.init();
