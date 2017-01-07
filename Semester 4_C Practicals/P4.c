/*------Vishal Kumar-------*/
#include<stdio.h>
void main(){
	int i,j,n,k,m;
	float x[15],s,y[15],z[15];
	FILE *p,*q;
	p=fopen("C:/Data/cwork/in4.txt","r");
	q=fopen("C:/Data/cwork/out4.txt","w");
	fscanf(p,"%d%d%d",&n,&k,&m);
	for(i=0;i<n;i++){
		fscanf(p,"%f",&x[i]);
		y[i]=0;
	}
	for(i=0;i<n-(m-1);i++){
		s=0;
		for(j=i;j<i+m;j++)
			s += x[j];
			y[i]=s/m;
	}
	for(i=0;i<n-(k-1)-(m-1);i++){ 
		s=0;
		for(j=i;j<i+k;j++)
			s += y[j];
		z[i]=s/k;
	}
	fprintf(q,"Days	Observations	Simple MA	Centered MA\n");
	for(i=0;i<n;i++){
		if(i>4&&i<=10)
			fprintf(q," %d\t%.0f\t\t%f\t%f\n",i+1, x[i], y[i-5], z[i-5]);
		else	fprintf(q," %d\t%.0f\t\t   -\t\t  -\n", i+1, x[i]);
	}
	fclose(p);
	fclose(q);
}

/*----------INPUT-------------
15 2 10
20 22 24 25 23 26 28 26 29 27 28 30 27 29 28
------------OUTPUT------------
Days	Observations	Simple MA	Centered MA
 1	20		   -		  -
 2	22		   -		  -
 3	24		   -		  -
 4	25		   -		  -
 5	23		   -		  -
 6	26		25.000000	25.400000
 7	28		25.799999	26.200001
 8	26		26.600000	26.750000
 9	29		26.900000	27.099998
 10	27		27.299999	27.549999
 11	28		27.799999	0.000000
 12	30		   -		  -
 13	27		   -		  -
 14	29		   -		  -
 15	28		   -		  -
----------------------------*/