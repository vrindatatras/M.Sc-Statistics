#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 10

float det(int p,float s[MAX][MAX]){
 int i,j,k;
 float d=1.0,R;
 for(i=0;i<p;i++){
  for(j=0;j<p;j++){
   if(j>i){
    R=s[j][i]/s[i][i];
    for(k=0;k<p;k++)
     s[j][k]-=R*s[i][k];
   }
  }
 }
 for(i=0;i<p;i++)
  d*=s[i][i];
 return(d);
}

void main(){
 FILE *p,*q;
 int i,j,n,n1,n2,k=2,p1[5],q1=0,sq=0,cb=0,qsq[5],qcb[5],p3,N=300;
 float x[10][10],x1[10][10],x2[10][10],D,D1,D2,L,F,lambda,T;
 clrscr();
 p=fopen("10_pg3.txt","r");
 q=fopen("10_pg3out.txt","w");
 fscanf(p,"%d%d%d",&n,&n1,&n2);
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   fscanf(p,"%f",&x[i][j]);
 for(i=0;i<n1;i++)
  for(j=0;j<n1;j++)
   x1[i][j]=x[i][j];
 for(i=0;i<n2;i++)
  for(j=0;j<n2;j++)
   x2[i][j]=x[i+n2][j+n2];
 D=det(n,x);
 D1=det(n1,x1);
 D2=det(n2,x2);
 fprintf(q,"\n D = %f\t D1 = %f\t D2 = %f",D,D1,D2);
 for(i=0;i<k;i++){
  p1[i]=k;
  qsq[i]=pow(p1[i],2);
  qcb[i]=pow(p1[i],3);
  q1+=p1[i];
  sq+=qsq[i];
  cb+=qcb[i];
 }
 p3=pow(q1,3);
 L=D/(D1*D2);
 F=((q1*q1)/2.0)-(sq/2.0);
 lambda=(3.0/2.0)+(p3-cb)/(6*F);
 T=(lambda-N)*log(L);
 fprintf(q,"\n T = %f",T);
 fclose(p);
 fclose(q);
}
/*---------INPUT---------
4	2	2
51.121	23.86	1.793	0.998
23.86	54.756	3.633	3.211
1.793	3.633	18.255	21.122
0.998	3.211	21.122	60.516
----------OUTPUT---------

 D = 1447935.875000	 D1 = 2229.881592	 D2 = 658.580627
 T = 4.192860
 ---------------------*/