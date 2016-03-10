#include <stdio.h>
#define MAX_SIZE 10
#define MIN_SIZE 0

typedef struct Stack
{

	int stack[MAX_SIZE];
	int top;

	Stack(){

		top = 0;
	}

	int push(int in){
		if (top > MAX_SIZE - 1)
			return -1;

		stack[top++] = in;
		//top++;

		return 0;
	}
	void pop(){
		int result;

		if (top < MIN_SIZE + 1)
		{
			printf("EMPTY STACK \n");
			return;
		}

		result = stack[top--];
		printf("%d \n", result);
		//stack[top] = 0;
		//top--;

		//printf("%d \n", result);
	}

};
int main(){

	int a = 0;

	/*
	init();

	for (a = 0; a < MAX_SIZE; a++)
		push(a);

	for (a = 0; a < MAX_SIZE ; a++)
		pop();

		*/

	Stack s;// 컴파일 타입의 메모리 자동으로 생성자 불러옴
	for (a = 0; a < MAX_SIZE; a++)
		s.push(a);

	for (a = 0; a < MAX_SIZE; a++)
		s.pop();

	return 0;

}