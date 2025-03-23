#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//邻接表节点
typedef struct AdjList {
    int dest;
    struct AdjList* next;
} AdjList;
// 创建新的邻接表节点
AdjList* newAdjList(int dest) {
    AdjList* newNode = (AdjList*)malloc(sizeof(AdjList));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
int main(){
	int n;
	scanf("%d",&n);
	int graph[n][n];
	memset(graph,0,sizeof(graph));
	//创建邻接表
	AdjList* head = (AdjList*)malloc(sizeof(AdjList)*n);
	for(int i=0;i<n;i++){
		head[i].dest = i;
		head[i].next = NULL;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(graph[i][j]==1){
				AdjList* newnode=newAdjList(j);
				AdjList* hh=head[i].next;
				if(hh==NULL)head[i].next=newnode;
				else{
					while(hh->next)
						hh=hh->next;
					hh->next=newnode;
				}
			}
		}
	}
	for(int j=0;j<n;j++){
		printf("%d:",head[j].dest);
		AdjList* hh=head[j].next;
		while(hh){
			printf("->%d",hh->dest);
			hh=hh->next;
		}
		printf("\n");
	}
}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
////邻接表节点
//typedef struct AdjList {
//    int dest;
//    struct AdjList* next;
//} AdjList;
//// 创建新的邻接表节点
//AdjList* newAdjList(int dest) {
//    AdjList* newNode = (AdjList*)malloc(sizeof(AdjList));
//    newNode->dest = dest;
//    newNode->next = NULL;
//    return newNode;
//}
//int main(){
//	int n,e;
//	scanf("%d",&n);
//	scanf("%d",&e);
//	int graph[n][n];
//	memset(graph,0,sizeof(graph));
//	//创建邻接表
//	AdjList* head = (AdjList*)malloc(sizeof(AdjList)*n);
//	for(int i=0;i<n;i++){
//		int num;
//		scanf("%d",&num);
//		head[i].dest = num;
//		head[i].next = NULL;
//	}
//	for(int i=0;i<e;i++){
//		int a1,a2;
//		scanf("%d %d",&a1,&a2);
//		graph[a1][a2]=graph[a2][a1]=1;
//		AdjList *newnode1=newAdjList(a1);
//		AdjList *newnode2=newAdjList(a2);
//		for(int j=0;j<n;j++){
//			if(head[j].dest==a1){
//				newnode2->next=head[j].next;
//				head[j].next=newnode2;
//			}
//			if(head[j].dest==a2){
//				newnode1->next=head[j].next;
//				head[j].next=newnode1;
//			}
//		}
//	}
//	for(int j=0;j<n;j++){
//		printf("%d:",head[j].dest);
//		AdjList* hh=head[j].next;
//		while(hh){
//			printf("->%d",hh->dest);
//			hh=hh->next;
//		}
//		printf("\n");
//	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			printf("%d,",graph[i][j]);
//		}
//		printf("\n");
//	}
//}
