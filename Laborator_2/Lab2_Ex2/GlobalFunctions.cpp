#include "Class.h"
#include <string.h>
int CompareName(Class c1, Class c2)
{
	int x = strcmp(c1.getName(), c2.getName());
	if (x == 0) return 0;
	if (x > 0) return 1;
	return -1;
}

int CompareGradeMath(Class c1, Class c2)
{
	if (c1.getMathGrade() == c2.getMathGrade())return 0;
	if (c1.getMathGrade() > c2.getMathGrade()) return 1;
	return -1;
}

int CompareGradeEngl(Class c1, Class c2)
{
	if (c1.getEnglGrade() == c2.getEnglGrade())return 0;
	if (c1.getEnglGrade() > c2.getEnglGrade()) return 1;
	return -1;
}

int CompareGradeHist(Class c1, Class c2)
{
	if (c1.getHistGrade() == c2.getHistGrade())return 0;
	if (c1.getHistGrade() > c2.getHistGrade()) return 1;
	return -1;
}

int CompareGradeAvg(Class c1, Class c2)
{
	if (c1.getAvgGrade() == c2.getAvgGrade())return 0;
	if (c1.getAvgGrade() > c2.getAvgGrade()) return 1;
	return -1;
}