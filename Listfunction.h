#include "define.h"
status InitList(SqList& L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    if(L.elem){
        return INFEASIBLE;
    }
    else{
        L.elem=(ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
        if(!L.elem)return OVERFLOW;
        L.listsize=LIST_INIT_SIZE;
        L.length=0;
        return OK;
    }
}
status DestroyList(SqList& L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    if(L.elem){
        free(L.elem);
        L.elem=NULL;
        return OK;
    }
    else{
        return INFEASIBLE;
    }
}
status ClearList(SqList& L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    if(L.elem){
        L.length=0;
        return OK;
    }else{
        return INFEASIBLE;
    }
}
status ListEmpty(SqList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    if(L.elem){
        if(L.length)return FALSE;
        else return TRUE;
    }
    else return INFEASIBLE;
}
status ListLength(SqList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    if(L.elem){
        return L.length;
    }
    else return INFEASIBLE;
}
status GetElem(SqList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L.elem){
        if(i<1||i>L.length)return ERROR;
        else e=L.elem[i-1];
        return OK;
    }
    else return INFEASIBLE;
}
status LocateElem(SqList L,ElemType e,int (*compare)(ElemType,ElemType))
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
{
    if(L.elem){
        for(int i=0;i<L.length;i++){
            if(compare(L.elem[i],e)){
                return i+1;
            }
        }
        return FALSE;
    }
    else return INFEASIBLE;
}
status PriorElem(SqList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L.elem){
        for(int i=0;i<L.length;i++){
            if(L.elem[i]==e){
                if(!i)return ERROR;
                else{
                    pre=L.elem[i-1];
                    return OK;
                }
            }
        }
        return ERROR;
    }
    else{
        return INFEASIBLE;
    }
}
status NextElem(SqList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L.elem){
        for(int i=0;i<L.length;i++){
            if(L.elem[i]==e){
                if(i==L.length-1||L.length<=1)return ERROR;//线性表过短或元素e为最后一个元素
                else{
                    next=L.elem[i+1];
                    return OK;
                }
            }
        }
        return ERROR;
    }
    else{
        return INFEASIBLE;
    }
}
status ListInsert(SqList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L.elem){
        if(i<=0||i>L.length+1)return ERROR;
        if(L.length+1>L.listsize){
            L.elem=(ElemType*) realloc(L.elem,sizeof(ElemType)*(L.listsize+LISTINCREMENT));
            L.listsize+=LISTINCREMENT;
        }
        for(int j=0; j < L.length - i + 1; j++){
            L.elem[L.length - j]=L.elem[L.length - j - 1];
        }
        L.elem[i-1]=e;
        L.length++;
        return OK;
    }
    else{
        return INFEASIBLE;
    }
}
status ListDelete(SqList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L.elem){
        if(i<=0||i>L.length)return ERROR;
        e=L.elem[i-1];
        for(int j=0; j < L.length - i; j++){
            L.elem[i+j-1]=L.elem[i+j];
        }
        L.length--;
        return OK;
    }
    else{
        return INFEASIBLE;
    }
}
status ListTraverse(SqList L,void (*visit)(ElemType))
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    if(L.elem){
        for(int i=0;i<L.length;i++){
            visit(L.elem[i]);
        }
        printf("\n");
        return OK;
    }
    else{
        return INFEASIBLE;
    }
}
ElemType MaxSubArray(SqList L){
    ElemType *dp=(ElemType*)malloc(sizeof(ElemType)*L.length);
    ElemType maxsum;
    int begin_of_maxsub=0,end_of_maxsub=0;//用于存储所求最大和子数组的起始下标和结束下标
    int begin_now=0,end_now=0;
    dp[0]=maxsum=L.elem[0];
    for(int i=0;i<L.length-1;i++){
        if(dp[i]+L.elem[i+1]<L.elem[i+1]){//下一个元素的大小大于之前的最大子数组和，更新begin_now,end_now
            dp[i+1]=L.elem[i+1];
            begin_now=end_now=i+1;
        }else{
            dp[i+1]=dp[i]+L.elem[i+1];
            end_now++;
        }
        if(dp[i+1]>maxsum){
            begin_of_maxsub=begin_now,end_of_maxsub=end_now;
            maxsum=dp[i+1];
        }
    }
    /*----------打印功能仅支持int型数据------------------*/
    printf("从数组中找到的和最大的连续子数组为：\n");
    for(int i=begin_of_maxsub;i<=end_of_maxsub;i++){
        printf("%d ",L.elem[i]);
    }
    printf("\n");
    /*------------------------------------------------*/
    free(dp);
    return maxsum;

}
int SubArrayNum(SqList L,ElemType k){
    ElemType *presum=(ElemType*)malloc(sizeof(ElemType)*(L.length+1));
    presum[0]=0;
    int ans=0;
    for(int i=1;i<=L.length;i++){
        presum[i]=presum[i-1]+L.elem[i-1];
    }
    for(int i=0;i<L.length;i++){
        for(int j=i+1;j<L.length+1;j++){
            if(presum[j]-presum[i]==k)ans++;
        }
    }
    return ans;
}
status SortList(SqList L){
    ElemType tmp;
    for(int i=0;i<L.length-1;i++){
        for(int j=0;j<L.length-i-1;j++){
            if(L.elem[j]>L.elem[j+1]){
                tmp=L.elem[j];
                L.elem[j]=L.elem[j+1];
                L.elem[j+1]=tmp;
            }
        }
    }
    return OK;
}
/*--------------从文件存储与读取线性表所需函数-----begin---------*/
void print_SaveAndLoadListmenu(void){
    printf("\n\n");
    printf("              Menu for Save and Load List            \n");
    printf("-----------------------------------------------------\n");
    printf("    	    0. Save to file   1. Load from file      \n");
    printf("-----------------------------------------------------\n");
    printf("请选择你的操作[0~1]:");
    return;
}
status  SaveList(SqList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    if(L.elem){
        FILE *fp;
        if((fp=fopen(FileName,"w"))!=NULL){
            for(int i=0;i<L.length;i++){
                fprintf(fp,"%d",L.elem[i]);
                if(i!=L.length-1)fprintf(fp," ");
            }
            fclose(fp);
            return OK;
        }else return ERROR;
    }
    else{
        return INFEASIBLE;
    }
}
status  LoadList(SqList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    if(!L.elem){
        FILE *fp;
        if((fp=fopen(FileName,"r"))!=NULL){
            L.elem=(ElemType*) malloc(sizeof(ElemType)*LIST_INIT_SIZE);
            L.length=0;
            L.listsize=LIST_INIT_SIZE;
            int e;
            while(fscanf(fp,"%d",&e)!=-1){
                if(L.length+1>L.listsize) {
                    L.elem=(ElemType*) realloc(L.elem,sizeof(ElemType)*(L.listsize+LISTINCREMENT));
                    L.listsize+=LISTINCREMENT;
                }
                L.elem[L.length++] = e;
            }
            fclose(fp);
            return OK;
        }else return ERROR;
    }
    else{
        return INFEASIBLE;
    }
}
/*--------------从文件存储与读取线性表所需函数------end----------*/
status SaveAndLoadList(SqList &L){
    int optionofSorL=0,opoffile=0,stateofop=0;
    char filename[30] = {"data.txt"};
    print_SaveAndLoadListmenu();
    scanf("%d",&optionofSorL);
    switch (optionofSorL) {
        case 0://Save the list
            printf("您想要将线性表存储至默认文件data.txt还是其他文件[0-储存至data.txt/1-储存至其他文件]\n");
            scanf("%d",&opoffile);
            if(opoffile==0)stateofop= SaveList(L,filename);
            else if(opoffile==1){
                printf("请输入你想保存线性表的文件名(没有则自动创建)\n");
                scanf("%s",filename);
                stateofop= SaveList(L,filename);
                if(stateofop==OK)return OK;
                else if(stateofop==ERROR){
                    printf("打开文件失败\n");
                    return ERROR;
                }else if(stateofop==INFEASIBLE){
                    printf("该线性表不存在！\n");
                    return ERROR;
                }
            }
            else{
                printf("输入字符非法！\n");
                return FALSE;
            }
            break;
        case 1:
            printf("您想要从默认文件data.txt还是其他文件读取线性表?[0-从data.txt/1-从其他文件]\n");
            scanf("%d",&opoffile);
            if(opoffile==0)stateofop= LoadList(L,filename);
            else if(opoffile==1){
                printf("请输入你想读取线性表的文件名\n");
                scanf("%s",filename);
                stateofop= LoadList(L,filename);
            }
            else{
                printf("输入字符非法！\n");
                return FALSE;
            }
            if(stateofop==OK)return OK;
            else if(stateofop==ERROR){
                printf("打开文件失败\n");
                return ERROR;
            }else if(stateofop==INFEASIBLE){
                printf("线性表非空，无法从文件读取数据，请先销毁已有的线性表！\n");
                return FALSE;
            }
            break;
        default:
            printf("输入字符非法！\n");
            return FALSE;
            break;
    }
}
/*--------------多线性表管理所需函数-----begin---------*/
void print_ListsManagemenu(void){
    printf("\n\n");
    printf("              Menu for Lists Manage                  \n");
    printf("-----------------------------------------------------\n");
    printf("    	    0. Switch List    1. Creat List          \n");
    printf("    	    2. Remove List    3. Search List         \n");
    printf("    	    4. Traverse all Lists                    \n");
    printf("-----------------------------------------------------\n");
    printf("请选择你的操作[0~4]:");
    return;
}
status AddList(LISTS &Lists,char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    if(Lists.length+1>Lists.listsize){
        return OVERFLOW;
    }
    Lists.elem[Lists.length].L.elem = NULL;
    InitList(Lists.elem[Lists.length].L);
    strcpy(Lists.elem[Lists.length++].name, ListName);
    return OK;

}
status RemoveList(LISTS &Lists,char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    for(int i=0;i<Lists.length;i++){
        if(!strcmp(Lists.elem[i].name,ListName)){
            for(int j=i;j<Lists.length;j++){
                Lists.elem[j]=Lists.elem[j+1];
            }
            Lists.length--;
            return OK;
        }
    }
    return ERROR;
}
int LocateList(LISTS Lists,char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    for(int i=0;i<Lists.length;i++){
        if(!strcmp(Lists.elem[i].name,ListName)){
            return i+1;
        }
    }
    return ERROR;
}
void TraverseAllList(LISTS &Ls){
    printf("序号 名称\n");
    for(int i=1;i<=Ls.length;i++){
        printf("%4d %s ",i,Ls.elem[i-1].name);
        for(int j=0;j<Ls.elem[i-1].L.length;j++){
            printf("%4d ",Ls.elem[i-1].L.elem[j]);
        }
        printf("\n");
    }
}
/*--------------多线性表管理所需函数-----end---------*/
void ListsManage(LISTS &Ls,SqList &L){
    int op,index,state,CreateOp;
    char temp[20];
    print_ListsManagemenu();
    scanf("%d",&op);
    switch (op) {
        case 0://切换进行单表操作的表
            if(Ls.length) {
                printf("现共有%d个线性表：\n", Ls.length);
                TraverseAllList(Ls);
                printf("请选择您要对哪一个表进行单表操作？[1~%d]\n", Ls.length);
                scanf("%d", &index);
                DestroyList(L);
                L = Ls.elem[index - 1].L;
                L.elem=(ElemType*) malloc(sizeof(ElemType)*Ls.elem[index - 1].L.listsize);
                memcpy(L.elem,Ls.elem[index-1].L.elem,sizeof(ElemType)*Ls.elem[index - 1].L.length);
                printf("线性表选中成功！选中了第%d个表\n", index);
            }else{
                printf("当前无线性表！\n");
            }
            break;
        case 1://创建一个新的线性表
            printf("请问您是否要将现在正在操作的线性表导入？[1-是/0-否]\n");
            scanf("%d",&CreateOp);
            if(CreateOp==1){
                if(Ls.length+1>Ls.listsize){
                    printf("存储线性表过多！\n");
                }else{
                    printf("请输入此线性表的命名：\n");
                    scanf("%s",temp);
                    int index=LocateList(Ls,temp),cover;
                    if(index){
                        printf("存在重名线性表！是否覆盖？[1-是/0-否]\n");
                        scanf("%d",&cover);
                        if(cover==1){
                            DestroyList(Ls.elem[index-1].L);
                            Ls.elem[index-1].L=L;
                            Ls.elem[index-1].L.elem=(ElemType*) malloc(sizeof(ElemType)*L.listsize);
                            memcpy(Ls.elem[index-1].L.elem,L.elem,sizeof(ElemType)*L.length);
                            printf("覆盖成功！\n");
                        }
                    }
                    else {
                        Ls.elem[Ls.length].L.elem = NULL;
                        Ls.elem[Ls.length].L=L;
                        Ls.elem[Ls.length].L.elem=(ElemType*) malloc(sizeof(ElemType)*L.listsize);
                        memcpy(Ls.elem[Ls.length].L.elem,L.elem,sizeof(ElemType)*L.length);
                        strcpy(Ls.elem[Ls.length++].name,temp);
                        printf("导入成功！\n");
                    }
                }
            }else if(CreateOp==0){
                printf("请输入你想新建线性表的名字：\n");
                scanf("%s",temp);
                if(LocateList(Ls,temp))printf("存在重名线性表！\n");
                else {
                    state = AddList(Ls, temp);
                    if (state == OK)printf("新建线性表成功！\n");
                    else if (state == OVERFLOW)printf("存储线性表过多！\n");
                }
            }else printf("输入错误！\n");
            break;
        case 2://移除一个线性表
            printf("请输入你想删除线性表的名字：\n");
            scanf("%s",temp);
            state= RemoveList(Ls,temp);
            if(state==OK)printf("删除线性表成功！\n");
            else if(state==ERROR)printf("未找到线性表！\n");
            break;
        case 3://查找线性表
            printf("请输入你想查找线性表的名字：\n");
            scanf("%s",temp);
            state= LocateList(Ls,temp);
            if(state!=ERROR)printf("找到线性表，其序号为%d\n",state);
            else printf("未找到线性表！\n");
            break;
        case 4://遍历所有线性表
            TraverseAllList(Ls);
            break;
    }

}
int max(ElemType a,ElemType b){
    return a>b?a:b;
}




