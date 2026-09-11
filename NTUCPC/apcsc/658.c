#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const int N = 200000;
struct Stack {
    int top, sz;
    int *a;
};
struct Stack* build() {
	struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
	s->top = s->sz = 0;
	s->a = (int *)malloc(N * sizeof(int));
	return s;
}
bool is_empty(struct Stack* s) {
	return (s->sz == 0);
}
void push(struct Stack* s, int val) {
    s->a[s->top] = val;
    s->top += 1;
	s->sz += 1;
}
void pop(struct Stack* s) {
    s->top -= 1;
	s->sz -= 1;
}
int top(struct Stack* s) {
	return s->a[s->top - 1];
}
int SIZE(struct Stack* s) {
	return s->sz;
}
int main() {
	struct Stack* s;
	s = build();
	int m, op, x;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d", &x);
			push(s, x);
		} else if (op == 2) {
			if (is_empty(s))
				printf("QQ\n");
			else
				pop(s);
		} else if (op == 3) {
			if (is_empty(s))
				printf("QQ\n");
			else
				printf("%d\n", top(s));
		} else {
			printf("%d\n", SIZE(s));
		}
	}
}