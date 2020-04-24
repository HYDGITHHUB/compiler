#include <stdio.h>
#include <string.h>
 
int syn,p,m,n,sum;
char prog[100],token[8],ch;
char *vessel[5]={"while","if","else","switch","case"};//存放关键字 
 
void screen();
 
main()
{
	p=0;
 	printf("请输入以#结尾的代码:\n");
 	
 	do{
    		scanf("%c",&ch);
    		prog[p++]=ch;
	}while(ch!='#');
 	
 	p=0;
	do{
			screen();
			switch(syn)
	 		{
	 			case 7:
	 				printf("( %d --> %d )\n",sum,syn);//数字 
	      		break;
	      		
	  			case -1:
	  				printf("you have input a wrong string\n");
	      			//getch();
	      			return 0;
	      		break;
	      		
	  			default: 
	  			printf("( %s --> %d )\n",token,syn);
	      		break;
	  		}
    	}while(syn!=0);
    //getch();
 }
 
void screen()
{  
 	sum=0;
	
    for(m=0;m<8;m++)
    	token[m++]= NULL;
	
    	ch=prog[p++];
    	m=0;
		
    while((ch==' ')||(ch=='\n'))
		ch=prog[p++];
	
    if(((ch<='z')&&(ch>='a'))||((ch<='Z')&&(ch>='A')))
     { 
      	while(((ch<='z')&&(ch>='a'))||((ch<='Z')&&(ch>='A'))||((ch>='0')&&(ch<='9')))
      	{
      		token[m++]=ch;
       		ch=prog[p++];
     	}
		
      	p--;
      	syn=6;
	  	for(n=0;n<5;n++)
    	if(strcmp(token,vessel[n])==0)
       	{ 
       		syn=n+1;
        	break;
       	}
     }
	 else if((ch>='0')&&(ch<='9'))
     { 
      	while((ch>='0')&&(ch<='9'))
    	{
    		sum=sum*10+ch-'0';
      		ch=prog[p++];
    	}
    	p--;
   		syn=7;
    }
    else 
    {
		switch(ch)
		{
		case '<':
			token[m++]=ch;
			ch=prog[p++];
			if(ch=='=')
			{ 
				syn=11;
				token[m++]=ch;
			}
			else
			{  
				syn=11;
				p--;
			}
		break;
		case '>':
			token[m++]=ch;
			ch=prog[p++];
			if(ch=='=')
			{
				syn=11;
				token[m++]=ch;
			}
			else
			{ 
				syn=11;
				p--;
			}
		break;
 
		case '+':
			token[m++]=ch;
			ch=prog[p++];
			if(ch=='+')
			{
				syn=8;
				token[m++]=ch;
			}
			else
			{
				syn=8;
				p--;
			}
		break;
 
		case '-':
			token[m++]=ch;
			ch=prog[p++];
			if(ch=='-')
			{
				syn=9;
				token[m++]=ch;
			}
			else
			{ 
				syn=9;
				p--;
			}
		break;
 
		case '=':
			token[m++]=ch;
			ch=prog[p++];
			if(ch=='=')
			{
				syn=12;
				token[m++]=ch;
			}
			else
			{
				syn=12;
				p--;
			}
		break;
 
		case '*':
			syn=10;
			token[m++]=ch;
		break;
 
		case '(': 
			syn=14;
			token[m++]=ch;
		break;
 
		case ')':
			syn=15;
			token[m++]=ch;
		break;
 
		case '{': 
			syn=16;
			token[m++]=ch;
		break;
 
		case '}': 
			syn=17;
			token[m++]=ch;
		break;
 
		case ';':
			syn=13;
			token[m++]=ch;
		break;
 
		case '#': 
			syn=0;
			token[m++]=ch;
		break;
 
		case ':':
			syn=18;
			token[m++]=ch;
		break;
 
		}
	}
    	token[m++]='\0';
}
 
 
