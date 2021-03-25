#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/fcntl.h>
#include <wiringPi.h>
#include <lcd.h>
#include <time.h>

#define COLUMNS 16
#define LCD_RS 3
#define LCD_E 14
#define LCD_D4 4
#define LCD_D5 12
#define LCD_D6 13
#define LCD_D7 6
#define LCD_RS 3

int lcd;




int main(int argc, char *argv[])
{
	wiringPiSetup();

	if(lcd = lcdInit(2,16,4,LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0,0, 0, 0))
	{
		printf("lcdInit nije uspeo! \n");
		return -1;
	}

	int fd = -1, ret;
	char *tmp1,  tmp2[10], ch = 't';
	char devname_head[50] = "/sys/bus/w1/devices/28-000007237df2";

	
	char devname_end[10] = "/w1_slave";
	char dev_name[100];
	long value;
	double temp;
	int integer, decimal;
	char buffer[100];
	int i,j;

	while(1)
	{
		strcpy(dev_name, devname_head);
		strcat(dev_name,devname_end);

		if((fd = open(dev_name, O_RDONLY)) <0)
		{
			perror("Greska pri ocitavanju!");
			exit(1);
		}

		ret = read(fd, buffer, sizeof(buffer));

		if(ret < 0)
		{
			perror("Greska pri citanju");
			exit(1);
		}

		tmp1 = strchr(buffer, ch);
		sscanf(tmp1, "t=%s", tmp2);
		value = atoi(tmp2);
		temp = (double)value/1000;
		//printf("%lf\n", temp);
		//printf("%lf\n", prag);
		lcdPosition(lcd, 0, 0);
		lcdPrintf(lcd, "%.2lf", temp);
		delay(2000);
		lcdClear(lcd);
	
	}
	return 0;


}
