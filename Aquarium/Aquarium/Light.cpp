// 
// 
// 

#include "Light.h"

LightStruct Light;

void setLights(int &menuLevel, int &menuItem, int &menuItemElement, LiquidCrystal &lcd) // menuLevel = 2 - ������ ������� �������� ����
{
	if (menuLevel != 2 && menuItem != 3) return;
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
		// ��������� ������� ������ "�����"
	case btnUP:
		Light.currentLight++;
		if (Light.currentLight > 2)
		{
			Light.currentLight = 0;
		}
		changeLightStr();
		delay(100);
		//lcd.clear();
		printSetLights(lcd);
		break;
		// ��������� ������� ������ "����"
	case btnDOWN:
		Light.currentLight--;
		if (Light.currentLight < 0)
		{
			Light.currentLight = 2;
		}
		changeLightStr();
		delay(100);
		//lcd.clear();
		printSetLights(lcd);
		break;
	}
}

void printSetLights(LiquidCrystal &lcd)
{
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print(" - Lights set - ");
	lcd.setCursor(0, 1);
	lcd.print(" Lights:        ");
	lcd.setCursor(9, 1);
	lcd.print(Light.currentLightStr);
}

void changeLightStr()
{
	// ��������� �������� ���������� ���������
	switch (Light.currentLight)
	{
	case 0:
		Light.currentLightStr = "OFF";
		break;
	case 1:
		Light.currentLightStr = "Sensor";
		break;
	case 2:
		Light.currentLightStr = "ON";
		break;
	}
	
}

void initLight()
{
	Light.currentLight = 0;
	Light.currentLightStr = "OFF";
}