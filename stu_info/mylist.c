//
//  mylist.c
//  学生信息管理系统
//
//  Created by 黄主江 on 2021/4/6.
//  Copyright © 2021年 黄主江. All rights reserved.
//

#include "mylist.h"
Node * CreateList(){
    Node* HeadNode=(Node*)malloc(sizeof(Node));
    HeadNode->next=NULL;
    return HeadNode;
}
//创建新节点
Node* CreateNode(student data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
//插入节点
void insertNodeByHead(Node* headNode,student data){
    Node* newNode=CreateNode(data);
    newNode->next=headNode->next;
    headNode->next=newNode;
}
//指定数据删除节点
void deleteAppoinNode(Node* headNode,char* name){
    Node* frontNode=headNode;
    Node* PosNode=frontNode->next;
    while(PosNode!=NULL&&strcmp(PosNode->data.name,name)){
        frontNode=PosNode;
        PosNode=frontNode->next;
    };
    if(PosNode==NULL){
        printf("未找到指定位置无法删除\n");
        return;
    }
    frontNode->next=PosNode->next;
    free(PosNode);
    printf("已删除指定位置\n");
}
//查找指定数值节点
Node* searchInfoByName(Node* headNode,char* name){
    Node* posNode=headNode->next;
    while(posNode!=NULL&&strcmp(posNode->data.name,name))
        posNode=posNode->next;
    if(posNode==NULL){
        printf("未找到指定数值");
        return NULL;
    }
    printf("已找到学生%s\n",posNode->data.name);
    return posNode;
}
//修改指定学生信息
void UpdateInfoByName(Node* node,student data){
    node->data=data;
}
//打印链表
void printList(Node* headNode){
    Node* pMove=headNode->next;
    printf("%s\t%s\t%s\t%s\n","姓名","年龄","性别","电话");
    while(pMove){
        printf("%s\t%d\t%s\t%s\n",pMove->data.name,pMove->data.age,pMove->data.sex,pMove->data.tel);
        pMove=pMove->next;
    }
    printf("\n");
}
//文件读操作
int readInfoFromFile(Node* headNode,char* filename){
    student data;
    
    //1.打开文件
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL){//当没有改文件，我们就直接创建文件
        fopen(filename,"w+");
        fclose(fp);
        return 1;
    }

    //2.读文件
    while(1){
        fscanf(fp,"%s\t%d\t%s\t%s\n",data.name,&data.age,data.sex,data.tel);
        insertNodeByHead(headNode, data);
        if(feof(fp))
            break;
     }
    //3.关闭文件
    fclose(fp);
    return 0;
}
//文件写操作
void writeInfoToFile(Node* headNode,char* filename){
    FILE *fp;
    fp=fopen(filename,"w");
    Node* pMove=headNode->next;
    while(pMove){
        fprintf(fp,"%s\t%d\t%s\t%s\n",pMove->data.name,pMove->data.age,pMove->data.sex,pMove->data.tel);
        pMove=pMove->next;
    }
    fclose(fp);
}
