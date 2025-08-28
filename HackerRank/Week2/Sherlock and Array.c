#include <stdio.h>

void balancedSums(int arr[], int n){
    long long total=0,left=0;
    for(int i=0;i<n;i++) total+=arr[i];
    for(int i=0;i<n;i++){
        if(left==total-left-arr[i]){
            printf("YES\n");
            return;
        }
        left+=arr[i];
    }
    printf("NO\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        balancedSums(arr,n);
    }
    return 0;
}
