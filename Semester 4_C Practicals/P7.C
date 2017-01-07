#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void inverse(int P,float c[40][40],float I[40][40]){
	int i,j,k;
	float r,t;
	for(i=0;i<P;i++)
		for(j=0;j<P;j++)
			if(i==j)
				I[i][j]=1.0;
			else	I[i][j]=0.0;	
	for(i=0;i<P;i++){
		r=c[i][i];
		for(j=0;j<P;j++){
			c[i][j]/=r;
			I[i][j]/=r;
		}
		for(k=0;k<P;k++){
			if(k!=i){
				t=c[k][i];
				for(j=0;j<P;j++){
					c[k][j]-=t*c[i][j];
					I[k][j]-=t*I[i][j];
				}
			}
		}
	}
}

void mmult(float x[40][40], float y[40][40], int m, int n, int q, float z[40][40]){
	int i,j ,k;
	for(i=0; i<m; i++)
		for(j=0;j<q;j++){
			z[i][j]=0.0;
			for(k=0;k<n;k++)
				z[i][j]+=x[i][k]*y[k][j];
		}
}

void para(float x[40][40], float y[40][40], int n, float b[40][40]){
	int i,j;
	float xtrn[40][40],A[40][40],B[40][40],I[40][40];
	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
			xtrn[j][i]=x[i][j];
	mmult(xtrn, x, 3, n, 3, A);
	mmult(xtrn, y, 3, n, 1, B);
	inverse(3, A, I);
	mmult(I, B, 3, 3, 1, b);
}

void main(){
	int i, j, n;
	float x[40], y[40], X[40][40], Y[40][40], b[40][40];
	FILE *p, *q;
	clrscr();
	p=fopen("C:/Data/cwork/in7.txt","r");
	q=fopen("C:/Data/cwork/out7.txt","w");
	fscanf(p, "%d", &n);
	for(i=0; i<n; i++)
		fscanf(p, "%f", &y[i]);
	for(i=0; i< n-1; i++)
		Y[i][0]=y[i+1];
	for(i=0;i<n;i++)
		fscanf(p, "%f", &x[i]);
	for(i=0;i<n-1;i++){
		X[i][0]=1.0;
		X[i][1]=x[i+1];
		X[i][2]=y[i];
	}
	para(X, Y, n-1, b);
	fprintf(q, "Fitted model:\nY(t)=(%.4f)+(%.4f)X(t)+(%.4f)Y(t-1)\n", b[0][0],b[1][0],b[2][0]);
	fprintf(q, "Mean Lag=%f\n", b[2][0]/(1-b[2][0]));
	fprintf(q, "Median Lag=%f\n", -1.0*log(2)/log(b[2][0]));
	fclose(p);
	fclose(q);
}
/*---------INPUT--------
30
11300	11581	12149	12626	12407	12551	13155	13583	14035
14230	14021	14069	14105	14741	15401	16020	16541	16398
17463	17760	17899	17677	17989	18399	18910	19294	19727
20232	20989	21901
12823	13218	13692	14496	14268	14393	14873	15256	15845
16120	16063	16265	16328	16673	17799	18229	18641	18870
19522	19833	20058	19919	20318	20384	20709	21055	21385
21838	22672	23191
----------OUTPUT--------
Fitted model:
Y(t)=(-1240.7216)+(0.6025)X(t)+(0.4114)Y(t-1)
Mean Lag=0.698925
Median Lag=0.780389
-------------------*/