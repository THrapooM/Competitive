#include<bits/stdc++.h>
using namespace std;
char z;
int i,k=0,N;
char x[100005];
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        stack <char> s;
        scanf("%s",x);
        N = strlen(x);
        for(i=0; i<N; i++)
        {
            s.push(x[i]);
            if(s.top()=='}')
            {
                s.pop();
                if(s.empty() || s.top()!='{')
                {
                    k = 1;
                    break;
                }
                else
                    s.pop();
            }
            else if(s.top()==']')
            {
                s.pop();
                if(s.empty() || s.top()!='[')
                {
                    k = 1;
                    break;
                }
                else
                    s.pop();

            }
            else if(s.top()==')')
            {
                s.pop();
                if(s.empty()|| s.top()!='(')
                {
                    k = 1;
                    break;
                }
                else
                    s.pop();
            }
//            else if (!s.empty()){
//                k = 1;
//                break;
//            }
        }
        if(s.empty()&&k==0)
            printf("yes\n");
        else
            printf("no\n");
        k = 0;
    }
}

