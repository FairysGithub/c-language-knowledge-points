#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1000  //������󶥵���
#define MAX_M 3000  //����������
typedef struct {
    int u, v, cost;
} Edge;
Edge edges[MAX_M];
int parent[MAX_N + 1];
int compare(const void *a, const void *b) {
    return ((Edge *)a)->cost - ((Edge *)b)->cost;
}
int find(int x) {
    if (x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
int main() {
    int N, M;
    printf("�����������Ŀ�ͺ�ѡ��·��Ŀ(�ÿո����)��\n");
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    printf("�������·��ͨ����������ı���Լ�Ԥ��ɱ�(�ÿո����)��\n");
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].cost);
    }
	//�Ա߽�������
    qsort(edges, M, sizeof(Edge), compare);
    int total_cost = 0;
    int num_edges = 0;
    for (int i = 0; i < M; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int cost = edges[i].cost;
        if (find(u) != find(v)) {
            parent[find(u)] = find(v);
            total_cost += cost;
            num_edges++;
        }
        if (num_edges == N - 1) {
            break;
        }
    }
    if (num_edges == N - 1) {
        printf("��ͳɱ�Ϊ��%d\n", total_cost);
    } else {
        printf("���ܽ���ɱ�׼��·��\n");
    }
    return 0;
}
