struct FastIO  
{  
	static const int S=200;  
	int wpos;  
	char wbuf[S];  
	FastIO():wpos(0){}  
	inline int xchar()  
	{  
		static char buf[S];  
		static int len=0,pos=0;  
		if(pos==len) pos=0,len=fread(buf,1,S,stdin);  
		if(pos==len) exit(0);  
		return buf[pos++];  
	}  
	inline int read()  
	{  
		int s=1,c=xchar(),x=0;  
		while(c<=32) c=xchar();  
		if(c=='-') s=-1,c=xchar();  
		for(;'0'<=c&&c<='9';c=xchar()) x=x*10+c-'0';  
		return x*s;  
	}  
	~FastIO()  
	{  
		if(wpos) fwrite(wbuf,1,wpos,stdout),wpos=0;  
	}  
}io;
