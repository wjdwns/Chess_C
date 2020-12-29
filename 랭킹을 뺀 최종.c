#include <stdio.h>
#include<conio.h>
#include<windows.h>
char map_reading[30][30][5]; //맵 저장 배열 
char map_undo[5][30][30];  //맵 이동 전의 배열 
char map_rn[30][30][5]; //초기 맵 배열 
void load(); //맵 로드 함수 
void undo();  //맵 언도 함수 
void map_print(); // 맵 출력 함수 
void key_all(char); //각각의 키 처리 함수 
void key_hjkl(char); //상하좌우 처리 함수 
void rn_get(); //초기 맵 저장 함수 
void rn_put(); //초기 맵 사용 함수 
void level_clear(); //레벨 클리어 여부 함수 
void goal_get();  //목적지 위치 저장 함수 
void player_name(); //플레이어 이름 저장 함수 
void file_save(); //필요한 요소 저장 함수 
void file_load();  //필요한 요소 꺼내오는 함수 
char example='0'; //예시 값 
char player[10]; //플레이어 이름 배열 
int max_map=0;  //불러오는 파일의 총 단게 
int map_Y[5]={0}; //각 레벨의 y최대 값 
int map_X[5]={0}; //각 레벨의 x 최대 값 
int map_goal[5]={0}; //각 레벨의 목적지 수 
int map_box[5]={0}; //각 레벨의 상자 수 
int hero_undo_X[5]={0}; //이동전 주인공의 x위치 
int hero_undo_Y[5]={0}; //이동전 주인공의  y위치 
int hero_X[5]={0}; //주인공의 x위치 
int hero_Y[5]={0}; //주인공의 y위치 
int level=0; //현재 단계 
int stop=0; //멈춰야 하는 여부 
int undo_time=0; //언도를 한 횟수 
int hero_rn_X[5]={0}; //초기맵의 주인공 x위치 
int hero_rn_Y[5]={0}; //초기맵의 주인공 y위치 
int move_time=0; //움직인 횟수 
int map_goal_place[30][30][5]; //목적지의 위치 
int clear=1; //클리어 여 부 
int error=0; //에러 여부 

int main(void){
   int i,j=0,n;
   load();
   if(map_box[level]!=map_goal[level]){
            printf("박스의 개수와 보관장소의 개수가 같지 않습니다.");
            error++;
        }
     player_name();
     while(stop==0&&error==0){
        printf("hello %s\n\n",player);
         level_clear();
      if(clear==1){
            undo_time=0;
            move_time=0;
            clear--;
            goal_get();
            rn_get();      
      }
      printf("%d\n",move_time);
         printf("%d\n",undo_time);
         map_print();
         key_all(getch());
         system("cls");
        }
    if(stop==1){
       printf("SEE YOU %s....",player);
   }
}

void load(){             
   int i,j=0,k=0,t_enter=0,w=0;
   FILE *map;
   map=fopen("C:\\Users\\Name\\Desktop\\map.txt","r");
   while (example!='e'){
      mapping:
         for(i=0;i<30;i++){
            fscanf(map,"%c",&example);
            if('2'<=example&&example<='5'){
               max_map++;
            k++;
               j=0;
               t_enter=0;
               w++;
               goto mapping;
            }
            else if(example=='\n'){
               if(t_enter==0){
                  t_enter++;
                  i--;
               }
               else {
                  map_reading[i][j][k]=example;
                  if(j==0){
                     map_X[w]++;
                  }
                  map_Y[w]++;
                  j++;
                  goto mapping;
               }         
            }
            else if(example=='1'){
               i--;
            }
            else if(example=='e'){
               break;
            }
            else {
               map_reading[i][j][k]=example;
               if(j==0){
                  map_X[w]++;
               }
               if(map_reading[i][j][k]=='$'){
                  map_box[w]++;
               }
               else if(map_reading[i][j][k]=='O'){
                  map_goal[w]++;
               }
               else if(map_reading[i][j][k]=='@'){
                  hero_X[w]=i;
                  hero_Y[w]=j;
               }
            }
         }
   }
   return;
}

void level_clear(){
   int goal=0,i,j;
   for(j=0;j<map_Y[level];j++){
      for(i=0;i<map_X[level];i++){
         if(map_goal_place[i][j][level]=='O'&&map_reading[i][j][level]=='$'){
            goal++;
       }
      }
   }
   if(goal==map_goal[level]){
      level++;
      clear++;
   }
    if(level==max_map+1){
       if(clear==1){
          printf("축하합니다! 모든 스테이지를 클리어 하셨습니다. %s",player);
          stop=2;
      }
   }
}

void rn_get(){
   int i,j;
   for(j=0;j<map_Y[level];j++){
      for(i=0;i<map_X[level];i++){
         map_rn[i][j][level]=map_reading[i][j][level];
      }
   }
   hero_rn_X[level]=hero_X[level];
   hero_rn_Y[level]=hero_Y[level];
}

void goal_get(){
   int i,j;
   for(j=0;j<map_Y[level];j++){
      for(i=0;i<map_X[level];i++){
         if(map_reading[i][j][level]=='O'){
            map_goal_place[i][j][level]='O';
       }
      }
   }
   for(j=0;j<map_Y[level];j++){
      for(i=0;i<map_X[level];i++){
         if(map_reading[i][j][level]=='O'){
            map_reading[i][j][level]='.';
       }
      }
   }
}

void undo(){
   int i,j,back;
    for(back=4;back>0;back--){ 
    for(j=0;j<map_Y[level];j++){
        for(i=0;i<map_X[level];i++){
           map_undo[back][i][j]=map_undo[back-1][i][j];
        }
     }
     hero_undo_X[back]=hero_undo_X[back-1];
     hero_undo_Y[back]=hero_undo_Y[back-1];
   }
   for(j=0;j<map_Y[level];j++){
      for(i=0;i<map_X[level];i++){
         map_undo[0][i][j]=map_reading[i][j][level];
      }
   }
   hero_undo_X[0]=hero_X[level];
   hero_undo_Y[0]=hero_Y[level];
}

void rn_put(){
   int i,j;
   for(j=0;j<map_Y[level];j++){
                for(i=0;i<map_X[level];i++){
                   map_reading[i][j][level]=map_rn[i][j][level];
               }
            }
         hero_X[level]=hero_rn_X[level];
         hero_Y[level]=hero_rn_Y[level];
}

void player_name(){
   printf("Start......\n");
   printf("input name : ");
   scanf("%s",&player);
}

void file_save(){
   int i,j;
   FILE *sokoban;
    sokoban=fopen("C:\\Users\\Name\\Desktop\\sokoban.txt","w");
    fprintf(sokoban,"%d",level);
    fprintf(sokoban,"&");
    for(j=0;j<map_Y[level];j++){
        for(i=0;i<map_X[level];i++){
            fprintf(sokoban,"%c",map_reading[i][j][level]);
        }
    }
    fprintf(sokoban,"&");
    for(i=0;i<10;i++){
       fprintf(sokoban,"%c",player[i]);
   }
   fprintf(sokoban,"&");
    fprintf(sokoban,"%d",hero_X[level]);
    fprintf(sokoban,"&");
    fprintf(sokoban,"%d",hero_Y[level]);
    fprintf(sokoban,"&");
    fprintf(sokoban,"%d",undo_time);
    fprintf(sokoban,"&");
    fprintf(sokoban,"%d",move_time);
    fprintf(sokoban,"&");
    fprintf(sokoban,"%d",clear);
    fprintf(sokoban,"~");
    fclose(sokoban);
}

void file_load(){
   int i,j;
   FILE *sokoban;
   sokoban=fopen("C:\\Users\\Name\\Desktop\\sokoban.txt","r");
   fscanf(sokoban,"%d",&level);
   while(getc(sokoban)!='&'){
   }
    for(j=0;j<map_Y[level];j++){
        for(i=0;i<map_X[level];i++){
            fscanf(sokoban,"%c",&map_reading[i][j][level]);
        }
    }
    while(getc(sokoban)!='&'){
   }
    for(i=0;i<10;i++){
       fscanf(sokoban,"%c",&player[i]);
   }
   while(getc(sokoban)!='&'){
   }
    fscanf(sokoban,"%d",&hero_X[level]);
    while(getc(sokoban)!='&'){
   }
    fscanf(sokoban,"%d",&hero_Y[level]);
    while(getc(sokoban)!='&'){
   }
    fscanf(sokoban,"%d",&undo_time);
    while(getc(sokoban)!='&'){
   }
    fscanf(sokoban,"%d",&move_time);
    while(getc(sokoban)!='&'){
   }
    fscanf(sokoban,"%d",&clear);
    undo();
    if(getc(sokoban)=='~'){
      fclose(sokoban);
   }
}

void map_print(){
   int i,j;
   for(j=0;j<map_Y[level];j++){
         for(i=0;i<map_X[level];i++){
            if(map_goal_place[i][j][level]=='O'){
               if(map_reading[i][j][level]=='$'){
                  printf("$");
            }
            else if(map_reading[i][j][level]=='@'){
               printf("@");
            }
            else{
               printf("O");
            }
         }
         else if(map_reading[i][j][level]=='.'){
               printf(" ");
            }
            else{
            printf("%c",map_reading[i][j][level]);
            }   
         }
      }
}

void key_all(char a){
   int i,j,front;
   switch (a){
      case 'h':
         key_hjkl(a);
         return;
      case 'j':
         key_hjkl(a);
         return;
      case 'k':
         key_hjkl(a);
         return;
      case 'l':
         key_hjkl(a);
         return;
      case 'u':
        if(undo_time<=5){
            undo_time++;
            for(j=0;j<map_Y[level];j++){
                for(i=0;i<map_X[level];i++){
                    map_reading[i][j][level]=map_undo[0][i][j];
                }
            }
        hero_X[level]=hero_undo_X[level];
        hero_Y[level]=hero_undo_Y[level];
        for(front=0;front<4;front++){ 
          for(j=0;j<map_Y[level];j++){
              for(i=0;i<map_X[level];i++){
                    map_undo[front][i][j]=map_undo[front+1][i][j];
              }
           }
         hero_undo_X[front+1]=hero_undo_X[front];
        hero_undo_Y[front+1]=hero_undo_Y[front];
      }
        }
         break;
      case 'r':
        rn_put();
         break;
      case 'n':
          rn_put();
          level=0;
          rn_put();
          undo_time=0;
          move_time=0;
         break;
      case 'e':
          stop++;
         break;
      case 's':
          file_save();
         break;
      case 'f':
          file_load();
         break;
      case 'd':
          system("cls");
         printf("h(왼쪽), j(아래)m k(위), l(오른쪽)\n");
         printf("u(undo)\n");
         printf("r(replay)\n");
         printf("n(new)\n");
         printf("e(exit)\n");
         printf("s(save)\n");
         printf("f(file load)\n");
         printf("d(display help)\n");
         printf("t(top)\n");
         break;
      case 't':
         break;
   }
}

void key_hjkl(char a){
   int i=0,j=0;
   switch (a){
      case 'h':
         i++;
         break;
      case 'j':
         j--;
         break;
      case 'k':
         j++;
         break;
      case 'l':
         i--;
         break;
   }
   undo();
   move_time++;
   if(map_reading[hero_X[level]-1*i][hero_Y[level]-1*j][level]=='#'){
            return;
         }
   else if(map_reading[hero_X[level]-1*i][hero_Y[level]-1*j][level]=='$'){
      if(map_reading[hero_X[level]-2*i][hero_Y[level]-2*j][level]=='#'){
         return;
      }
      else if(map_reading[hero_X[level]-2*i][hero_Y[level]-2*j][level]=='$'){
          return;
     }
      else{
         example=map_reading[hero_X[level]-2*i][hero_Y[level]-2*j][level];
         map_reading[hero_X[level]-2*i][hero_Y[level]-2*j][level]=map_reading[hero_X[level]-1*i][hero_Y[level]-1*j][level];
         map_reading[hero_X[level]-1*i][hero_Y[level]-1*j][level]=map_reading[hero_X[level]][hero_Y[level]][level];
         map_reading[hero_X[level]][hero_Y[level]][level]=example;
         hero_X[level]=hero_X[level]-1*i;
         hero_Y[level]=hero_Y[level]-1*j;
         return;
      }
   }
   else{
      example=map_reading[hero_X[level]-1*i][hero_Y[level]-1*j][level];
      map_reading[hero_X[level]-1*i][hero_Y[level]-1*j][level]=map_reading[hero_X[level]][hero_Y[level]][level];
      map_reading[hero_X[level]][hero_Y[level]][level]=example;
      hero_X[level]=hero_X[level]-1*i;
      hero_Y[level]=hero_Y[level]-1*j;
      return;
   }
} 
