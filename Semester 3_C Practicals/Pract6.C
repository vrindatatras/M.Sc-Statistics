/*---Vishal Kumar; Practical 6---*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

sorting(float a[],int n){
int i,j;
float t;
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		if(a[i]<a[j]){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
}

float rank(float x[],float y[],float r[],int n){
	int i,j;
    float w=0.0,c=0.0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			if(x[i]==y[j]){
				w+=j+1;
				c=c+1;
			}
		r[i]=w/c;
        c=0;w=0;
	}
}
FILE *p,*q;

void main(){
    int i,j,n1,n2,n3,n,n11;
    float s1[50],s2[50],s3[50],cs1[50],cs2[50],rc[50],r1[50],r2[50],r3[50];
    float sum_r1=0,sum_r2=0,sum_r3=0,h,h1=0.0, sumo=0.0, b=0.0, k;
    p=fopen("C:/cprog/kwt6.txt","r");
    q=fopen("C:/cprog/kwtout6.txt","w");
    clrscr();
    fscanf(p,"%d %d %d",&n1,&n2,&n3);
    for(i=0;i<n1;i++)
		fscanf(p,"%f",&s1[i]);
    for(i=0;i<n2;i++)
		fscanf(p,"%f",&s2[i]);
    for(i=0;i<n3;i++)
		fscanf(p,"%f",&s3[i]);
    fprintf(q,"Sample 1:");
    for(i=0;i<n1;i++)
		fprintf(q,"%.1f\t",s1[i]);
    fprintf(q,"\n");
    fprintf(q,"Sample 2:");
    for(i=0;i<n2;i++)
		fprintf(q,"%.1f\t",s2[i]);
    fprintf(q,"\n");
    fprintf(q,"Sample 3:");
    for(i=0;i<n3;i++)
		fprintf(q,"%.1f\t",s3[i]);
    fprintf(q,"\n");
	
    n=n1+n2+n3;
    n11=n1+n2;
    for(i=0;i<n1;i++)
		cs1[i]=s1[i];
    for(i=n1;i<n11;i++)
		cs1[i]=s2[i-n1];
    for(i=n11;i<n;i++)
		cs1[i]=s3[i-n11];
    fprintf(q,"The combined sample is:\n");
    for(i=0;i<n;i++)
		fprintf(q,"%.1f\t",cs1[i]);
    for(i=0;i<n;i++)
		cs2[i]=cs1[i];
    sorting(cs1,n);
    fprintf(q,"\n");
    fprintf(q,"The sorted sample is:\n");
    for(i=0;i<n;i++)
		fprintf(q,"%.1f\t",cs1[i]);
    rank(cs2,cs1,rc,n);
	fprintf(q,"\nThe rank of the combined sample is:\n");
    for(i=0;i<n;i++)
    fprintf(q,"%.1f\t",rc[i]);

   for(i=0;i<n1;i++)
	   r1[i]=rc[i];
   for(i=n1;i<n11;i++)
	   r2[i-n1]=rc[i];
   for(i=n11;i<n;i++)
	   r3[i-n11]=rc[i];
    fprintf(q,"\nThe ranks in samples are:\n");
    fprintf(q,"Sample 1:");
    for(i=0;i<n1;i++)
		fprintf(q,"%.1f\t",r1[i]);
    fprintf(q,"\n");
    fprintf(q,"Sample 2:");
    for(i=0;i<n2;i++)
		fprintf(q,"%.1f\t",r2[i]);
    fprintf(q,"\n");
    fprintf(q,"Sample 3:");
    for(i=0;i<n3;i++)
		fprintf(q,"%.1f\t",r3[i]);
    fprintf(q,"\n");
    for(i=0;i<n1;i++)
		sum_r1+=r1[i];
    for(i=0;i<n2;i++)
		sum_r2+=r2[i];
    for(i=0;i<n3;i++)
		sum_r3+=r3[i];
	
	b = rc[0];k = 1;
	for(i=0; i < n; i++){
		if(b==rc[i])
			k++;
		else{
			k=pow(k, 3)-k;
			b=rc[i];
			sumo=sumo+k;
			k=1.0;
		}
	}
	h=(12./(n*(n+1.)))*(n1*pow(sum_r1/n1,2)+n2*pow(sum_r2/n2,2)+n3*pow(sum_r3/n3,2))-(3*(n+1));
    h1=h/(1-(sumo/(n*(n*n-1))));
    fprintf(q,"\nThe test statistics H is:%f",h1);
	getch();
}

/*-------INPUT-------
9 5 5
1.7 1.9	6.1 12.5 16.5 25.1 30.5	42.1 82.5
13.6 19.8 25.2	46.2 61.1
13.4 20.9 25.1 29.7 46.9
---------OUTPUT------
Sample 1:1.7	1.9	6.1	12.5	16.5	25.1	30.5	42.1	82.5	
Sample 2:13.6	19.8	25.2	46.2	61.1	
Sample 3:13.4	20.9	25.1	29.7	46.9	

The combined sample is:
1.7	1.9	6.1	12.5	16.5	25.1	30.5	42.1	82.5	13.6	
19.8	25.2	46.2	61.1	13.4	20.9	25.1	29.7	46.9	

The sorted sample is:
1.7	1.9	6.1	12.5	13.4	13.6	16.5	19.8	20.9	25.1	
25.1	25.2	29.7	30.5	42.1	46.2	46.9	61.1	82.5	

The rank of the combined sample is:
1.0	2.0	3.0	4.0	7.0	10.5	14.0	15.0	19.0	6.0	
8.0	12.0	16.0	18.0	5.0	9.0	10.5	13.0	17.0	

The ranks in samples are:
Sample 1:1.0	2.0	3.0	4.0	7.0	10.5	14.0	15.0	19.0	
Sample 2:6.0	8.0	12.0	16.0	18.0	
Sample 3:5.0	9.0	10.5	13.0	17.0	

The test statistics H is:1.498507
---------*/