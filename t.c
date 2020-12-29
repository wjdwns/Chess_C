 int t1(void)
 {
	 FILE  *save;
	 char a[100][10];
	 int b[100], c[100], d[100], e[100], f[100], g[100], i = 0, j, _;
	 save = fopen("C:\\Users\\ICOM1811\\Desktop\\save.txt", "r");
	 
	 while ((_ = getc(save)) != EOF)
	 {
		 fscanf(save, "%s %d %d %d %d %d %d", &a[i], &b[i], &c[i], &d[i], &e[i], &f[i], &g[i]);
		 i++;
	 }
	 Bubble1(b, i, a, c, d, e, f, g);
	 printf("맵1의 랭킹 \n\n");
	 for (int k = 0; k < i; k++)
	 {
		 printf("%d. %s님 %d번\n", k+1, a[k], c[k]);
	 }
	 fclose(save);
	 return 0;
 }
 int t2(void)
 {
	 FILE  *save;
	 char a[100][10];
	 int b[100], c[100], d[100], e[100], f[100], g[100], i = 0, j, _;
	 save = fopen("C:\\Users\\ICOM1811\\Desktop\\save.txt", "r");

	 while ((_ = getc(save)) != EOF)
	 {
		 fscanf(save, "%s %d %d %d %d %d %d", &a[i], &b[i], &c[i], &d[i], &e[i], &f[i], &g[i]);
		 i++;
	 }
	 Bubble2(b, i, a, c, d, e, f, g);
	 printf("맵2의 랭킹 \n\n");
	 for (int k = 0; k < i; k++)
	 {
		 printf("%d. %s님 %d번\n", k + 1, a[k], d[k]);
	 }
	 fclose(save);
	 return 0;
 }
 int t3(void)
 {
	 FILE  *save;
	 char a[100][10];
	 int b[100], c[100], d[100], e[100], f[100], g[100], i = 0, j, _;
	 save = fopen("C:\\Users\\ICOM1811\\Desktop\\save.txt", "r");

	 while ((_ = getc(save)) != EOF)
	 {
		 fscanf(save, "%s %d %d %d %d %d %d", &a[i], &b[i], &c[i], &d[i], &e[i], &f[i], &g[i]);
		 i++;
	 }
	 Bubble3(b, i, a, c, d, e, f, g);
	 printf("맵3의 랭킹 \n\n");
	 for (int k = 0; k < i; k++)
	 {
		 printf("%d. %s님 %d번\n", k + 1, a[k], e[k]);
	 }
	 fclose(save);
	 return 0;
 }
 int t4(void)
 {
	 FILE  *save;
	 char a[100][10];
	 int b[100], c[100], d[100], e[100], f[100], g[100], i = 0, j, _;
	 save = fopen("C:\\Users\\ICOM1811\\Desktop\\save.txt", "r");

	 while ((_ = getc(save)) != EOF)
	 {
		 fscanf(save, "%s %d %d %d %d %d %d", &a[i], &b[i], &c[i], &d[i], &e[i], &f[i], &g[i]);
		 i++;
	 }
	 Bubble4(b, i, a, c, d, e, f, g);
	 printf("맵4의 랭킹 \n\n");
	 for (int k = 0; k < i; k++)
	 {
		 printf("%d. %s님 %d번\n", k + 1, a[k], f[k]);
	 }
	 fclose(save);
	 return 0;
 }
 int t5(void)
 {
	 FILE  *save;
	 char a[100][10];
	 int b[100], c[100], d[100], e[100], f[100], g[100], i = 0, j, _;
	 save = fopen("C:\\Users\\ICOM1811\\Desktop\\save.txt", "r");

	 while ((_ = getc(save)) != EOF)
	 {
		 fscanf(save, "%s %d %d %d %d %d %d", &a[i], &b[i], &c[i], &d[i], &e[i], &f[i], &g[i]);
		 i++;
	 }
	 Bubble5(b, i, a, c, d, e, f, g);
	 printf("맵5의 랭킹 \n\n");
	 for (int k = 0; k < i; k++)
	 {
		 printf("%d. %s님 %d번\n", k + 1, a[k], g[k]);
	 }
	 fclose(save);
	 return 0;
 }
 void Bubble1(int *score, int count, char *name, int *move1, int *move2, int *move3, int *move4, int *move5)
 {
	 int i, j;
	 int temp;

	 for (i = 0; i < count - 1; i++)
	 {
		 for (j = 1; j < count - i; j++)
		 {
			 if (move1[j - 1] > move1[j])
			 {
				 temp = score[j - 1];
				 score[j - 1] = score[j];
				 score[j] = temp;
				 temp = name[j - 1];
				 name[j - 1] = name[j];
				 name[j] = temp;
				 temp = move1[j - 1];
				 move1[j - 1] = move1[j];
				 move1[j] = temp;
				 temp = move2[j - 1];
				 move2[j - 1] = move2[j];
				 move2[j] = temp;
				 temp = move3[j - 1];
				 move3[j - 1] = move3[j];
				 move3[j] = temp;
				 temp = move4[j - 1];
				 move4[j - 1] = move4[j];
				 move4[j] = temp;
				 temp = move5[j - 1];
				 move5[j - 1] = move5[j];
				 move5[j] = temp;
			 }
		 }
	 }
 }
 void Bubble2(int *score, int count, char *name, int *move1, int *move2, int *move3, int *move4, int *move5)
 {
	 int i, j;
	 int temp;

	 for (i = 0; i < count - 1; i++)
	 {
		 for (j = 1; j < count - i; j++)
		 {
			 if (move2[j - 1] > move2[j])
			 {
				 temp = score[j - 1];
				 score[j - 1] = score[j];
				 score[j] = temp;
				 temp = name[j - 1];
				 name[j - 1] = name[j];
				 name[j] = temp;
				 temp = move1[j - 1];
				 move1[j - 1] = move1[j];
				 move1[j] = temp;
				 temp = move2[j - 1];
				 move2[j - 1] = move2[j];
				 move2[j] = temp;
				 temp = move3[j - 1];
				 move3[j - 1] = move3[j];
				 move3[j] = temp;
				 temp = move4[j - 1];
				 move4[j - 1] = move4[j];
				 move4[j] = temp;
				 temp = move5[j - 1];
				 move5[j - 1] = move5[j];
				 move5[j] = temp;
			 }
		 }
	 }
 }
 void Bubble3(int *score, int count, char *name, int *move1, int *move2, int *move3, int *move4, int *move5)
 {
	 int i, j;
	 int temp;

	 for (i = 0; i < count - 1; i++)
	 {
		 for (j = 1; j < count - i; j++)
		 {
			 if (move3[j - 1] > move3[j])
			 {
				 temp = score[j - 1];
				 score[j - 1] = score[j];
				 score[j] = temp;
				 temp = name[j - 1];
				 name[j - 1] = name[j];
				 name[j] = temp;
				 temp = move1[j - 1];
				 move1[j - 1] = move1[j];
				 move1[j] = temp;
				 temp = move2[j - 1];
				 move2[j - 1] = move2[j];
				 move2[j] = temp;
				 temp = move3[j - 1];
				 move3[j - 1] = move3[j];
				 move3[j] = temp;
				 temp = move4[j - 1];
				 move4[j - 1] = move4[j];
				 move4[j] = temp;
				 temp = move5[j - 1];
				 move5[j - 1] = move5[j];
				 move5[j] = temp;
			 }
		 }
	 }
 }
 void Bubble4(int *score, int count, char *name, int *move1, int *move2, int *move3, int *move4, int *move5)
 {
	 int i, j;
	 int temp;

	 for (i = 0; i < count - 1; i++)
	 {
		 for (j = 1; j < count - i; j++)
		 {
			 if (move4[j - 1] > move4[j])
			 {
				 temp = score[j - 1];
				 score[j - 1] = score[j];
				 score[j] = temp;
				 temp = name[j - 1];
				 name[j - 1] = name[j];
				 name[j] = temp;
				 temp = move1[j - 1];
				 move1[j - 1] = move1[j];
				 move1[j] = temp;
				 temp = move2[j - 1];
				 move2[j - 1] = move2[j];
				 move2[j] = temp;
				 temp = move3[j - 1];
				 move3[j - 1] = move3[j];
				 move3[j] = temp;
				 temp = move4[j - 1];
				 move4[j - 1] = move4[j];
				 move4[j] = temp;
				 temp = move5[j - 1];
				 move5[j - 1] = move5[j];
				 move5[j] = temp;
			 }
		 }
	 }
 }
 void Bubble5(int *score, int count, char *name, int *move1, int *move2, int *move3, int *move4, int *move5)
 {
	 int i, j;
	 int temp;

	 for (i = 0; i < count - 1; i++)
	 {
		 for (j = 1; j < count - i; j++)
		 {
			 if (move5[j - 1] > move5[j])
			 {
				 temp = score[j - 1];
				 score[j - 1] = score[j];
				 score[j] = temp;
				 temp = name[j - 1];
				 name[j - 1] = name[j];
				 name[j] = temp;
				 temp = move1[j - 1];
				 move1[j - 1] = move1[j];
				 move1[j] = temp;
				 temp = move2[j - 1];
				 move2[j - 1] = move2[j];
				 move2[j] = temp;
				 temp = move3[j - 1];
				 move3[j - 1] = move3[j];
				 move3[j] = temp;
				 temp = move4[j - 1];
				 move4[j - 1] = move4[j];
				 move4[j] = temp;
				 temp = move5[j - 1];
				 move5[j - 1] = move5[j];
				 move5[j] = temp;
			 }
		 }
	 }
 }
