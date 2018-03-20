#ifndef _LIST_WITH_HEAD_
#define _LIST_WITH_HEAD_

struct node {
	int data;
	struct node *next;
};

//创建链表
void init_list(struct node **phead);

//创建节点
struct node *make_node(int data);

//释放节点
void free_node(struct node *free_node);

//从链表头部插入节点
int insert_from_head(struct node *head, struct node *new_node);

//从链表尾部插入节点
int insert_to_tail(struct node *head, struct node *new_node);

//查找节点
struct node *search_node(struct node *head, int data);

//删除节点
void delete_node(struct node *head, struct node *pnode);

//打印链表
void print_list_with_head(struct node *head);

//销毁链表
void destroy_list_with_head(struct node **phead);

//逆序链表
void reverse(struct node *head);
#endif
