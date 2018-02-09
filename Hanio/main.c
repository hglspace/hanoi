//
//  main.c
//  HanoiResolve
//
//  Created by hgl on 2018/2/9.
//  Copyright © 2018年 hgl. All rights reserved.
//

#include <stdio.h>
#include "custom.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    void hanoi(int n,struct sqstack * x,struct sqstack * y,struct sqstack * z);
    //把塔座x y z 当作是三个栈(先进后出,把元素按从大到小的顺序加入到栈，出栈的时候按从小到大的顺序,符合规则)
    struct sqstack * x=(struct sqstack *)malloc(sizeof(struct sqstack));
    struct sqstack * y=(struct sqstack *)malloc(sizeof(struct sqstack));
    struct sqstack * z=(struct sqstack *)malloc(sizeof(struct sqstack));
    initStack(x,'x');
    initStack(y,'y');
    initStack(z,'z');
    push(x, 3);//圆盘3
    push(x, 2);//圆盘2
    push(x, 1);//圆盘1
    printf("塔座x上的圆盘的编号从小到大是:\n");
    while(!stackEmpty(x)){
        printf("%d\t",pop(x));
    }
    //上面把x上的元素都取出来了，现在再放入一次
    push(x, 3);
    push(x, 2);
    push(x, 1);
    printf("\n\n移动的过程如下:\n");
    hanoi(3, x, y, z);
    printf("\n将圆盘移至塔座z上后，z上的元素是:\n");
    while(!stackEmpty(z)){
        printf("%d\t",pop(z));
    }
    printf("\n");
    destory(x);
    destory(y);
    destory(z);
    free(x);
    free(y);
    free(z);
    return 0;
}
void hanoi(int n,struct sqstack * x,struct sqstack * y,struct sqstack * z){
    void moveAction(struct sqstack * x,struct sqstack * y);
    if(n==1){
        moveAction(x, z);//将编号为1的圆盘从x移到z
    }else{
        hanoi(n-1, x, z, y);//将x上编号为1至n-1的圆盘移到y,z作辅助塔
        moveAction(x, z);//将编号为n的圆盘从x移至z
        hanoi(n-1, y, x, z);//将y上编号为1至n-1的圆盘移到z,x作辅助塔
    }
}

void moveAction(struct sqstack * x,struct sqstack * y){
    int i=pop(x);
    printf("从塔座%c移动元素%d到塔座%c\n",x->base->tz,i,y->base->tz);
    push(y, i);//x栈顶的元素加到y中
}

