/* file name: bin_search_tree.c */
/* 利用二元搜尋樹處理資料－載入、儲存、新增、刪除、修改、輸出 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/* 定義student結構 */
struct student {
	char name[20];  /* 學生姓名 */
	int score;  /* 學生成績 */
	struct student *llink;  /* 左子鏈結 */
	struct student *rlink;  /* 右子鏈結 */
};

int d[100],j ,count=0;
void load_f(void);      /* 載入函數 */
void save_f(void);      /* 儲存函數 */
void insert_f(void);    /* 新增函數 */
void delete_f(void);    /* 刪除函數 */
void modify_f(void);    /* 修改函數 */
void show_f(void);  
void show_post(void);    /* 輸出函數 */
void show_preorder(void);
void access(char [], int);  /* 將資料加入二元搜尋樹 */
void removing(char []);  /* 將資料從二元搜尋樹中移除 */
struct student *replace(struct student *);  /* 尋找替代節點 */
void connect(struct student *, char);  /* 調整鏈結 */
void inorder(struct student *);  /* 資料以中序法輸出 */
void preorder(struct student *, FILE *);  /* 資料以前序法寫入檔案 */
void postorder(struct student *); /* 資料以後序法輸出 */
void preorder1(struct student *); /* 資料以前序法顯示*/
void inorder_decrease(struct student *);/* modified by 蕭老師*/ 
void show_smallest(void); /* modified by 蕭老師*/ 
void access1(char [], int);/* modified by 蕭老師*/ 
void show_bigest(void); /* modified by 蕭老師*/ 
void mysearch_inorder(void);/* modified by 蕭老師*/ 
void mysearch_deorder(void);/* modified by 蕭老師*/ 
void show_total(void);/* modified by 蕭老師*/ 
void mytotal(struct student *);
struct student *search(char []);  /* 搜尋節點 */
struct student *search_re_r(struct student *);  /* 搜尋右子樹替代節點 */
struct student *search_re_l(struct student *);  /* 搜尋左子樹替代節點 */
struct student *search_p(struct student *);  /* 搜尋父節點 */

struct student *root,*root1, *ptr; 

int main(void)
{
	char option;
	load_f();  /* 載入檔案 */
	while(1)
	{
		puts("");
		puts("********************");
		puts("     <1> insert");
		puts("     <2> delete");
		puts("     <3> modify");
		puts("     <4> show-all-increase");
		puts("     <5> quit");
		puts("     <6> show post-order");/* modified by 蕭老師*/ 
	    puts("     <7> show pre-order");/* modified by 蕭老師*/ 
	    puts("     <8> show smallest");/* modified by 蕭老師*/ 
	    puts("     <9> show  bigest");/* modified by 蕭老師*/ 
	    puts("     <p> show  subtree-indoer");/* modified by 蕭老師*/ 
	    puts("     <d> show  show-all-decrease ");/* modified by 蕭老師*/ 
	    puts("     <t> show total ");/* modified by 蕭老師*/ 
		puts("********************");
		printf("Enter your choice: ");
		option = getche();
		printf("\n\n");
		switch(option)
		{
			case '1':
				insert_f();
				break;
			case '2':
				delete_f();
				break;
			case '3':
				modify_f();
				break;
			case '4':
				show_f();
				break;
			case '5':
				save_f();  /* 儲存檔案 */
				exit(0);
			case '6':
				show_post();/* modified by 蕭老師*/ 
				break;
			case '7':
				show_preorder(); /* modified by 蕭老師*/ 
				break;
			case '8':
				show_smallest();/* modified by 蕭老師*/ 
				break;
			case '9':
				show_bigest();/* modified by 蕭老師*/ 
				break;
			case 'p':
				mysearch_inorder();/* modified by 蕭老師*/ 
				break;
			case 'd':
			    mysearch_deorder();/* modified by 蕭老師*/ 
				break;
			case 't':
		       count=0;
		       j=0;
				show_total();/* modified by 蕭老師*/ 
				break;
			default :
				puts("Wrong option!");
		}
	}
	system("PAUSE");
	return 0;
}

/* 載入函數，將資料檔dfile.dat載入到程式中 */
void load_f(void)
{
	FILE *fptr;
	char name[20];
	int score;
	printf("File loading...");
	if((fptr = fopen("bst.dat", "r")) == NULL)  /* 開啟檔案 */
	{
		puts("failed!");
		puts("Dfile.dat not found!");
		return;
	}
	while(fscanf(fptr, "%s %d", name, &score) != EOF)  /* 讀取檔案資料 */
		if(strcmp(name, "") != 0)
		 {
			access(name, score); 
		/*	accesss1(name, score);  */  /*建立右小左大的二元搜尋樹  modified by 蕭老師*/ 
		}
	puts("OK!");
	fclose(fptr);  /* 關閉檔案 */
}

/* 儲存檔案，將二元搜尋樹中的資料儲存至資料檔dfile.dat中 */
void save_f(void)
{
	FILE *fptr;
	printf("File saving...");
	if((fptr = fopen("bst.dat", "w")) == NULL)  /* 開啟檔案 */
	{
		puts("failed!");
		return;
	}
	preorder(root, fptr);  /* 以前序法寫入 */
	puts("OK!");
	fclose(fptr);  /* 關閉檔案 */
}

/* 新增函數，新增一筆新的資料 */
void insert_f(void)
{
	char name[20], temp[4];
	int score;
	puts("=====INSERT DATA=====");
	printf("Enter student name: ");
	gets(name);
	printf("Enter data structures score: ");
	gets(temp);
	score = atoi(temp);
	access(name, score);
}

/* 刪除函數，將資料從二元搜尋樹中刪除 */
void delete_f(void)
{
	char name[20];
	if(root == NULL)
	{
		puts("No student record!");
		return;
	}
	puts("=====DELETE DATA=====");
	printf("Enter student name: ");
	gets(name);
	removing(name);
}

/* 修改資料，修改學生成績 */
void modify_f(void)
{
	struct student *node;
	char name[20], temp[4];
	if(root == NULL)  /* 判斷根節點是否為NULL */
	{
		puts("No student record!");
		return;
	}
	puts("=====MODIFY DATA===== ");
	printf("Enter student name: ");
	gets(name);
	if((node = search(name)) == NULL)
		printf("Student %s not found!\n", name);
	else
	{
		/* 列出原資料狀況 */
		printf("Original student name: %s\n", node->name);
		printf("Original student score: %d\n", node->score);
		printf("Enter new score: ");
		gets(temp);
		node->score = atoi(temp);
		printf("Data of student %s modified\n", name);
	}
}

/* 輸出函數，將資料輸出至螢幕 */
void show_f(void)
{
	if(root == NULL)  /* 判斷根節點是否為NULL */
	{
		puts("No student record!");
		return;
	}
	puts("=====SHOW Inorder DATA=====");
	inorder(root);  /* 以中序法輸出資料 */
}

void show_post(void) /* modified by 蕭老師*/ 
{
	if(root == NULL)  /* 判斷根節點是否為NULL */
	{
		puts("No student record!");
		return;
	}
	puts("=====SHOW Postorder DATA=====");
	postorder(root);  /* 以中序法輸出資料 */
}


void show_preorder(void)/* modified by 蕭老師*/ 
{
	if(root == NULL)  /* 判斷根節點是否為NULL */
	{
		puts("No student record!");
		return;
	}
	puts("=====SHOW Preorder DATA=====");
	preorder1(root);  /* 以中序法輸出資料 */
}


/* 處理二元搜尋樹，將新增資料加入至二元搜尋樹中 */
void access(char name[], int score)
{
	struct student *node, *prev;
	if(search(name) != NULL)  /* 資料已存在則顯示錯誤 */
	{
		printf("Student %s has existed!\n", name);
		return;
	}
	ptr = (struct student *) malloc(sizeof(struct student));
	strcpy(ptr->name, name);
	ptr->score = score;
	ptr->llink = ptr->rlink = NULL;
	if(root == NULL)  /* 當根節點為NULL的狀況 */
		root = ptr;
	else  /* 當根節點不為NULL的狀況 */
	{
		node = root;
		while(node != NULL)  /* 搜尋資料插入點 */
		{
			prev = node;
			if(strcmp(ptr->name, node->name) < 0)
				node = node->llink;
			else
				node = node->rlink;
		}
		if(strcmp(ptr->name, prev->name) < 0)
			prev->llink = ptr;
		else
			prev->rlink = ptr;
	}
}



/* 建立右小左大的二元搜尋樹  modified by 蕭老師*/ 
void access1(char name[], int score)
{
	struct student *node, *prev;
	if(search(name) != NULL)  /* 資料已存在則顯示錯誤 */
	{
		printf("Student %s has existed!\n", name);
		return;
	}
	ptr = (struct student *) malloc(sizeof(struct student));
	strcpy(ptr->name, name);
	ptr->score = score;
	ptr->llink = ptr->rlink = NULL;
	if(root == NULL)  /* 當根節點為NULL的狀況 */
		root = ptr;
	else  /* 當根節點不為NULL的狀況 */
	{
		node = root;
		while(node != NULL)  /* 搜尋資料插入點 */
		{
			prev = node;
			if(strcmp(ptr->name, node->name) < 0)
				node = node->rlink;
			else
				node = node->llink;
		}
		if(strcmp(ptr->name, prev->name) < 0)
			prev->rlink = ptr;
		else
			prev->llink = ptr;
	}
}


/* 將資料從二元搜尋樹中移除 */
void removing(char name[])
{
	struct student *del_node;
	if((del_node = search(name)) == NULL)  /* 找不到資料則顯示錯誤 */
	{
		printf("Student %s not found!\n", name);
		return;
	}
	/* 節點不為樹葉節點的狀況 */
	if(del_node->llink != NULL || del_node->rlink != NULL)
		del_node = replace(del_node);
	else  /* 節點為樹葉節點的狀況 */
		if(del_node == root)
			root = NULL;
		else
			connect(del_node, 'n');
	free(del_node);  /* 釋放記憶體 */
	printf("Data of student %s deleted!\n", name);
}

/* 尋找刪除非樹葉節點的替代節點 */
struct student *replace(struct student *node)
{
	struct student *re_node;
	/* 當右子樹找不到替代節點，會搜尋左子樹是否存在替代節點 */
	if((re_node = search_re_r(node->rlink)) == NULL)
		re_node = search_re_l(node->llink);
	if(re_node->rlink != NULL)  /* 當替代節點有右子樹存在的狀況 */
		connect(re_node, 'r');
	else
		if(re_node->llink != NULL)  /* 當替代節點有左子樹存在的狀況 */
			connect(re_node, 'l');
		else  /* 當替代節點為樹葉節點的狀況 */
			connect(re_node, 'n');
	strcpy(node->name, re_node->name);
	node->score = re_node->score;
	return re_node;
}

/* 調整二元搜尋樹的鏈結，link為r表示處理右鏈結，為l表處理左鏈結，
   為m則將鏈結指向NULL */
void connect(struct student *node, char link)
{
	struct student *parent;
	parent = search_p(node);  /* 搜尋父節點 */
	/* 節點為父節點左子樹的狀況 */
	if(strcmp(node->name, parent->name) < 0)
		if(link == 'r')  /* link為r */
			parent->llink = node->rlink;
		else  /* link為m */
			parent->llink = NULL;
	else  /* 節點為父節點右子樹的狀況 */
		if(link == 'l')  /* link為l */
			parent->rlink = node->llink;
		else  /* link為m */
			parent->rlink = NULL;
}


void postorder(struct student *node)
{
	if(node != NULL)
	{
		postorder(node->llink);		
		postorder(node->rlink);		
		printf("%-10s %d\n", node->name, node->score);
	}
}

void show_total(void)/* modified by 蕭老師*/ 
{
       

	if(root == NULL)  /* 判斷根節點是否為NULL */
	{
		puts("No student record!");
		return;
	}
	puts("=====SHOW Total Node=====\n");
	
    mytotal(root);  
    
	printf("Total node NO. %d,  Total Score:%d, Avg Score:%d \n  ", count, j , j/count);		
}

void  mytotal(struct student *node)  /* modified by 蕭老師*/ 
{
	

	if(node != NULL)
	{
		mytotal(node->llink);	
			count ++;	
			j=j+node->score;
	    mytotal(node->rlink);		
	}
	
	
}


void preorder1(struct student *node)  /* modified by 蕭老師*/ 
{
	if(node != NULL)
	
	{
		
    	printf("%-10s %d\n", node->name, node->score);			
		preorder1(node->llink);				
		preorder1(node->rlink);
		 
	}
}
/* 以前序法將資料寫入檔案，採遞迴方式 */
void preorder(struct student *node, FILE *fptr)
{
	if(node != NULL)
	{
		fprintf(fptr, "%s %d\n", node->name, node->score);
		preorder(node->llink, fptr);
		preorder(node->rlink, fptr);
	}
}

/* 搜尋target所在節點 */
struct student *search(char target[])
{
	struct student *node;
	node = root;
	while(node != NULL)
	{
		if(strcmp(target, node->name) == 0)
			return node;
		else
			/* target小於目前節點，往左搜尋 */
			if(strcmp(target, node->name) < 0)
				node = node->llink;
			else  /* target大於目前節點，往右搜尋 */
				node = node->rlink;
	}
	return node;
}


void mysearch_inorder(void) /* modified by 蕭老師*/ /* 給定一個key, 來顯示其中序排序  由小排到大*/
{
	struct student *subroot;
	
	char name[20];
	
	printf("=====尋找子樹的中序拜訪  由小到大排序===== \n");
	printf("Enter student name: ");
	gets(name);
	subroot = root;
	
	
	while(subroot != NULL)
	{
		if(strcmp(name , subroot->name) == 0)
		break;
		else
			/* target小於目前節點，往左搜尋 */
			if(strcmp(name, subroot->name) < 0)
				subroot = subroot->llink;
			else  /* target大於目前節點，往右搜尋 */
				subroot = subroot->rlink;
	}

	if(subroot == NULL)  /* 判斷根節點是否為NULL */
	{
		printf("No student record!");
	 
	}
	
	printf("=====SHOW %s Subtree Inorder DATA=====\n",subroot->name);
	
	/* 以中序法輸出資料 */
 
	inorder(subroot);
} 

void mysearch_deorder(void) /* modified by 蕭老師*/ /* 給定一個key, 來顯示其中序排序  由大排到小*/
{
	struct student *subroot;
	int i,temp[100];
	char name[20];
	
	printf("=====尋找子樹的中序拜訪  由大到小排序===== \n");
	printf("Enter student name: ");
	gets(name);
	subroot = root;
	
	
	while(subroot != NULL)
	{
		if(strcmp(name , subroot->name) == 0)
		break;
		else
			/* target小於目前節點，往左搜尋 */
			if(strcmp(name, subroot->name) < 0)
				subroot = subroot->llink;
			else  /* target大於目前節點，往右搜尋 */
				subroot = subroot->rlink;
	}

	if(subroot == NULL)  /* 判斷根節點是否為NULL */
	{
		printf("No student record!");
	 
	}
	
	printf("=====SHOW %s Subtree Inorder DATA by decrease=====\n",subroot->name);
	
	
	for (i=1;i<=100;i++)
	    {
	    	d[i]=0;
	    	temp[i]=0;
		}
	
	/* 以中序法輸出資料 */
     j=1;
     
	inorder_decrease(subroot);
	
		/*處理d陣列中的值倒過來*/ 
	i=1;
 
    while (j!=0)
	{
     j--;
	 temp[i]=d[j];

	i++;
    }
		
    i=1	;
    while (temp[i]!=0)
	{
    printf("  %d\n", temp[i]);
 	i++;
    }
}

/* 以中序法輸出資料，採遞迴方式 */
void inorder(struct student *node)
{
	if(node != NULL)
	{
		inorder(node->llink);
		printf("%-10s %d\n", node->name, node->score);
		inorder(node->rlink);
	}
}


void inorder_decrease(struct student *node)/* 由大到小排序  modified by 蕭老師*/
{
	if(node != NULL)
	{
		inorder_decrease(node->llink);
	    d[j]= node->score;  /* 將inoder結果放入d陣列*/ 
	    j++;
		inorder_decrease(node->rlink);
		
	}
}

/* 搜尋右子樹替代節點 */
struct student *search_re_r(struct student *node)
{
 struct student *re_node;
	re_node = node;
	while(re_node != NULL && re_node->llink != NULL)
		re_node = re_node->llink;
	return re_node;
}

/* 搜尋左子樹替代節點 */
struct student *search_re_l(struct student *node)
{
 	struct student *re_node;
	re_node = node;
	while(re_node != NULL && re_node->rlink != NULL)
		re_node = re_node->rlink;
	return re_node;
}


void show_smallest() /* modified by 蕭老師*/ 
{
	struct student *re_node;
	if(root == NULL)  /* 判斷根節點是否為NULL */
	{
		puts("No student record!");
		return;
	}

	re_node = root;
	while(re_node != NULL && re_node->llink != NULL)
		re_node = re_node->llink;
	
	puts("=====SHOW Smallest DATA=====");
	printf("%-10s %d\n", re_node->name, re_node->score);
		
}





void show_bigest() /* modified by 蕭老師*/ 
{
	
	struct student *re_node;
	if(root == NULL)  /* 判斷根節點是否為NULL */
	{
		puts("No student record!");
		return;
	}

	re_node = root;
	while(re_node != NULL && re_node->rlink != NULL)
		re_node = re_node->rlink;
	
	puts("=====SHOW Smallest DATA=====");
	printf("%-10s %d\n", re_node->name, re_node->score);
}


/* 搜尋node的父節點 */
struct student *search_p(struct student *node)
{
	struct student *parent;
	parent = root;
	while(parent != NULL)
	{
		if(strcmp(node->name, parent->name) < 0)
			if(strcmp(node->name, parent->llink->name) == 0)
				return parent;
			else
				parent = parent->llink;
		else
			if(strcmp(node->name, parent->rlink->name) == 0)
				return parent;
			else
				parent = parent->rlink;
	}
	return NULL;
}
