//
//  custom.h
//  HanoiResolve
//
//  Created by zyq on 2018/2/9.
//  Copyright © 2018年 zyq. All rights reserved.
//

#ifndef custom_h
#define custom_h
struct SNode{//栈中的元素结点
    int data;//存放结点的信息
    char tz;//塔座的信息
    struct SNode * next;//下一个元素
};
struct sqstack{
    struct SNode * base;//在栈构造之前和销毁之后，base的值为NULL
    struct SNode * top;//栈顶指针
};
void initStack(struct sqstack * s,char tz);
void push(struct sqstack * s,int e);
int pop(struct sqstack * s);
void destory(struct sqstack * s);
int stackEmpty(struct sqstack * s);
#endif /* custom_h */

