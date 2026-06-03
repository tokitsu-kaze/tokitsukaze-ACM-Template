struct KMP_Automaton
{
	#define type char
	static const int K=;
	int nex[MAX],len,fail[MAX][K];
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
		memset(fail[0],0,sizeof fail[0]);
		for(i=0;i<=len;i++)
		{
			for(k=0;k<K;k++) fail[i][k]=fail[nex[i]][k];
			if(i+1<=len) fail[i][get_id(s[i+1])]=i;
		}
	}
	vector<int> match(type *s,int n)
	{
		int i,j;
		vector<int> res;
		for(i=1,j=0;i<=n;i++)
		{
			j=fail[j][get_id(s[i])];
			if(t[j+1]==s[i]) j++;
			if(j==len)
			{
				res.push_back(i-len+1);
				j=nex[j];
			}
		}
		return res;
	}
	Matrix get_mat()
	{
		int i,j,to;
		Matrix a(len,0);
		for(i=0;i<len;i++)
		{
			for(j=0;j<K;j++)
			{
				to=fail[i][j];
				if(get_id(t[to+1])==j) to++;
				a.c[i][to]++;
			}
		}
		return a;
	}
	#undef type
}kmpam;
/*
kmpam.get_next(t,len); // t[1..len]
kmpam.match(s,n); // s[1..n] return all pos t in s 
*/
