#include <stdio.h>

int main(){
	int n,m,i,j,l,p,sub,h;
	int k[10];
    scanf("%d %d", &n,&m);
    k[n];
	for(i=0;i<m;i++){
		scanf("%d", &k[i]);
	}for(j=1;j<m;j++){
		if(k[j]>k[j-1]){sub=k[j]-k[j-1];
		}else sub=k[j-1]-k[j];
		if(sub<=n)p++;
		}
		if(p==m-1){
		    printf("YOU WIN\n");
	    }else{
		    printf("GAME OVER\n");
	    }

		return 0;
}
