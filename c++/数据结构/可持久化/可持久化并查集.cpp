struct Persistent_DSU
{
	struct node{int ls,rs,fa,dep;}t[MAX<<5];
	int root[MAX],tot,n,qx,qop,qv;
	void build(int l,int r,int &id)
	{
		if(!id) id=++tot;
		t[id]={0,0,0,0};
		if(l==r)
		{
			t[id]={0,0,l,1};
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,t[id].ls);
		build(mid+1,r,t[id].rs);
	}
	void init(int _n,int init_ver)
	{
		n=_n;
		tot=root[0]=0;
		t[0]={0,0,0,0};
		build(1,n,root[init_ver]);
	}
	int copy_node(int x)
	{
		t[++tot]=t[x];
		return tot;
	}
	void update(int l,int r,int &id,int pre)
	{
		if(!id) id=copy_node(pre);
		if(l==r)
		{
			if(qop==1) t[id].fa=qv;
			else t[id].dep+=qv;
			return;
		}
		int mid=(l+r)>>1;
		if(qx<=mid) update(l,mid,t[id].ls=0,t[pre].ls);
		else update(mid+1,r,t[id].rs=0,t[pre].rs);
	}
	int query(int l,int r,int id)
	{
		if(!id) return 0;
		if(l==r) return id;
		int mid=(l+r)>>1;
		if(qx<=mid) return query(l,mid,t[id].ls);
		else return query(mid+1,r,t[id].rs);
	}
	void create_ver(int now_ver,int pre_ver,int pos,int v,int op)
	{
		root[now_ver]=0;
		qx=pos;
		qv=v;
		qop=op;
		update(1,n,root[now_ver],root[pre_ver]);
	}
	void update_ver(int now_ver,int pos,int v,int op)
	{
		qx=pos;
		qv=v;
		qop=op;
		update(1,n,root[now_ver],root[now_ver]);
	}
	int ask_id(int now_ver,int pos)
	{
		qx=pos;
		return query(1,n,root[now_ver]);
	}
	void clear_ver(int now_ver){root[now_ver]=0;}
	void copy_ver(int now_ver,int pre_ver){root[now_ver]=root[pre_ver];}
	int find_id(int now_ver,int x)
	{
		int id;
		while(1)
		{
			id=ask_id(now_ver,x);
			if(x==t[id].fa) return id;
			x=t[id].fa;
		}
		return 0;
	}
	int find(int now_ver,int x){return t[find_id(now_ver,x)].fa;}
	bool merge(int now_ver,int pre_ver,int a,int b)
	{
		int raid,rbid;
		raid=find_id(pre_ver,a);
		rbid=find_id(pre_ver,b);
		if(t[raid].fa==t[rbid].fa)
		{
			copy_ver(now_ver,pre_ver);
			return 0;
		}
		if(t[raid].dep>t[rbid].dep) swap(raid,rbid);
		if(now_ver==pre_ver) update_ver(now_ver,t[raid].fa,t[rbid].fa,1);
		else create_ver(now_ver,pre_ver,t[raid].fa,t[rbid].fa,1);
		if(t[raid].dep==t[rbid].dep) update_ver(now_ver,t[rbid].fa,1,2);
		return 1;
	}
}dsu;
/*
dsu.init(n,init_ver);
dsu.find(now_ver,x);
dsu.merge(now_ver,pre_ver,a,b);
dsu.clear_ver(now_ver);
dsu.copy_ver(now_ver,pre_ver);
*/
