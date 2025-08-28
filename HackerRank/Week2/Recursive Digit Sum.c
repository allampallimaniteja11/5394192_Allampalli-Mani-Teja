#include <stdio.h>
#include <string.h>

int superDigit(char s[], long long k){
    long long sum=0;
    for(int i=0;i<strlen(s);i++) sum+=s[i]-'0';
    sum*=k;
    while(sum>=10){
        long long tmp=0;
        while(sum){
            tmp+=sum%10;
            sum/=10;
        }
        sum=tmp;
    }
    return sum;
}

int main(){
    char n[100001];
    long long k;
    scanf("%s %lld",n,&k);
    printf("%d\n",superDigit(n,k));
    return 0;
}
