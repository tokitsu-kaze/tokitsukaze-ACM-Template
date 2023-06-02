struct KMP
{
	int nex[MAX],len;
	char t[MAX];
	void get_next(char *s)
	{
		int i,j;
		len=strlen(s+1);
		for(i=1;i<=len;i++) t[i]=s[i];
		t[len+1]='\0';
		j=nex[1]=0;
		for(i=2;i<=len;i++)
		{
			while(j&&t[j+1]!=s[i]) j=nex[j];
			if(t[j+1]==s[i]) j++;
			nex[i]=j;
		}
	}
	
	// s[1..n], return all pos t in s 
	vector<int> match(char *s)
	{
		int n,i,j;
		vector<int> res;
		n=strlen(s+1);
		for(i=1,j=0;i<=n;i++)
		{
			while(j&&t[j+1]!=s[i]) j=nex[j];
			if(t[j+1]==s[i]) j++;
			if(j==len)
			{
				res.push_back(i-len+1);
				j=nex[j];
			}
		}
		return res;
	}
}kmp;// kmp.get_next(s); s[1..len]
