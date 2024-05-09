#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int number;
    struct node* next;
}person;
person* initLink(int n)
{
    person* head = (person*)malloc(sizeof(person));
    head->number = 1;
    head->next = NULL;
    person* cyclic = head;
    for (int i = 2; i <= n; i++)
    {
        person* body = (person*)malloc(sizeof(person));
        body->number = i;
        body->next = NULL;
        cyclic->next = body;
        cyclic = cyclic->next;
    }
    cyclic->next = head;//��β����
    return head;
}
void findAndKillK(person* head, int k, int m)
{
    person* tail = head;
    //�ҵ������һ��������һ����㣬Ϊɾ��������׼��
    while (tail->next != head)
    {
        tail = tail->next;
    }
    person* p = head;
    //�ҵ����Ϊk����
    while (p->number != k)
    {
        tail = p;
        p = p->next;
    }
    //�ӱ��Ϊk���˿�ʼ��ֻ�з���p->next==pʱ��˵�������г���p��㣬���б�Ŷ������ˣ�
    while (p->next != p)
    {
        //�ҵ���p����1��ʼ����m���ˣ����һ�Ҫ֪����m-1de�˵�λ��tail��������ɾ��������
        for (int i = 1; i < m; i++)
        {
            tail = p;
            p = p->next;
        }
        tail->next = p->next;//�������Ͻ�p���ժ����
        printf("%d\t", p->number);
        free(p);
        p = tail->next;//����ʹ��pָ��ָ����б�ŵ���һ����ţ���Ϸ����
    }
    printf("%d\t", p->number);
    if (p->next == p) {
        if (p->number == 20) {
            printf("\n");
            printf("You won the geme!");
        }
        else {
            printf("\n");
            printf("You are loser!");
        }
    }
    free(p);
}
int main()
{
    int k = 1;
    int m;
    int n=20;
    printf("��Ϸ����1.������ȥ����ֵ(λ��1-20) 2.��Ҫ�ﵽ����20��ֵλ�����һλ\n");
    printf("�������ݸ�������ȥ����ֵ\n");
    person* head = initLink(n);
    scanf("%d", &m);
    findAndKillK(head, k, m);
    return 0;
}