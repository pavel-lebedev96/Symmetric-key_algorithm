#pragma once
#ifndef CRYPT_TEXT_H
#define CRYPT_TEXT_H
#include "text_stat.h"
#include <vector>
class crypt_text:public text_methods
{
	/*def - стандартная стат-ка*/
	/*dest - статистика зашифров. текста*/
	text_stat def, dest;
	/*подсчет суммы отклонений стат-ки зашифров. текста
	от станд. стат-ки*/
	float calc_sum();
public:
	/*Конструктор: чтение и подсчет стат-к для зашифров. и обычного текстов*/
	/*max_size - максимальная длина сочетаний букв в статистике*/
	crypt_text(const string &file_name, const set<string> &stat_files, int max_size);
	/*Подсчет стандартной статистики*/
	void mk_def_stat(const set<string> &stat_files,int max_size);
	/*Подсчет статистки зашифрованн. текста*/
	void mk_dest_stat(const string &file_name,int max_size);
	/*Функция дешифровки*/
	/*Случайным образом перемешивает буквы, расположенные в порядке
	убывания частоты встречаемости, составляет алфавит и находит 
	минимальную сумму откл-й*/
	/*n - число попыток*/
	void decrypt(int n);
};
#endif /*CRYPT_TEXT_H*/