#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
typedef struct Lnode {       //数据结构采取单链表
    int order_num;          //职工序号
    char name[20];          //职工姓名
    int id;                 //职工ID
    int basic_salary;       //职工基本工资
    int job_salary;        //职工职务工资
    int subsidy;          //职工津贴
    int total_salary;       //职工总工资
    struct Lnode* next;
}Lnode, * LinkList;
void Input_Information(LinkList& L) {           //输入职工信息
    L->next = NULL;
    Lnode* p = new Lnode;
    p = L;
    int num;                                //职工人数
    int i;
    printf("输入职工人数:");
    scanf("%d", &num);
    printf("输入格式: 姓名 ID号 基本工资 职务工资 津贴 \n");
    for (i = 0; i < num; i++) {                  //进行输入职工信息
        Lnode* q = new Lnode;
        printf("第%d个职工:", i + 1);
        q->order_num = i + 1;
        scanf("%s %d %d %d %d", &q->name, &q->id, &q->basic_salary, &q->job_salary, &q->subsidy);
        q->total_salary = q->basic_salary + q->job_salary + q->subsidy;
        q->next = p->next;
        p->next = q;
        p = q;
    }
}
void Display_Information(LinkList& L) {        //显示职工信息
    Lnode* p = new Lnode;
    p = L->next;
    printf("序号 姓名 ID号 基本工资 职务工资 津贴 总工资\n");
    while (p != NULL) {
        printf("%-6d%-5s%-5d%-9d%-8d%-6d%-6d\n", p->order_num, p->name, p->id, p->basic_salary, p->job_salary, p->subsidy, p->total_salary);
        p = p->next;
    }
}
void Delete_Information(LinkList& L) {          //删除指定职工信息
    int delete_id;
    int i = 1;                                //职工编号
    printf("删除前的全体职工信息:\n");
    Display_Information(L);
    printf("要删除职工的ID号:");
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
        printf("所查找的员工不存在！\n");
        return;
    }
    printf("删除后的全体职工信息:\n");
    printf("序号 姓名 ID号 基本工资 职务工资 津贴 总工资\n");
    s = L->next;
    while (s != NULL) {
        printf("%-6d%-5s%-5d%-9d%-8d%-6d%-6d\n", i, s->name, s->id, s->basic_salary, s->job_salary, s->subsidy, s->total_salary);
        s->order_num = i;
        s = s->next;
        i++;
    }
}
void Search_Information(LinkList& L) {                //查询职工信息
    int search_id;                                  //被查询的职工ID号
    printf("要查找的职工的ID号:");
    scanf("%d", &search_id);
    Lnode* p = new Lnode;
    p = L->next;
    while (p != NULL && p->id != search_id) {
        p = p->next;
    }
    if(p!=NULL){
        if (p->id == search_id) {
        printf("序号 姓名 ID号 基本工资 职务工资 津贴 总工资\n");
        printf("%-6d%-5s%-5d%-9d%-8d%-6d%-6d\n", p->order_num, p->name, p->id, p->basic_salary, p->job_salary, p->subsidy, p->total_salary);
    }
    }
    else {
        printf("所查找的员工不存在！\n");
    }
}
void Revise_Information(LinkList& L) {                 //更改职工信息
    int search_id;
    printf("要查找的职工的ID号:");
    scanf("%d", &search_id);
    Lnode* p = new Lnode;
    Lnode* q = new Lnode;
    p = L->next;
    printf("修改前:\n");
    while (p != NULL && p->id != search_id) {
        p = p->next;
    }
    if(p!=NULL){    
        if (p->id == search_id) {
        printf("序号 姓名 ID号 基本工资 职务工资 津贴 总工资\n");
        printf("%-6d%-5s%-5d%-9d%-8d%-6d%-6d\n", p->order_num, p->name, p->id, p->basic_salary, p->job_salary, p->subsidy, p->total_salary);
    }
    }
    else {
        printf("所查找的员工不存在！\n");
        return;
    }
    q = p;
    printf("进行修改\n");
    printf("输入: 姓名 ID号 基本工资 职务工资 津贴 \n");
    scanf("%s %d %d %d %d", &q->name, &q->id, &q->basic_salary, &q->job_salary, &q->subsidy);
    q->total_salary = q->basic_salary + q->job_salary + q->subsidy;
    printf("修改后:\n");
    Display_Information(L);
}
void Quit_Program() {                             //退出
    printf("感谢你的使用!!!");
}
void Menu(){                                      //菜单页面
    printf("************* 职工工资管理系统 **********\n");
    printf("*            1-----输入信息             *\n");
    printf("*            2-----显示信息             *\n");
    printf("*            3-----删除信息             *\n");
    printf("*            4-----修改信息             *\n");
    printf("*            5-----查找信息             *\n");
    printf("*            6-----退出程序             *\n");
    printf("*****************************************\n");
    printf("            输入您的选择(1-6):");
}
void Show_Menu(LinkList& L) {                     //主菜单
    int choose;
    while (1) {
        Menu();
        scanf("%d", &choose);
        switch (choose) {                           //进行选择模块
        case 1: {
            Input_Information(L);             //输入信息
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            Display_Information(L);           //显示信息
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            Delete_Information(L);            //删除信息
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            Revise_Information(L);             //修改信息
            system("pause");
            system("cls");
            break;
        }
        case 5: {
            Search_Information(L);             //查找信息
            system("pause");
            system("cls");
            break;
        }
        case 6: {
            Quit_Program();                    //退出程序
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