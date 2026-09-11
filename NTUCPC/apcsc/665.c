#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct info {
	int x;
	struct info *prv, *nxt;
};
struct Deque {
	struct info *front, *rear;
	int sz;
};
struct Deque* build() {
	struct Deque* q = (struct Deque*)malloc(sizeof(struct Deque));
	q->front = q->rear = NULL;
	q->sz = 0;
	return q;
}
bool is_empty(struct Deque* q) {
	return (q->sz == 0);
}
void push_front(struct Deque* q, int val) {
	q->sz += 1;
	struct info* cur = (struct info*)malloc(sizeof(struct info));
	cur->x = val;
	cur->prv = NULL;
	cur->nxt = NULL;
	if (q->front == NULL) {
		q->front = q->rear = cur;
		return;
	}
	cur->nxt = q->front;
	q->front->prv = cur;
	q->front = cur;
}
void push_back(struct Deque* q, int val) {
	q->sz += 1;
	struct info* cur = (struct info*)malloc(sizeof(struct info));
	cur->x = val;
	cur->prv = NULL;
	cur->nxt = NULL;
	if (q->rear == NULL) {
		q->front = q->rear = cur;
		return;
	}
	cur->prv = q->rear;
	q->rear->nxt = cur;
	q->rear = cur;
}
void pop_front(struct Deque* q) {
	q->sz -= 1;
	struct info* cur = q->front;
	q->front = cur->nxt;
	if (q->front == NULL) {
		q->rear = NULL;
		return;
	}
	q->front->prv = NULL;
	free(cur);
}
void pop_back(struct Deque* q) {
	q->sz -= 1;
	struct info* cur = q->rear;
	q->rear = cur->prv;
	if (q->rear == NULL) {
		q->front = NULL;
		return;
	}
	q->rear->nxt = NULL;
	free(cur);
}
int front(struct Deque* q) {
	return q->front->x;
}
int back(struct Deque* q) {
	return q->rear->x;
}
int SIZE(struct Deque* q) {
	return q->sz;
}
int main() {
	struct Deque* q;
	q = build();
	int m, op, x;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d", &x);
			push_back(q, x);
		} else if (op == 2) {
			scanf("%d", &x);
			push_front(q, x);
		} else if (op == 3) {
			if (is_empty(q))
				printf("error\n");
			else
				printf("%d\n", back(q));
		} else if (op == 4) {
			if (is_empty(q))
				printf("error\n");
			else
				printf("%d\n", front(q));
		} else if (op == 5) {
			if (is_empty(q))
				printf("error\n");
			else
				pop_back(q);
		} else if (op == 6) {
			if (is_empty(q))
				printf("error\n");
			else
				pop_front(q);
		} else {
			printf("%d\n", SIZE(q));
		}
	}
}