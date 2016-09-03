#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 50

void inverse(int P,float c[][MAX],float I[][MAX]){
int i,j,k;
float r,t;
if(c[0][0]==0.0)
	for(i=1;i<P;i++){
		if(c[i][0]!=0.0){
			for(j=0;j<P;j++){
				c[0][j]+=c[i][j];
				I[0][j]+=I[i][j];
			}
		}
		break;
	}
for(i=0;i<P;i++){
	r=c[i][i];
	for(j=0;j<P;j++){
		c[i][j]=c[i][j]/r;
		I[i][j]=I[i][j]/r;
	}
	for(k=0;k<P;k++)
		if(k!=i){
			t=c[k][i];
			for(j=0;j<P;j++){
			c[k][j]-=t*c[i][j];
			I[k][j]-=t*I[i][j];
			}
		}
	}
}

void main(){
FILE *p,*q;
int i,j,k,n[MAX],x[MAX],y[MAX],X[2][MAX],Xt[MAX][2],N;
float Ey[MAX],Py[MAX],b0,b1,S[MAX][MAX],I[MAX][MAX],A[2][MAX],V[MAX][MAX],Z,sigsqr;
clrscr();
p=fopen("pract12.txt","r");
q=fopen("output12.txt","w");
fscanf(p,"%d%f%f",&N,&b0,&b1);
fprintf(q,"N=%d\tbo=%f\tb1=%f\n",N,b0,b1);
for(j=0;j<N;j++)
	fscanf(p,"%d",&x[j]);
for(j=0;j<N;j++)
	fscanf(p,"%d",&n[j]);
for(j=0;j<N;j++)
	fscanf(p,"%d",&y[j]);
for(j=0;j<N;j++){
	Py[j]=1.0/(1.0+exp(-1.0*(b0+b1*x[j])));
	Ey[j]=(float)n[j]*Py[j];
}
for(j=0;j<N;j++){
	X[0][j]=1;
	X[1][j]=x[j];
	Xt[j][0]=X[0][j];
	Xt[j][1]=X[1][j];
}
fprintf(q,"\n xi \t ni \t yi \t E(yi)\n");
for(i=0;i<N;i++)
	fprintf(q," %d\t%d\t%d\t%.0f\n",x[i],n[i],y[i],Ey[i]);
for(i=0;i<N;i++)
	for(j=0;j<N;j++){
		if(i==j){
			I[i][j]=1.0;
			V[i][j]=n[i]*Py[i]*(1-Py[i]);
		}
		else{
			I[i][j]=0.0;
			V[i][j]=0.0;
		}
	}
for(i=0;i<2;i++){
	for(j=0;j<N;j++){
		V[i][j]=0.0;
		for(k=0;k<N;k++)
		V[i][j]+=X[i][k]*V[k][j];
	}
}
for(i=0;i<2;i++){
	for(j=0;j<2;j++){
		S[i][j]=0.0;
		for(k=0;k<N;k++)
			S[i][j]+=V[i][k]*Xt[k][j];
	}
}
inverse(2,S,I);
fprintf(q,"\nMatrix S-inverse : \n");
for(i=0;i<2;i++){
	fprintf(q,"\n");
	for(j=0;j<2;j++)
	fprintf(q,"%f\t",I[i][j]);
}
sigsqr=I[1][1];
Z=(b1*b1)/sigsqr;
fprintf(q,"\n\n Z = %f",Z);
fclose(p);
fclose(q);
}

/*-------------INPUT------------------
38	-2.2903	0.1156
0	2	3	4	5	6	7	8	9	10	11	12
13	14	15	16	17	18	19	20	21	22	23	24
25	26	27	28	29	30	31	32	33	34	35	36
37	41	1	1	4	11	9	14	12	22	33	19
31	17	32	25	18	24	27	19	15	13	17	14
13	11	12	6	7	3	7	5	3	3	1	1
1	1	1	1	0	0	1	0	3	3	4	5	
3	6	5	5	13	7	7	8	8	13	7	6
9	12	7	8	8	2	5	1	4	4	3	3
1	1	1	1	1	0




---------------OUTPUT-----------------
N=38	bo=-2.290300	b1=0.115600
 xi 	 ni 	 yi 	 E(yi)
 0	1	0	0
 2	1	0	0
 3	4	1	1
 4	11	0	2
 5	9	3	1
 6	14	3	2
 7	12	4	2
 8	22	5	4
 9	33	3	7
 10	19	6	5
 11	31	5	8
 12	17	5	5
 13	32	13	10
 14	25	7	8
 15	18	7	7
 16	24	8	9
 17	27	8	11
 18	19	13	9
 19	15	7	7
 20	13	6	7
 21	17	9	9
 22	14	12	8
 23	13	7	8
 24	11	8	7
 25	12	8	8
 26	6	2	4
 27	7	5	5
 28	3	1	2
 29	7	4	5
 30	5	4	4
 31	3	3	2
 32	3	3	2
 33	1	1	1
 34	1	1	1
 35	1	1	1
 36	1	1	1
 37	1	1	1
 41	1	0	1

Matrix S-inverse : 

0.076901	-0.004126	
-0.004125	0.000257	

 Z = 51.960030
 ---------------------*/