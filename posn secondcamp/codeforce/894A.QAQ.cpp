// #include<bits/stdc++.h>
// using namespace std;
// string s;
// int i,j,k,ans;
// int main(){
//     cin >> s;
//     if(s.length() < 3) {printf("0"); return 0;}
//     for(i = 0 ; i < s.length()-2 ; i++){
//         for(j = i+1 ; j < s.length()-1; j++){
//             for(k = j+1 ; k < s.length() ; k++){
//                 if(s[i]=='Q' && s[j]=='A' && s[k]=='Q') ans++;
//             }
//         }       
//     }
//     printf("%d",ans);
// }
#include<bits/stdc++.h>
using namespace std;
string s;
int i,Q[105],A[105],ans;
int main(){
    cin >> s;
    if(s[0]=='Q') Q[0] = 1;
    else Q[0] = 0;
    for(i = 1 ; i < s.length() ; i++){
            A[i] = A[i-1];
            Q[i] = Q[i-1];
            if(s[i]=='Q') Q[i]++;
            if(s[i]=='A') A[i] += Q[i];
    }
    for(i = 0 ; i < s.length() ; i++){
            if(s[i]=='Q') ans += A[i];
    }
    printf("%d",ans);

}