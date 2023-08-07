/* file name: bin_search_tree.c */
/* �Q�ΤG���j�M��B�z��ơи��J�B�x�s�B�s�W�B�R���B�ק�B��X */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/* �w�qstudent���c */
struct student {
	char name[20];  /* �ǥͩm�W */
	int score;  /* �ǥͦ��Z */
	struct student *llink;  /* ���l�쵲 */
	struct student *rlink;  /* �k�l�쵲 */
};

int d[100],j ,count=0;
void load_f(void);      /* ���J��� */
void save_f(void);      /* �x�s��� */
void insert_f(void);    /* �s�W��� */
void delete_f(void);    /* �R����� */
void modify_f(void);    /* �ק��� */
void show_f(void);  
void show_post(void);    /* ��X��� */
void show_preorder(void);
void access(char [], int);  /* �N��ƥ[�J�G���j�M�� */
void removing(char []);  /* �N��Ʊq�G���j�M�𤤲��� */
struct student *replace(struct student *);  /* �M����N�`�I */
void connect(struct student *, char);  /* �վ��쵲 */
void inorder(struct student *);  /* ��ƥH���Ǫk��X */
void preorder(struct student *, FILE *);  /* ��ƥH�e�Ǫk�g�J�ɮ� */
void postorder(struct student *); /* ��ƥH��Ǫk��X */
void preorder1(struct student *); /* ��ƥH�e�Ǫk���*/
void inorder_decrease(struct student *);/* modified by ���Ѯv*/ 
void show_smallest(void); /* modified by ���Ѯv*/ 
void access1(char [], int);/* modified by ���Ѯv*/ 
void show_bigest(void); /* modified by ���Ѯv*/ 
void mysearch_inorder(void);/* modified by ���Ѯv*/ 
void mysearch_deorder(void);/* modified by ���Ѯv*/ 
void show_total(void);/* modified by ���Ѯv*/ 
void mytotal(struct student *);
struct student *search(char []);  /* �j�M�`�I */
struct student *search_re_r(struct student *);  /* �j�M�k�l����N�`�I */
struct student *search_re_l(struct student *);  /* �j�M���l����N�`�I */
struct student *search_p(struct student *);  /* �j�M���`�I */

struct student *root,*root1, *ptr; 

int main(void)
{
	char option;
	load_f();  /* ���J�ɮ� */
	while(1)
	{
		puts("");
		puts("********************");
		puts("     <1> insert");
		puts("     <2> delete");
		puts("     <3> modify");
		puts("     <4> show-all-increase");
		puts("     <5> quit");
		puts("     <6> show post-order");/* modified by ���Ѯv*/ 
	    puts("     <7> show pre-order");/* modified by ���Ѯv*/ 
	    puts("     <8> show smallest");/* modified by ���Ѯv*/ 
	    puts("     <9> show  bigest");/* modified by ���Ѯv*/ 
	    puts("     <p> show  subtree-indoer");/* modified by ���Ѯv*/ 
	    puts("     <d> show  show-all-decrease ");/* modified by ���Ѯv*/ 
	    puts("     <t> show total ");/* modified by ���Ѯv*/ 
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
				save_f();  /* �x�s�ɮ� */
				exit(0);
			case '6':
				show_post();/* modified by ���Ѯv*/ 
				break;
			case '7':
				show_preorder(); /* modified by ���Ѯv*/ 
				break;
			case '8':
				show_smallest();/* modified by ���Ѯv*/ 
				break;
			case '9':
				show_bigest();/* modified by ���Ѯv*/ 
				break;
			case 'p':
				mysearch_inorder();/* modified by ���Ѯv*/ 
				break;
			case 'd':
			    mysearch_deorder();/* modified by ���Ѯv*/ 
				break;
			case 't':
		       count=0;
		       j=0;
				show_total();/* modified by ���Ѯv*/ 
				break;
			default :
				puts("Wrong option!");
		}
	}
	system("PAUSE");
	return 0;
}

/* ���J��ơA�N�����dfile.dat���J��{���� */
void load_f(void)
{
	FILE *fptr;
	char name[20];
	int score;
	printf("File loading...");
	if((fptr = fopen("bst.dat", "r")) == NULL)  /* �}���ɮ� */
	{
		puts("failed!");
		puts("Dfile.dat not found!");
		return;
	}
	while(fscanf(fptr, "%s %d", name, &score) != EOF)  /* Ū���ɮ׸�� */
		if(strcmp(name, "") != 0)
		 {
			access(name, score); 
		/*	accesss1(name, score);  */  /*�إߥk�p���j���G���j�M��  modified by ���Ѯv*/ 
		}
	puts("OK!");
	fclose(fptr);  /* �����ɮ� */
}

/* �x�s�ɮסA�N�G���j�M�𤤪�����x�s�ܸ����dfile.dat�� */
void save_f(void)
{
	FILE *fptr;
	printf("File saving...");
	if((fptr = fopen("bst.dat", "w")) == NULL)  /* �}���ɮ� */
	{
		puts("failed!");
		return;
	}
	preorder(root, fptr);  /* �H�e�Ǫk�g�J */
	puts("OK!");
	fclose(fptr);  /* �����ɮ� */
}

/* �s�W��ơA�s�W�@���s����� */
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

/* �R����ơA�N��Ʊq�G���j�M�𤤧R�� */
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

/* �ק��ơA�ק�ǥͦ��Z */
void modify_f(void)
{
	struct student *node;
	char name[20], temp[4];
	if(root == NULL)  /* �P�_�ڸ`�I�O�_��NULL */
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
		/* �C�X���ƪ��p */
		printf("Original student name: %s\n", node->name);
		printf("Original student score: %d\n", node->score);
		printf("Enter new score: ");
		gets(temp);
		node->score = atoi(temp);
		printf("Data of student %s modified\n", name);
	}
}

/* ��X��ơA�N��ƿ�X�ܿù� */
void show_f(void)
{
	if(root == NULL)  /* �P�_�ڸ`�I�O�_��NULL */
	{
		puts("No student record!");
		return;
	}
	puts("=====SHOW Inorder DATA=====");
	inorder(root);  /* �H���Ǫk��X��� */
}

void show_post(void) /* modified by ���Ѯv*/ 
{
	if(root == NULL)  /* �P�_�ڸ`�I�O�_��NULL */
	{
		puts("No student record!");
		return;
	}
	puts("=====SHOW Postorder DATA=====");
	postorder(root);  /* �H���Ǫk��X��� */
}


void show_preorder(void)/* modified by ���Ѯv*/ 
{
	if(root == NULL)  /* �P�_�ڸ`�I�O�_��NULL */
	{
		puts("No student record!");
		return;
	}
	puts("=====SHOW Preorder DATA=====");
	preorder1(root);  /* �H���Ǫk��X��� */
}


/* �B�z�G���j�M��A�N�s�W��ƥ[�J�ܤG���j�M�� */
void access(char name[], int score)
{
	struct student *node, *prev;
	if(search(name) != NULL)  /* ��Ƥw�s�b�h��ܿ��~ */
	{
		printf("Student %s has existed!\n", name);
		return;
	}
	ptr = (struct student *) malloc(sizeof(struct student));
	strcpy(ptr->name, name);
	ptr->score = score;
	ptr->llink = ptr->rlink = NULL;
	if(root == NULL)  /* ��ڸ`�I��NULL�����p */
		root = ptr;
	else  /* ��ڸ`�I����NULL�����p */
	{
		node = root;
		while(node != NULL)  /* �j�M��ƴ��J�I */
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



/* �إߥk�p���j���G���j�M��  modified by ���Ѯv*/ 
void access1(char name[], int score)
{
	struct student *node, *prev;
	if(search(name) != NULL)  /* ��Ƥw�s�b�h��ܿ��~ */
	{
		printf("Student %s has existed!\n", name);
		return;
	}
	ptr = (struct student *) malloc(sizeof(struct student));
	strcpy(ptr->name, name);
	ptr->score = score;
	ptr->llink = ptr->rlink = NULL;
	if(root == NULL)  /* ��ڸ`�I��NULL�����p */
		root = ptr;
	else  /* ��ڸ`�I����NULL�����p */
	{
		node = root;
		while(node != NULL)  /* �j�M��ƴ��J�I */
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


/* �N��Ʊq�G���j�M�𤤲��� */
void removing(char name[])
{
	struct student *del_node;
	if((del_node = search(name)) == NULL)  /* �䤣���ƫh��ܿ��~ */
	{
		printf("Student %s not found!\n", name);
		return;
	}
	/* �`�I�����𸭸`�I�����p */
	if(del_node->llink != NULL || del_node->rlink != NULL)
		del_node = replace(del_node);
	else  /* �`�I���𸭸`�I�����p */
		if(del_node == root)
			root = NULL;
		else
			connect(del_node, 'n');
	free(del_node);  /* ����O���� */
	printf("Data of student %s deleted!\n", name);
}

/* �M��R���D�𸭸`�I�����N�`�I */
struct student *replace(struct student *node)
{
	struct student *re_node;
	/* ��k�l��䤣����N�`�I�A�|�j�M���l��O�_�s�b���N�`�I */
	if((re_node = search_re_r(node->rlink)) == NULL)
		re_node = search_re_l(node->llink);
	if(re_node->rlink != NULL)  /* ����N�`�I���k�l��s�b�����p */
		connect(re_node, 'r');
	else
		if(re_node->llink != NULL)  /* ����N�`�I�����l��s�b�����p */
			connect(re_node, 'l');
		else  /* ����N�`�I���𸭸`�I�����p */
			connect(re_node, 'n');
	strcpy(node->name, re_node->name);
	node->score = re_node->score;
	return re_node;
}

/* �վ�G���j�M���쵲�Alink��r��ܳB�z�k�쵲�A��l��B�z���쵲�A
   ��m�h�N�쵲���VNULL */
void connect(struct student *node, char link)
{
	struct student *parent;
	parent = search_p(node);  /* �j�M���`�I */
	/* �`�I�����`�I���l�𪺪��p */
	if(strcmp(node->name, parent->name) < 0)
		if(link == 'r')  /* link��r */
			parent->llink = node->rlink;
		else  /* link��m */
			parent->llink = NULL;
	else  /* �`�I�����`�I�k�l�𪺪��p */
		if(link == 'l')  /* link��l */
			parent->rlink = node->llink;
		else  /* link��m */
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

void show_total(void)/* modified by ���Ѯv*/ 
{
       

	if(root == NULL)  /* �P�_�ڸ`�I�O�_��NULL */
	{
		puts("No student record!");
		return;
	}
	puts("=====SHOW Total Node=====\n");
	
    mytotal(root);  
    
	printf("Total node NO. %d,  Total Score:%d, Avg Score:%d \n  ", count, j , j/count);		
}

void  mytotal(struct student *node)  /* modified by ���Ѯv*/ 
{
	

	if(node != NULL)
	{
		mytotal(node->llink);	
			count ++;	
			j=j+node->score;
	    mytotal(node->rlink);		
	}
	
	
}


void preorder1(struct student *node)  /* modified by ���Ѯv*/ 
{
	if(node != NULL)
	
	{
		
    	printf("%-10s %d\n", node->name, node->score);			
		preorder1(node->llink);				
		preorder1(node->rlink);
		 
	}
}
/* �H�e�Ǫk�N��Ƽg�J�ɮסA�Ļ��j�覡 */
void preorder(struct student *node, FILE *fptr)
{
	if(node != NULL)
	{
		fprintf(fptr, "%s %d\n", node->name, node->score);
		preorder(node->llink, fptr);
		preorder(node->rlink, fptr);
	}
}

/* �j�Mtarget�Ҧb�`�I */
struct student *search(char target[])
{
	struct student *node;
	node = root;
	while(node != NULL)
	{
		if(strcmp(target, node->name) == 0)
			return node;
		else
			/* target�p��ثe�`�I�A�����j�M */
			if(strcmp(target, node->name) < 0)
				node = node->llink;
			else  /* target�j��ثe�`�I�A���k�j�M */
				node = node->rlink;
	}
	return node;
}


void mysearch_inorder(void) /* modified by ���Ѯv*/ /* ���w�@��key, ����ܨ䤤�ǱƧ�  �Ѥp�ƨ�j*/
{
	struct student *subroot;
	
	char name[20];
	
	printf("=====�M��l�𪺤��ǫ��X  �Ѥp��j�Ƨ�===== \n");
	printf("Enter student name: ");
	gets(name);
	subroot = root;
	
	
	while(subroot != NULL)
	{
		if(strcmp(name , subroot->name) == 0)
		break;
		else
			/* target�p��ثe�`�I�A�����j�M */
			if(strcmp(name, subroot->name) < 0)
				subroot = subroot->llink;
			else  /* target�j��ثe�`�I�A���k�j�M */
				subroot = subroot->rlink;
	}

	if(subroot == NULL)  /* �P�_�ڸ`�I�O�_��NULL */
	{
		printf("No student record!");
	 
	}
	
	printf("=====SHOW %s Subtree Inorder DATA=====\n",subroot->name);
	
	/* �H���Ǫk��X��� */
 
	inorder(subroot);
} 

void mysearch_deorder(void) /* modified by ���Ѯv*/ /* ���w�@��key, ����ܨ䤤�ǱƧ�  �Ѥj�ƨ�p*/
{
	struct student *subroot;
	int i,temp[100];
	char name[20];
	
	printf("=====�M��l�𪺤��ǫ��X  �Ѥj��p�Ƨ�===== \n");
	printf("Enter student name: ");
	gets(name);
	subroot = root;
	
	
	while(subroot != NULL)
	{
		if(strcmp(name , subroot->name) == 0)
		break;
		else
			/* target�p��ثe�`�I�A�����j�M */
			if(strcmp(name, subroot->name) < 0)
				subroot = subroot->llink;
			else  /* target�j��ثe�`�I�A���k�j�M */
				subroot = subroot->rlink;
	}

	if(subroot == NULL)  /* �P�_�ڸ`�I�O�_��NULL */
	{
		printf("No student record!");
	 
	}
	
	printf("=====SHOW %s Subtree Inorder DATA by decrease=====\n",subroot->name);
	
	
	for (i=1;i<=100;i++)
	    {
	    	d[i]=0;
	    	temp[i]=0;
		}
	
	/* �H���Ǫk��X��� */
     j=1;
     
	inorder_decrease(subroot);
	
		/*�B�zd�}�C�����ȭ˹L��*/ 
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

/* �H���Ǫk��X��ơA�Ļ��j�覡 */
void inorder(struct student *node)
{
	if(node != NULL)
	{
		inorder(node->llink);
		printf("%-10s %d\n", node->name, node->score);
		inorder(node->rlink);
	}
}


void inorder_decrease(struct student *node)/* �Ѥj��p�Ƨ�  modified by ���Ѯv*/
{
	if(node != NULL)
	{
		inorder_decrease(node->llink);
	    d[j]= node->score;  /* �Ninoder���G��Jd�}�C*/ 
	    j++;
		inorder_decrease(node->rlink);
		
	}
}

/* �j�M�k�l����N�`�I */
struct student *search_re_r(struct student *node)
{
 struct student *re_node;
	re_node = node;
	while(re_node != NULL && re_node->llink != NULL)
		re_node = re_node->llink;
	return re_node;
}

/* �j�M���l����N�`�I */
struct student *search_re_l(struct student *node)
{
 	struct student *re_node;
	re_node = node;
	while(re_node != NULL && re_node->rlink != NULL)
		re_node = re_node->rlink;
	return re_node;
}


void show_smallest() /* modified by ���Ѯv*/ 
{
	struct student *re_node;
	if(root == NULL)  /* �P�_�ڸ`�I�O�_��NULL */
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





void show_bigest() /* modified by ���Ѯv*/ 
{
	
	struct student *re_node;
	if(root == NULL)  /* �P�_�ڸ`�I�O�_��NULL */
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


/* �j�Mnode�����`�I */
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
