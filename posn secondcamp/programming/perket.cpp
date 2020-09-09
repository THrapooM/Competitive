#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int INF = 1e9;

int n;
int sour[N], bitter[N];
int picked[N];
int ans = INF;

void pick(int i)
{
    if (i <= n) {
        picked[i] = 1;
        pick(i+1);
        picked[i] = 0;
        pick(i+1);
    } else { // i == n+1
        int total_sour = 1, total_bitter = 0, count_used = 0;
        for (int j = 0; j < n; j++) {
            if (picked[j]) {
                ++count_used;
                total_sour *= sour[j];
                total_bitter += bitter[j];
            }
        }
        if (count_used != 0)
            ans = min(ans, abs(total_sour - total_bitter));
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &sour[i], &bitter[i]);
    pick(0);
    printf("%d\n", ans);

    return 0;
}
