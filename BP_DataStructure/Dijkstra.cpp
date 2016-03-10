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

	//�ְ�
	heap[0] = 0;
	check[m] = heap[m];
	printf("%c / %d \n", m + 65, check[m]);
	//heap[0] = -1;
	while(1)
	{

		// pop üũ
		
		m = heap[root] % 10; // ���� �ڸ��� m �׷��� ���� �ڽ� �ֱ� �Ҷ� ���
		
		// �Ʊ� ������ �ƴҶ� ������ 
		if (check[m]  < 0){
			check[m] = heap[root] / 10;// 10 �ڸ��� ������ ���� 
			last_line = check[m];// ���� �����̶� ���Ҷ� ����� ���� ������ ���� 
			printf("%c / %d \n", m + 65, check[m]);

		}

		// �ǳ� ã�� 
		for (i = 0; i < sizeof(heap) / 4; i++){
			if (heap[i] < 0)
			{
				i--;

				// �� ������ ��Ʈ�� �ø��� 
				heap[root] = heap[i];

				//	printf("%d ��° %d�� %d�� �ø��� !\n", m, heap[m], root );

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
		//printf("���� ���� \n");

		//// ��Ʈ�� �Ʒ��� �� �ؼ� �ٲٱ� 
		// �ݺ� 
		while (1){

			// �����ʰ��� �� ������ 
			if (heap[(root * 2) + 1] > heap[(root * 2) + 2]){

				// ������ ���°Ŵϱ� �극��ũ
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
			// �������� �� ������ 
			else
			{
				// ������ ���°Ŵϱ� �극��ũ 
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


		////// �ڽ� �ֱ� 
		for (n = 0; n < MAX_SIZE; n++){
			// ������ ������ �������� 
			if (graph[m][n] < 1)
				continue;
			// �ѹ� üũ ������ �������� �ֱ� 
			if (check[n] > -1)
				continue;
			// ���ڸ� ã�� 
			while (heap[i]>-1){
				i++;
			}
			heap[i] = ((graph[m][n] + last_line ) * 10) + n;// �����Ǳ���*10 + ��� 

			while (1){
				// ����
				if (i % 2 != 0){
					if ((heap[i / 2] / 10 ) >  (heap[i]/10)){
						//printf("���� ������ : %d, %d, %d, %d\n", m / 2, m, heap[m], heap[m / 2]);
						temp = heap[i];
						heap[i] = heap[i / 2];
						heap[i / 2] = temp;
						//printf("������ : %d, %d, %d, %d\n", m / 2, m, heap[m], heap[m / 2]);

					}
					i = i / 2;
				}
				// ������
				else
				{
					if ((heap[(i / 2) - 1] / 10) > (heap[i]/10)){
						//printf("������ ������ : %d, %d, %d, %d\n", (m / 2) - 1, m, heap[m], heap[(m / 2) - 1]);
						temp = heap[i];
						heap[i] = heap[(i / 2) - 1];
						heap[(i / 2) - 1] = temp;
						//printf("������ : %d, %d, %d, %d\n", (m / 2) - 1, m, heap[m], heap[(m / 2) - 1]);

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
	// ���� 
	while (1){

		// �����ʰ��� �� ������ 
		if ((heap[(root * 2) + 1]/10) > (heap[(root * 2) + 2]/10)){
			// ������ ���°Ŵϱ� �극��ũ
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
		// �������� �� ������ 
		else
		{
			// ������ ���°Ŵϱ� �극��ũ 
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