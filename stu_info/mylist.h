#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[20];
    int age;
    char sex[5];
    char tel[20];
}student;

typedef struct Node{
    student data;
    struct Node* next;
}Node;
//初始化链表
Node * CreateList(void);
//创建新节点
Node* CreateNode(student data);
//插入节点
void insertNodeByHead(Node* headNode,student data);
//删除指定位置节点
void deleteAppoinNode(Node* headNode,char* name);
//查找指定数值节点
Node* searchInfoByName(Node* headNode,char* name);
//修改指定学生信息
void UpdateInfoByName(Node* node,student data);
//打印链表
void printList(Node* headNode);
//文件读操作
int readInfoFromFile(Node* headNode,char* filename);
//文件写操作
void writeInfoToFile(Node* headNode,char* filename);
