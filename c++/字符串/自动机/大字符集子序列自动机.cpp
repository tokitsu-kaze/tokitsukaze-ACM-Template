struct Subsequence_Automaton
{
	const int rt=0;
	int n,VALMAX;
	vector<vector<int>> pos;
	void init(int _n,int *a)
	{
		int i;
		pos.clear();
		n=_n;
		VALMAX=0;
		for(i=1;i<=n;i++) VALMAX=max(VALMAX,a[i]);
		pos.resize(VALMAX+1);
		for(i=1;i<=n;i++) pos[a[i]].push_back(i);
	}
	int next(int now,int val)
	{
		if(val>VALMAX) return n+1;
		auto it=lower_bound(pos[val].begin(),pos[val].end(),now+1);
		if(it==pos[val].end()) return n+1;
		return *it;
	}
}seqam;
/*
seqam.init(n,a);  // a[1..n]
now=seqam.rt;
seqam.next(now,val);
*/
