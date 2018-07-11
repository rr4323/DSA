#include"header.h"
typedef void(*DISPLAY)(void*);
typedef int(*COMPARE)(void*, void*);
typedef struct _employee{
	char name[32];
	unsigned char age;
} Employee;
typedef struct _node {
	void *data;
	struct _node *next;
} Node;
typedef struct _linkedList {
	Node *head;
	Node *tail;
	Node *current;
} LinkedList;
void initializeList(LinkedList *list) {
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}
void addHead(LinkedList *list, void* data) {
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = data;
	if (list->head == NULL) {
		list->tail = node;
		node->next = NULL;
	}
       	else {
		node->next = list->head;
	}
	list->head = node;
}
void addTail(LinkedList *list, void* data) {
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (list->head == NULL) {
		list->head = node;
	} else {
		list->tail->next = node;
	}
	list->tail = node;
}
int compareEmployee(Employee *e1, Employee *e2) {
	return strcmp(e1->name, e2->name);
}
Node *getNode(LinkedList *list, COMPARE compare , void* data) {
	Node *node = list->head;
	while (node != NULL) {
		if (compare(node->data, data) == 0) {
			return node;
		}
		node = node->next;
	}
	return NULL;
}
void delete(LinkedList *list, Node *node) {
	if (node == list->head) {
		if (list->head->next == NULL) {
			list->head = list->tail = NULL;
		} else {
			list->head = list->head->next;
		}
	} else {
		Node *tmp = list->head;
		while (tmp != NULL && tmp->next != node) {
			tmp = tmp->next;
		}
		if (tmp != NULL) {
			tmp->next = node->next;
		}
		}
	free(node);
}
void displayEmployee(Employee* employee) {
	printf("%s\t%d\n", employee->name, employee->age);
}
void displayLinkedList(LinkedList *list, DISPLAY display) {
	printf("\nLinked List\n");
	Node *current = list->head;
	while (current != NULL) {
		display(current->data);
		current = current->next;
	}
}
void main(int argc,char** argv)
{
	LinkedList linkedList;
	Employee *samuel = (Employee*) malloc(sizeof(Employee));
	strcpy(samuel->name, "Samuel");
	samuel->age = 32;
	Employee *sally = (Employee*) malloc(sizeof(Employee));
	strcpy(sally->name, "Sally");
	sally->age = 28;
	Employee *susan = (Employee*) malloc(sizeof(Employee));
	strcpy(susan->name, "Susan");
	susan->age = 45;
	initializeList(&linkedList);
	addHead(&linkedList, samuel);
	addHead(&linkedList, sally);
	addHead(&linkedList, susan);
	addTail(&linkedList, susan);
	addTail(&linkedList, sally);
	addTail(&linkedList, samuel);
	Node *node = getNode(&linkedList,(int (*)(void*, void*))compareEmployee, sally);
	delete(&linkedList, node);
	displayLinkedList(&linkedList, (DISPLAY)displayEmployee);
}
