#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
typedef struct Lnode {       //���ݽṹ��ȡ������
    int order_num;          //ְ�����
    char name[20];          //ְ������
    int id;                 //ְ��ID
    int basic_salary;       //ְ����������
    int job_salary;        //ְ��ְ����
    int subsidy;          //ְ������
    int total_salary;       //ְ���ܹ���
    struct Lnode* next;
}Lnode, * LinkList;
void Input_Information(LinkList& L) {           //����ְ����Ϣ
    L->next = NULL;
    Lnode* p = new Lnode;
    p = L;
    int num;                                //ְ������
    int i;
    printf("����ְ������:");
    scanf("%d", &num);
    printf("�����ʽ: ���� ID�� �������� ְ���� ���� \n");
    for (i = 0; i < num; i++) {                  //��������ְ����Ϣ
        Lnode* q = new Lnode;
        printf("��%d��ְ��:", i + 1);
        q->order_num = i + 1;
        scanf("%s %d %d %d %d", &q->name, &q->id, &q->basic_salary, &q->job_salary, &q->subsidy);
        q->total_salary = q->basic_salary + q->job_salary + q->subsidy;
        q->next = p->next;
        p->next = q;
        p = q;
    }
}
void Display_Information(LinkList& L) {        //��ʾְ����Ϣ
    Lnode* p = new Lnode;
    p = L->next;
    printf("��� ���� ID�� �������� ְ���� ���� �ܹ���\n");
    while (p != NULL) {
        printf("%-6d%-5s%-5d%-9d%-8d%-6d%-6d\n", p->order_num, p->name, p->id, p->basic_salary, p->job_salary, p->subsidy, p->total_salary);
        p = p->next;
    }
}
void Delete_Information(LinkList& L) {          //ɾ��ָ��ְ����Ϣ
    int delete_id;
    int i = 1;                                //ְ�����
    printf("ɾ��ǰ��ȫ��ְ����Ϣ:\n");
    Display_Information(L);
    printf("Ҫɾ��ְ����ID��:");
    scanf("%d", &delete_id);
    Lnode* p = new Lnode;
    Lnode* q = new Lnode;
    Lnode* s = new Lnode;
    p = L;
    q = L->next;
    while (q != NULL && q->id != delete_id) {
        p = q;
        q = q->next;
    }
    if(q!=NULL){
        if (q->id == delete_id) {
        p->next = q->next;
        delete(q);
    }
    }
    else {
        printf("�����ҵ�Ա�������ڣ�\n");
        return;
    }
    printf("ɾ�����ȫ��ְ����Ϣ:\n");
    printf("��� ���� ID�� �������� ְ���� ���� �ܹ���\n");
    s = L->next;
    while (s != NULL) {
        printf("%-6d%-5s%-5d%-9d%-8d%-6d%-6d\n", i, s->name, s->id, s->basic_salary, s->job_salary, s->subsidy, s->total_salary);
        s->order_num = i;
        s = s->next;
        i++;
    }
}
void Search_Information(LinkList& L) {                //��ѯְ����Ϣ
    int search_id;                                  //����ѯ��ְ��ID��
    printf("Ҫ���ҵ�ְ����ID��:");
    scanf("%d", &search_id);
    Lnode* p = new Lnode;
    p = L->next;
    while (p != NULL && p->id != search_id) {
        p = p->next;
    }
    if(p!=NULL){
        if (p->id == search_id) {
        printf("��� ���� ID�� �������� ְ���� ���� �ܹ���\n");
        printf("%-6d%-5s%-5d%-9d%-8d%-6d%-6d\n", p->order_num, p->name, p->id, p->basic_salary, p->job_salary, p->subsidy, p->total_salary);
    }
    }
    else {
        printf("�����ҵ�Ա�������ڣ�\n");
    }
}
void Revise_Information(LinkList& L) {                 //����ְ����Ϣ
    int search_id;
    printf("Ҫ���ҵ�ְ����ID��:");
    scanf("%d", &search_id);
    Lnode* p = new Lnode;
    Lnode* q = new Lnode;
    p = L->next;
    printf("�޸�ǰ:\n");
    while (p != NULL && p->id != search_id) {
        p = p->next;
    }
    if(p!=NULL){    
        if (p->id == search_id) {
        printf("��� ���� ID�� �������� ְ���� ���� �ܹ���\n");
        printf("%-6d%-5s%-5d%-9d%-8d%-6d%-6d\n", p->order_num, p->name, p->id, p->basic_salary, p->job_salary, p->subsidy, p->total_salary);
    }
    }
    else {
        printf("�����ҵ�Ա�������ڣ�\n");
        return;
    }
    q = p;
    printf("�����޸�\n");
    printf("����: ���� ID�� �������� ְ���� ���� \n");
    scanf("%s %d %d %d %d", &q->name, &q->id, &q->basic_salary, &q->job_salary, &q->subsidy);
    q->total_salary = q->basic_salary + q->job_salary + q->subsidy;
    printf("�޸ĺ�:\n");
    Display_Information(L);
}
void Quit_Program() {                             //�˳�
    printf("��л���ʹ��!!!");
}
void Menu(){                                      //�˵�ҳ��
    printf("************* ְ�����ʹ���ϵͳ **********\n");
    printf("*            1-----������Ϣ             *\n");
    printf("*            2-----��ʾ��Ϣ             *\n");
    printf("*            3-----ɾ����Ϣ             *\n");
    printf("*            4-----�޸���Ϣ             *\n");
    printf("*            5-----������Ϣ             *\n");
    printf("*            6-----�˳�����             *\n");
    printf("*****************************************\n");
    printf("            ��������ѡ��(1-6):");
}
void Show_Menu(LinkList& L) {                     //���˵�
    int choose;
    while (1) {
        Menu();
        scanf("%d", &choose);
        switch (choose) {                           //����ѡ��ģ��
        case 1: {
            Input_Information(L);             //������Ϣ
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            Display_Information(L);           //��ʾ��Ϣ
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            Delete_Information(L);            //ɾ����Ϣ
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            Revise_Information(L);             //�޸���Ϣ
            system("pause");
            system("cls");
            break;
        }
        case 5: {
            Search_Information(L);             //������Ϣ
            system("pause");
            system("cls");
            break;
        }
        case 6: {
            Quit_Program();                    //�˳�����
            system("pause");
            exit(0);
            break;
        }
        }
    }
}
int main() {
    LinkList L = new Lnode;
    Show_Menu(L);
    return 0;
}