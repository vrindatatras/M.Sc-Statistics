/*---Vishal Kumar; Practical 2---*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<time.h>

FILE *p, *q;
main()	{
	int n, i, j, c, d, MLE=0;
	float mu1, mu2, sig, u1, u2, x[20], y[20], sum1, sum2, a[20], b[20];
	clrscr();
	p=fopen("C:/cprog/norm2.txt","r");
	q=fopen("C:/cprog/normout2.txt","w");
	fscanf(p, "%f %f %f %d", &mu1, &mu2, &sig, &n);
	fprintf(q, "Value of the mean parameter is %.3f\t\n", mu1);
	fprintf(q, "Value of the mean parameter is %.3f\t\n", mu2);
	fprintf(q, "Value of population variance is %.3f\t\n", sig);
	fprintf(q, "Value of n is %d\t\n", n);
	fprintf(q, "Sample no.\tlogL(x) for mu=4\tlogL(x) for mu=5\tMLE\n");
	randomize();
	for(i=0; i<6; i++)	{
		for(j=0; j<12; j+=2)	{
			u1=rand()/(RAND_MAX+1.0);
			u2=rand()/(RAND_MAX+1.0);
			x[j]=(sqrt(-2.0*(log(u1))))*(cos(2.0*3.14*u2));
			x[j+1]=(sqrt(-2.0*(log(u1))))*(sin(2.0*3.14*u2));
			y[j]= 4.5+3*x[j];
			y[j+1]= 4.5+3*x[j+1];
			sum1 += pow((y[j]-4.0),2.0);
			sum2 += pow((y[j]-5.0),2.0);
		}
		a[i] = -50*log(2*3.1416*9)-(1/(2*sig))*sum1;
		b[i] = -50*log(2*3.1416*9)-(1/(2*sig))*sum2;
		if(a[i] > b[i])	{
			c++;
			MLE=4;
		}
		else	{
			d++;
			MLE=5;
		}
		fprintf(q, "%d\t\t%f\t\t%f\t\t%d\n", i+1, a[i], b[i], MLE);
	}
	if(c > d)
		fprintf(q, "\nMean=4 is the Maximum Likelihood Estimator");
	else
		fprintf(q, "\nMean=5 is the Maximum Likelihood Estimator");
}

/*----------INPUT----------
4 5 9 100
----------------------
/*----------OUTPUT----------
Value of the mean parameter is 4.000	
Value of the mean parameter is 5.000	
Value of population variance is 9.000	
Value of n is 100	
Sample no.	logL(x) for mu=4	logL(x) for mu=5	MLE
1		-207.331863		-206.645660		5
2		-210.965805		-209.620529		5
3		-212.856583		-212.517334		5
4		-214.702560		-215.070679		4
5		-219.068451		-218.736038		5
6		-221.992111		-222.270279		4

Mean=5 is the MLE
----------*/