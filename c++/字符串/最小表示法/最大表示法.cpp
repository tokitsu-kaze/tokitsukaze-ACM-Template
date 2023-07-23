int max_representation(char *s,int n) // s[0..n-1]
{
	int i,j,k,tmp;
	i=k=0;
	j=1;
	while(i<n&&j<n&&k<n)
	{
		tmp=s[(i+k)%n]-s[(j+k)%n];
		if(!tmp) k++;
		else
		{
			if(tmp<0) i=i+k+1;
			else j=j+k+1;
			if(i==j) j++;
			k=0;
		}
	}
	return i<j?i:j;
}
