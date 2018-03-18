#include "list_with_head.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//创建链表
void init_list(struct node **phead) {
	if (!phead) {
		fprintf(stderr, "Invalid argument in init_list\n");
		return;
	}
	struct node *head = (struct node *)malloc(sizeof(struct node));
	if (!head) {
		fprintf(stderr, "malloc error in head node allocation\n");
		return;
	}
	memset(head, 0, sizeof(struct node));
	head->data = 0;
	head->next = NULL;
	*phead = head;
	printf("init_list succeeded\n");

	return;
}

//创建节点
struct node *make_node(int data) {
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	if (!new_node) {
		fprintf(stderr, "malloc error in new node allocation\n");
		return NULL;
	}
	memset(new_node, 0, sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

//释放节点
void free_node(struct node *free_node) {
	if (!free_node) {
		fprintf(stderr, "Invalid argument in free_node\n");
		return;
	}
	free(free_node);
	return;
}

//从链表头部插入节点
int insert_from_head(struct node *head, struct node *new_node) {
	if (!head && !new_node) {
		fprintf(stderr, "Invalid arguments in insert_to_head\n");
		return -1;
	}
	new_node->next = head->next;
	head->next = new_node;

	return 0;
}

//从链表尾部插入节点
int insert_to_tail(struct node *head, struct node *new_node) {
	if (!head && !new_node) {
		fprintf(stderr, "Invalid arguments in insert_to_tail\n");
		return -1;
	}
	struct node *last_node = NULL;
	for (last_node = head; last_node->next != NULL; last_node = last_node->next);

	new_node->next = last_node->next; //new_node->next = NULL; 亦可省略此句
	last_node->next = new_node;

	return 0;
}

//查找节点
struct node *search_node(struct node *head, int data) {
	if (!head) {
		fprintf(stderr, "Invalid argument in search_node\n");
		return NULL;
	}
	struct node *p = NULL;
	for (p = head->next; p != NULL; p = p->next) {
		if (p->data == data) {
			return p;
		}
	}
	fprintf(stderr, "%d not found\n", data);
	return NULL;
}

//删除节点
void delete_node(struct node *head, struct node *pnode) {
	if (!head && !pnode) {
		fprintf(stderr, "Invalid arguments in delete_node\n");
		return;
	}
	struct node *p = NULL;
	for (p = head; p->next != NULL; p = p->next) {
		if (p->next == pnode) {
			p->next = pnode->next; //p->next = p->next->next;
			printf("%d is deleted\n", pnode->data);
			free_node(pnode);
			return;
		}
	}
}

//打印链表
void print_list_with_head(struct node *head) {
	if (!head) {
		fprintf(stderr, "Invalid argument in print_list_with_head\n");
		return;
	}
	struct node *p = NULL;
	for (p = head->next; p != NULL; p = p->next) {
		printf("%d\n", p->data);
	}
	return;
}

//销毁链表
void destroy_list_with_head(struct node **phead) {
	if (!phead) {
		fprintf(stderr, "Invalid argument in destroy_list_with_head\n");
		return;
	}
	struct node *head = (*phead)->next;
	struct node *p = NULL;
	while (head) {
		p = head;
		head = head->next;
		free_node(p);
	}
	*phead = NULL;
	printf("The list with head is freed\n");
	return;
}
