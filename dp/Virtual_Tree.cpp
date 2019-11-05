VI mp[MAX];
void add_edge(int a,int b)
{
    mp[a].pb(b);
    mp[b].pb(a);
}
int st[MAX],top,dfn[MAX];
bool cmp(int x,int y){return dfn[x]<dfn[y];}
int build_vtree(vector<int> &a)
{
	int lca;
    sort(all(a),cmp);
    a.erase(unique(all(a)),a.end());
    assert(a.size()>0);
    top=0;
    st[top++]=a[0];
    VI tmp;
    for(int i=1;i<sz(a);i++)
    {
        if(top==0){st[top++]=a[i]; continue;}
        lca=lca(a[i],st[top-1]);
        while(top>1&&dfn[st[top-2]]>=dfn[lca]) add_edge(st[top-2],st[top-1]),top--;
        if(lca!=st[top-1]) {add_edge(lca,st[top-1]),st[top-1]=lca; tmp.push_back(lca);}
        st[top++]=a[i];
    }
    while(top>1) add_edge(st[top-2],st[top-1]),top--;
    for(auto it:tmp) a.push_back(it);
    return st[0];
}
