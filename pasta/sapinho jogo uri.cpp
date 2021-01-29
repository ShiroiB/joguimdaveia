#include <stdio.h>

int main(){
	int n,m,i,j,l,p=0,sub,h;
    scanf("%d %d", &n,&m);
    int k[m];
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
