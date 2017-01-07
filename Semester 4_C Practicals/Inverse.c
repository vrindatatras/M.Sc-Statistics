/*------Vishal Kumar------*/

void inverse(int P,float c[][MAX],float I[][MAX]){
	int i,j,k;
	float r,t;
	for(i=0;i<P;i++){
		r=c[i][i];
		for(j=0;j<P;j++)
			{
			c[i][j]=c[i][j]/r;
			I[i][j]=I[i][j]/r;
		}
		for(k=0;k<P;k++){
			if(k!=i){
				t=c[k][i];
				for(j=0;j<P;j++){
					c[k][j]-=t*c[i][j];
					I[k][j]-=t*I[i][j];
				}
			}
		}
	}
}