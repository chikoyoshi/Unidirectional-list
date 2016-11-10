#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}LISTEL;

LISTEL *root;

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

void insert_node(int k, int y)
{
	int i;
	LISTEL *p,*q;
	if(k <= 0)
	{
		fprintf(stderr, "Error : Target node is not found!\n");
		return ;
	}
	p = (LISTEL *)malloc( sizeof(LISTEL));
	p = root;
	for(i=0;i<k;i++)
	{
		if(p == NULL)
		{
			fprintf(stderr,"Error : Target node is not found!\n");
			return;
		}
		p = p->next;
	}
	q = (LISTEL *)malloc(sizeof(LISTEL));
	q->data = y;
	q->next = p->next;
	p->next = q;
}

void delete_node(int k)
{
	int i;
	LISTEL *p,*q;
	p = (LISTEL *)malloc(sizeof(LISTEL));
	p = root;
	if(p == NULL|| k <= 0)
	{
		printf("Error : Target node is not found!\n");
		return;
	}
	//先頭ノードを削除するプログラムを書く
	p = p->next;
	p = root;
	q = (LISTEL *)malloc(sizeof(LISTEL));
	q = root;
	//2番目以降のノードを削除するプログラムを書く
	for(i=0;i<k-2;i++)
	{
		if(p == NULL)
		{
			printf("Erro : Target node is not found!\n");
			return;
		}
		q = q->next;
		p = p->next;
	}
	p = p->next;
	q->next = p->next;
}

int main()
{
	int k, y;
	root = NULL;
	construct_list();
	print_list();

	printf("*******Insert*******\n");
	printf("Input insert-location: ");
	scanf("%d", &k);
	printf("Input insert data:");
	scanf("%d", &y);
	insert_node(k,y);
	print_list();

	printf("*******Delete*******\n");
	printf("Input delete-location: ");
	scanf("%d",&k);
	delete_node(k);
	print_list();

	return 0;
}