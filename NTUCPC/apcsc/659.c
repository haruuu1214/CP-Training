#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int cnt = 0;
        char str[20005];
        scanf("%s", &str);
        int sz = strlen(str);
        bool fg = false;
        for (int i = 0; i < sz; i++) {
            char cur = str[i];
            if (cur == '(')
                cnt += 1;
            else {
                if (cnt <= 0) {
                    fg = true;
                    printf("N\n");
                    break;
                }
                cnt -= 1;
            }
        }
        if (! fg) {
            if (cnt == 0)
                printf("Y\n");
            else
                printf("N\n");
        }
    }
}