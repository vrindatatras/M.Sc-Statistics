/*---Vishal Kumar; Practical 4---*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<time.h>

FILE *p, *q;
void main(){
	int i, j, n;
	float a[20], b[20], sum1, sum2;
	clrscr();
	p=fopen("C:/cprog/spr4.txt","r");
	q=fopen("C:/cprog/sprout4.txt","w");
	fscanf(p, "%d", &n);
	fprintf(q, "Sample size is %d\n", n);
	for(i=0; i<n; i++)
		fscanf(p, "%f", &a[i]);
	fprintf(q, "xi\t\tzi\t\tDecision\n");
	for(i=0; i<n; i++){
		sum1+=a[i];
		b[i]=sum1*log(6.0/5.0)-(i+1);
		fprintf(q, "%f\t%f", a[i], b[i]);
		if(b[i] > log((1.0-0.02)/0.04))
			fprintf(q, "\tRejected\n");
		else if(b[i] < log((0.02/(1-0.04))))
			fprintf(q, "\tAccepted\n");
		else fprintf(q, "\tContinue Sampling\n");
	}
	getch();
}



/*-------INPUT---------
16
1 3 4 5 6 5 2 3 5 5 2 6 8 2 7 2
-------OUTPUT----------
Sample size is 16
xi		zi		Decision
1.000000	-0.817678	Continue Sampling
3.000000	-1.270714	Continue Sampling
4.000000	-1.541427	Continue Sampling
5.000000	-1.629820	Continue Sampling
6.000000	-1.535890	Continue Sampling
5.000000	-1.624283	Continue Sampling
2.000000	-2.259640	Continue Sampling
3.000000	-2.712675	Continue Sampling
5.000000	-2.801067	Continue Sampling
5.000000	-2.889459	Continue Sampling
2.000000	-3.524816	Continue Sampling
6.000000	-3.430887	Continue Sampling
8.000000	-2.972314	Continue Sampling
2.000000	-3.607671	Continue Sampling
7.000000	-3.331420	Continue Sampling
2.000000	-3.966777	accepted
----------------------*/