#include<bits/stdc++.h>
using namespace std;
int dice[6] = {1,2,3,5,4,6};
string s;
int t;
int k = 0;
int x,y;
void swap(int *x,int *y){
    int t;
     t = *x;
    *x = *y;
    *y = t;
}
int main()
{
    int n;
    cin >> n;
    int i,j;

    for(i=0;i<n;i++){
        cin >> s;
        int dice[6] = {1,2,3,5,4,6};
        for(j=0;j<s.length();j++)
        {
            if(s[j]=='F')      {swap(&dice[0],&dice[1]);swap(&dice[0],&dice[3]); swap(&dice[3],&dice[5]);}
            else if(s[j]=='B') {swap(&dice[1],&dice[5]);swap(&dice[0],&dice[5]);swap(&dice[3],&dice[5]);}
            else if(s[j]=='L') {swap(&dice[0],&dice[2]);swap(&dice[0],&dice[4]);swap(&dice[4],&dice[5]);}
            else if(s[j]=='R') {swap(&dice[0],&dice[2]);swap(&dice[2],&dice[4]);swap(&dice[2],&dice[5]);}
            else if(s[j]=='C') {swap(&dice[1],&dice[4]);swap(&dice[2],&dice[3]);swap(&dice[2],&dice[4]);}
            else if(s[j]=='D') {swap(&dice[1],&dice[2]);swap(&dice[2],&dice[3]);swap(&dice[3],&dice[4]);}
        }
    printf("%d ",dice[1]);

    }
    return 0;

}
