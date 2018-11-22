struct Hash_map
{
    static const int p=999917;
    ll val[MAX],w[MAX];
    int tot,head[p],nex[MAX];
    int top,st[MAX];
    void clear(){tot=0;while(top) head[st[top--]]=0;}
    void add(int x,ll y){val[++tot]=y;nex[tot]=head[x];head[x]=tot;w[tot]=0;}
    bool count(ll y)
    {
        int x=y%p;
        for(int i=head[x];i;i=nex[i])
        {
			if(y==val[i]) return 1;
		}
        return 0;
    }
    ll& operator [](ll y)
    {
        int x=y%p;
        for(int i=head[x];i;i=nex[i])
        {
			if(y==val[i]) return w[i];
		}
        add(x,y);
        st[++top]=x;
		return w[tot];
    }
}mp;
