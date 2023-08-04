#include <stdio.h>
int graph[25][25] = {0};
int visit[25] = {0};
int stack[25], top = -1;
void push(int k) {
    stack[++top] = k;
}
int pop() {
    return stack[top--];
}
int is_empty() {
    return top == -1 ? 1 : 0;
}
int main() {
    int n, p, a, b, h, i, j;
    printf("Enter no.of vertices and edges: ");
    scanf("%d %d", &n, &p);
    printf("Enter source and destination of the edge:\n");
    while (p--) {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    printf("Enter starting vertex index: ");
    scanf("%d", &h);
    push(h);
    visit[h] = 1;
    while (!is_empty()) {
        h = pop();
        printf("%d ", h); // Process the vertex
        for (i = 0; i < n; i++) {
            if (graph[h][i] && !visit[i]) {
                push(i);
                visit[i] = 1;
            }
        }
    }
    printf("\n");
    return 0;
}
