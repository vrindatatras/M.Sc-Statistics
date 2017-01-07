#include<stdio.h>
#include<conio.h>
#include<math.h>
#define n 18
#define k 2

float sum(float a[],float b[]){
	int i;
	float t=0.0;
	for(i=0;i<n;i++)
		t+=a[i]*b[i];
	return(t);
}

float cov(float a[],float b[]){
	int i;
	float I[n],d;
	for(i=0;i<n;i++)
		I[i]=1.0;
	d=sum(a,b)-(sum(a,I)*sum(b,I)/n);
	return(d);
}

main(){
  int i;
  float y[50],x[50],lx[50],u[50],u1[50],I[50];
  float sx[n],r=0.0,F1=0.0,b0=0.0,b1=0.0;

  FILE *p,*q;

  p=fopen("C:/Data/cwork/in8.txt","r");
	q=fopen("C:/Data/cwork/out8.txt","w");
	
  for(i=0;i<n;i++){
   fscanf(p,"%f %f",&y[i],&x[i]);
   I[i]=1.0;
   lx[i]=log(x[i]);
   sx[i]=sqrt(x[i]);
   }

   b1=cov(x,y)/cov(x,x);
   b0=(sum(y,I)/n)-(b1*(sum(x,I)/n));

   for(i=0;i<n;i++){
    u[i]=y[i]-b0-b1*x[i];
    u1[i]=log(pow(u[i],2));
   }

  fprintf(q,"PARK'S TEST\n");

  r=pow(cov(u1,lx),2)/(cov(u1,u1)*cov(lx,lx));
  F1=(r*(n-k))/(1-r)*(k-1);
  fprintf(q,"R Square:=%.4f\nCal F=%.4f\n",r, F1);
  return;
}





/*-----INPUT------
62.5	6378.4
92.9	11626.4
178.9	14655.1
268.4	21869.2
494.7	26408.3
1083.0	32405.6
1620.6	35107.7
421.7	40297.7
509.2	70761.6
6620.1	82552.8
3918.6	9524.0
1595.3	101314.0
6107.5	116141.3
4454.1	122315.7
3163.8	141649.9
13210.7	175025.8
1703.8	230614.5
9528.3	293543.0
--------OUTPUT--------
PARK'S TEST
R Square:=0.0548
Cal F=0.9278
---------------*/