#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include <lcd.h>
#include <string.h>
#include <time.h>

char p[8] = { 0b11111,
	      0b11111,
	      0b10001,
	      0b10001,
	      0b10001,
	      0b10001,
	      0b10001,
	      0b10001};


char i[8] = { 0b10001,
	      0b10001,
	      0b10011,
	      0b10101,
	      0b11001,
	      0b10001,
	      0b10001,
	      0b10001};


char v[8] = { 0b11110,
	      0b10001,
	      0b10010,
	      0b11100,
	      0b10010,
	      0b10001,
	      0b10001,
	      0b11110};


char o[8] = { 0b11111,
	      0b10001,
	      0b10001,
	      0b10001,
	      0b10001,
	      0b10001,
	      0b10001,
	      0b11111};

#define COLUMNS 16
#define LCD_RS 3
#define LCD_E 14
#define LCD_D4 4
#define LCD_D5 12
#define LCD_D6 13
#define LCD_D7 6

int lcd;

int main()
{
	wiringPiSetup();
	if(lcd = lcdInit(2,16,4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0))
	{
		printf("lcdIint nije uspeo! \n");
		return -1;
	}

	lcdCharDef (lcd, 0, p);
	lcdCharDef (lcd, 1, i);
	lcdCharDef (lcd, 2, v);
	lcdCharDef (lcd, 3, o);

	lcdClear(lcd);

	int i;
	lcdPosition(lcd, 0, 0);
	//lcdPuts (lcd, ":Volume");
	for (i=0; i<4; i++){
		lcdPosition (lcd, i, 0);
		lcdPutchar (lcd, i);
	}
}
