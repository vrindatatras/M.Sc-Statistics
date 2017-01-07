#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
FILE *p,*q;
void main()
{
	int i,j,n;
	float sigma=1.0,delta;
	float c=0.0,d=0.0,x[50],y[50],z[50],cp[50],cn[50];
	float mean0=10.0,mean1=11.0,k;
	p=fopen("C:/Data/cwork/in14.txt","r");
	q=fopen("C:/Data/cwork/out14.txt","w");
	fscanf(p,"%d",&n);
	for(i=0;i<n;i++)
		fscanf(p,"%f",&x[i]);
	delta=(mean1-mean0)/sigma;
	k=(delta*sigma)/2.0;
	fprintf(q,"delta=%f\tk=%f\n",delta,k);
	fprintf(q,"\n");
	for(i=0;i<n;i++){
		y[i]=x[i]-(mean0+k);
		z[i]=(mean0-k)-x[i];
	}
	cp[0]=0.0;
	cn[0]=0.0;
	fprintf(q,"\n");
	fprintf(q,"S.No\tci+\tNi+\tci-\tNi-\n");
	for(i=1;i<n;i++)
	{
		cp[i]=max(0,y[i]+cp[i-1]);
		cn[i]=max(0,z[i]+cn[i-1]);
		if(cp[i]>0)
			c++;
		else
			c=0.0;

		if(cn[i]>0)
			d++;
		else
			d=0.0;
		fprintf(q,"%d\t%.3f\t%.f\t%.3f\t%.f\n",i,cp[i],c,cn[i],d);
		if(c>5||d>5)
		break;
		}
}










/*----------INPUT----------
30
9.45 7.99 9.29 11.66 12.16 10.18 8.04 11.46 9.20 10.34 9.03 11.47 10.51 9.40
10.08 9.37 10.62 10.31 8.52 10.84 10.9 9.33 12.29 11.50 10.60 10.08 10.38
11.62 11.31 10.52
------------OUTPUT---------
delta=1.000000	k=0.500000


S.No	ci+	Ni+	ci-	Ni-
1	0.000	0	1.510	1
2	0.000	0	1.720	2
3	1.160	1	0.000	0
4	2.820	2	0.000	0
5	2.500	3	0.000	0
6	0.040	4	1.460	1
7	1.000	5	0.000	0
8	0.000	0	0.300	1
9	0.000	0	0.000	0
10	0.000	0	0.470	1
11	0.970	1	0.000	0
12	0.980	2	0.000	0
13	0.000	0	0.100	1
14	0.000	0	0.000	0
15	0.000	0	0.130	1
16	0.120	1	0.000	0
17	0.000	0	0.000	0
18	0.000	0	0.980	1
19	0.340	1	0.000	0
20	0.740	2	0.000	0
21	0.000	0	0.170	1
22	1.790	1	0.000	0
23	2.790	2	0.000	0
24	2.890	3	0.000	0
25	2.470	4	0.000	0
26	2.350	5	0.000	0
27	3.470	6	0.000	0
------------------------*/