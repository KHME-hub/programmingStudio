/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]); // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // 배정 결과를 출력한다.

int main(){
    char mnames[10][20]; // 남학생명단(최대 10명)
    int mroom[10];		// 남학생명단별 호실 배정 목록
    char wnames[10][20]; // 여학생명단(최대 10명)
    int wroom[10];		// 여학생명단별 호실 배정 목록
    int person[2][5]={0};   // 2개 층별 5개 호실의 배정 인원 수 
    int mcount=0, wcount=0; // 인원 합계 (남, 여)
    int menu;

    srand(time(0));
    printf("===========================================\n");
    printf("생활관 호실 배정 프로그램\n");
    printf("===========================================\n");
    while(1){
        printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
        scanf("%d", &menu);
        if(menu==0) break;
        else if(menu==1) {
            if(mcount>=10) {
                printf("정원 초과입니다. 등록불가!\n");
                continue;
            }
            printf("학생 이름은? > ");
            scanf("%s", mnames[mcount]);
            int roomno = findRoom(person[0]);
            mroom[mcount] = 100+roomno;
            printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
            mcount++;
        }
        else if(menu==2) {
            if(wcount>=10) {
                printf("정원 초과입니다. 등록불가!\n");
                continue;
            }
            printf("학생 이름은? > ");
            scanf("%s", wnames[wcount]);
            int roomno = findRoom(person[1]);
            wroom[wcount] = 200+roomno;
            printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
            wcount++;
        }
    }

    printf("===========================================\n");
    printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
    printf("===========================================\n");
    printReport(mnames, mroom, mcount, wnames, wroom, wcount);

    return 0;
}

int findRoom(int persons[5]){
//빈 방을 배정하되 호실 번호는 순서와 무관. 따라서 난수를 통해 호실 배정. 또한 int main()에서 menu 선택 결과에 따라 성별 구분, 그에 따른 함수 호출. (findRoom(person[0])/findRoom(person[1])). findRoom의 함수 선언 내의 배열 persons[5]는 (person[0])/(person[1])의 호실을 나타내는 포인터로서 동작.
    int n;
    while(1){
        n = rand() % 5 +1;  //1~5 사이 난수
        if(persons[n] < 2){
            persons[n] +=1;
            return n;
        }
    }
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
//빈 방 배정이 끝난 뒤 남학생 명단, 여학생 명단, 호실별 배정 명단을 출력.
    int s=1;
    printf("남학생 명단 (%d명)\n", mc);
    for(int i=0; i<mc; i++){
        printf("%d. %s [%d호]\n", s, mn[i], mr[i]);
        s++;
    }
    s=1;
    printf("\n여학생 명단 (%d명)\n", wc);
    for(int j=0; j<wc; j++){
        printf("%d. %s [%d호]\n", s, wn[j], wr[j]);
        s++;
    }
    printf("\n호실별 배정 명단\n");
    printf("101호:");
    for(int k=0; k<mc; k++){
        if(mr[k]==101) 
            printf("%s ", mn[k]);
    }
    printf("\n102호:");
    for(int k=0; k<mc; k++){
        if(mr[k]==102) 
            printf("%s ", mn[k]);
    }
    printf("\n103호:");
    for(int k=0; k<mc; k++){
        if(mr[k]==103) 
            printf("%s ", mn[k]);
    }
    printf("\n104호:");
    for(int k=0; k<mc; k++){
        if(mr[k]==104) 
            printf("%s ", mn[k]);
    }
    printf("\n105호:");
    for(int k=0; k<mc; k++){
        if(mr[k]==105) 
            printf("%s ", mn[k]);
    }
    printf("\n201호:");
    for(int k=0; k<wc; k++){
        if(wr[k]==201) 
            printf("%s ", wn[k]);
    }
    printf("\n202호:");
    for(int k=0; k<wc; k++){
        if(wr[k]==202) 
            printf("%s ", wn[k]);
    }
    printf("\n203호:");
    for(int k=0; k<wc; k++){
        if(wr[k]==203) 
            printf("%s ", wn[k]);
    }
    printf("\n204호:");
    for(int k=0; k<wc; k++){
        if(wr[k]==204) 
            printf("%s ", wn[k]);
    }
    printf("\n205호:");
    for(int k=0; k<wc; k++){
        if(wr[k]==205) 
            printf("%s ", wn[k]);
    }
//호실별 배정 명단에서는 방을 우선 나열하고 그 호실에 해당하는 학생이 있다면 이름을 출력.
}
