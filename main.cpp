#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Listfunction.h"
void print_functionmenu(void);
int compare(ElemType a,ElemType b);//����LocateElem��Ӧ�õĺ�������ʱ����Ϊ�ж��������Ƿ����
void visit(ElemType e);//����ListTraverse��Ӧ�õĺ�������ʱ����Ϊ��ӡ����
int main(void){
    SqList L;
    L.elem=NULL;
    LISTS Ls;
    Ls.length=0;
    Ls.listsize=10;
    /*----------�����ô���--------
    printf("�����У����ύ���룡\n");
    L.elem=(ElemType*) malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    L.listsize=LIST_INIT_SIZE;
    L.elem[0]=1,L.elem[1]=2,L.elem[2]=3,L.elem[3]=4,L.elem[4]=5,L.elem[5]=6,L.elem[6]=7,L.elem[7]=8;
    L.length=8;
    ----------�����ô���--------*/
    int op=1;
    int st;
    while(op){
        system("cls");
        print_functionmenu();
        scanf("%d",&op);
        switch(op){
            case 1:
                //printf("\n----IntiList���ܴ�ʵ�֣�\n");
                st=InitList(L);
                if(st==OK) printf("���Ա����ɹ���\n");
                else if(st==INFEASIBLE)printf("���Ա��Ѿ����ڣ�\n");
                else printf("����δ֪�������Ա���ʧ�ܣ�\n");
                getchar();getchar();
                break;
            case 2:
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                st= DestroyList(L);
                if(st==OK) printf("���Ա��ѱ����٣�\n");
                else if(st==INFEASIBLE)printf("���Ա����ڣ�\n");
                else printf("����δ֪�������Ա�����ʧ�ܣ�\n");
                getchar();getchar();
                break;
            case 3:
                //printf("\n----ClearList���ܴ�ʵ�֣�\n");
                st= ClearList(L);
                if(st==OK) printf("���Ա��ѱ���գ�\n");
                else if(st==INFEASIBLE)printf("���Ա����ڣ�\n");
                else printf("����δ֪�������Ա����ʧ�ܣ�\n");
                getchar();getchar();
                break;
            case 4:
                //printf("\n----ListEmpty���ܴ�ʵ�֣�\n");
                st= ListEmpty(L);
                if(st==TRUE) printf("���Ա�Ϊ�գ�\n");
                else if(st==FALSE)printf("���Ա�Ϊ�գ�\n");
                else if(st==INFEASIBLE)printf("���Ա����ڣ�\n");
                else printf("����δ֪�����޷��ж����Ա��Ƿ�Ϊ�ձ�\n");
                getchar();getchar();
                break;
            case 5:
                //printf("\n----ListLength���ܴ�ʵ�֣�\n");
                st= ListLength(L);
                if(st>=0) printf("���Ա���Ϊ%d\n",st);
                else if(st==INFEASIBLE)printf("���Ա����ڣ�\n");
                else printf("����δ֪�������Ա��Ȼ�ȡʧ�ܣ�\n");
                getchar();getchar();
                break;
            case 6:
                //printf("\n----GetElem���ܴ�ʵ�֣�\n");
                if(ListEmpty(L))printf("���Ա�Ϊ�գ��޷���ȡԪ�أ�\n");
                else{
                    int i;
                    printf("��������Ҫ��ȡԪ�ص����i[1~%d]:", ListLength(L));
                    scanf("%d",&i);
                    ElemType e;
                    st= GetElem(L,i,e);
                    if(st==ERROR)printf("iֵ�Ƿ�\n");
                    else if(st==OK)printf("���Ϊ%d��Ԫ��Ϊ%d\n",i,e);//ע��Ŀǰ�ù��ܽ�֧��int�����ݵ����
                    else if(st==INFEASIBLE)printf("���Ա�����\n");
                    else printf("����δ֪�������Ա�Ԫ�ػ�ȡʧ�ܣ�\n");
                }
                getchar();getchar();
                break;
            case 7:
                //printf("\n----LocateElem���ܴ�ʵ�֣�\n");
                if(ListEmpty(L)==TRUE)printf("���Ա�Ϊ�գ��޷�����Ԫ�أ�\n");
                else{
                    ElemType e;
                    printf("��������Ҫ����Ԫ��e\n");
                    scanf("%d",&e);//ע���ù���Ŀǰ��֧��int�����ݵĲ���
                    st= LocateElem(L,e,compare);
                    if(st==FALSE)printf("δ���ҵ�%d\n",e);
                    else if(st>0)printf("ֵΪ%dԪ�����Ϊ%d\n",e,st);//ע��Ŀǰ�ù��ܽ�֧��int�����ݵ����
                    else if(st==INFEASIBLE)printf("���Ա�����\n");
                    else printf("����δ֪�������Ա�Ԫ�ػ�ȡʧ�ܣ�\n");
                }
                getchar();getchar();
                break;
            case 8:
                //printf("\n----PriorElem���ܴ�ʵ�֣�\n");
                if(ListEmpty(L)==TRUE)printf("���Ա�Ϊ�գ��޷�����Ԫ�أ�\n");
                else{
                    ElemType cur_e,pre_e;
                    printf("��������Ҫ����ǰ����Ԫ��cur_e\n");
                    scanf("%d",&cur_e);//ע���ù���Ŀǰ��֧��int�����ݵĲ���
                    st= PriorElem(L,cur_e,pre_e);
                    if(st==ERROR)printf("δ���ҵ�%d��ǰ��\n",cur_e);
                    else if(st==OK)printf("ֵΪ%dԪ��ǰ��Ԫ��Ϊ%d\n",cur_e,pre_e);//ע��Ŀǰ�ù��ܽ�֧��int�����ݵ����
                    else if(st==INFEASIBLE)printf("���Ա�����\n");
                    else printf("����δ֪�������Ա�ǰ��Ԫ�ػ�ȡʧ�ܣ�\n");
                }
                getchar();getchar();
                break;
            case 9:
                //printf("\n----NextElem���ܴ�ʵ�֣�\n");
                if(ListEmpty(L)==TRUE)printf("���Ա�Ϊ�գ��޷�����Ԫ�أ�\n");
                else{
                    ElemType cur_e,next_e;
                    printf("��������Ҫ���Һ�̵�Ԫ��cur_e\n");
                    scanf("%d",&cur_e);//ע���ù���Ŀǰ��֧��int�����ݵĲ���
                    st= NextElem(L,cur_e,next_e);
                    if(st==ERROR)printf("δ���ҵ�%d�ĺ��\n",cur_e);
                    else if(st==OK)printf("ֵΪ%dԪ�غ��Ԫ��Ϊ%d\n",cur_e,next_e);//ע��Ŀǰ�ù��ܽ�֧��int�����ݵ����
                    else if(st==INFEASIBLE)printf("���Ա�����\n");
                    else printf("����δ֪�������Ա���Ԫ�ػ�ȡʧ�ܣ�\n");
                }
                getchar();getchar();
                break;
            case 10:
                //printf("\n----ListInsert���ܴ�ʵ�֣�\n");
                if(ListEmpty(L)==INFEASIBLE)printf("�����Ա�����\n");
                else {
                    int i;
                    ElemType e;
                    printf("��������Ҫ��L�в���Ԫ�ص�λ��[1~%d]:", ListLength(L)+1);
                    scanf("%d",&i);
                    printf("��������Ҫ�����Ԫ��ֵ:");
                    scanf("%d",&e);//ע��Ŀǰ�ù��ܽ�֧��int�����ݵĲ���
                    st= ListInsert(L,i,e);
                    if(st==OK)printf("����ɹ�\n");
                    else if(st==ERROR)printf("����ʧ�ܣ������iֵ����\n");
                    else printf("����δ֪�������Ա����Ԫ��ʧ�ܣ�\n");
                }
                getchar();getchar();
                break;
            case 11:
                //printf("\n----ListDelete���ܴ�ʵ�֣�\n");
                if(ListEmpty(L)==INFEASIBLE)printf("�����Ա�����\n");
                else if(ListEmpty(L)==TRUE)printf("���Ա�Ϊ��!\n");
                else{
                    int i;
                    ElemType e;
                    printf("��������Ҫ��L��ɾ��Ԫ�ص�λ��[1~%d]:", ListLength(L));
                    scanf("%d",&i);
                    st= ListDelete(L,i,e);
                    if(st==OK)printf("ɾ���ɹ����ɹ�ɾ���˵�%d��Ԫ��%d\n",i,e);//ע��Ŀǰ�ù��ܽ�֧��int�����ݵ�ɾ��
                    else if(st==ERROR)printf("ɾ��ʧ�ܣ������iֵ����\n");
                    else printf("����δ֪�������Ա�ɾ��Ԫ��ʧ�ܣ�\n");
                }
                getchar();getchar();
                break;
            case 12:
                //printf("\n----ListTrabverse���ܴ�ʵ�֣�\n");
                if(ListEmpty(L)==INFEASIBLE)printf("�����Ա����ڣ�\n");
                else if(ListEmpty(L)==TRUE)printf("���Ա�Ϊ��!\n");
                else{
                    st=ListTraverse(L,visit);
                    if(st==OK)printf("���Ա�������\n");
                    else printf("����δ֪�������Ա����Ԫ��ʧ��!\n");
                }
                getchar();getchar();
                break;
            case 13:
                //printf("\n----MaxSubArray���ܴ�ʵ�֣�\n");
                if(ListEmpty(L)==INFEASIBLE)printf("�����Ա����ڣ�\n");
                else if(ListEmpty(L)==TRUE)printf("���Ա�Ϊ��!\n");
                else{
                    printf("����������Ϊ%d\n",MaxSubArray(L));
                }
                getchar();getchar();
                break;
            case 14:
                //printf("\n----SubArrayNum���ܴ�ʵ�֣�\n");
                if(ListEmpty(L)==INFEASIBLE)printf("�����Ա����ڣ�\n");
                else if(ListEmpty(L)==TRUE)printf("���Ա�Ϊ��!\n");
                else{
                    ElemType k;
                    printf("������ҪѰ�ҵ�����֮�ͣ�\n");
                    scanf("%d",&k);//ע��Ŀǰ��֧��int�����ݵĲ���
                    printf("��Ϊ%d�����������鹲��%d��\n",k,SubArrayNum(L,k));
                }
                getchar();getchar();
                break;
            case 15:
                //printf("\n----SortList���ܴ�ʵ�֣�\n");
                if(ListEmpty(L)==INFEASIBLE)printf("�����Ա����ڣ�\n");
                else if(ListEmpty(L)==TRUE)printf("���Ա�Ϊ��!\n");
                else if(SortList(L)==OK)printf("���Ա����������\n");
                else printf("����δ֪�������Ա�δ��������\n");
                getchar();getchar();
                break;
            case 16:
                //printf("\n----SaveAndLoadList���ܴ�ʵ�֣�\n");
                if(SaveAndLoadList(L)==OK)printf("����ɶ����Ա���ļ��洢���ȡ��\n");
                else printf("�����������Ա�δ���������ļ��洢���ȡ\n");
                getchar();getchar();
                break;
            case 17:
                ListsManage(Ls,L);
                getchar();getchar();
                break;
            case 0:
                break;
            default:
                printf("�������룬�����ԣ�\n");
                getchar();getchar();
                break;
        }//end of switch
    }//end of while
    printf("��ӭ�´���ʹ�ñ�ϵͳ��ϵͳ����ʮ����˳���\n");
    for(int i=0;i<10;i++){
        Sleep(1000);
        printf(".");
    }
    return 0;
}
void print_functionmenu(void){
    printf("\n\n");
//    printf("�����У����ύ���룡\n");
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
    printf("��ѡ����Ĳ���[0~17]:");
    return;
}
int compare(ElemType a,ElemType b){
    if(a==b)return TRUE;
    else return FALSE;
}
void visit(ElemType e){
    printf("%d ",e);
}
