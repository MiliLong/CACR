#include<bits/stdc++.h>
using namespace std;

const int day = 24*60*60;    //全部转化为秒 
const int hour = 60*60;
const int minutes = 60;
 
int start() {      //出发时间 
    int a,b,c;
    scanf("%d:%d:%d",&a,&b,&c);
    int time = a*hour + b*minutes + c;
    return time;
}
 
int end() {   //到达时间 
    int a,b,c;
    scanf("%d:%d:%d",&a,&b,&c);
    int time = a*hour + b*minutes + c;
    char ch,extra_day;
    while( (ch = getchar())!='\n' && ch != '\r' ) {
        if(ch == '(') {
            getchar();  //除去"+" 
            extra_day = getchar();   //额外天数 
            time = time + (extra_day - '0')*day;
        }
    } 
    return time;
}
 
void display(int time) {    //显示时间 
    int a,b,c;
    a = time/hour;
    time = time % hour;
    b = time / minutes;
    time = time % minutes;
    c = time;
    printf("%02d:%02d:%02d\n",a,b,c);
}
 
int main() {
    int h1,m1,s1,h2,m2,s2;
    int t;
    scanf("%d",&t);
    while(t--) {
        int start1 = start();
        int end1 = end();
        int start2 = start();
        int end2 = end();
        int ans = 0;
        ans = (end1 - start1) + (end2 - start2);  //相加 
        display(ans/2);    //除2 //设,t1,t2,T1,T2;
        //s为时差，t2-(t1+s)=T2-(T1-s)=2t;相加除以二就得出t了；
    }
    return 0;
}
