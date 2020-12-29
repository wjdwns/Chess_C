#include <stdio.h>
#include<conio.h>
#include<windows.h>
char map_reading[30][30][5], map_undo[30][30], map_rn[30][30][5];
void load();
void undo();
void map_print();
void key_all(char);
void key_hjkl(char);
void rn_get();
void rn_put();
void level_clear();
void goal_get();
void player_name();
void file_save();
void file_load();
char example='0';
char player[10];
int map_Y[5]={0},map_X[5]={0},map_goal[5]={0},map_box[5]={0},hero_undo_X[5]={0},hero_undo_Y[5]={0},discorrect=1;
int hero_X[5]={0},hero_Y[5]={0},level=0,stop=0,undo_time=0,hero_rn_X[5]={0},hero_rn_Y[5]={0},move_time=0;
int map_goal_place[30][30][5],clear=1;

int main(void){
   int i,j=0,n;
   player_name();
   load();
  	while(stop==0){
  		if(map_box[level]!=map_goal[level]){
      		printf("박스의 개수와 보관장소의 개수가 같지 않습니다.");
  		}
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
   int i,j;
   for(j=0;j<map_Y[level];j++){
      for(i=0;i<map_X[level];i++){
         map_undo[i][j]=map_reading[i][j][level];
      }
   }
   hero_undo_X[level]=hero_X[level];
   hero_undo_Y[level]=hero_Y[level];
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
	scanf("%s",&player);
}

void file_save(){
	int i,j;
	FILE *sokoban;
    sokoban=fopen("C:\\Users\\Name\\Desktop\\sokoban.txt","w");
    fprintf(sokoban,"%d",level);
    fprintf(sokoban,"\n&\n");
    for(j=0;j<map_Y[level];j++){
        for(i=0;i<map_X[level];i++){
            fprintf(sokoban,"%c",map_undo[i][j]);
        }
    }
    fprintf(sokoban,"\n&\n");
    for(i=0;i<10;i++){
    	fprintf(sokoban,"%c",player[i]);
	}
	fprintf(sokoban,"\n&\n");
    fprintf(sokoban,"%d",discorrect);
    fprintf(sokoban,"\n&\n");
    fprintf(sokoban,"%d",hero_X[level]);
    fprintf(sokoban,"\n&\n");
    fprintf(sokoban,"%d",hero_Y[level]);
    fprintf(sokoban,"\n&\n");
    fprintf(sokoban,"%d",undo_time);
    fprintf(sokoban,"\n&\n");
    fprintf(sokoban,"%d",move_time);
    fprintf(sokoban,"\n&\n");
    fprintf(sokoban,"%d",clear);
    fprintf(sokoban,"\n~");
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
   int i,j;
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
         if(discorrect==0){
             if(undo_time<=5){
                undo_time++;
                for(j=0;j<map_Y[level];j++){
                   for(i=0;i<map_X[level];i++){
                      map_reading[i][j][level]=map_undo[i][j];
                  }
               }
            hero_X[level]=hero_undo_X[level];
            hero_Y[level]=hero_undo_Y[level];
             }
          discorrect=1;
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
         break;
      case 'f':
      	 file_save();
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
      	 undo();
         example=map_reading[hero_X[level]-2*i][hero_Y[level]-2*j][level];
         map_reading[hero_X[level]-2*i][hero_Y[level]-2*j][level]=map_reading[hero_X[level]-1*i][hero_Y[level]-1*j][level];
         map_reading[hero_X[level]-1*i][hero_Y[level]-1*j][level]=map_reading[hero_X[level]][hero_Y[level]][level];
         map_reading[hero_X[level]][hero_Y[level]][level]=example;
         hero_X[level]=hero_X[level]-1*i;
         hero_Y[level]=hero_Y[level]-1*j;
         move_time++;
        discorrect=0;
         return;
      }
   }
   else{
   	  undo();
      example=map_reading[hero_X[level]-1*i][hero_Y[level]-1*j][level];
      map_reading[hero_X[level]-1*i][hero_Y[level]-1*j][level]=map_reading[hero_X[level]][hero_Y[level]][level];
      map_reading[hero_X[level]][hero_Y[level]][level]=example;
      hero_X[level]=hero_X[level]-1*i;
      hero_Y[level]=hero_Y[level]-1*j;
      move_time++;
      discorrect=0;
      return;
   }
} 
