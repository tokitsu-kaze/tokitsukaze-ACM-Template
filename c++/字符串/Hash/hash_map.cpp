struct hash_map
{
	#define type int
	#define TA pair<type,type>
    static const int p=999917;
    TA val[MAX];
	type w[MAX];
    int tot,head[p],nex[MAX];
    int top,st[MAX];
    hash_map(){top=tot=0;}
    void clear(){tot=0;while(top) head[st[top--]]=0;}
    void add(int x,TA y){val[++tot]=y;nex[tot]=head[x];head[x]=tot;w[tot]=0;}
    bool count(TA y)
    {
        int x=y.first%p;
        for(int i=head[x];i;i=nex[i])
        {
			if(y==val[i]) return 1;
		}
        return 0;
    }
    type& operator [](TA y)
    {
        int x=y.first%p;
        for(int i=head[x];i;i=nex[i])
        {
			if(y==val[i]) return w[i];
		}
        add(x,y);
        st[++top]=x;
		return w[tot];
    }
    #undef TA
    #undef type
}flag;
