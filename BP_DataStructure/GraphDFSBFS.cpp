/*
�׷���
�����������ũ�� �ٸ�����
- �������� ����� �����Ǽ��� ��� ¦���̾��, ������ �� ������ ������ ó�� ����ߴ� �������� ���ƿ� �� �ִ�.

�׷����� ����
- ������ �׷���(undirected graph)
������迡 �־ ���⼺�� ���� �׷���
- ���� �׷���(directedgraph) ���̱׷���(digraph)
������ ���������� ���Ե� �׷���
- �����׷���
������ �������� �ٸ� ��� ������ ������ �׷���
���� �׷����� ��쿡�� ������ �׷����� ������ �ι谡 �ȴ�.

����ġ �׷���(Weight Graph)�� �κ� �׷���(Sub Graph)
- ����ġ(Weight Graph)
������ ��ġ������ �ξ �����ϴ� �׷���
�̵��ϴµ� �ɸ��� �ð��̳� �� ���������� �Ÿ�
- �κб׷���(Sub Graph)

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

	// ó�� üũ 
	check[start] = 1;
	stack.push(start);

	//printf("push - %d \n", start);

	while (true){ 
		noway = 0; 

		// ���� ������ �ְ� üũ �ƴ��� Ȯ�� 
		for (i = 0; i < 6; i++){
			// ������ ������ ���� 
			if ((gp[start][i] != 0) && (check[i] != 1))
			{
				//printf("%d -> %d \n", start, i);

				start = i;
				noway = 1;
				check[start] = 1;

				break;
			}
		}

		// ������ ��� �� ���� ������ Ǫ��
		if (noway != 0){

				stack.push(start);
				//printf("push - %d \n", start);
		}
		// ������ ��
		else{
			start = stack.pop();

			if (start < -9)
				return;

			printf("%d \n", start);
		}
	}
}

// �ִ� �Ÿ� ���Ҷ� BFS �ʺ� �켱 Ž��
void BFS(int gp[][6], int start){

	Queue queue;

	int i = 0;
	int check[6] = { 0, 0, 0, 0, 0, 0 };
	int noway = 0;

	// ó�� üũ 
	check[start] = 1;
	queue.push(start);


	while (true){
		noway = 0;

		// ���� ������ �ְ� üũ �ƴ��� Ȯ�� 
		for (i = 0; i < 6; i++){
			// ������ ������ ���� 
			if ((gp[start][i] != 0) && (check[i] != 1))
			{
				start = i;
				noway = 1;
				check[start] = 1;

				break;
			}
		}

		// ������ ������ ����� ������ Ǫ��
		if (noway != 0){
			queue.push(start);
			//printf("push - %d \n", start);
		}
		// ������ ��
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