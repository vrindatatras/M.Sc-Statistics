#include<stdio.h>
#include<math.h>

FILE *p1,*p2;
float s[10][10],sinv[10][10];
int p;

float minv(float a[10][10],float iv[10][10],int r1,int c1){
	int i,j,k,c=2*c1,r=r1;
	float b,c11,id[10][10],x[10][10];
	for(i=0;i<r;i++)         
		for(j=0;j<c/2;j++)
			x[i][j]=a[i][j];
	for(i=0;i<r;i++)     
		for(j=0;j<r;j++){
			if(i==j)
				id[i][j]=1;
			else	id[i][j]=0;
		}	
	for(i=0;i<r;i++)      
		for(j=c/2;j<c;j++)      
			x[i][j]=id[i][j-c/2];
	for(k=0;k<r;k++){        
		b=x[k][k];
		if(b!=0){
			for(j=0;j<c;j++)
				x[k][j]=x[k][j]/b;
		}
		for(i=0;i<r;i++){
			if(i!=k){
				c11=x[i][k];
				for(j=k;j<c;j++)
				x[i][j]=x[i][j]-(c11*x[k][j]);
			}
		}
	}
	for(i=0;i<r;i++)
		for(j=c/2;j<c;j++)
			iv[i][j-c/2]=x[i][j];
}

void main(){
int i,j,k,n;
float xbar[10],mu[10],t2=0.0,f=0.0;
float d[10][1],dt[1][10],mul1[10][10],m[5][5];
clrscr();
p1=fopen("C:/cprog/in9.txt","r");
p2=fopen("C:/cprog/out9.txt","w");
fscanf(p1,"%d%d",&p,&n);
for(i=0;i<p;i++)
	fscanf(p1,"%f",&xbar[i]);
for(i=0;i<p;i++)
	fscanf(p1,"%f",&mu[i]);
for(i=0;i<p;i++)
	for(j=0;j<p;j++)
		fscanf(p1,"%f",&s[i][j]);
fprintf(p2,"Sample mean vector is given under:\n");
for(i=0;i<p;i++)
	fprintf(p2,"%.3f\t",xbar[i]);
fprintf(p2,"\n\nMu vector is given as below:\n");
for(i=0;i<p;i++)
	fprintf(p2,"%.3f\t",mu[i]);
fprintf(p2,"\n\nSample dispersion matrix is given below:\n");
for(i=0;i<p;i++){
    for(j=0;j<p;j++)
		fprintf(p2,"%.3f\t",s[i][j]);
		fprintf(p2,"\n");
}
fprintf(p2,"\nThe difference vector of xbar and mu is given below:\n");
for(i=0;i<p;i++)
	d[i][0]=xbar[i]-mu[i];
for(i=0;i<p;i++)
	fprintf(p2,"%.3f\n",d[i][0]);
fprintf(p2,"\n\nThe transpose of difference matrix is given below:\n");
for(i=0;i<p;i++)
    dt[0][i]=d[i][0];
for(j=0;j<p;j++)
	fprintf(p2,"%.3f\t",dt[0][j]);
minv(s,sinv,p,p);
fprintf(p2,"\n\nThe inverse of sample dispersion matrix is given below:\n");
for(i=0;i<p;i++){
	for(j=0;j<p;j++)
		fprintf(p2,"%.3f\t",sinv[i][j]);
		fprintf(p2,"\n");
}
//multiplication of sinv and difference vector
for(i=0;i<p;i++)
	for(j=0;j<1;j++){
		mul1[i][j]=0.0;
	for(k=0;k<p;k++)
	    mul1[i][j]+=sinv[i][k]*d[k][j];
	}
//multiplication of transpose of difference vector and mul1 
for(i=0;i<1;i++)	
	for(j=0;j<1;j++){
		m[i][j]=0.0;
	for(k=0;k<p;k++)
	    m[i][j]+=dt[i][k]*mul1[k][j];
    }
	
t2=n*m[0][0];
f=((n-p)/(float)p)*(t2/(float)(n-1));
fprintf(p2,"\nThe value of our test statistic is F= %f\n",f);
getch();
}

/*
-------------INPUT----------------
5	30

16.804	9.361	2.010	2.251	0.260

17.013	8.520	3.505	0.760	1.000

176.804	-34.377	-14.427	-1.226	-1.334
-34.377	28.857	-0.120	0.073	-0.028
-14.427	-0.120	2.683	0.188	0.141
-1.226	0.073	0.188	0.253	0.017
-1.334	-0.028	0.141	0.017	0.096
-------------OUTPUT---------------
Sample mean vector is given under:
16.804	9.361	2.010	2.251	0.260	

Mu vector is given as below:
17.013	8.520	3.505	0.760	1.000	

Sample dispersion matrix is given below:
176.804	-34.377	-14.427	-1.226	-1.334	
-34.377	28.857	-0.120	0.073	-0.028	
-14.427	-0.120	2.683	0.188	0.141	
-1.226	0.073	0.188	0.253	0.017	
-1.334	-0.028	0.141	0.017	0.096	

The difference vector of xbar and mu is given below:
-0.209
0.841
-1.495
1.491
-0.740

The transpose of difference matrix is given below:
-0.209	0.841	-1.495	1.491	-0.740	

The inverse of sample dispersion matrix is given below:
0.019	0.023	0.096	0.005	0.129	
0.023	0.063	0.119	-0.006	0.166	
0.096	0.119	0.908	-0.249	0.081	
0.005	-0.006	-0.249	4.185	-0.303	
0.129	0.166	0.081	-0.303	12.190	

The value of our test statistic is F= 101.268730
-------------------*/