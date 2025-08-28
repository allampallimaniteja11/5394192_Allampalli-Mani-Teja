#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesarCipher(char s[], int k){
    int n=strlen(s);
    k=k%26;
    for(int i=0;i<n;i++){
        if(isalpha(s[i])){
            char base=isupper(s[i])?'A':'a';
            s[i]=(char)((s[i]-base+k)%26+base);
        }
    }
    printf("%s",s);
}

int main(){
    int n,k;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    scanf("%d",&k);
    caesarCipher(s,k);
    return 0;
}
