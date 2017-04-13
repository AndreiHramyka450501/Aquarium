// 
// 
// 

#include "MainMenu.h"

void printMainMenu(LiquidCrystal &lcd, int &menuItem)
{
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("***Main menu****");
	lcd.setCursor(0, 1);
	if (menuItem == 0)
	{
		lcd.print("                ");
		lcd.setCursor(0, 1);
		lcd.print("    Date set    ");
	}
	if (menuItem == 1)
	{
		lcd.print("                ");
		lcd.setCursor(0, 1);
		lcd.print("    Time set    ");
	}
	if (menuItem == 2)
	{
		lcd.print("                ");
		lcd.setCursor(0, 1);
		lcd.print("    Temp set    ");
	}
	if (menuItem == 3)
	{
		lcd.print("                ");
		lcd.setCursor(0, 1);
		lcd.print("   Lights set   ");
	}
	if (menuItem == 4)
	{
		lcd.print("                ");
		lcd.setCursor(0, 1);
		lcd.print("    Air set     ");
	}
	if (menuItem == 5)
	{
		lcd.print("                ");
		lcd.setCursor(0, 1);
		lcd.print("  Feeding set   ");
	}
}

void printSub(int &menuItem, int &menuItemElement, LiquidCrystal &lcd)
{
	switch (menuItem)
	{
	case 0:
		printSetDate(lcd);
		break;
	case 1:
		printSetTime(lcd);
		break;
	case 2:
		printSetTemp(lcd, menuItemElement);
		break;
	case 3:
		printSetLights(lcd);
		break;
	case 4:
		printSetAir(lcd);
		break;
	case 5:
		printSetFeed(lcd, menuItemElement);
		break;
	}
}

void mainMenu(int &menuLevel, int &menuItem, int &menuItemElement, LiquidCrystal &lcd) // menuLevel = 1 - ������ ������� ����
{
	if (menuLevel != 1) return;
	deb();
	//Serial.println(lcd_key); 
	// ��������� ������� ������ ���� (�����)
	switch (Button.lcd_key)
	{
	case btnSELECT:
		menuLevel = 0;
		menuItem = 0;
		delay(100);
		printMainScreen(lcd);
		//lcd.clear();
		break;
		// ��������� ������� ������ "������" (����� �������� ������ ����)
	case btnRIGHT:
		menuLevel = 2;
		delay(100);
		//lcd.clear();
		printSub(menuItem, menuItemElement, lcd);
		break;
		// ��������� ������� ������ "�����" (����� �������� ������ ����)
	case btnLEFT:
		menuLevel = 2;
		delay(100);
		//lcd.clear();
		printSub(menuItem, menuItemElement, lcd);
		break;
		// ��������� ������� ������ "�����" (������� ���� �����)
	case btnUP:
		menuItem--;
		if (menuItem < 0)
		{
			menuItem = 5;
		}
		delay(100);
		printMainMenu(lcd, menuItem);
		//lcd.clear();
		break;
		// ��������� ������� ������ "����" (������� ���� ����)
	case btnDOWN:
		menuItem++;
		if (menuItem > 5)
		{
			menuItem = 0;
		}
		delay(100);
		printMainMenu(lcd, menuItem);
		//lcd.clear();
		break;
	}
}



