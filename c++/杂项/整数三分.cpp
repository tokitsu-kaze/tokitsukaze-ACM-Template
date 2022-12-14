while(l<r)  
{  
	lm=l+(r-l)/3;
	rm=l+2*(r-l+1)/3;
	tl=cal(lm);
	tr=cal(rm);
	if(tl>tr) l=lm+1;
	else r=rm-1;
}
