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

//char id[20];
void Display(employee_data **);//display function for local data base
//void write_xl(employee_data **);
//void view_employee_details(employee_data **);
void dd(employee_data **head);
void *display_th1();
employee_data *head=NULL;
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
	//view_employee_details(&head);
	dd(&head);
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

void dd(employee_data **head)
{
	employee_data *temp=*head;
	//printf("Enter the employee ID\n");
	//scanf("%s",&id[0]);
	pthread_t th[3];
	pthread_create(&th[0],NULL,&display_th1,NULL);
//	pthread_create(&th[1],NULL,display_th2,id[0]);
	
	pthread_join(th[0],NULL);
//	pthread_join(th[1],NULL);


}
void *display_th1()
{
	char id[20];
        printf("enter id\n");
        scanf("%s",id);
        employee_data *new=head;
        //new=malloc(sizeof(employee_data));
        while(new!=NULL)
        {
                //printf("hi\n");
                if(strcmp(new->EMP_ID,id)==0)
                {
                        //printf("Employee ID is not present in the list\n");
                        //printf("hii\n");
                        printf("EMP_ID:\t%s\nName:\t%s\nGender:\t%c\nEMAIL_ID:\t%s\nBAnd:\t%s\nDOJ:\t%s\nContact_No:\t%s\nReporting Manager:\t%s\nTech_Area:\t%s\nProject_Info:\t%s\nStatus:\t%s\n\n",new->EMP_ID,new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager,new->Tech_area,new->Project_info,new->Status);
                        break;
                }
               /* else
                	printf("hii\n");
                        printf("EMP_ID:\t%s\nName:\t%s\nGender:\t%c\nEMAIL_ID:\t%s\nBAnd:\t%s\nDOJ:\t%s\nContact_No:\t%s\nReporting Manager:\t%s\nTech_Area:\t%s\nProject_Info:\t%s\nStatus:\t%s\n\n",new->EMP_ID,new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager,new->Tech_area,new->Project_info,new->Status);
                        break;
                }*/
                new=new->link;
        }
 }


/*void write_xl(employee_data **head)
{
	
	employee_data *new=(*head);
	FILE *fp;
	fp=fopen("Record1.xlsx","r+");
	if(fp==NULL)
	printf("failed to open the file :\n");
//	int count=0;
	if(new==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(new!=NULL)
		{
			fprintf(fp,"%s,%s,%c,%s,%s,%s,%s,%s,%s,%s,%s\n",new->EMP_ID,new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager,new->Tech_area,new->Project_info,new->Status);
			new=new->link;
//			count++;
		}
	//	printf("count:%d\n",count);
	}
}
*/
