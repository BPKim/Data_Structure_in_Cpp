/*
그래프
쾨니히스베르크의 다리문제
- 정점별로 연결된 간선의수가 모두 짝수이어야, 간선을 한 번씩만 지나서 처음 출발했던 정점으로 돌아올 수 있다.

그래프의 종류
- 무방향 그래프(undirected graph)
연결관계에 있어서 방향성이 없는 그래프
- 방향 그래프(directedgraph) 다이그래프(digraph)
간선에 방향정보가 포함된 그래프
- 완전그래프
각각의 정점에서 다른 모든 정점을 연결한 그래프
방향 그래프의 경우에는 무방향 그래프의 간선의 두배가 된다.

가중치 그래프(Weight Graph)와 부분 그래프(Sub Graph)
- 가중치(Weight Graph)
간선에 가치정보를 두어서 구성하는 그래프
이동하는데 걸리는 시간이나 두 정점사이의 거리
- 부분그래프(Sub Graph)

*/
#include <stdio.h>
#include <stdlib.h> // malloc

enum { A, B, C, D, E, F };

#define MAX_SIZE 40
#define MIN_SIZE 0

struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

struct list{

	Node * head;
	Node * cur;
	Node * tail;

	int number;
};
typedef struct list List;

struct graph{
	int numV; // 정점의 수 
	int numE; // 간선의 수

	List * adjList;
};
typedef struct graph Graph;

void ListInit(List *list);
void Insert(List * list, int data);
void PrintList(List *list);

void GraphInit(Graph * gp);
void AddEdge(Graph *gp, int from, int to);
void ShowGraph(Graph *gp);

void GraphInit(Graph * gp, int num){

	int i;

	gp->numV = num;
	gp->numE = 0;

	gp->adjList = (List*)malloc(sizeof(List)*num); // 정점의 개수만큼 리스트 생성 

	for (i = 0; i < num; i++){
		ListInit(&(gp->adjList[i]));

	}
}
void AddEdge(Graph *gp, int from, int to){

	Insert(&gp->adjList[from], to);

	gp->numE++;

}
void ShowGraph(Graph *gp)
{
	int i;
	Node *temp;
	for (i = 0; i < gp->numV; i++){
		printf("정점 %c의 간선 \n", i + 65);

		PrintList(&gp->adjList[i]);

	}
}
void ListInit(List *list){

	list->head = (Node*)malloc(sizeof(Node));
	list->cur = (Node*)malloc(sizeof(Node));
	list->tail = (Node*)malloc(sizeof(Node));


	list->head->next = NULL;
	list->cur->next = NULL;
	list->tail->next = NULL;

	list->head->data = 0;
	list->cur->data = 0;
	list->tail->data = 0;

	list->number = 0;

}

void Insert(List * list, int data){ // 노드생성함수시작

	Node *temp = (Node*)malloc(sizeof(Node));

	temp->data = data;
	temp->next = NULL;

	// 맨처음아닐때
	if (list->head->next != NULL){

		list->cur->next = list->head->next;

		while (list->cur->next->next != NULL){
			list->cur->next = list->cur->next->next;
		}

		list->cur->next->next = temp;
		list->tail->next = temp;
	}
	// 맨처음일때 
	else{

		list->head->next = temp;
		list->cur->next = temp;
		list->tail->next = temp;
	}

	list->number++;

}

void PrintList(List *list){

	int i = 0;

	list->head = list->head->next;// 맨앞은 헤더니까 패스 

	while (i < list->number){

		printf(" %c ", list->head->data + 65);
		list->head = list->head->next;

		i++;
	}

	printf("\n");
}

int main(){

	Graph gp;
	GraphInit(&gp, 6);

	AddEdge(&gp, A, B);
	AddEdge(&gp, A, C);
	AddEdge(&gp, A, D);
	AddEdge(&gp, B, C);

	ShowGraph(&gp);

	List list;
	
	return 0;

}