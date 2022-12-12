//��� �ʺ��ڸ� ���� ����� ����
//���� �̿��Ͽ� ���ڿ� ��

/*
{����
string_comparison �Լ� ���� �˻�� pop�Լ� �۵��� �ȵǴ� ���� ����
line_length �Լ� ���ڿ� ���� ���ϱ� ���ڿ� ���� �ٸ� ����
���� �����ö� �ѱ۱��� ���� ����
ui ũ�� �ʸ��� �ذ�
txt���� ��ġ ã�� �� ���� ����
�˻�����ȸ�� ���ĺ����� ���Ľ� �ѱ��� ���� �ذ�
}
{���
12.10 | 14:25 �˻� ��� ����(�� ���� ����X)
12.10 | 17:40 �˻��� ���� ���� ����
12.10 | 16:30 main ȭ�� ui ����
12.10 | 17:10 ��ü ���� ��ȸ ��� ����
12.10 | 17:50 ��ü �˻��� ���� ����
12.10 | 20 :00 �˻��� ���ĺ� ������ ����
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#include<string.h>

#define STACK_SIZE 100
#define SEARCH_SIZE 100


typedef struct{//���ں� ����ü ���۱�
    int top;
    char data[100];//txt ���� ������ ����
    char data2[100];//�� ���� ����
}Stack;
Stack s;

//�� ���� ����{
char temp;
char temp2;
//}

void gotoxy(int x, int y){//Ŀ�� ��ġ �̵�
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

void initStack(){//���� �ʱ�
    s.top = -1;
}

int isEmpty(){//���� ����ִ� �� �˻�
    if(s.top == -1){
        return 1;
    }
    return 0;
}

int isFull(){//������ ���� ���ִ��� �˻�
    if(s.top == STACK_SIZE-1){
        return 1;
    }
    return 0;
}

void push(char item, char item2){//���� �� �ֱ�
    if(isFull()){
        //printf("Stack is Full\n");
        return;
    }
    s.top++;
    s.data[s.top] = item;
    s.data2[s.top] = item2;
    //printf("push:%c %c\n",item, item2);
}

void pop(){ //push�� ���� �����ϰ� ���� ���ϴ� ������ ���� �����Ѵ�
	if(isEmpty()){
		printf("Stack is Empty\n");
		return ;
	}
	temp = s.data[s.top];
	temp2 = s.data2[s.top];
	s.top--;
}

int line_length(char line[100]){//����� ������ ���� ���ϱ�
    int i;
    for(i=0;line[i]!='/';i++){//for ������ ���̸� /��ġ������ ���� ����
        ;
    }
    //printf("����: %d\n",i); //���ڿ� ���� ���
    return i+1;
}

int string_comparison(char line[100], char searchvalue[100]){//���ڿ� ������ �˻� �ϴ� �Լ�

    //printf("value:%s %s", line, searchvalue);
    //printf("length: %d %d\n",line_length(line), strlen(searchvalue));

    if(line_length(line) == strlen(searchvalue)){//���̰� ���� ��� ������ �˻�
        initStack();//���� ����� �ʱ�ȭ �ϱ�
        //printf("����\n"); //���� �������� ���
        for(int i=0;i< line_length(line) -1;i++){//���� push ���ְ� ����
            push(line[i],searchvalue[i]);//line ������ searchvalue���� �ε��� ���� �ֱ�

        }
        for(int i=0;i<line_length(line)-1;i++){//���� pop�Ͽ� �����ϰ� ������ ���ϴ� ���� �ݺ���
            pop();//pop ������ temp temp2������ ����
            if(temp!=temp2){//���� ���ϰ� �ٸ���if�� ����
                //printf("�ٸ� %c %c\n",temp,temp2);//�ٸ� ���� ����Ѵ�
                return 0;//���� �ٸ� ��� 0�� ��ȯ�Ͽ� string_comparison �Լ��� ������
            }
            //printf("�� ����: %c %c\n", temp, temp2);//������ ���� �����ش�
        }
        return 1;//������ 1�� ��ȯ�Ѵ�c
    }
    //printf("%s", searchvalue);
    //printf("\n\n");
    return 0;//���ڿ� ���̰� �ٸ� ��� 0�� ��ȯ
}

void draw_main(){//û�� main ȭ�� �׸���
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);//���� �ʷϻ� ����
    printf("��������������������������������������������������������������������������\n");//�� �� �� ��
    printf("��������������������������������������������������������������������������\n");
    printf("��������������������������������������������������������������������������\n");
    printf("��������������������������������������������������������������������������\n");
    printf("��������������������������������������������������������������������������\n");
    printf("��������������������������������������������������������������������������\n");
    printf("��������������������������������������������������������������������������\n");
    printf("��������������������������������������������������������������������������\n");
    printf("��������������������������������������������������������������������������\n");
    printf("��������������������������������������������������������������������������\n");
    printf("Dev\n");
    printf("");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//�Ͼ�� ����
}

void search_main(){//�˻� ȭ�� �̵�
    while(1){
        char line[100];
        char searchvalue[100];
        int se=1;
        FILE* fp = fopen("test.txt","r");
        int i=0;//���� ���� ����

        printf("exit: 1\n");
        printf("�˻�� �Է� �ϼ���:");

        fgets(searchvalue, SEARCH_SIZE, stdin);//�˻��� �Է�

        if(searchvalue[0]=='1' && strlen(searchvalue)==2){//1�Է� �Ǿ������ if�� �۵�
            system("cls");
            break;
        }

        system("cls");

        while(fgets(line,sizeof(line), fp) != NULL){//�ٺ��� �б�
            //printf("%s",line);
            if(string_comparison(line,searchvalue)){
                //printf("����\n");
                i=1;
                int j;

                for(j=0;line[j]!='/';j++){//�ٷ� ���� txt���� ���� /���� ���� ũ�⸦ ����
                    ;
                }
                j=j+2;// //�� ���� ��������
                for(int y=0; line[j]!='\n';y=y*10){//���� ���ϱ�
                    y=y+(line[j]-'0');
                    se=y;
                    j++;
                }
            }
        }

        fclose(fp);
        if(i==0){//�˻�� ���� ��� ����
            printf("ã�� ���� �ٽ� �Է� �ϼ���\n");
        }
        else{//�˻�� ���� ��� ����
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);//���� �ʷϻ� ����
            char num1[100];
            sprintf(num1,"search/%d.txt", se);
            FILE* fp = fopen(num1,"r");
            printf("�˻� ���\n");
            printf("��������������������������������������������������������������������������\n");
            while(fgets(line,sizeof(line), fp) != NULL){
                printf("%s", line);
            }
            printf("\n��������������������������������������������������������������������������\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//�Ͼ�� ����
            i=0;
            fclose(fp);
        }
    }
}

void char_slice(char* line){//i ���� j�� �����ϴ� �Լ�
    int i;
    for(i=0;line[i]!='/';i++){
        ;
    }
    line[i]='\n';
    line[i+1]=NULL;
}

void search_inquiry(){//�˻���
    printf("��������������������������������������������������������������������������\n");
    printf("�˻��� ��ȸ\n");
    int i=0,j,n=50,k,hu;
    char temp[100];
    char line[100][100];
    FILE* fp = fopen("test.txt","r");

    while(fgets(line[i],sizeof(line[i]), fp) != NULL){//�ٺ��� �б�
        //printf("%s",line[i]);
        i++;
    }

    hu=i;

    for(i=0; i<hu-2; i++)
    {
        k=i;
        for(j=i+1; j<hu; j++)
        {
            if(line[j][0]<line[k][0])
            {
                k=j;
            }
        }
        strcpy(temp, line[i]);
        strcpy(line[i], line[k]);
        strcpy(line[k], temp);
    }

    for(i=0;i<hu; i++)
    {
        char_slice(line[i]);
        printf("%s",line[i]);
    }

    getch();
    system("cls");
}

void dictionary_all_page(){
    char searchvalue[100];
    char line[100];
    char num1[101];
    int i=0;

    while (1){
        printf("����Ű�� �Է��Ͽ� ���� ��ũ��\n");
        printf("exit: Esc\n");
        int key = getch();
        system("cls");
        if(key==72){
            i!=1?i--:i;
            sprintf(num1,"search/%d.txt",i);
            FILE* fp = fopen(num1,"r");
            while(fgets(line,100, fp)){//�ٺ��� �б�
                printf("%s",line);
            }
            printf("\n");
        }
        else if(key == 80){
            i!=11?i++:i;
            sprintf(num1,"search/%d.txt",i);
            FILE* fp = fopen(num1,"r");
            while(fgets(line,100, fp)){//�ٺ��� �б�
                printf("%s",line);
            }
            printf("\n");
        }
        else if(key == 27){
            break;
        }
    }
}
void main_center_UI(){//main ȭ��
    int a=0,b=0;
    int key;
    while(1){
        draw_main();
        if(b==0){//�˻� �ϱ� ǥ��
            gotoxy(70-2,12);
            printf(">�˻� �ϱ�");
            gotoxy(70,13);
            printf("���� ��ü ����");
            gotoxy(70,14);
            printf("�˻��� ��ȸ");
            gotoxy(70,15);
            printf("������");
        }//���� ��ü���� ǥ��
        else if(b==1){
            gotoxy(70,12);
            printf("�˻� �ϱ�");
            gotoxy(70-2,13);
            printf(">���� ��ü ����");
            gotoxy(70,14);
            printf("�˻��� ��ȸ");
            gotoxy(70,15);
            printf("������");
        }//�˻��� ��ȸ ǥ��
        else if(b==2){
            gotoxy(70,12);
            printf("�˻� �ϱ�");
            gotoxy(70,13);
            printf("���� ��ü ����");
            gotoxy(70-2,14);
            printf(">�˻��� ��ȸ");
            gotoxy(70,15);
            printf("������");
        }//������ ����
        else if(b==3){
            gotoxy(70,12);
            printf("�˻� �ϱ�");
            gotoxy(70,13);
            printf("���� ��ü ����");
            gotoxy(70,14);
            printf("�˻��� ��ȸ");
            gotoxy(70-2,15);
            printf(">������");
        }
        key = getch();
        if(key ==72){
            b!=0?b--: b;
        }
        else if(key == 80){
            b!=3?b++:b;
        }
        system("cls");
        //printf("%d",key);
        if(key==13){
            if(b==0){//�˻� ȭ�� �̵�
                search_main();
            }
            else if(b==1){
                dictionary_all_page();
            }
            else if(b==2){
                search_inquiry();
            }
            else if(b==3){
                break;
                //return;
            }
        }
    }
}

int main(){
    char searchvalue[100];// �˻��� ���� ����
    char line[100];//�ٺ��� �д� ���� �����ϴ� ����

    FILE* fp = fopen("test.txt","r");//txt ���� �б�� ����
    system("mode con cols=146 lines=30 | title �ʺ� ����ڸ� ���� ����");
    main_center_UI(line,searchvalue, fp);
    //printf("%s",searchvalue);//�Է��� �˻��� ���

    return 0;
}
