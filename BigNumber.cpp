struct BigN{
	char str[2005];
	int a[2005];

	void read(char *str){//数据读入
		a[0]=strlen(str);
		for(int i=1;i<=a[0];i++)
			a[i]=str[a[0]-i]-'0';
	}
	void prin(){//数据输出
	    for(int i=a[0];i>0;i--)
            printf("%d ",a[i]);
            putchar(10);
	}

	BigN operator* (const BigN &x){//乘法，最高支持1000位乘法
		BigN c;
		memset(c.a,0,sizeof(c.a));
		for(int i=1;i<=a[0];i++)
			for(int j=1;j<=x.a[0];j++){
				c.a[i+j-1]+=a[i]*x.a[j];
			}
			//for(int i=1;
		int ca=0;
		for(int i=1;i<a[0]+x.a[0];i++){
			c.a[i]+=ca;
			if(c.a[i]>9)ca=c.a[i]/10;
			else ca=0;
			c.a[i]%=10;
		}
		if(ca){
			c.a[0]=a[0]+x.a[0];
			c.a[c.a[0]]=ca;
		}
		else c.a[0]=a[0]+x.a[0]-1;
		return c;
	}

	BigN operator+ (const BigN &x){//加法，最高支持2000位加法
		BigN r;
		int maxs=max(a[0],x.a[0]),ca=0;
		for(int i=1;i<=maxs;i++){
			r.a[i]=a[i]+x.a[i]+ca;
			if(r.a[i]>9)ca=r.a[i]/10;
			else  ca=0;
			r.a[i]%=10;
		}
		if(ca){
            r.a[maxs+1]=ca;
        r.a[0]=maxs+1;
		}
		else r.a[0]=maxs;
		return r;
	}
	
};
