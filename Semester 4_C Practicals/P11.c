#include<stdio.h>
#include<conio.h>
FILE *p,*q;
float sum(float x[10],int n)
{
	int i;
	float s=0.0;
	for(i=0;i<n;i++)
		s+=x[i];
	return(s);
}
void main()
{
	int i,j,n,k,d[10],e[10];
	float x[10],y[10],z[10],A,B,GRR,NRR,GFR,ASFR[10],S,TFR,L,nfi[10],t[10],c[10];
	p=fopen("C:/Data/cwork/in11.txt","r");
	q=fopen("C:/Data/cwork/out11.txt","w");
	clrscr();
	fscanf(p,"%d",&k);
	fscanf(p,"%d",&n);
	for(i=0;i<n;i++)
		fscanf(p,"%f",&x[i]);
	for(i=0;i<n;i++)
		fscanf(p,"%f",&y[i]);
	for(i=0;i<n;i++)
		fscanf(p,"%f",&z[i]);
	for(i=0;i<n;i++)
		fscanf(p,"%d",&d[i]);
	for(i=0;i<n;i++)
		fscanf(p,"%d",&e[i]);
	A=sum(x,n);
	B=sum(y,n);
	GFR=(B/A)*k;
	for(i=0;i<n;i++)
		ASFR[i]=(y[i]/x[i])*k;
	S=sum(ASFR,n);
	TFR=5.0*S;
	GRR=(46.2/100.0)*TFR;
	for(i=0;i<n;i++)
	{
		nfi[i]=(((46.2/100.0)*y[i])/x[i])*k;
		c[i]=1.0-z[i];
		t[i]=nfi[i]*c[i];
		}
	L=sum(t,n);
	NRR=5.0*L;
	fprintf(q,"GFR=%f\nTFR=%f\nGRR=%f\nNRR=%f\n",GFR,TFR,GRR,NRR);
	fprintf(q,"Age Group\tASFR\n");
	for(i=0;i<n;i++)
	fprintf(q,"%d-%d\t\t%f\n",d[i],e[i],ASFR[i]);
}










/*-------INPUT--------
1000
7
16000.0 16400.0 15800.0 15200.0 14800.00 15000.0 14500.0
260.0 2244.0 1894.0 1320.0 916.0 280.0 145.0
0.120 0.180 0.150 0.200 0.220 0.230 0.250
15 20 25 30 35 40 45
19 24 29 34 39 44 49
---------OUTPUT-------
GFR=65.543175
TFR=2251.766846
GRR=1040.316284
NRR=850.114807
Age Group	ASFR
15-19		16.250000
20-24		136.829269
25-29		119.873421
30-34		86.842102
35-39		61.891891
40-44		18.666666
45-49		10.000000
---------------------*/