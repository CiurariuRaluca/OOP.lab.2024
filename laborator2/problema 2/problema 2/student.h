#pragma once
class student
{
	char nume[20];
	float mate, engleza, istorie;
public:
	void setName(char a[20]);
	void getName(char a[20]);

	void  setMate(float a);
	float getMate();
	
	void setEngleza(float b);
	float getEngleza();
	
	void setIstorie(float c);
	float getIstorie();

	float medie();
};

