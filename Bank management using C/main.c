#include<stdio.h>
#include<stdlib.h>
struct Account
	{	
		char Name[20];
		int accno,date,month,year,balance;
	};

void main()
{    

restart:  //label for goto to restart module
    
	do{  char n;struct Account a;char name[20];int acc,withdraw,deposit;
		
		printf("\n\n\t\t\t\tWelcome Here\n");   				//welcome Note
		getchar();
		printf("\t\t\t\tChoose any Number \n");
		printf("\t\t\t\t1.open account\n");
		printf("\t\t\t\t2.check balance\n");
		printf("\t\t\t\t3.withdraw money\n");
		printf("\t\t\t\t4.Deposit money\n");
		printf("\t\t\t\t5.Admin");
		printf("\n\t\t\t\t6.exit\n\t\t\t\t");
		
		scanf("%c",&n);
		           									
				

	
	
	switch(n)
	{
		case '1':													//open account
		{    FILE * file=NULL;
		     file=fopen("data.txt","ab");
			 
			printf("\n\t\t\t\tEnter your name/user");
			getchar();
			gets(a.Name);
			printf("\n\t\t\t\tEnter date of birth");
			scanf("%d%d%d",&a.date,&a.month,&a.year);
			printf("\n\t\t\t\tEnter start balance amount");
			scanf("%d",&a.balance);
			printf("\n\t\t\t\tEnter Account password (must be integar)");
			scanf("%d",&a.accno);
			fwrite(&a,sizeof(a),1,file);
			fclose(file);
			file=NULL;
			break;
		}
		
		case '2':													//CHECK ACCOUNT
		{	 FILE * file=NULL;
		     file=fopen("data.txt","rb");
				if(file==NULL)
					{	printf("\n\t\t\t\tSData File Missing\n");
						n=6;  //to start again
						goto restart; //restart module
					}
			 printf("\n\t\t\t\tEnter Name to Check account");
			 getchar();
			 gets(name);
			 printf("\n\t\t\t\tEnter account password");
			 scanf("%d",&acc);
			 while (fread(&a,sizeof(a),1,file))
			 {if(acc==a.accno)
				 {
					 printf("\n\t\t\t\tName:%s",a.Name);
					 printf("\n\t\t\t\tDate of birth: %d/%d/%d",a.date,a.month,a.year);
					 printf("\n\t\t\t\tBalance : %d",a.balance);
				 }	
					
			 }
			 
			 fclose(file);
			 file=NULL;
			 break;
		}
		
		case '3':															//withdraw
		{FILE * file=NULL;
		     file=fopen("data.txt","rb+");
				if(file==NULL)
					{	printf("\n\t\t\t\tSData File Missing\n");
						n=6;  //to start again
						goto restart; //restart module
					}
			  printf("\n\t\t\t\tEnter Name to Check account");
			 getchar();
			 gets(name);
			 printf("\n\t\t\t\tEnter account password");
			 scanf("%d",&acc);
			 while (fread(&a,sizeof(a),1,file))
			 {if(acc==a.accno)
				 {
					 printf("\n\t\t\t\tEnter Ammount How much you withdraw");
					 scanf("%d",&withdraw);
					 if(withdraw>a.balance)
						{
							printf("\n\t\t\t\tInsufficent money");
						}
					 else
					
						{	
							a.balance=a.balance-withdraw;
						    printf("\n\t\t\t\tAfter withdraw your money is %d",a.balance);
							fseek(file,-sizeof(a),SEEK_CUR);
							fwrite(&a,sizeof(a),1,file);
							fclose(file);
							file=NULL;	
							break;
							
							
							
							
						}
				 }	
			 }
			 
			 
			 fclose(file);
			 file=NULL;
			 break;
		}	
		
		case '4':
		{FILE * file=NULL;
		     file=fopen("data.txt","rb+");
				if(file==NULL)
					{	printf("\n\t\t\t\tSData File Missing\n");
						n=6;  //to start again
						goto restart; //restart module
					}
			  printf("\n\t\t\t\tEnter Name to Check account");
			 getchar();
			 gets(name);
			 printf("\n\t\t\t\tEnter account password");
			 scanf("%d",&acc);
			 while (fread(&a,sizeof(a),1,file))
			 {if(acc==a.accno)
				 {
					 printf("\n\t\t\t\tEnter Ammount How much you Deposit");
					 scanf("%d",&deposit);
					 a.balance=a.balance+deposit;
						    printf("\n\t\t\t\tAfter deposit your money is %d",a.balance);
							fseek(file,-sizeof(a),SEEK_CUR);
							fwrite(&a,sizeof(a),1,file);
				 }
			 }
							fclose(file);
							file=NULL;
							break;
		}
		
		case '6':
		{
			exit(1);
		}
		case '5' :
		{ int admin;
			printf("\n\t\t\t\tEnter admin password to excess Data base");
			scanf("%d",&admin);
			if(admin==12345)
			{FILE * file=NULL;
		     file=fopen("data.txt","r");
			  while (fread(&a,sizeof(a),1,file))
				{
					 printf("\n\t\t\t\tName:%s",a.Name);
					 printf("\n\t\t\t\tDate of birth: %d/%d/%d",a.date,a.month,a.year);
					 printf("\n\t\t\t\tBalance : %d",a.balance);
					 printf("\n\t\t\t\t---------------");
				}
							fclose(file);
							file=NULL;
							break;
			}
			else
			{	
				printf("\n\t\t\t\tYou Enter Wrong password");
				break;
			}
		
		}			
		
		
		
		
		
		default:
		{
					printf("\n\t\t\t\tInvalid Input enter Again\n\n");
		}
					
	
	}}while(1);
	getch();
	
}