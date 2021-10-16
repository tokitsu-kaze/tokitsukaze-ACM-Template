int min_representation(char *s)
{
	int i=0,j=1,k=0;
	int len=strlen(s);
	while(i<len&&j<len&&k<len)
	{
		if(s[(i+k)%len]==s[(j+k)%len])k++;
		else
		{
			if(s[(i+k)%len]>s[(j+k)%len])i=i+k+1;
			else j=j+k+1;
			if(i==j)j++;
			k=0;
		}
	}
	return i<j?i:j;
}
