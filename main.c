#include"main.h"

employee_data *head=NULL,*temp=NULL;
void read_database();
void view_employee_details();

void main(void)
{
	//void (*fp[4])()={add_employee_details,view_employee_details,modify_employee_details,delete_employee_details};
	//char option;
	//int flag=0;
	//while(1)
	//{
		//printf("Please select below option\n");
		//printf("1.Add\n2.View\n3.Modify\n4.Delete\n*.Exit\n");
		//scanf("%c",&option);
		/*switch(option)
		{
			case '1':  read_database();
				   fp[0]();
				   write_database();
				   break;
				   
			case '2':  read_database();
				   fp[1]();
				   write_database();
				   break;
				   
			case '3':  read_database();
				   fp[2]();
				   write_database();
				   break;
				   
			case '4':  read_database();
			           fp[3]();
			           write_database();
				   break;
		        case '*': printf("Exiting from the Application\n");
		        	   exit(0);
		        default: flag++;
		        	  if(flag==1)
		        	  {
		        	  	printf("Invalid option you have three chances enter again\n");
		        	  }
		        	  if(flag==2)
		        	  {
		        	  	printf("Invalid option you have two chances enter again\n");
		        	  }
		        	  if(flag==3)
		        	  {
		        	  	printf("Invalid option you have one chances enter again\n");
		        	  }
		        	  if(flag==4)
		        	  {
		        	  	printf("Exiting from application\n");
		        	  }
		}*/
	//}
	read_database();
//	add_employee_details();
	view_employee_details();

}

//employee_data *head=NULL,*temp=NULL;

void read_database()
{

	char ch;
	char read_buffer[SIZE];
	int i=0,flag=0;
	employee_data *new_node=NULL;

	FILE *read_fp;
	read_fp=fopen("TS_Employees_Data.xlsx","r");
	if(read_fp==NULL)
	{
		printf("File cannot opened Successfully\n");
	}
	else
	{
		while((ch=getc(read_fp))!=EOF)
		{
			read_buffer[i++]=ch;
			new_node=(employee_data *)malloc(sizeof(employee_data));
			while((ch=getc(read_fp))!='\n')
			{
				if((ch==','))
				{
					i=0;
					flag++;
					if(flag==1)
					{
						strcpy(new_node->EMP_ID,read_buffer);
						memset(read_buffer,'\0',sizeof(read_buffer));
					}
					if(flag==2)
					{
						strcpy(new_node->Name,read_buffer);
						memset(read_buffer,'\0',sizeof(read_buffer));
					}
					if(flag==3)
					{
						new_node->GENDER=read_buffer[0];
						memset(read_buffer,'\0',sizeof(read_buffer));
					}
					if(flag==4)
					{
						strcpy(new_node->EMAIL_ID,read_buffer);
						memset(read_buffer,'\0',sizeof(read_buffer));
					}
					if(flag==5)
					{
						strcpy(new_node->Band,read_buffer);
						memset(read_buffer,'\0',sizeof(read_buffer));
					}
					if(flag==6)
					{
						strcpy(new_node->DOJ,read_buffer);
						memset(read_buffer,'\0',sizeof(read_buffer));
					}
					if(flag==7)
					{
						strcpy(new_node->Contact_No,read_buffer);
						memset(read_buffer,'\0',sizeof(read_buffer));
					}
					if(flag==8)
					{
						strcpy(new_node->Reporting_Manager,read_buffer);
						memset(read_buffer,'\0',sizeof(read_buffer));
					}
					if(flag==9)
					{
						strcpy(new_node->Tech_area,read_buffer);
						memset(read_buffer,'\0',sizeof(read_buffer));
					}
					if(flag==10)
					{
						strcpy(new_node->Project_info,read_buffer);
						memset(read_buffer,'\0',sizeof(read_buffer));
					}
					if(flag==11)
					{
						strcpy(new_node->Status,read_buffer);
						memset(read_buffer,'\0',sizeof(read_buffer));
						flag=0;
					}
				}
				else
				{
					read_buffer[i++]=ch;
				}

			}
			new_node->link=NULL;

			if(head==NULL)
			{
				head=temp=new_node;
			}
			else
			{
				temp->link=new_node;
				temp=new_node;
			}
		}
	}
	free(new_node);
	fclose(read_fp);
}


void Display()
{
	employee_data *new=head;
	if(new==NULL)
	{
			
	}
	while(new!=NULL)
	{

	}
}
char id0[20];
void view_employee_details()
{
	printf("enter id0\n");
	fgets(id0,20,stdin);
	employee_data *new=head;
	new=malloc(sizeof(employee_data));
	while((new->link)!=NULL)
	{
		printf("hi\n");
		if(strcmp(new->EMP_ID,id0)==0)
		{
			printf("hii\n");
			printf("EMP_ID:\t%s\nName:\t%s\nGender:\t%c\nEMAIL_ID:\t%s\nBAnd:\t%s\nDOJ:\t%s\nContact_No:\t%s\nReporting Manager:\t%s\nTech_Area:\t%s\nProject_Info:\t%s\nStatus:\t%s\n\n",new->EMP_ID,new->Name,new->GENDER,new->EMAIL_ID,new->Band,new->DOJ,new->Contact_No,new->Reporting_Manager,new->Tech_area,new->Project_info,new->Status);
		}
		new=new->link;

	}
}


