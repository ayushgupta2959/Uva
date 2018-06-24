using namespace std;
#include <bits/stdc++.h>
int main(){
	int i;
	double h,u,d,f,hr,pdc;
	while(true){
		scanf("%lf%lf%lf%lf",&h,&u,&d,&f);
		if(h==0)	break;
		f=(f*u)/100;
		hr=u-d;
		pdc=u;
		i=1;
		while(hr>=0&&hr<=h){
			pdc = pdc-f;
			if(pdc>0) hr = hr+pdc;
			i++;
			if(hr<=h) hr = hr-d;
			else break;
		}
		if(u>h)	{
			i=1;
			hr = u;
		}
		if(hr<0)	printf("failure on day %d\n",i);
		else		printf("success on day %d\n",i);
	}
	return 0;
}

