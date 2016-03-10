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

#define NODE_NUMBER 6

#define MAX_SIZE 40
#define MIN_SIZE 0

typedef struct Queue
{
	int queue[MAX_SIZE];
	int front = 0;
	int rear = 0;

	void init(){

		front = 0;
		rear = 0;
	}

	int push(int in){
		if (rear > MAX_SIZE - 1)
		{
			//printf("FULL QUEUE \n");
			return -1;
		}

		queue[rear] = in;
		rear++;

		return 0;
	}
	int pop(){
		int result;

		if (front == rear)
		{
			printf("EMPTY QUEUE \n");
			return -10;
		}

		result = queue[front];
		queue[front] = 0;
		front++;

		//printf("%d \n", result);

		return result;
	}

}q;


typedef struct Stack
{

	int stack[MAX_SIZE];
	int top;

	Stack(){

		top = -1;
	}

	int push(int in){
		if (top > MAX_SIZE - 1)
			return -1;

		stack[++top] = in;
		//top++;

		return 0;
	}
	int pop(){
		int result;

		if (top < MIN_SIZE)
		{
			//printf("EMPTY STACK \n");
			return -10;
		}

		result = stack[top--];


		//printf("%d \n", result);
		return result;
	}

};

void DFS(int gp[][6], int start)
{
	Stack stack;
	int i=0;
	int check[6] = { 0, 0, 0, 0, 0, 0 };
	int noway = 0; 

	// 처음 체크 
	check[start] = 1;
	stack.push(start);

	//printf("push - %d \n", start);

	while (true){ 
		noway = 0; 

		// 다음 전달할 애가 체크 됐는지 확인 
		for (i = 0; i < 6; i++){
			// 다음에 전달할 아이 
			if ((gp[start][i] != 0) && (check[i] != 1))
			{
				//printf("%d -> %d \n", start, i);

				start = i;
				noway = 1;
				check[start] = 1;

				break;
			}
		}

		// 다음에 들어 갈 길이 있으면 푸시
		if (noway != 0){

				stack.push(start);
				//printf("push - %d \n", start);
		}
		// 없으면 팝
		else{
			start = stack.pop();

			if (start < -9)
				return;

			printf("%d \n", start);
		}
	}
}

// 최단 거리 구할때 BFS 너비 우선 탐색
void BFS(int gp[][6], int start){

	Queue queue;

	int i = 0;
	int check[6] = { 0, 0, 0, 0, 0, 0 };
	int noway = 0;

	// 처음 체크 
	check[start] = 1;
	queue.push(start);


	while (true){
		noway = 0;

		// 다음 전달할 애가 체크 됐는지 확인 
		for (i = 0; i < 6; i++){
			// 다음에 전달할 아이 
			if ((gp[start][i] != 0) && (check[i] != 1))
			{
				start = i;
				noway = 1;
				check[start] = 1;

				break;
			}
		}

		// 다음에 전달할 사람이 있으면 푸쉬
		if (noway != 0){
			queue.push(start);
			//printf("push - %d \n", start);
		}
		// 없으면 팝
		else{
			start = queue.pop();

			if (start < -9)
				return;

			printf("%d \n", start);
		}
	}
}

int main(){

	int graph[6][6] = {{0, 1, 0, 0, 0, 1}, 
					   {1, 0, 1, 0, 0, 0},
					   {0, 1, 0, 1, 1, 1},
					   {0, 0, 1, 0, 1, 0},
					   {0, 0, 1, 1, 0, 0},
					   {1, 0, 1, 0, 0, 0}};

	DFS(graph, A);

	return 0;


}