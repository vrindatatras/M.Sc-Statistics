#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void mult(float a[][21],float b[][21],int n,int p1,float z[][21]);
void mult1(float x1[][21],float y[],int n,int p1,float z[]);
void inv(float s[][21],int n,float m1[][21]);

FILE *p,*q;
void main(){
 int i,j,n;
 float x[30],y[30], x1[21][21],x2[21][21],z[21][21],xinv[21][21],z1[21],b[5];
 float e[30],sum=0.0,sum1=0.0,d,d1;

 p=fopen("C:/Data/cwork/in9.txt","r");
 q=fopen("C:/Data/cwork/out9.txt","w");

 fscanf(p,"%d",&n);
 for(i=0;i<n;i++)
   fscanf(p,"%f%f",&y[i],&x[i]);

 for(i=0;i<n;i++){
   x1[i][0]=1.0;
   x1[i][1]=x[i];
 }

 for(i=0;i<2;i++)
   for(j=0;j<n;j++)
     x2[i][j]=x1[j][i];
 mult(x2,x1,n,2,z);
 inv(z,2,xinv);
 mult1(x2,y,n,2,z1);
 mult1(xinv,z1,2,2,b);

 for(i=0;i<2;i++)
   fprintf(q,"b[%d]=%f\n",i,b[i]);
 for(i=0;i<n;i++)
   e[i]=y[i]-(b[0]+b[1]*x[i]);
 for(i=1;i<n;i++)
   sum+=pow((e[i]-e[i-1]),2);
 for(i=0;i<n;i++)
   sum1+=pow(e[i],2);

 d=sum/sum1;
 fprintf(q,"d=%f\n",d);
}

void mult(float a[][21],float b[][21],int n,int p1,float z[][21]){
  int i,j,k;
  for(i=0;i<p1;i++){
    for(j=0;j<p1;j++){
      z[i][j]=0.0;
      for(k=0;k<n;k++)
      z[i][j]+=a[i][k]*b[k][j];
    }
  }
}
void mult1(float x1[][21],float y[],int n,int p1,float z[]){
  int i,j;
  for(i=0;i<p1;i++){
    z[i]=0.0;
    for(j=0;j<n;j++)
    z[i]+=x1[i][j]*y[j];
  }
}

void inv(float s[][21],int n,float m1[][21]){
 int i,j,k;
 float y[21][21],m[21][42],z[21][21],temp,c;
 for(i=0;i<n;i++){
  for(j=0;j<n;j++){
   if(i==j)
   y[i][j]=1.0;
   else
   y[i][j]=0.0;
  }
}

 for(i=0;i<n;i++){
   for(j=0;j<(2*n);j++){
    if(j<n)
     m[i][j]=s[i][j];
     else
     m[i][j]=y[i][j-n];
    }
 }
 for(i=0;i<n;i++){
   temp=m[i][i];
   for(j=0;j<(2*n);j++)
    m[i][j]=m[i][j]/temp;
    {
    for(k=0;k<n;k++){
     if(k!=i){
       c=m[k][i];
       for(j=0;j<2*n;j++)
       m[k][j]=m[k][j]-c*m[i][j];
     }
   }
 }
}
 for(i=0;i<n;i++){
  for(j=0;j<n;j++)
    m1[i][j]=m[i][j+n];
 }
 for(i=0;i<n;i++){
   for(j=0;j<n;j++){
     z[i][j]=0.0;
       for(k=0;k<n;k++)
	 z[i][j]+=m1[i][k]*s[k][j];
   }
 }
}







/*--------INPUT--------
20
3083 75
3149 78
3218 80
3239 82
3295 84
3374 88
3475 93
3569 97
3597 99
3725 104
3794 109
3959 115
4043 120
4194 127
4318 135
4493 144
4683 153
4850 161
5005 170
5236 182
---------OUTPUT----------
b[0]=1608.508179
b[1]=20.090952

d=1.080049
--------------------*/