#include <stdio.h>
void PLAYER_NAME(){

	FILE *fp;
	fp = fopen("C:\\Users\\gdevw\\Desktop\\player.txt", "w");
	
	if( fp == NULL){
		printf("파일 오픈 실패 !\n");
	}
	else{	
	char p1[10];
	printf("사용자 이름을 입력하시오. :");
	scanf("%s", &p1);
	fprintf(fp, "%s\n", p1);
	}
	fclose(fp);
	return ;
}

int main(void){
	PLAYER_NAME();
	return 0;
}
