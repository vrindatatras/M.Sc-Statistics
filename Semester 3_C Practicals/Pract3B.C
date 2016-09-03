#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

float maxlike(float x[],float mu,float sigma,int n){
	int i;	
	float ml=0;
	for(i=0; i<n; i++)
		ml+=(float)(log(1/sqrt(2.0*3.1428*sigma))-(x[i]-mu)*(x[i]-mu)/(2.0*sigma));
	return(ml);
}

void main(){
float x[200],u1,u2,mle[10],mlenum,mleden,lm,mlm,mu[4],sig[4],z;
int n,i,j,k,c;
FILE *p, *q;
clrscr();
randomize();
p=fopen("C:/cprog/3bin.txt","r");
q=fopen("C:/cprog/3bout.txt","w");
fscanf(p, "%d", &n);
for(i=0; i<n ; i++)
	fscanf(p, "%f%f", &mu[i], &sig[i]);
fprintf(q, "N\t-2Log(lm(x))\n\n");
for(i=0;i<40;i++){
	c=0; mlenum=0.0; mleden=0.0; lm=0.0;
	for(j=0;j<n;j+=2){
		u1=(float)rand()/(RAND_MAX+1.0);
		u2=(float)rand()/(RAND_MAX+1.0);
		x[j]=(float)sqrt(-2*log(u1))*cos(2.0*3.1428*u2);
		x[j+1]=(float)sqrt(-2*log(u1))*sin(2.0*3.1428*u2);
		x[j]=2+sqrt(12)*x[j];
		x[j+1]=2+sqrt(12)*x[j+1];
	}
	for(j=0;j<3;j++){
		mle[c]=0.0;
		for(k=0;k<3;k++){
			mle[c]=(float)maxlike(x, mu[j], sig[k], n);
			if(c==0){
				mlenum=mle[c];
				mleden=mle[c];
			}
			else	mleden=(float)max(mleden,mle[c]);
			if((mu[j]==1 || mu[j]==2) && (sig[k]==4||sig[k]==9) && c>0)
				mlenum=(float)max(mlenum,mle[c]);
		}
		c++;
	}
	lm=-2*(mlenum-mleden);
	fprintf(q,"%d\t%f\n",i+1,lm);
	mlm+=lm;
}
mlm=mlm/40;
z=(mlm-2)/sqrt(4);
if(z>1.95996 || z<-1.95996)
	fprintf(q,"\n\nz = %f\n -2log(lm(x)) does not follow a chi-sq distribution with 2 d.f.",z);
else	fprintf(q,"\n\nz = %f -2log(lm(x)) follows a chi-sq distribution with 2 d.f.",z);
fclose(p);
fclose(q);
}


/*-------INPUT-------
100
1 4 2 9 3 16
---------------------
-------OUTPUT--------
N	-2Log(lm(x))

1	14.297607
2	2.091003
3	-0.000000
4	-0.000000
5	-0.000000
6	-0.000000
7	1.276245
8	8.073364
9	8.973022
10	1.876404
11	1.413391
12	-0.000000
13	1.543701
14	5.370605
15	-0.000000
16	-0.000000
17	-0.000000
18	-0.000000
19	4.872070
20	-0.000000
21	4.550964
22	5.716431
23	2.533997
24	-0.000000
25	5.918335
26	-0.000000
27	-0.000000
28	4.736328
29	10.394226
30	3.048218
31	1.123535
32	9.424561
33	-0.000000
34	-0.000000
35	-0.000000
36	1.889893
37	-0.000000
38	-0.000000
39	6.154968
40	2.293945
z = 0.344660 -2log(lm(x)) follows a chi-sq distribution with 2 d.f.
-----------------------*/