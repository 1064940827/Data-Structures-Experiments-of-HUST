#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Listfunction.h"
void print_functionmenu(void);
int compare(ElemType a,ElemType b);//函数LocateElem所应用的函数，此时作用为判断两数据是否相等
void visit(ElemType e);//函数ListTraverse所应用的函数，此时作用为打印数据
int main(void){
    SqList L;
    L.elem=NULL;
    LISTS Ls;
    Ls.length=0;
    Ls.listsize=10;
    /*----------测试用代码--------
    printf("测试中！非提交代码！\n");
    L.elem=(ElemType*) malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    L.listsize=LIST_INIT_SIZE;
    L.elem[0]=1,L.elem[1]=2,L.elem[2]=3,L.elem[3]=4,L.elem[4]=5,L.elem[5]=6,L.elem[6]=7,L.elem[7]=8;
    L.length=8;
    ----------测试用代码--------*/
    int op=1;
    int st;
    while(op){
        system("cls");
        print_functionmenu();
        scanf("%d",&op);
        switch(op){
            case 1:
                //printf("\n----IntiList功能待实现！\n");
                st=InitList(L);
                if(st==OK) printf("线性表创建成功！\n");
                else if(st==INFEASIBLE)printf("线性表已经存在！\n");
                else printf("发生未知错误，线性表创建失败！\n");
                getchar();getchar();
                break;
            case 2:
                //printf("\n----DestroyList功能待实现！\n");
                st= DestroyList(L);
                if(st==OK) printf("线性表已被销毁！\n");
                else if(st==INFEASIBLE)printf("线性表不存在！\n");
                else printf("发生未知错误，线性表销毁失败！\n");
                getchar();getchar();
                break;
            case 3:
                //printf("\n----ClearList功能待实现！\n");
                st= ClearList(L);
                if(st==OK) printf("线性表已被清空！\n");
                else if(st==INFEASIBLE)printf("线性表不存在！\n");
                else printf("发生未知错误，线性表清空失败！\n");
                getchar();getchar();
                break;
            case 4:
                //printf("\n----ListEmpty功能待实现！\n");
                st= ListEmpty(L);
                if(st==TRUE) printf("线性表为空！\n");
                else if(st==FALSE)printf("线性表不为空！\n");
                else if(st==INFEASIBLE)printf("线性表不存在！\n");
                else printf("发生未知错误，无法判断线性表是否为空表！\n");
                getchar();getchar();
                break;
            case 5:
                //printf("\n----ListLength功能待实现！\n");
                st= ListLength(L);
                if(st>=0) printf("线性表长度为%d\n",st);
                else if(st==INFEASIBLE)printf("线性表不存在！\n");
                else printf("发生未知错误，线性表长度获取失败！\n");
                getchar();getchar();
                break;
            case 6:
                //printf("\n----GetElem功能待实现！\n");
                if(ListEmpty(L))printf("线性表为空，无法获取元素！\n");
                else{
                    int i;
                    printf("请输入您要获取元素的序号i[1~%d]:", ListLength(L));
                    scanf("%d",&i);
                    ElemType e;
                    st= GetElem(L,i,e);
                    if(st==ERROR)printf("i值非法\n");
                    else if(st==OK)printf("序号为%d的元素为%d\n",i,e);//注：目前该功能仅支持int型数据的输出
                    else if(st==INFEASIBLE)printf("线性表不存在\n");
                    else printf("发生未知错误，线性表元素获取失败！\n");
                }
                getchar();getchar();
                break;
            case 7:
                //printf("\n----LocateElem功能待实现！\n");
                if(ListEmpty(L)==TRUE)printf("线性表为空，无法查找元素！\n");
                else{
                    ElemType e;
                    printf("请输入您要查找元素e\n");
                    scanf("%d",&e);//注：该功能目前仅支持int型数据的查找
                    st= LocateElem(L,e,compare);
                    if(st==FALSE)printf("未查找到%d\n",e);
                    else if(st>0)printf("值为%d元素序号为%d\n",e,st);//注：目前该功能仅支持int型数据的输出
                    else if(st==INFEASIBLE)printf("线性表不存在\n");
                    else printf("发生未知错误，线性表元素获取失败！\n");
                }
                getchar();getchar();
                break;
            case 8:
                //printf("\n----PriorElem功能待实现！\n");
                if(ListEmpty(L)==TRUE)printf("线性表为空，无法查找元素！\n");
                else{
                    ElemType cur_e,pre_e;
                    printf("请输入您要查找前驱的元素cur_e\n");
                    scanf("%d",&cur_e);//注：该功能目前仅支持int型数据的查找
                    st= PriorElem(L,cur_e,pre_e);
                    if(st==ERROR)printf("未查找到%d的前驱\n",cur_e);
                    else if(st==OK)printf("值为%d元素前驱元素为%d\n",cur_e,pre_e);//注：目前该功能仅支持int型数据的输出
                    else if(st==INFEASIBLE)printf("线性表不存在\n");
                    else printf("发生未知错误，线性表前驱元素获取失败！\n");
                }
                getchar();getchar();
                break;
            case 9:
                //printf("\n----NextElem功能待实现！\n");
                if(ListEmpty(L)==TRUE)printf("线性表为空，无法查找元素！\n");
                else{
                    ElemType cur_e,next_e;
                    printf("请输入您要查找后继的元素cur_e\n");
                    scanf("%d",&cur_e);//注：该功能目前仅支持int型数据的查找
                    st= NextElem(L,cur_e,next_e);
                    if(st==ERROR)printf("未查找到%d的后继\n",cur_e);
                    else if(st==OK)printf("值为%d元素后继元素为%d\n",cur_e,next_e);//注：目前该功能仅支持int型数据的输出
                    else if(st==INFEASIBLE)printf("线性表不存在\n");
                    else printf("发生未知错误，线性表后继元素获取失败！\n");
                }
                getchar();getchar();
                break;
            case 10:
                //printf("\n----ListInsert功能待实现！\n");
                if(ListEmpty(L)==INFEASIBLE)printf("该线性表不存在\n");
                else {
                    int i;
                    ElemType e;
                    printf("请输入你要在L中插入元素的位置[1~%d]:", ListLength(L)+1);
                    scanf("%d",&i);
                    printf("请输入你要插入的元素值:");
                    scanf("%d",&e);//注：目前该功能仅支持int型数据的插入
                    st= ListInsert(L,i,e);
                    if(st==OK)printf("插入成功\n");
                    else if(st==ERROR)printf("插入失败，输入的i值有误\n");
                    else printf("发生未知错误，线性表插入元素失败！\n");
                }
                getchar();getchar();
                break;
            case 11:
                //printf("\n----ListDelete功能待实现！\n");
                if(ListEmpty(L)==INFEASIBLE)printf("该线性表不存在\n");
                else if(ListEmpty(L)==TRUE)printf("线性表为空!\n");
                else{
                    int i;
                    ElemType e;
                    printf("请输入你要在L中删除元素的位置[1~%d]:", ListLength(L));
                    scanf("%d",&i);
                    st= ListDelete(L,i,e);
                    if(st==OK)printf("删除成功，成功删除了第%d个元素%d\n",i,e);//注：目前该功能仅支持int型数据的删除
                    else if(st==ERROR)printf("删除失败，输入的i值有误\n");
                    else printf("发生未知错误，线性表删除元素失败！\n");
                }
                getchar();getchar();
                break;
            case 12:
                //printf("\n----ListTrabverse功能待实现！\n");
                if(ListEmpty(L)==INFEASIBLE)printf("该线性表不存在！\n");
                else if(ListEmpty(L)==TRUE)printf("线性表为空!\n");
                else{
                    st=ListTraverse(L,visit);
                    if(st==OK)printf("线性表遍历完成\n");
                    else printf("发生未知错误，线性表遍历元素失败!\n");
                }
                getchar();getchar();
                break;
            case 13:
                //printf("\n----MaxSubArray功能待实现！\n");
                if(ListEmpty(L)==INFEASIBLE)printf("该线性表不存在！\n");
                else if(ListEmpty(L)==TRUE)printf("线性表为空!\n");
                else{
                    printf("子数组和最大为%d\n",MaxSubArray(L));
                }
                getchar();getchar();
                break;
            case 14:
                //printf("\n----SubArrayNum功能待实现！\n");
                if(ListEmpty(L)==INFEASIBLE)printf("该线性表不存在！\n");
                else if(ListEmpty(L)==TRUE)printf("线性表为空!\n");
                else{
                    ElemType k;
                    printf("请输入要寻找的数组之和：\n");
                    scanf("%d",&k);//注：目前仅支持int型数据的查找
                    printf("和为%d的连续子数组共有%d个\n",k,SubArrayNum(L,k));
                }
                getchar();getchar();
                break;
            case 15:
                //printf("\n----SortList功能待实现！\n");
                if(ListEmpty(L)==INFEASIBLE)printf("该线性表不存在！\n");
                else if(ListEmpty(L)==TRUE)printf("线性表为空!\n");
                else if(SortList(L)==OK)printf("线性表已完成排序！\n");
                else printf("发生未知错误，线性表未正常排序\n");
                getchar();getchar();
                break;
            case 16:
                //printf("\n----SaveAndLoadList功能待实现！\n");
                if(SaveAndLoadList(L)==OK)printf("已完成对线性表的文件存储与读取！\n");
                else printf("发生错误，线性表未正常进行文件存储与读取\n");
                getchar();getchar();
                break;
            case 17:
                ListsManage(Ls,L);
                getchar();getchar();
                break;
            case 0:
                break;
            default:
                printf("错误输入，请重试！\n");
                getchar();getchar();
                break;
        }//end of switch
    }//end of while
    printf("欢迎下次再使用本系统，系统将在十秒后退出！\n");
    for(int i=0;i<10;i++){
        Sleep(1000);
        printf(".");
    }
    return 0;
}
void print_functionmenu(void){
    printf("\n\n");
//    printf("测试中！非提交代码！\n");
    printf("      Menu for Linear Table On Sequence Structure    \n");
    printf("-----------------------------------------------------\n");
    printf("    	    1. InitList        7. LocateElem         \n");
    printf("    	    2. DestroyList     8. PriorElem          \n");
    printf("    	    3. ClearList       9. NextElem           \n");
    printf("    	    4. ListEmpty       10. ListInsert        \n");
    printf("    	    5. ListLength      11. ListDelete        \n");
    printf("    	    6. GetElem         12. ListTrabverse     \n");
    printf("    	    0. Exit                                  \n");
    printf("-----------------------------------------------------\n");
    printf("  Extra function:                                    \n");
    printf("            13. MaxSubArray    14. SubArrayNum       \n");
    printf("            15. SortList       16. SaveAndLoadList   \n");
    printf("            17. Lists Manage                         \n");
    printf("-----------------------------------------------------\n");
    printf("请选择你的操作[0~17]:");
    return;
}
int compare(ElemType a,ElemType b){
    if(a==b)return TRUE;
    else return FALSE;
}
void visit(ElemType e){
    printf("%d ",e);
}
