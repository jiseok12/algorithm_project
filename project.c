//계발 초보자를 위한 도우미 사전
//스택 이용하여 문자열 비교

/*
{오류
string_comparison 함수 문자 검사시 pop함수 작동이 안되는 오류 수정
line_length 함수 문자열 길이 구하기 문자열 길이 다름 수정
파일 가져올때 한글깨짐 오류 수정
ui 크기 않맞음 해결
txt파일 위치 찾기 값 오류 수정
검색어 알파벳순을 정렬시 한국어 깨짐 해결
}
{기능
12.10 | 14:25 검색 기능 구현(값 보기 구현X)
12.10 | 17:40 검색한 정보 보기 구현
12.10 | 16:30 main 화면 ui 구현
12.10 | 17:10 전체 사전 조회 기능 구현
12.10 | 17:50 전체 검색어 보기 구현
12.10 | 20 :00 검색어 알파벳 순으로 구현
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#include<string.h>

#define STACK_SIZE 100
#define SEARCH_SIZE 100


typedef struct{//문자비교 구조체 만글기
    int top;
    char data[100];//txt 파일 데이터 저장
    char data2[100];//검 색어 저장
}Stack;
Stack s;

//비교 문자 저장{
char temp;
char temp2;
//}

void gotoxy(int x, int y){//커서 위치 이동
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

void initStack(){//스택 초기
    s.top = -1;
}

int isEmpty(){//스택 비어있는 지 검사
    if(s.top == -1){
        return 1;
    }
    return 0;
}

int isFull(){//스택이 가득 차있는지 검사
    if(s.top == STACK_SIZE-1){
        return 1;
    }
    return 0;
}

void push(char item, char item2){//스택 값 넣기
    if(isFull()){
        //printf("Stack is Full\n");
        return;
    }
    s.top++;
    s.data[s.top] = item;
    s.data2[s.top] = item2;
    //printf("push:%c %c\n",item, item2);
}

void pop(){ //push한 값을 제거하고 같을 비교하는 변수에 값을 저장한다
	if(isEmpty()){
		printf("Stack is Empty\n");
		return ;
	}
	temp = s.data[s.top];
	temp2 = s.data2[s.top];
	s.top--;
}

int line_length(char line[100]){//저장된 파일의 길이 구하기
    int i;
    for(i=0;line[i]!='/';i++){//for 문으로 길이를 /위치까지의 길이 구함
        ;
    }
    //printf("길이: %d\n",i); //문자열 길이 출력
    return i+1;
}

int string_comparison(char line[100], char searchvalue[100]){//문자열 같은지 검색 하는 함수

    //printf("value:%s %s", line, searchvalue);
    //printf("length: %d %d\n",line_length(line), strlen(searchvalue));

    if(line_length(line) == strlen(searchvalue)){//길이가 같을 경우 같은지 검사
        initStack();//스택 사용전 초기화 하기
        //printf("진입\n"); //길이 성공여부 출력
        for(int i=0;i<line_length(line)-1;i++){//값을 push 해주고 있음
            push(line[i],searchvalue[i]);//line 변수와 searchvalue값을 인덱스 별로 넣기

        }
        for(int i=0;i<line_length(line)-1;i++){//값을 pop하여 저장하고 같은지 비교하는 것을 반복함
            pop();//pop 삭제와 temp temp2에값을 저장
            if(temp!=temp2){//값을 비교하고 다를때if문 실해
                //printf("다름 %c %c\n",temp,temp2);//다른 값을 출력한다
                return 0;//값이 다를 경우 0을 반환하여 string_comparison 함수를 나간다
            }
            //printf("값 보기: %c %c\n", temp, temp2);//성공한 값을 보여준다
        }
        return 1;//성공시 1을 반환한다c
    }
    //printf("%s", searchvalue);
    //printf("\n\n");
    return 0;//문자열 길이가 다를 경우 0을 반환
}

void draw_main(){//청음 main 화면 그리기
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);//글자 초록색 변경
    printf("□□□■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");//■ ■ ■ □
    printf("□□□■□□■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
    printf("□□□■□□□■□■□□□■■■■■□□□■□□□■□□□■■■■■□□□□■■■■■□□□□■■■■□□□□□■□□□□□□□□□□□□□□□□\n");
    printf("□□□■□□□■□□□□■□□□□□□■■■■■□□□□■□□□□□■□□■□□□□□■□□■□□□■■□□□□□■■■■■■■□□■□□□□□■\n");
    printf("□□□■□□□■□■□■□□□□□□□□□■□□□■□■□□□□□□□■□■□□□□□■□□■□□□■□■□□□□■□□□□□□□□□■□□□■□\n");
    printf("□□□■□□■□□■□□■□□□□□□□□■□□□■□□■□□□□□■□□■□□□□□■□□■□□□■□□■□□□■□□□□□□□□□□■□■□□\n");
    printf("□□□■■■□□□■□□□■■■■■□□□■□□□■□□□■■■■■□□□■□□□□□■□□□■■■□□□□■□□■□□□□□□□□□□□■□□□\n");
    printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□□□\n");
    printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□□□□\n");
    printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□□□□□\n");
    printf("Dev\n");
    printf("");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//하얀색 변경
}

void search_main(){//검색 화면 이동
    while(1){
        char line[100];
        char searchvalue[100];
        int se=1;
        FILE* fp = fopen("test.txt","r");
        int i=0;//성공 여부 변수

        printf("exit: 1\n");
        printf("검색어를 입력 하세요:");

        fgets(searchvalue, SEARCH_SIZE, stdin);//검색어 입력

        if(searchvalue[0]=='1' && strlen(searchvalue)==2){//1입력 되었을경우 if문 작동
            system("cls");
            break;
        }

        system("cls");

        while(fgets(line,sizeof(line), fp) != NULL){//줄별로 읽기
            //printf("%s",line);
            if(string_comparison(line,searchvalue)){
                //printf("성공\n");
                i=1;
                int j;

                for(j=0;line[j]!='/';j++){//줄로 읽은 txt파일 내용 /까지 문자 크기를 구함
                    ;
                }
                j=j+2;// //뒤 숫자 가져오기
                for(int y=0; line[j]!='\n';y=y*10){//숫자 구하기
                    y=y+(line[j]-'0');
                    se=y;
                    j++;
                }
            }
        }

        fclose(fp);
        if(i==0){//검색어가 없을 경우 실행
            printf("찾기 실패 다시 입력 하세요\n");
        }
        else{//검색어가 있을 경우 실행
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);//글자 초록색 변경
            char num1[100];
            sprintf(num1,"search/%d.txt", se);
            FILE* fp = fopen(num1,"r");
            printf("검색 결과\n");
            printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
            while(fgets(line,sizeof(line), fp) != NULL){
                printf("%s", line);
            }
            printf("\n□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//하얀색 변경
            i=0;
            fclose(fp);
        }
    }
}

void char_slice(char* line){//i 값을 j에 대입하는 함수
    int i;
    for(i=0;line[i]!='/';i++){
        ;
    }
    line[i]='\n';
    line[i+1]=NULL;
}

void search_inquiry(){//검색어
    printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
    printf("검색어 조회\n");
    int i=0,j,n=50,k,hu;
    char temp[100];
    char line[100][100];
    FILE* fp = fopen("test.txt","r");

    while(fgets(line[i],sizeof(line[i]), fp) != NULL){//줄별로 읽기
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
        printf("방향키를 입력하여 정보 스크롤\n");
        printf("exit: Esc\n");
        int key = getch();
        system("cls");
        if(key==72){
            i!=1?i--:i;
            sprintf(num1,"search/%d.txt",i);
            FILE* fp = fopen(num1,"r");
            while(fgets(line,100, fp)){//줄별로 읽기
                printf("%s",line);
            }
            printf("\n");
        }
        else if(key == 80){
            i!=11?i++:i;
            sprintf(num1,"search/%d.txt",i);
            FILE* fp = fopen(num1,"r");
            while(fgets(line,100, fp)){//줄별로 읽기
                printf("%s",line);
            }
            printf("\n");
        }
        else if(key == 27){
            break;
        }
    }
}
void main_center_UI(){//main 화면
    int a=0,b=0;
    int key;
    while(1){
        draw_main();
        if(b==0){//검색 하기 표시
            gotoxy(70-2,12);
            printf(">검색 하기");
            gotoxy(70,13);
            printf("사전 전체 보기");
            gotoxy(70,14);
            printf("검색어 조회");
            gotoxy(70,15);
            printf("나가기");
        }//사전 전체보기 표시
        else if(b==1){
            gotoxy(70,12);
            printf("검색 하기");
            gotoxy(70-2,13);
            printf(">사전 전체 보기");
            gotoxy(70,14);
            printf("검색어 조회");
            gotoxy(70,15);
            printf("나가기");
        }//검색어 조회 표시
        else if(b==2){
            gotoxy(70,12);
            printf("검색 하기");
            gotoxy(70,13);
            printf("사전 전체 보기");
            gotoxy(70-2,14);
            printf(">검색어 조회");
            gotoxy(70,15);
            printf("나가기");
        }//나가기 보기
        else if(b==3){
            gotoxy(70,12);
            printf("검색 하기");
            gotoxy(70,13);
            printf("사전 전체 보기");
            gotoxy(70,14);
            printf("검색어 조회");
            gotoxy(70-2,15);
            printf(">나가기");
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
            if(b==0){//검색 화면 이동
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
    char searchvalue[100];// 검색어 저장 변수
    char line[100];//줄별로 읽는 값을 저장하는 변수

    FILE* fp = fopen("test.txt","r");//txt 파일 읽기로 열기
    system("mode con cols=146 lines=30 | title 초보 계발자를 위한 사전");
    main_center_UI(line,searchvalue, fp);
    //printf("%s",searchvalue);//입력한 검색어 출력

    return 0;
}
