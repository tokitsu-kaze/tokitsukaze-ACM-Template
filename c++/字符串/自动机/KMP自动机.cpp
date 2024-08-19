struct KMP_Automaton
{
	#define type char
	static const int K=;
	int nex[MAX],len,lst[MAX][K];
	type t[MAX];
	int get_id(char c){return c-;} //may need change
	void get_next(type *s,int n)
	{
		int i,j,k;
		len=n;
		for(i=1;i<=len;i++) t[i]=s[i];
		t[len+1]=0;
		nex[0]=nex[1]=0;
		j=0;
		for(i=2;i<=len;i++)
		{
			while(j&&t[j+1]!=s[i]) j=nex[j];
			if(t[j+1]==s[i]) j++;
			nex[i]=j;
		}
		memset(lst[0],0,sizeof lst[0]);
		for(i=1;i<=len;i++)
		{
			for(k=0;k<K;k++) lst[i][k]=lst[nex[i]][k];
			if(i+1<=len) lst[i][get_id(s[i+1])]=i;
		}
	}
	vector<int> match(type *s,int n)
	{
		int i,j;
		vector<int> res;
		for(i=1,j=0;i<=n;i++)
		{
			j=lst[j][get_id(s[i])];
			if(t[j+1]==s[i]) j++;
			if(j==len)
			{
				res.push_back(i-len+1);
				j=nex[j];
			}
		}
		return res;
	}
	#undef type
}kmp;
/*
kmp.get_next(t,len); // t[1..len]
kmp.match(s,n); // s[1..n] return all pos t in s 
*/
