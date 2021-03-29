#include <stdio.h>
#include "main.h"

int main(int argc,char *argv[])
{
	int ret = -1;
	printf("Function:read and set Systemtime.\n");
	if(argc < 2)
	{
		printf("argc0 is program path.\n");
		printf("argc1 is read or write commmand.read command only need 1 Param\n");
		printf("argc2 is just for write command.\n");
		return 0;
	}
	else if(argc == 2)
	{ 	
		ret = systemtimeControl(argv[1],NULL,NULL);
		if(-1 == ret)
		{
			printf("systemtimeControl param error.\n");
			return -1;
		}
		
		return 0;
	}
	else if(argc == 3)
	{
		printf("hour,min,and min setting!param 2 format as \"21:24:52\".\n");
		ret = systemtimeControl(argv[1],argv[2],NULL);
		if(-1 == ret)
		{
			printf("systemtimeControl param error.\n");
			return -1;
		}
	}
	else if(argc == 4)
	{
		printf("hour,min,and min setting!param 2 format as \"21:24:52\".\n");
		printf("month,day,and year setting!param 3 format as \"01/19/12\".\n");
		ret = systemtimeControl(argv[1],argv[2],argv[3]);
		if(-1 == ret)
		{
			printf("systemtimeControl param error.\n");
			return -1;
		}
	}
	else
	{
		printf("error Input!\n");
	}
	return 0;
}
