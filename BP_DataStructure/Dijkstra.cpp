#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 7
enum { A, B, C, D, E, F };

void dijkstra(int graph[7][7])
{
	int check[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int heap[20] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int temp = 0;
	int i = 0;
	int row = 0, col = 0;

	heap[0] = graph[0][0];

	check[0] = heap[0];

	printf("%c", 0);


}

void showheap(int heap[]){

	int i = 0;
	for (i = 0; i < 10; i++){
		//if (heap[i]>-1)
			printf("%d ", heap[i]); 
	}
	printf("\n");

	printf("==aa=========================================== \n");
}


int main()
{

	int graph[7][7] = { { 0, 5, 1, 0, 0, 0, 0 },
						{ 5, 0, 0, 1, 0, 3, 3 },
						{ 1, 0, 0, 2, 0, 0, 0 },
						{ 0, 1, 2, 0, 5, 0, 0 },
						{ 0, 0, 0, 5, 0, 0, 0 },
						{ 0, 3, 0, 3, 0, 0, 2 },
						{ 0, 3, 0, 0, 0, 2, 0 } };

	int check[7] = { -1, -1, -1, -1, -1, -1, -1};
	int heap[20] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int root = 0;
	int i = 0;
	int m = 0, n = 0;
	int last_line=0;
	int temp = 0;

	//넣고
	heap[0] = 0;
	check[m] = heap[m];
	printf("%c / %d \n", m + 65, check[m]);
	//heap[0] = -1;
	while(1)
	{

		// pop 체크
		
		m = heap[root] % 10; // 일의 자리가 m 그래서 다음 자식 넣기 할때 사용
		
		// 아까 꺼낸거 아닐때 꺼내기 
		if (check[m]  < 0){
			check[m] = heap[root] / 10;// 10 자리가 간선의 길이 
			last_line = check[m];// 다음 간선이랑 더할때 사용할 현재 간선의 길이 
			printf("%c / %d \n", m + 65, check[m]);

		}

		// 맨끝 찾기 
		for (i = 0; i < sizeof(heap) / 4; i++){
			if (heap[i] < 0)
			{
				i--;

				// 맨 끝에거 루트로 올리기 
				heap[root] = heap[i];

				//	printf("%d 번째 %d를 %d로 올리고 !\n", m, heap[m], root );

				heap[i] = -1;


				break;
			}
		}
	

		/*
		for (i = 0; i < 20; i++){
			if (heap[i] >-1)
				printf("%d ", heap[i]);
		}
		printf("\n");
		*/
		//printf("정렬 시작 \n");

		//// 루트랑 아래랑 비교 해서 바꾸기 
		// 반복 
		while (1){

			// 오른쪽것이 더 작을때 
			if (heap[(root * 2) + 1] > heap[(root * 2) + 2]){

				// 음수면 없는거니까 브레이크
				if (heap[(root * 2) + 2] < 0)
					break;

				if (heap[root] > heap[(root * 2) + 2])
				{
					temp = heap[(root * 2) + 2];
					heap[(root * 2) + 2] = heap[root];
					heap[root] = temp;
				}

				root = (root * 2) + 2;
			}
			// 왼쪽쪽이 더 작을때 
			else
			{
				// 음수면 없는거니까 브레이크 
				if ((heap[(root * 2) + 1]) < 0)
					break;


				if (heap[root] > heap[(root * 2) + 1])
				{
					temp = heap[(root * 2) + 1];
					heap[(root * 2) + 1] = heap[root];
					heap[root] = temp;

				}

				root = (root * 2) + 1;
			}
		}


		////// 자식 넣기 
		for (n = 0; n < MAX_SIZE; n++){
			// 간선이 없을때 다음으로 
			if (graph[m][n] < 1)
				continue;
			// 한번 체크 했을때 다음간선 넣기 
			if (check[n] > -1)
				continue;
			// 빈자리 찾기 
			while (heap[i]>-1){
				i++;
			}
			heap[i] = ((graph[m][n] + last_line ) * 10) + n;// 간선의길이*10 + 노드 

			while (1){
				// 왼쪽
				if (i % 2 != 0){
					if ((heap[i / 2] / 10 ) >  (heap[i]/10)){
						//printf("왼쪽 변경전 : %d, %d, %d, %d\n", m / 2, m, heap[m], heap[m / 2]);
						temp = heap[i];
						heap[i] = heap[i / 2];
						heap[i / 2] = temp;
						//printf("변경후 : %d, %d, %d, %d\n", m / 2, m, heap[m], heap[m / 2]);

					}
					i = i / 2;
				}
				// 오른쪽
				else
				{
					if ((heap[(i / 2) - 1] / 10) > (heap[i]/10)){
						//printf("오른쪽 변경전 : %d, %d, %d, %d\n", (m / 2) - 1, m, heap[m], heap[(m / 2) - 1]);
						temp = heap[i];
						heap[i] = heap[(i / 2) - 1];
						heap[(i / 2) - 1] = temp;
						//printf("변경후 : %d, %d, %d, %d\n", (m / 2) - 1, m, heap[m], heap[(m / 2) - 1]);

					}
					i = (i / 2) - 1;

				}

				if (i < 1)
				{
					i = 0;

					break;
				}
			}
		}
	}
	/*
	// 정렬 
	while (1){

		// 오른쪽것이 더 작을때 
		if ((heap[(root * 2) + 1]/10) > (heap[(root * 2) + 2]/10)){
			// 음수면 없는거니까 브레이크
			if (heap[(root * 2) + 2] < 0)
				break;

			if ((heap[root]/10) > (heap[(root * 2) + 2]/10))
			{
				temp = heap[(root * 2) + 2];
				heap[(root * 2) + 2] = heap[root];
				heap[root] = temp;
			}

			root = (root * 2) + 2;
		}
		// 왼쪽쪽이 더 작을때 
		else
		{
			// 음수면 없는거니까 브레이크 
			if ((heap[(root * 2) + 1]) < 0)
				break;
			
			if ((heap[root]/10) > (heap[(root * 2) + 1]/10))
			{
				temp = heap[(root * 2) + 1];
				heap[(root * 2) + 1] = heap[root];
				heap[root] = temp;

			}

			root = (root * 2) + 1;
		}
	}
		

		//showheap(heap);
		*/
	
	return 0;
}