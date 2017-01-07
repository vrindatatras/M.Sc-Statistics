/*------Vishal Kumar------*/

#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include "batmean.h"

extern float batmean(float data[15000], int n);

float ssq(float x[], float y[], int n){
	int i;
    float sum=0.0, xbar, ybar;
    xbar = batmean(x, n);
    ybar = batmean(y, n);
    for(i=0;i<n;i++)
		sum += (x[i]-xbar)*(y[i]-ybar);
    return(sum);
}

float beta1(float x[], float y[], int n){
    int i;
    float sxy, sxx, b1, xbar, ybar;
    sxy = ssq(x, y, n);
    sxx = ssq(x, x, n);
    b1 = sxy/sxx;
    return(b1);
}

float beta0(float x[], float y[], float beta1, int n){
    int i;
    float xbar, ybar, b0;
    xbar = batmean(x,n);
    ybar = batmean(y,n);
    b0 = ybar - (xbar*beta1);
    return(b0);
}

float rsq(float y[],float yhat[], int n){
    int i;
    float r, syhat=0.0, syy;
    syy = ssq(y,y,n);
    for(i=0;i<n;i++)
		syhat+=(y[i]-yhat[i])*(y[i]-yhat[i]);
	r=1 - syhat/syy;
    return(r);
}

void main(){
	int i, n;
	float x[20],x2[20],x3[20],x4[20],y[20],y2[20],y3[20],y4[20],b01,b02,b03,b04,b11,b12,b13,b14,yh1[20],yh2[20],yh3[20],yh4[20],R1,R2,R3,R4;
	FILE *p, *q;
	p = fopen("C:/Data/cwork/in1.txt","r");
	q = fopen("C:/Data/cwork/out1.txt","w");
	clrscr();
	fscanf(p, "%d\n", &n);
	for(i=0; i<n; i++)
		fscanf(p, "%f %f", &y[i], &x[i]);

	fprintf(q, "(i) Linear Model\n");
	b11=beta1(x, y, n);
    b01=beta0(x, y, b11, n);
    fprintf(q, "y=%f+%f*x \n", b01, b11);
    for(i=0; i<n; i++)
		yh1[i]=b01+(b11*x[i]);
    R1 = rsq(y, yh1, n);
    fprintf(q,"Rsquare: %f\n", R1);

	fprintf(q, "\n(ii) Double log Model\n");
    for(i=0;i<n;i++){
		y2[i] = log(y[i]);
		x2[i] = log(x[i]);
    }
    b12=beta1(x2, y2, n);
    b02=beta0(x2, y2, b12, n);
    fprintf(q, "y=%f+%f*x \n", b02, b12);
    for(i=0; i<n; i++)
    yh2[i] = b02 + (b12*x2[i]);
    R2 = rsq(y2, yh2, n);
    fprintf(q,"Rsquare: %f\n", R2);

	fprintf(q, "\n(iii) Log-Linear Model\n");
	for(i=0;i<n;i++){
		y3[i] = y2[i];
		x3[i] = x[i];
    }
    b13 = beta1(x3, y3, n);
    b03 = beta0(x3, y3, b13, n);
    fprintf(q, "y=%f+%f*x \n", b03, b13);
    for(i=0;i<n;i++)
    yh3[i] = b03+(b13*x3[i]);
    R3 = rsq(y3, yh3, n);
    fprintf(q,"Rsquare: %f\n", R3);

	fprintf(q, "\n(iv) Linear-Log Model\n");
	for(i=0;i<n;i++){
      y4[i] = y[i];
      x4[i] = x2[i];
    }
    b14 = beta1(x4, y4, n);
    b04 = beta0(x4, y4, b14, n);
    fprintf(q,"y=%f+%f*x \n", b04, b14);
    for(i=0;i<n;i++)
		yh4[i] = b04 + (b14*x4[i]);
    R4=rsq(y4, yh4, n);
    fprintf(q,"Rsquare: %f\n", R4);
	fclose(p);
	fclose(q);
	getch();
}






/*-------------INPUT------------
17
64.10	110.02
67.70	125.02
72.40	132.27
77.50	137.17
82.00	159.51
85.60	176.16
88.70	190.80
91.10	216.20
94.90	232.41
100.00	237.97
106.30	240.77
111.90	249.25
115.60	275.08
118.40	283.89
121.00	296.05
120.70	325.73
121.11	354.93
-------------OUTPUT--------------
(i) Linear Model
y=38.966202+0.260894*x 
Rsquare: 0.942363

(ii) Double log Model
y=1.403939+0.588987*x 
Rsquare: 0.964183

(iii) Log-Linear Model
y=3.931555+0.002799*x 
Rsquare: 0.928466

(iv) Linear-Log Model
y=-192.979645+54.215206*x 
Rsquare: 0.954343
--------------------------------*/