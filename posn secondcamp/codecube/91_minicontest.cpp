#include<bits/stdc++.h>
using namespace std;
int N,i,j,check,k;
string s;
bool f;
char c[] = "BW";
struct axis{
	int x,y;
};
vector<axis>vec;
int main(){
	scanf("%d",&N);
	cin >> s;
	vec.push_back({-1,-1});
	for(i = 0 ; i < N ; i++){
		if(s[i]=='B') vec.push_back({i,0});
		else if(s[i]=='W') vec.push_back({i,1});
	}
	vec.push_back({N,-1});
	for(i = 1 ; i < vec.size() ; i++){
		if(vec[i-1].y==-1)
			for(k = vec[i].x-1,f = !vec[i].y; k >=0 ; k--,f = !f)
				s[k] = c[f];
		
		else if(vec[i].y==-1)
			for(k = vec[i-1].x+1,f = !vec[i-1].y; k < N ; k++,f = !f)
				s[k] = c[f];
		
		else{
			for(k = vec[i].x-1,f = !vec[i].y ; k > vec[i-1].x ; k--, f = !f)
				s[k] = c[f];
			if (s[k+1] == s[k]) s[k+1] = 'G';
		}
	}
	cout << s;
}