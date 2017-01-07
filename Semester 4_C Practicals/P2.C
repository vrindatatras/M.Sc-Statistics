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
	int i,j, k=1, l=0, z=0, n;
	float x[20],y[20],sse, f1,f2, temp,temp2,sum[10],b01,b11,yh1[20],R1, k1[10],a,ybar[10],ycap[10], ycapv[10],ybarv[10], r[10],lof;
	FILE *p, *q;
	p = fopen("C:/Data/cwork/in2.txt","r");
	q = fopen("C:/Data/cwork/out2.txt","w");
	clrscr();
	fscanf(p, "%d\n", &n);
	for(i=0; i<n; i++)
		fscanf(p, "%f %f", &x[i], &y[i]);

	fprintf(q, "Linear Model\n");
	b11=beta1(x, y, n);
    b01=beta0(x, y, b11, n);
    fprintf(q, "y=%f+%f*x \n", b01, b11);
    for(i=0; i<n; i++)
		yh1[i]=b01+(b11*x[i]);
    R1 = rsq(y, yh1, n);
    fprintf(q,"Rsquare: %f\n", R1);

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(x[i] <= x[j]){
				temp = x[i];
				temp2= y[i];
				x[i] = x[j];
				y[i] = y[j];
				x[j] = temp;
				y[j] = temp2;
			}	
	
	a = x[0];
	j=0;
	r[0]=x[0];
	for(i=0; i<n; i++){
		if(a==x[i])
			k1[j]++;
		else{
			a=x[i];
			r[k]=x[i];
			k++;
			j++;
			i--;
		}
	}
		
	for(i=0; i<n; i++)
		ycap[i] = b01 + b11*x[i];
	
	for(i=0; i<n; i++)
		ycapv[i] = b01 + b11*r[i];
	
	z=0;
	for(i=0; i<k; i++){
		for(j=0; j<k1[i]; j++){
			sum[i] = sum[i] + y[z];
			z++;
		}
		ybarv[i] = sum[i]/k1[i];
	}
	
	z=0;
	for(i=0; i<k; i++)
		for(j=0; j<k1[i]; j++){
			ybar[z] = ybarv[i];
			z++;
		}
	
	f1 = R1*7/(1 - R1);
	fprintf(q, "The values of F statistics for testing significance of regression: %f\n", f1);
	
	for(i=0; i<k; i++)
		lof = lof + k1[i]*(ybarv[i] - ycapv[i])*(ybarv[i] - ycapv[i]);
	fprintf(q, "Sum of Squares due to lack of fit: %f\n", lof);
	for(i=0; i<n; i++)
		sse = sse + (y[i]-ycap[i])*(y[i]-ycap[i]);
	fprintf(q, "Sum of squares due to error: %f\n", sse);
	fprintf(q, "Sum of squares due to pure error: %f\n", sse-lof);
	f2 = lof*(n-k)/(sse-lof)/(k-2);
	fprintf(q, "The values of F statistics for testing lack of fit: %f\n", f2);
	fclose(p);
	fclose(q);
	getch();
}

/*-------------INPUT------------
9
280.00		2.10
250.00		3.00
300.00		3.20
320.00		1.40
310.00		2.60
280.00		3.90
320.00		1.30
300.00		3.40
320.00		2.80
-------------OUTPUT--------------
Linear Model
y=7.949756+-0.017854*x 
Rsquare: 0.231964
The values of F statistics for testing significance of regression: 2.114162
Sum of Squares due to lack of fit: 1.761236
Sum of squares due to error: 4.807903
Sum of squares due to pure error: 3.046667
The values of F statistics for testing lack of fit: 0.770782
--------------------------------*/