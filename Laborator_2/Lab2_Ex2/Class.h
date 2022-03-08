#pragma once
class Class
{
	char name[100];
	float MathGrade, EnglGrade, HistGrade, AvgGrade;
public:
	Class(int MathGrade);
	Class();
	
	void setName(char* name);
	char* getName();
	
	void setMathGrade(float MathGrade);
	float getMathGrade();
	
	void setEnglGrade(float EnglGrade);
	float getEnglGrade();
	
	void setHistGrade(float HistGrade);
	float getHistGrade();
	
	float getAvgGrade();
};
