#include<stdio.h>
#include<conio.h>
#include<math.h>

void main(){
	float t=10.0,x,r,a,b;
	FILE *q;
	clrscr();
	q=fopen("C:/Data/cwork/out12.txt","w");
	a=6220000.0;
	b=9421000.0;
	fprintf(q, "AP Method:\n");
	r=(b - a)/t;
	x=b + (r*16.0/3);
	fprintf(q, "\nMid year population of 1996=%.4f", x);
	x=b + (r*31.0/3);
	fprintf(q, "\nMid year population of 2001=%.4f\n", x);
	fprintf(q, "\nGP Method:\n");
	r = pow((b/a), 1/t) - 1;
	x=b*pow(1.0+r, 16.0/3);
	fprintf(q, "\nMid year population of 1996=%.4f", x);
	x=b*pow(1.0+r, 31.0/3);
	fprintf(q, "\nMid year population of 1996=%.4f", x);
	getch();
}
/*---------OUTPUT--------
AP Method:

Mid year population of 1996=11128200.0000
Mid year population of 2001=12728700.0000

GP Method:

Mid year population of 1996=11756026.0000
Mid year population of 1996=14468178.0000
------------------------*/