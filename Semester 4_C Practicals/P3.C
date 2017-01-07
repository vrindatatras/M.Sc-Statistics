/*-------Vishal Kumar--------*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 15

FILE *p,*q;
void inverse(int P,float c[MAX][MAX],float I[MAX][MAX]){
	int i,j,k;
	float r,t;
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

void model(int N,int r,float Y[MAX],float X[MAX][MAX]){
	int i,j,k;
	float X1[MAX][MAX],X1t[MAX][MAX],B[5][5],Ey[MAX],b0,b1,b2,b3;
	float S[MAX][MAX],I[MAX][MAX],V[MAX][MAX],SSE=0.0,TSS=0.0,sum=0.0,Rs,Rsq;
	for(i=0; i<N; i++){
		X1[i][0]=1.0;
		X1t[0][i] = X1[i][0];
		for(j=1; j<r; j++){
			X1[i][j] = X[i][j-1];
			X1t[j][i] = X1[i][j];
		}
		sum+=Y[i];
	}
	
	for(i=0;i<r;i++)
		for(j=0;j<r;j++)
			if(i==j)
				I[i][j]=1.0;
			else	I[i][j]=0.0;
	
	for(i=0;i<r;i++)
		for(j=0;j<1;j++){
			V[i][j]=0.0;
			for(k=0;k<N;k++)
				V[i][j]+=X1t[i][k]*Y[k];
		}
		
	for(i=0;i<r;i++)
		for(j=0;j<r;j++){
			S[i][j]=0.0;
			for(k=0;k<N;k++)
				S[i][j]+=X1t[i][k]*X1[k][j];
		}
	
	inverse(r,S,I);
	for(i=0;i<r;i++)
		for(j=0;j<1;j++){
			B[i][j]=0.0;
			for(k=0;k<r;k++)
				B[i][j]+=I[i][k]*V[k][j];
		}
	
	if(r==2){
		b0=B[0][0];
		b1=B[1][0];
		fprintf(q,"\n\n b0 = %f\tb1 = %f\n",b0,b1);
		for(i=0;i<N;i++){
			Ey[i]=0.0;
			for(j=0;j<r;j++)
				Ey[i]+=X1[i][j]*B[j][0];
		}
		for(i=0;i<N;i++){
			SSE+=(Y[i]-Ey[i])*(Y[i]-Ey[i]);
			TSS+=(Y[i]-(sum/N))*(Y[i]-(sum/N));
		}
		Rs=1.0-(SSE/TSS);
		Rsq=1.0-((1.0-Rs)*(N-1))/(N-r);
		fprintf(q,"\n SSE = %f \t TSS = %f \t Adj Rsq = %f \n",SSE,TSS,Rsq);
	}
	else if(r==3){
		b0=B[0][0];
		b1=B[1][0];
		b2=B[2][0];
		fprintf(q,"\n\n b0 = %f\tb1 = %f\tb2 = %f\n",b0,b1,b2);
		for(i=0;i<N;i++){
			Ey[i]=0.0;
			for(j=0;j<r;j++)
				Ey[i]+=X1[i][j]*B[j][0];
		}
		for(i=0;i<N;i++){
			SSE+=(Y[i]-Ey[i])*(Y[i]-Ey[i]);
			TSS+=(Y[i]-(sum/N))*(Y[i]-(sum/N));
		}
		Rs=1.0-(SSE/TSS);
		Rsq=1.0-((1.0-Rs)*(N-1))/(N-r);
		fprintf(q,"\n SSE = %f \t TSS = %f \t Adj Rsq = %f \n",SSE,TSS,Rsq);
	}
	else{
		b0=B[0][0];
		b1=B[1][0];
		b2=B[2][0];
		b3=B[3][0];
		fprintf(q,"\n\n b0 = %f\tb1 = %f\tb2 = %f\tb3=%f\n",b0,b1,b2,b3);
		for(i=0;i<N;i++){
			Ey[i]=0.0;
			for(j=0;j<r;j++)
				Ey[i]+=X1[i][j]*B[j][0];
		}
		for(i=0;i<N;i++){
			SSE+=(Y[i]-Ey[i])*(Y[i]-Ey[i]);
			TSS+=(Y[i]-(sum/N))*(Y[i]-(sum/N));
		}
		Rs=1.0-(SSE/TSS);
		Rsq=1.0-((1.0-Rs)*(N-1))/(N-r);
		fprintf(q,"\n SSE = %f \t TSS = %f \t Adj Rsq = %f \n",SSE,TSS,Rsq);
	}
}

void main(){
	int i,j,k,N;
	float x1[MAX],x2[MAX],x3[MAX],y[MAX],X[MAX][MAX],Y[MAX];
	clrscr();
	p = fopen("C:/Data/cwork/in3.txt","r");
	q = fopen("C:/Data/cwork/out3.txt","w");
	fscanf(p,"%d",&N);
	for(i=0; i<N; i++)
		fscanf(p,"%f %f %f %f", &x1[i], &x2[i], &x3[i], &y[i]);
	
	fprintf(q,"\n Model 1: y = b0 + b1*x1");
	for(i=0;i<N;i++){
		Y[i]=y[i];
		X[i][0]=x1[i];
	}
	model(N,2,Y,X);
	
	fprintf(q,"\n Model-2 :y = b0 + b1*x2");
	for(i=0;i<N;i++)
	{
		Y[i]=y[i];
		X[i][0]=x2[i];
	}
	model(N,2,Y,X);
	
	fprintf(q,"\n Model-3 :y = b0 + b1*x3");
	for(i=0;i<N;i++){
		Y[i]=y[i];
		X[i][0]=x3[i];
	}
	model(N,2,Y,X);
	
	fprintf(q,"\n Model-4 :y = b0 + b1*x1+b2*x2");
	for(i=0;i<N;i++){
		Y[i]=y[i];
		X[i][0]=x1[i];
		X[i][1]=x2[i];
	}
	model(N,3,Y,X);
	
	fprintf(q,"\n Model-5 :y = b0 + b1*x1+b2*x3");
	for(i=0;i<N;i++){
		Y[i]=y[i];
		X[i][0]=x1[i];
		X[i][1]=x3[i];
	}
	
	model(N,3,Y,X);
	fprintf(q,"\n Model-6 :y = b0 + b1*x2+b2*x3");
	for(i=0;i<N;i++){
		Y[i]=y[i];
		X[i][0]=x2[i];
		X[i][1]=x3[i];
	}
	model(N,3,Y,X);
	
	fprintf(q,"\n Model-7 :y = b0 + b1*x1+b2*x2+b3*x3");
	for(i=0;i<N;i++){
		Y[i]=y[i];
		X[i][0]=x1[i];
		X[i][1]=x2[i];
		X[i][2]=x3[i];
	}
	model(N,4,Y,X);
	
	fclose(p);
	fclose(q);
}

/*---------------INPUT-----------------
14
26	163	210	262.5
30	140.7	205	250
22	161.3	207.5	240
27	118.4	200	240
23	125.1	195	242.5
31	140.4	190	240
32	158.9	192.5	237.5
22	136.9	202.5	225
32	145.3	187.5	232.5
27	124.3	190	225
20	142.7	185	220
29	127.7	170	215
23	134.3	160	210
18	137.7	155	192.5

-----------------OUTPUT-----------------

 Model-1 : y = b0 + b1*x1

 b0 = 182.309982	b1 = 1.878908

 SSE = 3178.791016 	 TSS = 4145.089355 	 Adj Rsq = 0.169212 

 Model-2 :y = b0 + b1*x2

 b0 = 164.827744	b1 = 0.472690

 SSE = 3584.494629 	 TSS = 4145.089355 	 Adj Rsq = 0.063180 

 Model-3 :y = b0 + b1*x3

 b0 = 54.616665	b1 = 0.931283

 SSE = 877.295471 	 TSS = 4145.089355 	 Adj Rsq = 0.770716 

 Model-4 :y = b0 + b1*x1+b2*x2

 b0 = 125.499069	b1 = 1.775445	b2 = 0.425609

 SSE = 2727.235107 	 TSS = 4145.089355 	 Adj Rsq = 0.222430 

 Model-5 :y = b0 + b1*x1+b2*x3

 b0 = 42.227417	b1 = 1.022309	b2 = 0.857057

 SSE = 611.992126 	 TSS = 4145.089355 	 Adj Rsq = 0.825513 

 Model-6 :y = b0 + b1*x2+b2*x3

 b0 = 45.644028	b1 = 0.101927	b2 = 0.903426

 SSE = 854.150391 	 TSS = 4145.089355 	 Adj Rsq = 0.756471 

 Model-7 :y = b0 + b1*x1+b2*x2+b3*x3

 b0 = 32.884331	b1 = 1.025716	b2 = 0.105726	b3=0.827923

 SSE = 587.097290 	 TSS = 4145.089355 	 Adj Rsq = 0.815872 
---------------------*/