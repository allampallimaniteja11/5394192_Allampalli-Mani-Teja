#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,q,last=0;
    scanf("%d%d",&n,&q);
    int **arr=calloc(n,sizeof(int*)),*sz=calloc(n,sizeof(int));
    for(int i=0;i<q;i++){
        int t,x,y,idx;
        scanf("%d%d%d",&t,&x,&y);
        idx=(x^last)%n;
        if(t==1){
            arr[idx]=realloc(arr[idx],(sz[idx]+1)*sizeof(int));
            arr[idx][sz[idx]++]=y;
        }else{
            last=arr[idx][y%sz[idx]];
            printf("%d\n",last);
        }
    }
    for(int i=0;i<n;i++) free(arr[i]);
    free(arr); free(sz);
    return 0;
}
