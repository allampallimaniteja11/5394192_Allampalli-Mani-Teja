#include <stdio.h>

int isPowerOfTwo(unsigned long long n){
    return n && !(n & (n-1));
}

char* counterGame(unsigned long long n){
    int turns=0;
    while(n>1){
        if(isPowerOfTwo(n))
            n/=2;
        else{
            unsigned long long p=1;
            while(p*2<n) p*=2;
            n-=p;
        }
        turns++;
    }
    return (turns%2)? "Louise":"Richard";
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        unsigned long long n;
        scanf("%llu",&n);
        printf("%s\n",counterGame(n));
    }
    return 0;
}
