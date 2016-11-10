//j1414小林佳樹

#include <stdio.h>
#include <stdlib.h>

//連結リストの構造体宣言
typedef struct node
{
	int data;
	struct node *next;
}LISTEL;

LISTEL *root;	//リストの最初のノードを指すポインタ

//連結リストを構築する関数
void construct_list()
{
	LISTEL *p;
	int n, y, i, k, noIndex[50];
	char buf[100];
	while(1)
	{
		fprintf(stdout,"Input Data: ");
		fgets(buf, sizeof(buf), stdin);

		if(buf[0] == '\n')	{return;}
		i = 0, k = 0;
		//最初に入力された文字がスペースでない場合、配列の場所をnoIndex[]に格納
		if(buf[i] != ' ')		{noIndex[k++] = i;}
		//2つ目以降に入力された文字がスペースでない場合、配列の場所をnoIndex[]に格納
		while(buf[i] != '\0')
		{
			i++;
			if(buf[i-1] == ' ' && buf[i] != ' ' && buf[i] != '\n')		{noIndex[k++] = i;}
		}
		//文字数がオーバーした場合
		if(buf[i-1] != '\n')
		{
			fprintf(stderr, "Error : Too long input data\n");
			exit(1);
		}
		//入力された数字をリストに格納する
		for(i=0;i<k;i++)
		{
			n = sscanf(&buf[noIndex[i] ], "%d", &y);
			if(n != 1)
			{
				fprintf(stderr, "Error : non-number input data\n");
				continue;
			}
			p = (LISTEL *)malloc(sizeof(LISTEL));
			p->data = y; p->next = root; root = p;

		}
	}
}

//連結リストを出力する関数
void print_list()
{
	LISTEL *p;
	p = (LISTEL *)malloc( sizeof(LISTEL));
	p = root;
	if(p == NULL)
	{
		fprintf(stderr, "There is no data!");
		return;
	}
	fprintf(stdout,"List data:");
	while(p != NULL)
	{
		fprintf(stdout,"%4d",p->data);
		p = p->next;
	}
	fprintf(stdout,"\n");
}

int main()
{
	root = NULL;
	construct_list();
	print_list();
	return 0;
}