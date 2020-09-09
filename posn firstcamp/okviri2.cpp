#include <bits/stdc++.h>
using namespace std;
int n;
char c[20];
void f1(){
    for (int i = 0; i <= 4*n; i++){
        if (i%4==2){
            if (i%3==1) printf("*");
            else printf("#");
        }
        else printf(".");
    }
    printf("\n");
}
void f2(){
    for (int i = 0; i <= 4*n; i++){
        if (i%2){
            if (i%12==9 || i%12==11)printf("*");
            else printf("#");
        }
        else printf(".");
    }
    printf("\n");
}
void f3(){
    int t = 0;
    for (int i = 0; i < 4*n; i++){
        if (i%4==2) printf("%c",c[t++]);
        else if (!(i%4)){
            if (i%12==8||!(i%12)&&i) printf("*");
            else printf("#");
        }
        else printf(".");
    }
    if (n%3)printf("#");
    else printf("*");
    printf("\n");
}
int main(){
    scanf("%s",c);
    n = strlen(c);
    f1();
    f2();
    f3();
    f2();
    f1();
}
