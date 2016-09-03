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
float x0[10],x1[10],x2[10],d[10][1],dt[1][10],d1[10][1],dt1[1][10];
float d2[10][1],dt2[1][10],m[5][5],mul1[5][5],mul2[5][5],a1[5][5],a2[5][5];
clrscr();
p1=fopen("C:/cprog/in11.txt","r");
p2=fopen("C:/cprog/out11.txt","w");
fscanf(p1,"%d",&p);
for(i=0;i<p;i++)
	fscanf(p1,"%f",&x1[i]);
for(i=0;i<p;i++)
    fscanf(p1,"%f",&x2[i]);
for(i=0;i<p;i++)
    fscanf(p1,"%f",&x0[i]);
for(i=0;i<p;i++)
    for(j=0;j<p;j++)
		fscanf(p1,"%f",&s[i][j]);
fprintf(p2,"Transpose of mean score vector of group 1:\n");
for(i=0;i<p;i++)
    fprintf(p2,"%.3f\t",x1[i]);
fprintf(p2,"\n\nTranspose of mean score vector of group 2:\n");
for(i=0;i<p;i++)
	fprintf(p2,"%.3f\t",x2[i]);
fprintf(p2,"\n\nSample dispersion matrix is given as:\n");
for(i=0;i<p;i++){
    for(j=0;j<p;j++)
	fprintf(p2,"%.3f\t",s[i][j]);
	fprintf(p2,"\n");
}
fprintf(p2,"\nThe difference vector of mean score vectors is given as:\n");
for(i=0;i<p;i++)
    d[i][0]=x1[i]-x2[i];
for(i=0;i<p;i++)
    fprintf(p2,"%.3f\n",d[i][0]);
for(i=0;i<p;i++)
	dt[0][i]=d[i][0];
minv(s,sinv,p,p);
fprintf(p2,"\n\nThe inverse of sample dispersion matrix is given below:\n");
for(i=0;i<p;i++){
    for(j=0;j<p;j++)
		fprintf(p2,"%.3f\t",sinv[i][j]);
    fprintf(p2,"\n");
}
for(i=0;i<1;i++){
    for(j=0;j<p;j++){
		m[i][j]=0.0;
	for(k=0;k<p;k++)
	    m[i][j]+=dt[i][k]*sinv[k][j];
    }
}
fprintf(p2,"\n\nThe Fisher's linear discriminant function is:\n");
fprintf(p2,"\n(%.3fX1)+(%.3fX2)+(%.3fX3)+(%.3fX4)+(%.3fX5)\n",
			m[0][0],m[0][1],m[0][2],m[0][3],m[0][4]);
for(i=0;i<p;i++)
	d1[i][0]=x0[i]-x1[i];
for(i=0;i<p;i++)
	dt1[0][i]=d1[i][0];
fprintf(p2,"\n\nThe transpose of diff vector d1 is :\n");
for(i=0;i<p;i++)
    fprintf(p2,"%.3f\t",dt1[0][i]);
for(i=0;i<p;i++)
	d2[i][0]=x0[i]-x2[i];
for(i=0;i<p;i++)
	dt2[0][i]=d2[i][0];
fprintf(p2,"\n\nThe transpose of diff vector d2 is :\n");
for(i=0;i<p;i++)
	fprintf(p2,"%.3f\t",dt2[0][i]);
for(i=0;i<1;i++){
    for(j=0;j<p;j++){
		mul1[i][j]=0.0;
		for(k=0;k<p;k++)
	    mul1[i][j]+=dt1[i][k]*sinv[k][j];
    }
}
for(i=0;i<1;i++){
    for(j=0;j<1;j++){
	a1[i][j]=0.0;
	for(k=0;k<p;k++)
	a1[i][j]+=mul1[i][k]*d1[k][j];
	}
}
for(i=0;i<1;i++){
	for(j=0;j<p;j++){
		mul2[i][j]=0.0;
	for(k=0;k<p;k++)
		mul2[i][j]+=dt2[i][k]*sinv[k][j];
	}
}
for(i=0;i<1;i++){
    for(j=0;j<1;j++){
	a2[i][j]=0.0;
	for(k=0;k<p;k++)
	    a2[i][j]+=mul2[i][k]*d2[k][j];
    }
}
fprintf(p2,"\n\nThe value of A1 is %f.\n",a1[0][0]);
fprintf(p2,"The value of A2 is %f.\n",a2[0][0]);
getch();
}

/*---------INPUT-----------
5

62.610	65.240	61.310	70.310	75.250

39.240	58.330	59.260	48.210	45.090

59.24	52.33	62.11	66.92	69.53

70.553	24.869	35.070	36.207	40.539
24.869	19.942	21.224	19.642	21.421
35.070	21.224	27.751	24.181	29.034
36.207	19.642	24.181	33.116	27.471
40.539	21.421	29.034	27.471	39.361
----------OUTPUT-----------
Transpose of mean score vector of group 1:
62.610	65.240	61.310	70.310	75.250	

Transpose of mean score vector of group 2:
39.240	58.330	59.260	48.210	45.090	

Sample dispersion matrix is given as:
70.553	24.869	35.070	36.207	40.539	
24.869	19.942	21.224	19.642	21.421	
35.070	21.224	27.751	24.181	29.034	
36.207	19.642	24.181	33.116	27.471	
40.539	21.421	29.034	27.471	39.361	

The difference vector of mean score vectors is given as:
23.370
6.910
2.050
22.100
30.160


The inverse of sample dispersion matrix is given below:
0.047	0.029	-0.049	-0.023	-0.012	
0.029	0.305	-0.256	-0.047	0.026	
-0.049	-0.256	0.419	-0.004	-0.117	
-0.023	-0.047	-0.004	0.102	-0.019	
-0.012	0.026	-0.117	-0.019	0.123	


The Fisher's linear discriminant function is:

(0.333X1)+(1.990X2)+(-5.663X3)+(0.808X4)+(2.954X5)
 
The transpose of diff vector d1 is :
-3.370	-12.910	0.800	-3.390	-5.720	

The transpose of diff vector d2 is :
20.000	-6.000	2.850	18.710	24.440	

The value of A1 is 63.912983.
The value of A2 is 78.831367.
 ----------------*/