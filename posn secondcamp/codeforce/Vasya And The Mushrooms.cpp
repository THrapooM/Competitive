#include <bits/stdc++.h>

using namespace std;

const int N = 300 * 1000 + 9;

int n;
int a[2][N];
long long sum123[2][N];
long long sum321[2][N];
long long sum111[2][N];

int main() {
        scanf("%d", &n);
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);


for(int i = 0; i < 2; ++i)
		for(int j = n - 1; j >= 0; --j){
			sum123[i][j] = sum123[i][j + 1] + (j + 1) * 1LL * a[i][j];
			sum321[i][j] = sum321[i][j + 1] + (n - j) * 1LL * a[i][j];
			sum111[i][j] = sum111[i][j + 1] + a[i][j];
		}
			for(int i = 0; i < 2; ++i)
		for(int j = n - 1; j >= 0; --j){
			cout << i << ' ' << j << " : ";
			cout << sum123[i][j] << "  " << sum321[i][j] << "  " << sum111[i][j] << endl;
		}
}
