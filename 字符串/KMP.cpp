int Next[MAX];
void getnext(char *b,int *Next,int len)
{
	int i,j;
	i=0;
	j=Next[0]=-1;
	while(i<len)
	{
		if(j==-1||b[i]==b[j]) Next[++i]=++j;
		else j=Next[j];
	}
}
int KMP(char *a,char *b,int lena,int lenb)
{
	int i,j;
	getnext(b,Next,lenb);
	i=j=0;
	while(i<lena)
	{
		if(j==-1||a[i]==b[j])
		{
			i++;
			j++;
		}
		else j=Next[j];
		if(j==lenb) break;//successful match
	}
	return j==-1?0:j;
}
