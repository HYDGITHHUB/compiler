#include<stdio.h>
#include<string.h>
char*action[10][3]= {"S3#","S4#",NULL, /*ACTION*/
                     NULL,NULL,"acc",
                     "S6#","S7#",NULL,
                     "S3#","S4#",NULL,
                     "r3#","r3#",NULL,
                     NULL,NULL,"r1#",
                     "S6#","S7#",NULL,
                     NULL,NULL,"r3#",
                     "r2#","r2#",NULL,
                     NULL,NULL,"r2#"
                    };
int goto1[10][2]= {1,2, /*QOTO*/
                   0,0,0,5,0,8,0,0,0,0,0,9,0,0,0,0,
                   0,0
                  };
char vt[3]= {'a','b','#'}; /*��ŷ��ս��*/
char vn[2]= {'S','B'}; /*����ս��*/
char *LR[4]= {"E->S#","S->BB#","B->aB#","B->b#"}; /*��Ų���ʽ*/
int a[10];
char b[10],c[10],c1;
int top1,top2,top3,top,m,n;

int main() {
	int g,h,i,j,k,l,p,y,z,count;
	char x,copy[10],copy1[10];
	top1=0;
	top2=0;
	top3=0;
	top=0;
	a[0]=0;
	y=a[0];
	b[0]='#';
	count=0;
	z=0;
	printf("----------------���������ʽ(��#��β)--------------\n");
	do {
		scanf("%c",&c1);
		c[top3]=c1;
		top3=top3+1;
	} while(c1!='#');
	printf("����\t״̬ջ\t\t����ջ\t\t���봮\t\tACTION\tGOTO\n");
	do {
		y=z;
		m=0;
		n=0; /*y,zָ��״̬ջջ��*/
		g=top;
		j=0;
		k=0;
		x=c[top];
		count++;
		printf("%d\t",count);
		while(m<=top1) { /*���״̬ջ*/
			printf("%d",a[m]);
			m=m+1;
		}
		printf("\t\t");
		while(n<=top2) { /*�������ջ*/
			printf("%c",b[n]);
			n=n+1;
		}
		printf("\t\t");
		while(g<=top3) { /*������봮*/
			printf("%c",c[g]);
			g=g+1;
		}
		printf("\t\t");
		while(x!=vt[j]&&j<=2)j++;
		if(j==2&&x!=vt[j]) {
			printf("error\n");
			return 0;
		}
		if(action[y][j]==NULL) {
			printf("error\n");
			return 0;
		} else
			strcpy(copy,action[y][j]);
		if(copy[0]=='S') {
			/*�����ƽ�*/
			z=copy[1]-'0';
			top1=top1+1;
			top2=top2+1;
			a[top1]=z;
			b[top2]=x;
			top=top+1;
			i=0;
			while(copy[i]!='#') {
				printf("%c",copy[i]);
				i++;
			}
			printf("\n");
		}
		if(copy[0]=='r') {
			/*������Լ*/
			i=0;
			while(copy[i]!='#') {
				printf("%c",copy[i]);
				i++;
			}
			h=copy[1]-'0';

			strcpy(copy1,LR[h]);
			while(copy1[0]!=vn[k])k++;
			l=strlen(LR[h])-4;
			top1=top1-l+1;
			top2=top2-l+1;
			y=a[top1-1];
			p=goto1[y][k];
			a[top1]=p;
			b[top2]=copy1[0];
			z=p;
			printf("\t");
			printf("%d\n",p);
		}
	} while(action[y][j]!="acc");
	printf("acc\n");
	getchar();
}

