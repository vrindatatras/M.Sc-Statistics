/*---Vishal Kumar; Practical 5---*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

FILE *p, *q;

void main(){
	int r[50], in[50], a, i, k=1, temp,temp2, j;
	float expr, varr, m=0,n;
	clrscr();
	p=fopen("C:/cprog/runin.txt","r");
	q=fopen("C:/cprog/runout.txt","w");
	fscanf(p, "%f", &n);
	for(i=0; i<2*n; i++)
		fscanf(p, "%d", &r[i]);
	for(i=0; i<n; i++){
		in[i]=1;
		in[i+15]=2;
	}
	for(i=0; i<2*n; i++){
		for(j=0; j<2*n; j++){
			if(r[i] <= r[j]){
				temp = r[i];
				temp2=in[i];
				r[i]=r[j];
				in[i]=in[j];
				r[j]=temp;
				in[j]=temp2;
			}
		}
	}
	fprintf(q, "Sorted values are:\n");
	for(i=0;i <2*n; i++){
		fprintf(q, "%d ", r[i]);
		if(i==9 || i==19)
			fprintf(q, "\n");
	}
	fprintf(q, "\nSequence in runs is:\n");
	for(i=0;i <2*n; i++){
		fprintf(q, "%d ", in[i]);
		if(i==9 || i==19)
			fprintf(q, "\n");
	}
	a=in[0];
	for(i=0; i<2*n; i++){
		if(a==in[i]);
		else{
			a=in[i];
			k++;
		}
	}
	fprintf(q,"\nNumber of runs are: %d", k);
	expr=1+2*n*n/(n+n);
	varr=((2*n*n)*(2*n*n-n-n))/(((n+n)*(n+n))*(n+n-1));
	m=(k-expr)/sqrt(varr);
	fprintf(q, "\nMean is: %f\nVariance is: %f\nValue of z statistics is: %f", expr, varr, m);
	fclose(p);
	fclose(q);
}



/*--------INPUT-------
15
24 35 12 50 60 70 68 49 80 25 69 28 28 11 88
31 37 34 54 75 45 75 26 45 45 59 94 48 63 45
----------------------
--------OUTPUT--------
Sorted values are:
11 12 24 25 26 28 28 31 34 35 
37 45 45 45 45 48 49 50 54 59 
60 63 68 69 70 75 75 80 88 94 
Sequence in runs is:
1 1 1 1 2 1 1 2 2 1 
2 2 2 2 2 2 1 1 2 2 
1 2 1 1 1 2 2 1 1 2 
Number of runs are: 14
Mean is: 16.000000
Variance is: 7.241379
Value of z statistics is: -0.743223
----------------------*/