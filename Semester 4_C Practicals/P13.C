#include<stdio.h>
#include<conio.h>
#include<math.h>

void main(){
	int i,n=100,r=15;
	float x1,x2,s,t[20],r1,r2;
	FILE *p,*q;
	p=fopen("C:/Data/cwork/in13.txt","r");
	q=fopen("C:/Data/cwork/out13.txt","w");
	for(i=0; i<r; i++){
		fscanf(p, "%f", &t[i]);
		s += t[i];
	}	
	x1=(s+(n-r)*t[r-1])/r;
	x2=(n*t[r-1])/r;
	r1=exp(-500/x1);
	r2=exp(-500/x2);
	fprintf(q, "Failed tubes are not replaced:\n");
	fprintf(q, "Mean survival time= %.4f\n", x1);
	fprintf(q, "Reliability at t=500 hrs = %.4f", r1);
	fprintf(q, "\n\nFailed tubes are replaced:\n");
	fprintf(q, "Mean survival time= %.4f\n", x2);
	fprintf(q, "Reliability at t=500 hrs = %.4f", r2);
	getch();
}
/*----------INPUT----------
40 60 90 120 195 260 350 420 501 620 650 730 815 910 980
-----------OUTPUT---------
Failed tubes are not replaced:
Mean survival time= 6002.7334
Reliability at t=500 hrs = 0.9201

Failed tubes are replaced:
Mean survival time= 6533.3335
Reliability at t=500 hrs = 0.9263
------------------------*/