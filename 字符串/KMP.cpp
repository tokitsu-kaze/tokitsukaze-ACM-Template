//length of min loop  len-nex[len]
struct KMP
{
	int nex[MAX],len;
	char s[MAX];
	void get_next()
	{
		int i,j;
		i=0;
		j=nex[0]=-1;
		while(i<len)
		{
			if(j==-1||s[i]==s[j]) nex[++i]=++j;
			else j=nex[j];
		}
	}
	void init(char *_s)
	{
		len=strlen(_s);
		for(int i=0;i<len;i++) s[i]=_s[i];
		s[len]='\0';
		get_next();
	}
	int match(char *a)//s is a substring of a
	{
		int n,i,j;
		n=strlen(a);
		for(i=j=0;i<n;i++)
		{
			if(j==-1||a[i]==s[j]) j++;
			else j=nex[j];
			if(j==len) return 1;
		}
		return 0;
	}
}kmp;// kmp.init(s); s[0..len-1]
