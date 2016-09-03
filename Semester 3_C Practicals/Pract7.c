/*---Vishal Kumar; Practical 7---*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int Fn(int x[],int z,int n){
	int i,j,c=0;
	for(i=0;i<n;i++)
		if(z>=x[i])
    c++;
	return(c);
}

void main()
{
 FILE *p,*q;
 int i,j,k,r,n1,n2,N,NN,x[30],y[30],s[60],z[60],tmp=0;
 float Dn,K,calpha=1.36,l1[30],l2[30];
 clrscr();
 p=fopen("C:/cprog/in7.txt","r");
 q=fopen("C:/cprog/out7.txt","w");
 fscanf(p,"%d %d",&n1,&n2);
 fprintf(q,"\n Null Hypothesis: Both samples follow same distribution");
 fprintf(q,"\n Alternative Hypothesis: Both samples do not follow same distribution");
 for(i=0;i<n1;i++)
	fscanf(p,"%d",&x[i]);
 for(i=0;i<n2;i++)
	fscanf(p,"%d",&y[i]);
 N=n1+n2;
 for(i=0;i<N;i++){
	if(i<n1)
		s[i]=x[i];
	else
		s[i]=y[i-n1];
 }
 for(i=0;i<N;i++){
  for(j=0;j<(N-1)-i;j++){
   if(s[j]>s[j+1]){
		tmp=s[j];
		s[j]=s[j+1];
		s[j+1]=tmp;
   }
  }
 }
 fprintf(q,"\n Merged and Sorted Data :\n");
 for(i=0;i<N;i++){
	z[i]=s[i];
	fprintf(q,"%d\n",s[i]);
 }
 NN=N;
 for(i=0;i<NN;i++){
	r=i+1;
  if(z[i]==z[r]){
   for(j=0;j<r;j++)
		z[j]=z[j];
   for(j=r;j<NN;j++)
		z[j]=z[j+1];
   NN--;
  }
 }
 for(i=0;i<NN;i++){
	l1[i]=Fn(x,z[i],n1)/(float)n1;
	l2[i]=Fn(y,z[i],n2)/(float)n2;
 }
 Dn=0.0;
 for(i=0;i<NN;i++)
	Dn=max(Dn,fabs(l1[i]-l2[i]));
 K=calpha*sqrt((n1+n2)/(float)(n1*n2));
 fprintf(q,"Dn=%f\t K=%f",Dn,K);
 if(Dn>K)
	fprintf(q,"\n Reject H0");
 else
	fprintf(q,"\n Fail to reject H0");
 fclose(p);
 fclose(q);
 getch();
}

/*-----------INPUT-----------
15	15
227	176	254	149	16	55	234	294	247	92	184	147	88	161	171
202	14	165	171	292	271	151	235	147	99	63	284	53	228	271

-------------OUTPUT----------
Null Hypothesis: Both samples follow same distribution.
Alternative Hypothesis: Both samples do not follow same distribution.
Merged and Sorted Data :
14	16	53	55	63	88	92
99	147	147	149	151	161	165
171	171	176	184	202	227	228
234	235	247	254	271	271	284
292	294

Dn=0.200000	 K=0.496602
 Fail to reject H0
 ------------------*/