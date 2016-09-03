#include<stdlib.h>
#include<stdio.h>

float batmean(float data[], int n)	{
	int i;
	float mean1=0.0;
	for(i=0; i<n; i++)
		mean1 = mean1 + data[i];
	mean1 = mean1/n;
	return(mean1);
}	

float batvar(float data[], float mean, int n)	{
	int i;
	float sqr=0.0;
	for(i=0; i<n; i++)
		sqr = sqr + data[i]*data[i];
	sqr = sqr/n - mean*mean;
	return(sqr);
}