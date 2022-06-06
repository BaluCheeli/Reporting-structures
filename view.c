#include<stdio.h>
#include<stdlib.h>
#include "header.h"
#include<string.h>

char id0[20];
void view_employee_details(employee_data *head)
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
