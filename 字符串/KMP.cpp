/*
length of min loop

if(len%(len-nex[len])==0) res=len/(len-nex[len]);
else res=1; 

*/
int nex[MAX];
void get_next(char *s,int *nex,int len)
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
int KMP(char *a,char *b,int lena,int lenb)
{
	int i,j;
	get_next(b,nex,lenb);
	i=j=0;
	while(i<lena)
	{
		if(j==-1||a[i]==b[j])
		{
			i++;
			j++;
		}
		else j=nex[j];
		if(j==lenb) break;//successful match
	}
	return j==-1?0:j;
}
