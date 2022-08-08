struct Virtual_Tree
{
	int st[MAX],top;
	int build_vtree(VI &a,VI vtree_mp[])// return root 
	{
		int now_lca;
		sort(all(a),[&](int x,int y){return lca.dfn[x]<lca.dfn[y];});
		a.erase(unique(all(a)),a.end());
		assert(sz(a)>0);
		top=0;
		st[top++]=a[0];
		VI tmp;
		for(int i=1;i<sz(a);i++)
		{
			if(top==0)
			{
				st[top++]=a[i];
				continue;
			}
			now_lca=lca.lca(a[i],st[top-1]);
			while(top>1&&lca.dfn[st[top-2]]>=lca.dfn[now_lca])
			{
				vtree_mp[st[top-2]].pb(st[top-1]);
				top--;
			}
			if(now_lca!=st[top-1])
			{
				vtree_mp[now_lca].pb(st[top-1]);
				st[top-1]=now_lca;
				tmp.push_back(now_lca);
			}
			st[top++]=a[i];
		}
		while(top>1)
		{
			vtree_mp[st[top-2]].pb(st[top-1]);
			top--;
		}
		for(auto it:tmp) a.push_back(it);
		return st[0];
	}
	void clear_vtree(VI &a,VI vtree_mp[])
	{
		for(auto it:a) vtree_mp[it].clear();
	}
}vt; // need lca and dfn
