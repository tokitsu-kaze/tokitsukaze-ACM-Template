int max_representation(char *s)
{
	int i,j,k,len,t;
	len=strlen(s);
	i=k=0;
	j=1;
	while(i<len&&j<len&&k<len)
	{
		t=s[(i+k)%len]-s[(j+k)%len];
		if(!t) k++;
		else
		{
			if(t>0)
			{
				if(j+k+1>i) j=j+k+1;
				else j=i+1;
			}
			else if(i+k+1>j) i=i+k+1;
			else i=j+1;
			k=0;
		}
	}
	return i<j?i:j;
}
