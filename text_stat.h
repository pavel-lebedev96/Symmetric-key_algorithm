#pragma once
#ifndef TEXT_STAT_H
#define TEXT_STAT_H
#include "text_methods.h"
class text_stat :public text_methods
{
public:
	map<string, float> stat;
	/*статистика встречаемости в заданном тексте
	строк длиной от 1 до max_size включительно*/
	void make_stat(const int &);
};

#endif /*TEXT_STAT_H*/