#include <stdio.h>
void PLAYER_NAME(){

	FILE *fp;
	fp = fopen("C:\\Users\\gdevw\\Desktop\\player.txt", "w");
	
	if( fp == NULL){
		printf("���� ���� ���� !\n");
	}
	else{	
	char p1[10];
	printf("����� �̸��� �Է��Ͻÿ�. :");
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
