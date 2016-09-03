/*---Vishal Kumar; Practical 2---*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include "batmean.h"

extern float batmean(float data[], int n);
extern float batvar(float data[], float mean, int n);
FILE *p, *q;

	void main()	{
		int i, j, nos, m, n[5];
		float lambda, x[6000], mean, var, u[6000];
		p=fopen("C:/cprog/expo1.txt","r");
		q=fopen("C:/cprog/expoout1.txt","w");
		randomize();
		fscanf(p,"%f",&lambda);
		fprintf(q,"Parameter of exponential dist is %.3f\n",lambda);
		fscanf(p,"%d",&nos);
		fprintf(q, "Enter the number of sample(s):%d\n",nos);
		for(i=0; i<nos; i++)
			fscanf(p, "%d", &n[i]);
			
		fprintf(q, "n \t Mean \t\t Variance\n");
		for(i=0; i<nos; i++)	{
			for(j=0; j<n[i]; j++)	{
				u[j] = rand()/(RAND_MAX+1.0);
				x[j] = (-1.0)*lambda*log(u[j]);
			}
			m = n[i];
			mean = batmean(x, m);
			var= batvar(x, mean, m)/m;
			fprintf(q, "%d\t%f\t%f\n", n[i], mean, var);
		}
		fclose(q);
		fclose(p);
	}

/*----------INPUT----------
5 4 100 500 1000 5000
----------OUTPUT----------
Parameter of exponential dist is 5.000
Enter the number of sample(s):4
n 	 	Mean 		Variance
100		4.483798	0.197252
500		4.661891	0.043162
1000	4.786721	0.021167
5000	4.975409	0.004930
----------*/	