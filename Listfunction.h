#include "define.h"
status InitList(SqList& L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
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
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
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
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
    if(L.elem){
        L.length=0;
        return OK;
    }else{
        return INFEASIBLE;
    }
}
status ListEmpty(SqList L)
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L.elem){
        if(L.length)return FALSE;
        else return TRUE;
    }
    else return INFEASIBLE;
}
status ListLength(SqList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    if(L.elem){
        return L.length;
    }
    else return INFEASIBLE;
}
status GetElem(SqList L,int i,ElemType &e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L.elem){
        if(i<1||i>L.length)return ERROR;
        else e=L.elem[i-1];
        return OK;
    }
    else return INFEASIBLE;
}
status LocateElem(SqList L,ElemType e,int (*compare)(ElemType,ElemType))
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų����ظ���ţ����e�����ڣ�����0�������Ա�L������ʱ������INFEASIBLE����-1����
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
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L.elem){
        for(int i=0;i<L.length;i++){
            if(L.elem[i]==e){
                if(i==L.length-1||L.length<=1)return ERROR;//���Ա���̻�Ԫ��eΪ���һ��Ԫ��
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
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
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
    int begin_of_maxsub=0,end_of_maxsub=0;//���ڴ洢�����������������ʼ�±�ͽ����±�
    int begin_now=0,end_now=0;
    dp[0]=maxsum=L.elem[0];
    for(int i=0;i<L.length-1;i++){
        if(dp[i]+L.elem[i+1]<L.elem[i+1]){//��һ��Ԫ�صĴ�С����֮ǰ�����������ͣ�����begin_now,end_now
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
    /*----------��ӡ���ܽ�֧��int������------------------*/
    printf("���������ҵ��ĺ���������������Ϊ��\n");
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
/*--------------���ļ��洢���ȡ���Ա����躯��-----begin---------*/
void print_SaveAndLoadListmenu(void){
    printf("\n\n");
    printf("              Menu for Save and Load List            \n");
    printf("-----------------------------------------------------\n");
    printf("    	    0. Save to file   1. Load from file      \n");
    printf("-----------------------------------------------------\n");
    printf("��ѡ����Ĳ���[0~1]:");
    return;
}
status  SaveList(SqList L,char FileName[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
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
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
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
/*--------------���ļ��洢���ȡ���Ա����躯��------end----------*/
status SaveAndLoadList(SqList &L){
    int optionofSorL=0,opoffile=0,stateofop=0;
    char filename[30] = {"data.txt"};
    print_SaveAndLoadListmenu();
    scanf("%d",&optionofSorL);
    switch (optionofSorL) {
        case 0://Save the list
            printf("����Ҫ�����Ա�洢��Ĭ���ļ�data.txt���������ļ�[0-������data.txt/1-�����������ļ�]\n");
            scanf("%d",&opoffile);
            if(opoffile==0)stateofop= SaveList(L,filename);
            else if(opoffile==1){
                printf("���������뱣�����Ա���ļ���(û�����Զ�����)\n");
                scanf("%s",filename);
                stateofop= SaveList(L,filename);
                if(stateofop==OK)return OK;
                else if(stateofop==ERROR){
                    printf("���ļ�ʧ��\n");
                    return ERROR;
                }else if(stateofop==INFEASIBLE){
                    printf("�����Ա����ڣ�\n");
                    return ERROR;
                }
            }
            else{
                printf("�����ַ��Ƿ���\n");
                return FALSE;
            }
            break;
        case 1:
            printf("����Ҫ��Ĭ���ļ�data.txt���������ļ���ȡ���Ա�?[0-��data.txt/1-�������ļ�]\n");
            scanf("%d",&opoffile);
            if(opoffile==0)stateofop= LoadList(L,filename);
            else if(opoffile==1){
                printf("�����������ȡ���Ա���ļ���\n");
                scanf("%s",filename);
                stateofop= LoadList(L,filename);
            }
            else{
                printf("�����ַ��Ƿ���\n");
                return FALSE;
            }
            if(stateofop==OK)return OK;
            else if(stateofop==ERROR){
                printf("���ļ�ʧ��\n");
                return ERROR;
            }else if(stateofop==INFEASIBLE){
                printf("���Ա�ǿգ��޷����ļ���ȡ���ݣ������������е����Ա�\n");
                return FALSE;
            }
            break;
        default:
            printf("�����ַ��Ƿ���\n");
            return FALSE;
            break;
    }
}
/*--------------�����Ա�������躯��-----begin---------*/
void print_ListsManagemenu(void){
    printf("\n\n");
    printf("              Menu for Lists Manage                  \n");
    printf("-----------------------------------------------------\n");
    printf("    	    0. Switch List    1. Creat List          \n");
    printf("    	    2. Remove List    3. Search List         \n");
    printf("    	    4. Traverse all Lists                    \n");
    printf("-----------------------------------------------------\n");
    printf("��ѡ����Ĳ���[0~4]:");
    return;
}
status AddList(LISTS &Lists,char ListName[])
// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա����Ա������ֺ�̨���Գ�����롣
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
// Lists��ɾ��һ������ΪListName�����Ա�
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
// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
{
    for(int i=0;i<Lists.length;i++){
        if(!strcmp(Lists.elem[i].name,ListName)){
            return i+1;
        }
    }
    return ERROR;
}
void TraverseAllList(LISTS &Ls){
    printf("��� ����\n");
    for(int i=1;i<=Ls.length;i++){
        printf("%4d %s ",i,Ls.elem[i-1].name);
        for(int j=0;j<Ls.elem[i-1].L.length;j++){
            printf("%4d ",Ls.elem[i-1].L.elem[j]);
        }
        printf("\n");
    }
}
/*--------------�����Ա�������躯��-----end---------*/
void ListsManage(LISTS &Ls,SqList &L){
    int op,index,state,CreateOp;
    char temp[20];
    print_ListsManagemenu();
    scanf("%d",&op);
    switch (op) {
        case 0://�л����е�������ı�
            if(Ls.length) {
                printf("�ֹ���%d�����Ա�\n", Ls.length);
                TraverseAllList(Ls);
                printf("��ѡ����Ҫ����һ������е��������[1~%d]\n", Ls.length);
                scanf("%d", &index);
                DestroyList(L);
                L = Ls.elem[index - 1].L;
                L.elem=(ElemType*) malloc(sizeof(ElemType)*Ls.elem[index - 1].L.listsize);
                memcpy(L.elem,Ls.elem[index-1].L.elem,sizeof(ElemType)*Ls.elem[index - 1].L.length);
                printf("���Ա�ѡ�гɹ���ѡ���˵�%d����\n", index);
            }else{
                printf("��ǰ�����Ա�\n");
            }
            break;
        case 1://����һ���µ����Ա�
            printf("�������Ƿ�Ҫ���������ڲ��������Ա��룿[1-��/0-��]\n");
            scanf("%d",&CreateOp);
            if(CreateOp==1){
                if(Ls.length+1>Ls.listsize){
                    printf("�洢���Ա���࣡\n");
                }else{
                    printf("����������Ա��������\n");
                    scanf("%s",temp);
                    int index=LocateList(Ls,temp),cover;
                    if(index){
                        printf("�����������Ա��Ƿ񸲸ǣ�[1-��/0-��]\n");
                        scanf("%d",&cover);
                        if(cover==1){
                            DestroyList(Ls.elem[index-1].L);
                            Ls.elem[index-1].L=L;
                            Ls.elem[index-1].L.elem=(ElemType*) malloc(sizeof(ElemType)*L.listsize);
                            memcpy(Ls.elem[index-1].L.elem,L.elem,sizeof(ElemType)*L.length);
                            printf("���ǳɹ���\n");
                        }
                    }
                    else {
                        Ls.elem[Ls.length].L.elem = NULL;
                        Ls.elem[Ls.length].L=L;
                        Ls.elem[Ls.length].L.elem=(ElemType*) malloc(sizeof(ElemType)*L.listsize);
                        memcpy(Ls.elem[Ls.length].L.elem,L.elem,sizeof(ElemType)*L.length);
                        strcpy(Ls.elem[Ls.length++].name,temp);
                        printf("����ɹ���\n");
                    }
                }
            }else if(CreateOp==0){
                printf("�����������½����Ա�����֣�\n");
                scanf("%s",temp);
                if(LocateList(Ls,temp))printf("�����������Ա�\n");
                else {
                    state = AddList(Ls, temp);
                    if (state == OK)printf("�½����Ա�ɹ���\n");
                    else if (state == OVERFLOW)printf("�洢���Ա���࣡\n");
                }
            }else printf("�������\n");
            break;
        case 2://�Ƴ�һ�����Ա�
            printf("����������ɾ�����Ա�����֣�\n");
            scanf("%s",temp);
            state= RemoveList(Ls,temp);
            if(state==OK)printf("ɾ�����Ա�ɹ���\n");
            else if(state==ERROR)printf("δ�ҵ����Ա�\n");
            break;
        case 3://�������Ա�
            printf("����������������Ա�����֣�\n");
            scanf("%s",temp);
            state= LocateList(Ls,temp);
            if(state!=ERROR)printf("�ҵ����Ա������Ϊ%d\n",state);
            else printf("δ�ҵ����Ա�\n");
            break;
        case 4://�����������Ա�
            TraverseAllList(Ls);
            break;
    }

}
int max(ElemType a,ElemType b){
    return a>b?a:b;
}




