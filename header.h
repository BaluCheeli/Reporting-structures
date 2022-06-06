#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

#define SIZE 500

/*..............Global Employee Detail Structure.............*/
#pragma pack(1)
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
	char Reportees[SIZE];
	char Project_info[SIZE];
	char Status[SIZE];
	struct data *link;
}employee_data;

employee_data *head;

