#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int a[10005];
int main() {
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		int ans = 0;
        int cnt[10];
        for (int i = 0; i < 10; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++) cnt[a[i]] += 1;
        int cur = 0, tar = 0;
        for (int i = 0; i < 10; i++)
            if (cnt[i] > 0)
                tar = i;
        while (true) {
            if (a[cur] == tar) {
                if (cur == m) {
                    printf("%d\n", ans + 1);
                    break;
                }
                ans += 1;
                cnt[a[cur]] -= 1;
                while (tar >= 0 && cnt[tar] == 0) tar -= 1;
                a[cur] = 10;
            }
            cur = (cur + 1) % n;
        }
    }
}