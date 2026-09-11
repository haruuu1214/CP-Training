#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int N = 100000;
struct Queue {
    int front, rear, sz;
    int a[100000];
};
struct Queue* build() {
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = q->sz = 0;
	return q;
}
bool is_empty(struct Queue* q) {
	return (q->front == q->rear); // (q->sz == 0)
}
void push(struct Queue* q, int val) {
    q->a[q->rear] = val;
    q->rear = (q->rear + 1) % N;
	q->sz += 1;
}
void pop(struct Queue* q) {
    q->front = (q->front + 1) % N;
	q->sz -= 1;
}
int front(struct Queue* q) {
	return q->a[q->front];
}
int SIZE(struct Queue* q) {
	return q->sz;
}
int main() {
	struct Queue* q;
	q = build();
	int m, op, x;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d", &x);
			push(q, x);
		} else if (op == 2) {
			if (is_empty(q))
				printf("QQ\n");
			else
				pop(q);
		} else if (op == 3) {
			if (is_empty(q))
				printf("QQ\n");
			else
				printf("%d\n", front(q));
		} else {
			printf("%d\n", SIZE(q));
		}
	}
}