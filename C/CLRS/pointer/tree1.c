#include"header.h"
typedef void(*DISPLAY)(void*);
typedef int(*COMPARE)(void*, void*);
typedef struct _employee{
	char name[32];
	unsigned char age;
} Employee;
typedef struct _node {
	void *data;
	struct _node *left;
	struct _node *right;
} TreeNode;
int compareEmployee(Employee *e1, Employee *e2) {
	return strcmp(e1->name, e2->name);
}
void displayEmployee(Employee* employee) {
	printf("%s\t%d\n", employee->name, employee->age);
}
void insertNode(TreeNode **root, COMPARE compare, void* data) {
/*The root is passed as a pointer to a pointer to a TreeNode .
 * This is necessary because we want to modify the pointer passed
to the function, not what the pointer points to.*/
	TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	if (*root == NULL) {
		*root = node;
		return;
	}
	while (1) {
		if (compare((*root)->data, data) > 0) {
			if ((*root)->left != NULL) {
				*root = (*root)->left;
			} else {
				(*root)->left = node;
				break;
			}
			} else {
				if ((*root)->right != NULL) {
					*root = (*root)->right;
				} else {
					(*root)->right = node;
					break;
				}
			}
		}
}
void inOrder(TreeNode *root, DISPLAY display) {
	if (root != NULL) {
		inOrder(root->left, display);
		display(root->data);
		inOrder(root->right, display);
	}
}
void postOrder(TreeNode *root, DISPLAY display) {
	if (root != NULL) {
		postOrder(root->left, display);
		postOrder(root->right, display);
		display(root->data);
	}
}
void preOrder(TreeNode *root, DISPLAY display) {
	if (root != NULL) {
		display(root->data);
		preOrder(root->left, display);
		preOrder(root->right, display);
	}
}
void main(int argc,char** argv)
{
	Employee *samuel = (Employee*) malloc(sizeof(Employee));
	strcpy(samuel->name, "Samuel");
	samuel->age = 32;
	Employee *sally = (Employee*) malloc(sizeof(Employee));
	strcpy(sally->name, "Sally");
	sally->age = 28;
	Employee *susan = (Employee*) malloc(sizeof(Employee));
	strcpy(susan->name, "Susan");
	susan->age = 45;
	TreeNode *tree = NULL;

	insertNode(&tree, (COMPARE) compareEmployee, samuel);
	insertNode(&tree, (COMPARE) compareEmployee, sally);
	insertNode(&tree, (COMPARE) compareEmployee, susan);
	preOrder(tree, (DISPLAY) displayEmployee);
	inOrder(tree, (DISPLAY) displayEmployee);
	postOrder(tree, (DISPLAY) displayEmployee);

}
