#include <termio.h>
#include <stdio.h>
void DISPLAY_HELP()
{
	char key;
	_Bool a = 1;
	char ch_ = 0;
	while(a){
	ch_ = getch();
	if((ch_ == 'd') || (ch_ == 'D'))
	{
		printf("┏━━━━━━━━ ┓\n");
		printf("┃ h: 왼쪽 j: 아래 ┃\n");
		printf("┃ k: 위 l:오른쪽  ┃\n");
		printf("┃ u : undo        ┃\n");
		printf("┃ e: exit         ┃\n");
		printf("┃ n: new          ┃\n");
		printf("┃ s: save         ┃\n");
		printf("┃ f: file load    ┃\n");
		printf("┃ d: display help ┃\n");
		printf("┃ t: top          ┃\n");
		printf("┗━━━━━━━━ ┛\n");
	}
	return ;
}
}

int main(void){
	DISPLAY_HELP();
	return 0;
}

int getch(void){

	int ch;
    struct termios buf, save;
    tcgetattr(0,&save);
    buf = save;
    buf.c_lflag &= ~(ICANON|ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}
