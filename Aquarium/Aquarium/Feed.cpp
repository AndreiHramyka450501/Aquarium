// 
// 
// 

#include "Feed.h"

FeedStruct Feed;

void setFeed(int &menuLevel, int &menuItem, int &menuItemElement, LiquidCrystal &lcd) // menuLevel = 2 - ������ ������� �������� ����
{
	if (menuLevel != 2 && menuItem != 5) return;
	deb();
	// ��������� ������� ������ ���� (����� �� ������ ����)
	switch (Button.lcd_key)
	{
	case btnSELECT:
		menuLevel = 1;
		menuItemElement = 0;
		delay(100);
		//lcd.clear();
		printMainMenu(lcd, menuItem);
		break;
		// ��������� ������� ������ "������" (����� ����������� �������� ������)
	case btnRIGHT:
		menuItemElement++;
		if (menuItemElement > 2)
		{
			menuItemElement = 0;
		}
		delay(100);
		//lcd.clear();
		printSetFeed(lcd, menuItemElement);
		break;
		// ��������� ������� ������ "�����" (����� ����������� �������� �����)
	case btnLEFT:
		menuItemElement--;
		if (menuItemElement < 0)
		{
			menuItemElement = 2;
		}
		delay(100);
		//lcd.clear();
		printSetFeed(lcd, menuItemElement);
		break;
		// ��������� ������� ������ "�����" (��������� �����)
	case btnUP:
		if (menuItemElement == 0) // ��������� ������ ���������
		{
			Feed.currentFeed++;
			if (Feed.currentFeed > 2)
			{
				Feed.currentFeed = 0;
			}
			changeFeedStr();
			delay(100);
			//lcd.clear();
		}

		if (menuItemElement == 1) // ��������� ����� ���������
		{
			Feed.feedHour++;
			if (Feed.feedHour > 23)
			{
				Feed.feedHour = 0;
			}
			delay(100);
			//lcd.clear();
		}

		if (menuItemElement == 2) // ��������� ����� ���������
		{
			Feed.feedMinute++;
			if (Feed.feedMinute > 59)
			{
				Feed.feedMinute = 0;
			}
			delay(100);
			//lcd.clear();
		}
		printSetFeed(lcd, menuItemElement);
		break;
		// ��������� ������� ������ "����" (��������� �����)
	case btnDOWN:
		if (menuItemElement == 0) // ��������� ������ ���������
		{
			Feed.currentFeed--;
			if (Feed.currentFeed < 0)
			{
				Feed.currentFeed = 2;
			}
			changeFeedStr();
			delay(100);
			//lcd.clear();
		}

		if (menuItemElement == 1) // ��������� ����� ���������
		{
			Feed.feedHour--;
			if (Feed.feedHour < 0)
			{
				Feed.feedHour = 23;
			}
			delay(100);
			//lcd.clear();
		}

		if (menuItemElement == 2) // ��������� ����� ���������
		{
			Feed.feedMinute--;
			if (Feed.feedMinute < 0)
			{
				Feed.feedMinute = 59;
			}
			delay(100);
			//lcd.clear();
		}
		printSetFeed(lcd, menuItemElement);
		break;
	}
	// ��������� �������� ���������� ���������
}

void printSetFeed(LiquidCrystal &lcd, int &menuItemElement)
{
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print(" -Feeding set - ");
	lcd.setCursor(0, 1);
	if (menuItemElement == 0)
	{
		lcd.print("Auto:           ");
		lcd.setCursor(5, 1);
		lcd.print(Feed.currentFeedStr);
	}
	if (menuItemElement == 1 || menuItemElement == 2)
	{
		lcd.print(" Time:          ");
		lcd.setCursor(10, 1);
		if (Feed.feedHour < 10)
		{
			lcd.print("0");
		}
		lcd.print(Feed.feedHour);
		lcd.print(":");
		if (Feed.feedMinute < 10)
		{
			lcd.print("0");
		}
		lcd.print(Feed.feedMinute);
	}
}

void changeFeedStr()
{
	switch(Feed.currentFeed)
	{
	case 0:
		Feed.currentFeedStr = "OFF";
		break;
	case  1:
		Feed.currentFeedStr = "1time/day";
		break;
	case 2:
		Feed.currentFeedStr = "1time/2days";
		break;
	}
}

void initFeed()
{
	Feed.currentFeed = 0;
	Feed.feedHour = 8;
	Feed.feedMinute = 0;
	Feed.currentFeedStr = "OFF";
}