struct exKMP
{
	int next[MAX];
	void getnext(char *s)
	{
		int i,j,pos,len;
		next[i=0]=len=strlen(s);
		while(s[i]==s[i+1]&&i+1<len) i++;
		next[1]=i;
		pos=1;
		for(i=2;i<len;i++)
		{
			if(next[i-pos]+i<next[pos]+pos) next[i]=next[i-pos];
			else
			{
				j=max(0,next[pos]+pos-i);
				while(i+j<len&&s[j]==s[j+i]) j++;
				next[i]=j;
				pos=i;
			}
		}
	}
	void work(char *a,char *b,int *ex)
	{
		int i=0,j,pos,lena,lenb;
		getnext(b);
		lena=strlen(a);
		lenb=strlen(b);
		i=0;
		while(a[i]==b[i]&&i<lenb&&i<lena) i++;
		ex[0]=i;
		pos=0;
		for(i=1;i<lena;i++)
		{
			if(next[i-pos]+i<ex[pos]+pos) ex[i]=next[i-pos];
			else
			{
				j=max(0,ex[pos]+pos-i);
				while(i+j<lena&&j<lenb&&a[j+i]==b[j]) j++;
				ex[i]=j;
				pos=i;
			}
		}
	}
}exkmp;
