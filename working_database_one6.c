#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>


#define SIZE 500

/*..............Global Employee Detail Structure.............*/
typedef struct data
{
	char EMP_ID[SIZE];
	char Name[SIZE];
	char GENDER;
	char EMAIL_ID[SIZE];
	char Band[SIZE];
	char DOJ[SIZE];
	char Contact_No[SIZE];
	char Reporting_Manager[SIZE];
	char Tech_area[SIZE];
	char Project_info[SIZE];
	char Status[SIZE];
	struct data *link;
}employee_data;
void res();
void manager();
void reporties();
char s[20];
void Display(employee_data **);//display function for local data base
//void write_xl(employee_data **);
//void view_employee_details(employee_data **);
void dd(employee_data **head);
//void *display_th1();
employee_data *head=NULL;
char emp_id[20];
char id0[20];
char id1[20];
char id2[20];
pthread_mutex_t lock;
void res()
{
	char w[20]="Active";
	employee_data *temp=head,*t=head,*k=head,*new=head;
	while((temp->link)!=NULL)
	{
		if(strcmp(t->EMP_ID,emp_id)==0)
		{
			if(strcmp(k->Status,w)==0)
			{
				printf("EMP_ID:\t%s\nName:\t%s\nGender:\t%c\nEMAIL_ID:\t%s\nBAnd:\t%s\nDOJ:\t%s\nContact_No:\t%s\nReporting Manager:\t%s\nTech_Area:\t%s\nProject_Info:\t%s\nStatus:\t%s\n\n",new->EMP_ID,new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager,new->Tech_area,new->Project_info,new->Status);
				break;
			}
			else
				printf("RESIGNED\n");
		}

		temp=temp->link;
		t=t->link;
		k=k->link;
		new=new->link;
	}

}
void reporties()
{
	int k;
	employee_data *new=head,*n=head,*t=head;
	strcpy(s,new->Reporting_Manager);
	printf("%s\n",new->Reporting_Manager);
	k=strlen(s);
	printf("%d\n",k);
	/*while((new->link)!=NULL)
	  {
	  if(strcmp(n->EMP_ID,emp_id)==0)
	  {
	  strcpy(s,t->Name);
	  printf("%s\n",s);
	  manager();
	  }
	  new=new->link;
	  n=n->link;
	  t=t->link;
	  }
	  }*/

	/*void manager()
	  {

	  employee_data *new=head,*w=head,*n=head;;
	  while((new->link)!=NULL)
	  {

	  if(strcmp(w->Reporting_Manager,s)==0)
	  {
	  printf("%s",n->EMP_ID);
	  }
	  }*/
	  }
void *display1(void *p)
{
	pthread_mutex_lock(&lock);
	printf("enter id1 to display\n");
	scanf("%s",id0);
	strcpy(emp_id,id0);
	employee_data *new=head;
	while(new!=NULL)
	{
		//printf("hi\n");
		if(strcmp(new->EMP_ID,id0)==0)
		{
			//printf("Employee ID is not present in the list\n");
			//printf("hii\n");
			printf("EMP_ID:\t%s\nName:\t%s\nGender:\t%c\nEMAIL_ID:\t%s\nBAnd:\t%s\nDOJ:\t%s\nContact_No:\t%s\nReporting Manager:\t%s\nTech_Area:\t%s\nProject_Info:\t%s\nStatus:\t%s\n\n",new->EMP_ID,new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager,new->Tech_area,new->Project_info,new->Status);
			break;
		}
		new=new->link;
	}
	res();
	reporties();
	pthread_mutex_unlock(&lock);
}
/*
   void *display2(void *p)
   {
   pthread_mutex_lock(&lock);
   printf("enter id2 to display\n");
   scanf("%s",id1);
   strcpy(emp_id,id1);
   employee_data *new=head;
   if(strcmp(id0,id1)==0)
   {
   printf("data already enterd\n");
//pthread_exit(NULL);
}
else
{
while(new!=NULL)
{
//printf("hi\n");
if(strcmp(new->EMP_ID,id1)==0)
{
//printf("Employee ID is not present in the list\n");
//printf("hii\n");
printf("EMP_ID:\t%s\nName:\t%s\nGender:\t%c\nEMAIL_ID:\t%s\nBAnd:\t%s\nDOJ:\t%s\nContact_No:\t%s\nReporting Manager:\t%s\nTech_Area:\t%s\nProject_Info:\t%s\nStatus:\t%s\n\n",new->EMP_ID,new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager,new->Tech_area,new->Project_info,new->Status);
break;
}
new=new->link;
}
}
res();
pthread_mutex_unlock(&lock);
}

void *display3(void *p)
{
pthread_mutex_lock(&lock);
printf("enter id3 to display\n");
scanf("%s",id2);
strcpy(emp_id,id2);
employee_data *new=head;
if(strcmp(id2,id1)==0)
{
printf("data already enterd\n");
//pthread_exit(NULL);
}
else if(strcmp(id2,id0)==0)
{
printf("data already enterd\n");
// pthread_exit(NULL);
}
else
{
while(new!=NULL)
{
if(strcmp(new->EMP_ID,id2)==0)
{
//printf("Employee ID is not present in the list\n");
//printf("hii\n");
printf("EMP_ID:\t%s\nName:\t%s\nGender:\t%c\nEMAIL_ID:\t%s\nBAnd:\t%s\nDOJ:\t%s\nContact_No:\t%s\nReporting Manager:\t%s\nTech_Area:\t%s\nProject_Info:\t%s\nStatus:\t%s\n\n",new->EMP_ID,new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager,new->Tech_area,new->Project_info,new->Status);
break;
}
new=new->link;
}
}
res();
pthread_mutex_unlock(&lock);
}
*/

void main()
{

	char ch;
	char test_data[SIZE];//char buffer for temporarily store the data
	int i=0,flag=0,k=0;
	/********** Linked list variables ***********/
	employee_data *new=NULL;
	//employee_data *head=NULL;
	employee_data *temp=NULL;

	FILE *fp;			//file pointer
	fp=fopen("TS_Employees_Data.xlsx","r");//open xl file in read mode
	if(fp==NULL)
	{
		printf("File cannot opened Successfully\n");
	}
	else
	{
		while((ch=getc(fp))!=EOF)//reading the xl file data byte by byte till end of file
		{
			test_data[i++]=ch;		//storing the data in a char cuffer
			new=(employee_data *)malloc(sizeof(employee_data));// dynamic memory allocate for structure
			while((ch=getc(fp))!='\n')//reading the data till new line
			{
				if((ch==','))//checking the comma for seperaing the daat
				{
					i=0;
					flag++;
					if(flag==1)
					{
						strcpy(new->EMP_ID,test_data);
						memset(test_data,'\0',sizeof(test_data));
					}
					if(flag==2)
					{
						strcpy(new->Name,test_data);
						memset(test_data,'\0',sizeof(test_data));
					}
					if(flag==3)
					{
						new->GENDER=test_data[0];
						memset(test_data,'\0',sizeof(test_data));
					}
					if(flag==4)
					{
						strcpy(new->EMAIL_ID,test_data);
						memset(test_data,'\0',sizeof(test_data));
					}
					if(flag==5)
					{
						strcpy(new->Band,test_data);
						memset(test_data,'\0',sizeof(test_data));
					}
					if(flag==6)
					{
						strcpy(new->DOJ,test_data);
						memset(test_data,'\0',sizeof(test_data));
					}
					if(flag==7)
					{
						strcpy(new->Contact_No,test_data);
						memset(test_data,'\0',sizeof(test_data));
					}
					if(flag==8)
					{
						strcpy(new->Reporting_Manager,test_data);
						memset(test_data,'\0',sizeof(test_data));
					}
					if(flag==9)
					{
						strcpy(new->Tech_area,test_data);
						memset(test_data,'\0',sizeof(test_data));
					}
					if(flag==10)
					{
						strcpy(new->Project_info,test_data);
						memset(test_data,'\0',sizeof(test_data));
					}
					if(flag==11)
					{
						strcpy(new->Status,test_data);
						memset(test_data,'\0',sizeof(test_data));
						flag=0;
					}
				}
				else
				{
					test_data[i++]=ch;
				}

			}
			new->link=NULL;

			if(head==NULL)
			{
				head=temp=new;
			}
			else
			{
				temp->link=new;
				temp=new;
			}


		}
	}
	Display(&head);
	//display1();
	pthread_t th[3];
	pthread_create(&th[0],NULL,display1,NULL);
	//	pthread_create(&th[1],NULL,display2,NULL);
	//	pthread_create(&th[2],NULL,display3,NULL);
	pthread_join(th[0],NULL);
	//	pthread_join(th[1],NULL);
	//	pthread_join(th[2],NULL);
	//display2();
	//display3();
	//view_employee_details(&head);
	//dd(&head);
	//write_xl(&head);
	free(new);	

	fclose(fp);
}

void Display(employee_data **head)
{
	employee_data *new=(*head);
	int count=0;
	if(new==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(new!=NULL)
		{
			printf("EMP_ID:\t%s\nName:\t%s\nGender:\t%c\nEMAIL_ID:\t%s\nBAnd:\t%s\nDOJ:\t%s\nContact_No:\t%s\nReporting Manager:\t%s\nTech_Area:\t%s\nProject_Info:\t%s\nStatus:\t%s\n\n",new->EMP_ID,new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager,new->Tech_area,new->Project_info,new->Status);
			new=new->link;
			count++;
		}
		printf("count:%d\n",count);
	}
}
/*
   void *display1(void *p)
   {
   char id0[20];
   printf("enter id\n");
   scanf("%s",id0);
   employee_data *new=head;
//new=malloc(sizeof(employee_data));
while(new!=NULL)
{
//printf("hi\n");
if(strcmp(new->EMP_ID,id0)==0)
{
//printf("Employee ID is not present in the list\n");
//printf("hii\n");
printf("EMP_ID:\t%s\nName:\t%s\nGender:\t%c\nEMAIL_ID:\t%s\nBAnd:\t%s\nDOJ:\t%s\nContact_No:\t%s\nReporting Manager:\t%s\nTech_Area:\t%s\nProject_Info:\t%s\nStatus:\t%s\n\n",new->EMP_ID,new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager,new->Tech_area,new->Project_info,new->Status);
break;
}
new=new->link;
}
}
*/
/*void display2()
  {
  char id0[20];
  printf("enter id\n");
  scanf("%s",id0);
  employee_data *new=head;
//new=malloc(sizeof(employee_data));
while(new!=NULL)
{
//printf("hi\n");
if(strcmp(new->EMP_ID,id0)==0)
{
//printf("Employee ID is not present in the list\n");
//printf("hii\n");
printf("EMP_ID:\t%s\nName:\t%s\nGender:\t%c\nEMAIL_ID:\t%s\nBAnd:\t%s\nDOJ:\t%s\nContact_No:\t%s\nReporting Manager:\t%s\nTech_Area:\t%s\nProject_Info:\t%s\nStatus:\t%s\n\n",new->EMP_ID,new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager,new->Tech_area,new->Project_info,new->Status);
break;
}
new=new->link;
}
}


void display3()
{
char id0[20];
printf("enter id\n");
scanf("%s",id0);
employee_data *new=head;
//new=malloc(sizeof(employee_data));
while(new!=NULL)
{
//printf("hi\n");
if(strcmp(new->EMP_ID,id0)==0)
{
//printf("Employee ID is not present in the list\n");
//printf("hii\n");
printf("EMP_ID:\t%s\nName:\t%s\nGender:\t%c\nEMAIL_ID:\t%s\nBAnd:\t%s\nDOJ:\t%s\nContact_No:\t%s\nReporting Manager:\t%s\nTech_Area:\t%s\nProject_Info:\t%s\nStatus:\t%s\n\n",new->EMP_ID,new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager,new->Tech_area,new->Project_info,new->Status);
break;
}
new=new->link;
}
}*/
