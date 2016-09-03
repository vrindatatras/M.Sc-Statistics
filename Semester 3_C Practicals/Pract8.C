#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void main(){
FILE *p,*q;
int i,j,n,k;
float u1,u2,X[51],x1[51][51],y[51],mu[10],s[20][20],mean[3],sum[3]={0.};
float P[51][51],Q[51][51],V[51][51];
randomize();
clrscr();
p=fopen("C:/dprog/in8.txt","r");
q=fopen("C:/cpro/out8.txt","w");
for(j=0;j<3;j++)
   fscanf(p,"%f",&mu[j]);
for(i=0;i<3;i++)
	for(j=0;j<3;j++)
		fscanf(p,"%f",&s[i][j]);
for(j=0;j<50;j++){
	for(i=0;i<3;i++){
		u1=rand()/(RAND_MAX+1.0);
		u2=rand()/(RAND_MAX+1.0);
		y[i]=sqrt(-2.0*log(u1))*cos(2.0*3.14*u2);
	}
	for(i=0;i<3;i++){
		X[i]=0.0;
		for(k=0;k<3;k++)
			X[i]+=s[i][k]*y[k];
	}
	for(i=0;i<3;i++){
		x1[j][i]=X[i]+mu[i];
		sum[i]+=x1[j][i];
	}
}
fprintf(q,"Sample Mean Vector :\n");
for(i=0;i<3;i++){
	mean[i]=sum[i]/50.;
	fprintf(q,"%f\t",mean[i]);
}
for(i=0;i<50;i++)
	for(j=0;j<3;j++){
		P[i][j]=x1[i][j]-mean[j];
		Q[j][i]=P[i][j];
	}
for(k=0;k<3;k++)
	for(i=0;i<3;i++){
		V[i][k]=0.0;
		for(j=0;j<50;j++)
		V[i][k]+=Q[i][j]*P[j][k];
	}
fprintf(q,"\nSample Var-Cov Vector :\n");
for(k=0;k<3;k++){
	for(i=0;i<3;i++){
		V[k][i]=V[k][i]/50.0;
		fprintf(q,"%f\t",V[k][i]);
	}
	fprintf(q,"\n");
}
fclose(p);
fclose(q);
}
/*------INPUT------
5 5 5
5 0 0 3 3 0 -1 1 3
---------OUTPUT-------
Sample Mean Vector :
4.796202	4.688024	4.557366	
Sample Var-Cov Vector :
17.445168	9.319421	-5.935483	
9.319421	12.657358	-0.448194	
-5.935483	-0.448194	10.427118	
---------------------*/