/*---Vishal Kumar; Practical 3A---*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<time.h>

float lol(float y[200], float sig){
	int i;
	float ll, a;
	for(i=0; i<100; i++)
		a = a + pow((y[i]-6)/sqrt(sig),2);
	ll = -50.0*log(2*3.14*sig)-a/2.0;
	return(ll);
}
FILE *p, *q;
void main(){
	int i,j;
	float sig[5],u1,u2,x[200],y[200],ll[5],n,temp,max,loglam,d;
	clrscr();
	randomize();
	p=fopen("C:/cprog/norm3.txt","r");
	q=fopen("C:/cprog/normout3.txt","w");
	for(i=0; i<4; i++)
		fscanf(p, "%f", &sig[i]);
	for(j=0; j<100; j+=2){
		u1=rand()/(RAND_MAX+1.0);
		u2=rand()/(RAND_MAX+1.0);
		x[j]=sqrt(-2.0*(log(u1)))*cos(2.0*3.14*u2);
		x[j+1]=sqrt(-2.0*(log(u1)))*sin(2.0*3.14*u2);
		y[j]=6+sqrt(5)*x[j];
		y[j+1]=6+sqrt(5)*x[j+1];
		}
	for(i=0; i<4; i++){
		ll[i]=lol(y, sig[i]);
		fprintf(q, "MLE for variance %d is: %f\n", i+1, ll[i]);
	}
	if(ll[1]>ll[2])
		n=ll[1];
	else
		n=ll[2];
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(ll[i]<ll[j]){
				temp = ll[i];
				ll[i]=ll[j];
				ll[j]=temp;
			}
		}
	}
	fprintf(q, "\nAfter sorting log-likelihood\n");
	for(i=0; i<4; i++)
		fprintf(q, "%f\t", ll[i]);
	fprintf(q, "\nMax of Numerator %f\n", n);
	max=ll[3];
	fprintf(q, "Max of Denominator 	%f\n", max);
	loglam= n - max;
	fprintf(q, "log of lambda is %f\n", loglam);
	d = -2.0*loglam;
	fprintf(q, "2*log(lambda)=%f", d);
	fprintf(q, "\nCritical region is given by lambda(x)<= %f", exp(-1.0*0.003932/2));
	fclose(p);
	fclose(q);
}




/*--------INPUT-------
1 2 3 4
---------------------
--------OUTPUT-------
MLE for variance 1 is: -350.802032
MLE for variance 2 is: -255.992630
MLE for variance 3 is: -233.110306
MLE for variance 4 is: -225.916595

After sorting log-likelihood
-350.802032	-255.992630	-233.110306	-225.916595	
Max of Numerator -233.110306
Max of Denominator 	-225.916595
log of lambda is -7.193710
2*log(lambda)=14.387421
Critical region is given by lambda(x)<= 0.998036
--------------------*/
