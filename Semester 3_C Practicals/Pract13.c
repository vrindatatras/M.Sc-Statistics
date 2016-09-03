#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 50

void main(){
FILE *p,*q;
int i,j,k,x1[MAX],x2[MAX],x3[MAX],y[MAX],X[MAX][5],N;
float Ey[MAX],b0,b1,b2,b3,d[MAX],D=0.0;
clrscr();
p=fopen("C:/dprog/in13.txt","r");
q=fopen("C:/dprog/out13.txt","w");
fscanf(p,"%d%d%f%f%f%f",&N,&k,&b0,&b1,&b2,&b3);
fprintf(q,"N=%d\tk=%d\tbo=%f\tb1=%f\tb2=%f\tb3=%f",N,k,b0,b1,b2,b3);
for(j=0;j<N;j++)
	fscanf(p,"%d%d%d%d",&x1[j],&x2[j],&x3[j],&y[j]);
for(j=0;j<N;j++){
	Ey[j]=exp(b0+b1*x1[j]+b2*x2[j]+b3*x3[j]);
	d[j]=y[j]*log(y[j]/Ey[j])-(y[j]-Ey[j]);
	D+=d[j];
}
fprintf(q,"\n x1 \t x2 \t x3 \t yi \t E(yi)\n");
for(i=0;i<N;i++)
	fprintf(q," %d\t%d\t%d\t%d\t%.0f\n",x1[i],x2[i],x3[i],y[i],Ey[i]);
fprintf(q,"\n D = %f",2*D);
fclose(p);
fclose(q);
}
/*-------------INPUT--------------
15	4	2.2195	0.02174	.02240	.000276
7 5 7 7	6 6 5 6	5 6 5 7	6 6 6
4 3 3 2	4 3 3 2 4 2 2 3 3 3 4
90 105 105 90 105 90 75	105 90 75 90 75	90 90 75
3 5 7 9 10 8 6 14 11 9	5 11 6	11 12
--------------OUTPUT--------------
N=15	k=4	bo=2.219500	b1=0.021740	b2=0.022400	b3=0.000276
 x1 	 x2 	 x3 	 yi 	 E(yi)
 7	4	90	3	12
 5	3	105	5	11
 7	3	105	7	12
 7	2	90	9	11
 6	4	105	10	12
 6	3	90	8	11
 5	3	75	6	11
 6	2	105	14	11
 5	4	90	11	12
 6	2	75	9	11
 5	2	90	5	11
 7	3	75	11	12
 6	3	90	6	11
 6	3	90	11	11
 6	4	75	12	12
D = 29.873306*/