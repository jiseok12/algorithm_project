//��� �ʺ��ڸ� ���� ����� ����
//���� �̿��Ͽ� ���ڿ� ��

/*
{����
string_comparison �Լ� ���� �˻�� pop�Լ� �۵��� �ȵǴ� ���� ����
line_length �Լ� ���ڿ� ���� ���ϱ� ���ڿ� ���� �ٸ� ����
���� �����ö� �ѱ۱��� ���� ����
ui ũ�� �ʸ��� �ذ�
txt���� ��ġ ã�� �� ���� ����
}
{���
12.10 �˻� ��� ����(�� ���� ����X)
12.10 �˻��� ȭ�� ���̱�
12.10 main ȭ�� ui ����
12.10 �˻��� �� ���̱�
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>

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
        for(int i=0;i<line_length(line)-1;i++){//���� push ���ְ� ����
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

        if(searchvalue[0]=='1' && strlen(searchvalue)==2){
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

                for(j=0;line[j]!='/';j++){
                    ;
                }
                j=j+2;
                for(int y=0; line[j]!='\n';y=y*10){
                    y=y+(line[j]-'0');
                    se=y;
                    j++;
                }
            }
        }

        fclose(fp);
        if(i==0){
            printf("ã�� ���� �ٽ� �Է� �ϼ���\n");
        }
        else{
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
        }
    }
}

void main_center_UI(){//main ȭ��
    int a=0,b=0;
    int key;
    while(1){
        draw_main();
        if(b==0){
            gotoxy(70-2,12);
            printf(">�̻� �Է�");
            gotoxy(70,13);
            printf("���� ��ü ����");
            gotoxy(70,14);
            printf("��ȸ");
            gotoxy(70,15);
            printf("������");
        }
        else if(b==1){
            gotoxy(70,12);
            printf("�̻� �Է�");
            gotoxy(70-2,13);
            printf(">���� ��ü ����");
            gotoxy(70,14);
            printf("��ȸ");
            gotoxy(70,15);
            printf("������");
        }
        else if(b==2){
            gotoxy(70,12);
            printf("�̻� �Է�");
            gotoxy(70,13);
            printf("���� ��ü ����");
            gotoxy(70-2,14);
            printf(">��ȸ");
            gotoxy(70,15);
            printf("������");
        }
        else if(b==3){
            gotoxy(70,12);
            printf("�̻� �Է�");
            gotoxy(70,13);
            printf("���� ��ü ����");
            gotoxy(70,14);
            printf("��ȸ");
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
        if(key==13 && b==0){//�˻� ȭ�� �̵�
            search_main();
        }
        else if(key==13 && b==1){

        }
        else if(key==13 && b==3){
            break;
            //return;
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
