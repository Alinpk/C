/*
 1.界面
 2.数据结构设计
 3.交互
 */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "mylist.h"

//界面
void menu(void);
//交互
void KeyDown(Node* HeadNode);

char* filename="/Users/huangzhujiang/Desktop/学生信息管理系统/学生信息管理系统/学生信息管理系统/学生信息管理系统/2.txt";


int main() {
    Node* HeadNode=CreateList();
    readInfoFromFile(HeadNode, filename);
    while(1){
        menu();
        KeyDown(HeadNode);
        getchar();
        system("clear");
    }
    return 0;
}

void menu(){
    printf("----------【学生信息管理系统】--------\n");
    printf("\t\t0退出系统\n");
    printf("\t\t1录入信息\n");
    printf("\t\t2浏览信息\n");
    printf("\t\t3修改信息\n");
    printf("\t\t4删除信息\n");
    printf("\t\t5查找信息\n");
    printf("----------------------------------\n");
}

void KeyDown(Node* HeadNode){
    int choice=0;
    scanf("%d",&choice);
    student data;
    switch(choice){
        case 0:
            printf("感谢使用\n");
            writeInfoToFile(HeadNode, filename);
            getchar();
            exit(0);
            break;
        case 1:
            printf("--------------【录入信息】----------\n");
            //插入链表每次一条
            printf("请输入学生姓名，年龄，性别，电话：");
            fflush(stdin); //清空缓冲区
            scanf("%s%d%s%s",data.name,&data.age,data.sex,data.tel);
            insertNodeByHead(HeadNode,data);
            break;
        case 2:
            printf("--------------【浏览信息】----------\n");
            printList(HeadNode);
            getchar();
            break;
        case 3:
            printf("--------------【修改信息】----------\n");
            char name[20];
            printf("请输入修改的学生姓名（原来）：");
            fflush(stdin);
            scanf("%s",name);
            Node* node=searchInfoByName(HeadNode, name);
            if(node!=NULL){
                printf("请输入更新后的学生姓名，年龄，性别，电话：");
                fflush(stdin);
                scanf("%s%d%s%s",data.name,&data.age,data.sex,data.tel);
                UpdateInfoByName(node, data);
                printf("修改完成\n");
            }
            getchar();
            break;
        case 4:
            printf("--------------【删除信息】----------\n");
            printf("请输入删除的学生姓名：");
            fflush(stdin);
            scanf("%s",data.name);
            deleteAppoinNode(HeadNode, data.name);
            break;
        case 5:
            printf("--------------【查找信息】----------\n");
            printf("请输入查找学生姓名：");
            fflush(stdin);
            scanf("%s",data.name);
            if(searchInfoByName(HeadNode, data.name)!=NULL){
                data=searchInfoByName(HeadNode, data.name)->data;
                printf("%-10s%-10s%-10s%s\n","姓名","年龄","性别","电话");
                printf("%-10s%-10d%-10s%s\n",data.name,data.age,data.sex,data.tel);
            }
            getchar();
            break;
        default:
            printf("选择错误,重新输入\n");
            getchar();
            break;
    }
}
