#include<bits/stdc++.h>
using namespace std;
int X,Y;
char a[1005][1005];
int main(){
    cin >> X >> Y;
    int i,j;
    for(i=0;i<X;i++)
    {
        for(j=0;j<Y;j++){
            scanf(" %c",&a[i][j]);
        }
    }
    for(i=0;i<X;i++){
        for(j=0;j<Y;j++){
            if(a[i][j]=='+'){
                if(a[i+1][j]!='x'&&i+1<X) a[i+1][j]='.';
                else if(a[i-1][j]!='x'&&i-1>=0) a[i-1][j]='.';
                else if(a[i][j-1]!='x'&&j-1>=0) a[i][j-1]='.';
                else if(a[i][j+1]!='x'&&j+1<Y) a[i][j+1]='.';
                a[i][j]='.';
            }
            else if(a[i][j]=='x'){
                if(a[i+1][j-1]!='+'&&i+1<X&&j-1>=0) a[i+1][j-1]='.';
               else if(a[i+1][j+1]!='+'&&i+1<X&&j+1<Y) a[i+1][j+1]='.';
                else if(a[i-1][j-1]!='+'&&i-1>=0&&j-1>=0) a[i-1][j-1]='.';
                else if(a[i-1][j+1]!='+'&&i-1>=0&&j+1<Y) a[i-1][j+1]='.';
                else if(a[i+2][j+2]!='+'&&i+2<X&&j+2<Y) a[i+2][j-2]='.';
                    else if(a[i+2][j-2]!='+'&&i+2<X&&j-2>=0)a[i+2][j+2]='.';
                    else if(a[i-2][j-2]!='+'&&i-2>=0&&j-2>=0)a[i-2][j-2]='.';
                    else if(a[i-2][j+2]!='+'&&i-2>=0&&j+2<Y)a[i-2][j+2]='.';
                a[i][j]='.';
            }
        }
    }
    int cnt=0;
    for(i=0;i<X;i++){
        for(j=0;j<Y;j++){
            if(a[i][j]=='A') cnt++;
        }
    }
    printf("%d\n",cnt);
    for(i=0;i<X;i++){
        for(j=0;j<Y;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
