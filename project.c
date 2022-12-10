//��� �ʺ��ڸ� ���� ����� ����
//���� �̿��Ͽ� ���ڿ� ��

/*
{����
string_comparison �Լ� ���� �˻�� pop�Լ� �۵��� �ȵǴ� ���� ����
line_length �Լ� ���ڿ� ���� ���ϱ� ���ڿ� ���� �ٸ� ����
���� �����ö� �ѱ۱��� ���� ����
}
{���
12.10 �˻� ��� ����(�� ���� ����X)
12.10 �˻��� ȭ�� ���̱�
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define STACK_SIZE 100
#define SEARCH_SIZE 100


typedef struct{//���ں� ����ü ���۱�
    int top;
    char data[100];
    char data2[100];
}Stack;
Stack s;

//�� ���� ����{
char temp;
char temp2;
//}

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

    printf("value:%s %s", line, searchvalue);
    printf("length: %d %d\n",line_length(line), strlen(searchvalue));

    if(line_length(line) == strlen(searchvalue)){//���̰� ���� ��� ������ �˻�
        initStack();//���� ����� �ʱ�ȭ �ϱ�
        printf("����\n"); //���� �������� ���
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
        return 1;//������ 1�� ��ȯ�Ѵ�
    }
    //printf("%s", searchvalue);
    printf("\n\n");
    return 0;//���ڿ� ���̰� �ٸ� ��� 0�� ��ȯ
}
int main(){
    char searchvalue[100];// �˻��� ���� ����
    char line[100];//�ٺ��� �д� ���� �����ϴ� ����

    FILE* fp = fopen("test.txt","r");//txt ���� �б�� ����

    fgets(searchvalue, SEARCH_SIZE, stdin);//�˻��� �Է�

    while(fgets(line,sizeof(line), fp) != NULL){//�ٺ��� �б�
        //printf("%s",line);
        if(string_comparison(line,searchvalue)){
            printf("����\n\n");
        }
    }

    //printf("%s",searchvalue);//�Է��� �˻��� ���

    return 0;
}
