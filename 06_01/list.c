#include <stdlib.h>
#include <stdio.h>

struct _node{
    int data;
    struct _node *prev;
    struct _node *next;
}typedef node;

node* createNode()
{
    node *tmp;
    tmp = (node *)malloc(sizeof(node));

    tmp->prev = NULL;
    tmp->next = NULL;

    return tmp;
}

void destroyNodes(node *head)
{
    while(head->next != NULL)
    {
        head = head->next;
        free(head->prev);
    }
    free(head);
}

node* getNodeByIdx(node *head, int idx)
{
    node *c_node = head;

    while(idx!=0 && c_node->next)
    {
        c_node = c_node->next;
        idx--;
    }
    return c_node;
}

void push(node *head, int data)
{
    node *tmp;
    
    tmp = getNodeByIdx(head, -1);
    
    tmp->next = createNode();
    tmp->next->prev = tmp;
    tmp->data = data;
}

int pop(node *head)
{
    int data;
    node *tmp;
    tmp = getNodeByIdx(head, -1);

    data = tmp->data;
    tmp->prev->next = NULL;
    free(tmp);

    return data;
}

void insertNext(node *head, int idx, int data)
{
    node *tmp1, *tmp2;
    tmp1 = getNodeByIdx(head, idx);

    tmp2 = createNode();

    tmp1->next->prev = tmp2;
    tmp2->next = tmp1->next;

    tmp2->data = data;

    tmp1->next = tmp2;
    tmp2->prev = tmp1;
}

void removeByIdx(node *head, int idx)
{
    node *tmp;
    tmp = getNodeByIdx(head, idx);

    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;

    free(tmp);
}

int getDataByIdx(node *head, int idx)
{
    node *tmp;
    tmp = getNodeByIdx(head, idx);

    return tmp->data;
}

int getIdxByData(node *head, int data)
{
    int idx = 0;
    while(head->next != NULL)
    {
        if(head->data == data)
            return idx;
        head = head->next;
        idx++;
    }

    return -1;
}

void printNodes(node *head, char *str1, char *str2)
{
    while(head->next != NULL)
    {
        printf("%d%s", head->data, str1);
        head = head->next;
    }
    printf("%s\n", str2);
}