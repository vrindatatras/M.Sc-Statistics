/*---Vishal Kumar; Practical 1---*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include "batmean.h"

extern float batmean(float data[15000], int n);
extern float batvar(float data[15000], float mean, int n);
FILE *p, *q;

void main()	{
	int i, j, nos, n[5], m;
	float mu, sig, x[15000], y[15000], mean, var, median, u1, u2, ARE;
	p=fopen("C:/cprog/norm1.txt","r");
	q=fopen("C:/cprog/normout1.txt","w");
	fscanf(p,"%f%f",&mu,&var);
	fprintf(q,"Mean of normal dist is %.3f\nVariance of normal dist is %.3f\n",mu,var);
	fscanf(p,"%d",&nos);
	fprintf(q, "Enter the number of sample(s):%d\n",nos);
	for(i=0; i<nos; i++)
		fscanf(p, "%d", &n[i]);
	fprintf(q, "n \t Mean \t\t Variance \t Median \t ARE\n");
	for(i=0; i<nos; i++)	{
		randomize();
		for(j=0; j<n[i]; j+=2)	{
			u1=rand()/(RAND_MAX+1.0);
			u2=rand()/(RAND_MAX+1.0);
			x[j]=(sqrt(-2.0*(log(u1))))*(cos(2.0*3.14*u2));
			x[j+1]=(sqrt(-2.0*(log(u1))))*(sin(2.0*3.14*u2));
			y[j]= mu+sqrt(var)*x[j];
			y[j+1]= mu+sqrt(var)*x[j+1];
		}
			m = n[i];
		mean = batmean(y, m);
		var= batvar(y, mean, m)/m;
		median=(3.14/2.0)*var;
		ARE = (var/median)*100;
		fprintf(q, "%d\t%f\t%f\t%f\t%f\n", n[i], mean, var, median, ARE);
	}
	fclose(q);
	fclose(p);
}

/*----------INPUT----------
3 16 5 100 500 1000 1500 2000
----------OUTPUT----------
Mean of normal dist is 3.000
Variance of normal dist is 16.000
Enter the number of sample(s):5
n 	Mean 		Variance 	Median	 	ARE
100	3.279474	0.128766	0.202162	63.694267
500	3.011435	0.000267	0.000420	63.694267
1000	2.999522	0.000000	0.000000	63.694267
1500	2.774560	0.000447	0.000702	63.694271
2000	2.077951	0.001106	0.001736	63.694267
----------*/