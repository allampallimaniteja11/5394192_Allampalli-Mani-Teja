#include <stdio.h>
#include <stdlib.h>

int isLeap(int y){
    return (y%4==0 && y%100!=0) || (y%400==0);
}

int daysInMonth(int m,int y){
    int d[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(m==2 && isLeap(y)) return 29;
    return d[m];
}

int main(){
    int d1,m1,y1,d2,m2,y2;
    scanf("%d-%d-%d %d-%d-%d",&d1,&m1,&y1,&d2,&m2,&y2);
    int cnt=0;
    for(int y=y1;y<=y2;y++){
        int startM=(y==y1)?m1:1,endM=(y==y2)?m2:12;
        for(int m=startM;m<=endM;m++){
            int startD=(y==y1 && m==m1)?d1:1;
            int endD=(y==y2 && m==m2)?d2:daysInMonth(m,y);
            for(int d=startD;d<=endD;d++){
                long long val=d*1000000LL + m*10000LL + y;
                if(val%4==0 || val%7==0) cnt++;
            }
        }
    }
    printf("%d\n",cnt); // added newline
    return 0;
}
