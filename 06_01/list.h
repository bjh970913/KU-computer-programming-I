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

    tmp->data = 0;
    tmp->prev = tmp;
    tmp->next = tmp;

    return tmp;
}

void destroyNodes(node *head)
{
    node *cur = head;
    if(head == NULL)
    {
        return;
    }
    do
    {
        cur = cur->next;
        free(cur->prev);
    }
    while(cur->next != head);
}

/**
 * 리스트 데이터 출력
 * @param head 리스트 헤드
 * @param str0 출력 포멧 스트링 (유저 입력 절대 전달 금지)
 * @param str1 구분자
 * @param str2 마지막 데이터 표시
 */
void printNodes(node *head, char *str0, char *str1, char *str2)
{
    node *cur = head;
    if(head == NULL)
    {
        return;
    }
    while(cur->next != head)
    {
        printf(str0, cur->data, str1);
        cur = cur->next;
    }
    printf(str0, cur->data, str1);
    printf("%s", str2);
}

void push(node **head, int data)
{
    if(*head == NULL)
    {
        *head = createNode();
        (*head)->data = data;
        return;
    }
    node *tmp = createNode();

    tmp->data =  data;

    tmp->next = *head;
    tmp->prev = (*head)->prev;

    (*head)->prev->next = tmp;
    (*head)->prev = tmp;

    *head = tmp;
}

int pop(node **head)
{
    int tmp;
    node *tmp1;

    if(*head == NULL)
    {
        return 0;
    }
    
    tmp1 = *head;
    tmp = tmp1->data;

    tmp1->next->prev = tmp1->prev;
    tmp1->prev->next = tmp1->next;

    if(*head == tmp1->next)
    {
        *head = NULL;
    }
    else
    {
        *head = tmp1->next;
    }

    free(tmp1);

    return tmp;
}

void prepend(node **head, int data)
{
    push(head, data);
    *head = (*head)->next;
}