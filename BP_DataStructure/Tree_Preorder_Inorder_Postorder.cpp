#include <stdio.h>

void Preoeder(int tree[], int i)
{
	
	// root
	printf("%d ", tree[i]);

	if (tree[(2 * i) + 1] != -1){
		Preoeder(tree, (2 * i) + 1);
	}
	if (tree[(2 * i) + 2] != -1){
		Preoeder(tree, (2 * i) + 2);
	}
}
void Inorder(int tree[], int i)
{
	if (tree[(2 * i) + 1] != -1){
		Inorder(tree, (2 * i) + 1);
	}
	// root
	printf("%d ", tree[i]);

	if (tree[(2 * i) + 2] != -1){
		Inorder(tree, (2 * i) + 2);
	}
}
void Postorder(int tree[], int i)
{


	if (tree[(2 * i) + 1] != -1){
		Postorder(tree, (2 * i) + 1);
	}
	if (tree[(2 * i) + 2] != -1){
		Postorder(tree, (2 * i) + 2);
	}
	// root
	printf("%d ", tree[i]);

}

int main()
{
	int tree[35] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

	Preoeder(tree, 0);
	printf("\n");
	Inorder(tree, 0);
	printf("\n");
	Postorder(tree, 0);

	return 0; 
}