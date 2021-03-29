#include <string.h>
#define _XOPEN_SOURCE
#include <time.h>
#include <sys/time.h>
#include "systemTime.h"
#include <stdio.h>

int systemtimeControl(char *cmd,char *timeString,char *dateString)
{
	char time_arr[128] = "";
	time_t time_num;
	struct tm timevalue;
	struct tm *ptr;
	struct tm timechange;
	int ret = -1;
	memset(&timechange,0,sizeof timechange);
	memset(&timevalue,0,sizeof timevalue);
	if(!strcmp("read",cmd))
	{
		time(&time_num);
		ptr = localtime(&time_num);
		memcpy(&timevalue,ptr,sizeof(timevalue));
		strftime(time_arr,128,"%c",&timevalue);
		printf("%s\n",time_arr);
	}
	else if(!strcmp("write",cmd))
	{
		time(&time_num);
		ptr = localtime(&time_num);
		memcpy(&timevalue,ptr,sizeof(timevalue));
		strftime(time_arr,128,"%c",&timevalue);
		printf("before change,time is :[%s]\n",time_arr);	
		
			
		if(NULL != timeString || NULL != dateString)
		{
			struct timespec tsp;
			time_t timevalue_tsp;
			memset(&tsp,0,sizeof tsp);
			if(NULL != timeString)
 			{
				printf("change time as %s!\n",timeString);
				ret = strptime(timeString,"%X",&timechange);
				if(-1 == ret)
				{
					printf("strptime change format %s failed!\n",timeString);
					return -1;	
				}
				timevalue.tm_hour = timechange.tm_hour;
				timevalue.tm_min  = timechange.tm_min;
				timevalue.tm_sec  = timechange.tm_sec;
			}
			if(NULL != dateString)
			{
				printf("change date as %s!\n",dateString);
				ret = strptime(dateString,"%x",&timechange);
				if(-1 == ret)
				{
					printf("strptime change format %s failed!\n",dateString);
					return -1;	
				}
				timevalue.tm_year = timechange.tm_year;
				timevalue.tm_mon  = timechange.tm_mon;
				timevalue.tm_mday = timechange.tm_mday;						
			}
				timevalue_tsp = mktime(&timevalue);
				tsp.tv_sec    = timevalue_tsp;
				clock_settime(CLOCK_REALTIME,&tsp);
				
				ptr = localtime(&timevalue_tsp);
				strftime(time_arr,128,"%c",ptr);
	                	printf("after change,time is :[%s]\n",time_arr);
		}
	}
				return 0;
}



