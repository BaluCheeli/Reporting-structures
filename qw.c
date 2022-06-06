#include"TSindia_Emp_DB.h"

employee_data *head=NULL,*temp=NULL;

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

void write_database()
{
	
	employee_data *node=head;
	employee_data *temp_node=NULL;
	FILE *write_fp;
	int count=0;
	char write_buffer[SIZE];
	
	#if 1
	if(remove("TS_Employees_Data.xlsx"))
	{
		printf("New file is created\n");
	}
	#endif
	
	write_fp=fopen("TS_Employees_Data.xlsx","a");
	if(write_fp==NULL)
	{
		printf("File cannot created Successfully");
	}
	else
	{
		if(node==NULL)
		{
			printf("List is empty\n");
		}
		else
		{
			while(node!=NULL)
			{
				strcpy(write_buffer,"\0");
				strcpy(write_buffer,node->EMP_ID);
				fprintf(write_fp,"%s\t",write_buffer);
				strcpy(write_buffer,node->Name);
				fprintf(write_fp,"%s\t",write_buffer);
				write_buffer[0]=node->GENDER;
				fprintf(write_fp,"%c\t",write_buffer);
				strcpy(write_buffer,node->EMAIL_ID);
				fprintf(write_fp,"%s\t",write_buffer);
				strcpy(write_buffer,node->Band);
				fprintf(write_fp,"%s\t",write_buffer);
				strcpy(write_buffer,node->DOJ);
				fprintf(write_fp,"%s\t",write_buffer);
				strcpy(write_buffer,node->Contact_No);
				fprintf(write_fp,"%s\t",write_buffer);
				strcpy(write_buffer,node->Reporting_Manager);
				fprintf(write_fp,"%s\t",write_buffer);
				strcpy(write_buffer,node->Tech_area);
				fprintf(write_fp,"%s\t",write_buffer);
				strcpy(write_buffer,node->Project_info);
				fprintf(write_fp,"%s\t",write_buffer);
				strcpy(write_buffer,node->Status);
				fprintf(write_fp,"%s\n",write_buffer);
				
				node=node->link;
				count++;
			}
			printf("count:%d\n",count);
			//free(node);
		}
	}
	fclose(write_fp);
}

