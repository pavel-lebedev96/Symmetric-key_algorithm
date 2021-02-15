#pragma once
#ifndef TEXT_METHODS_H
#define TEXT_METHODS_H
#include <map>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;
class text_methods
{
protected:
	
	static map<char, char> alph;
	static string text;
public:
	/*конструктор по умолчанию*/
	text_methods() {};
	/*Конструктор: чтение из файлов алфавита и текста и конвертация текста*/
	text_methods(const string &alph_file, const set<string> &files);
	/*Конструтор: чтение из файлов текста и удаление ненужных символов*/
	text_methods(const set<string> &files);
	/*Запись текста в файл*/
	static void text_if(const string &file_name);
	/*Чтение текста из файла*/
	static void text_of(const string &file_name);
	/*Запись алфавита в файл*/
	static void alph_if(const string &file_name);
	/*Чтение алфавита из файла*/
	static void alph_of(const string &file_name);
	/*Перемешивание алфавита*/
	static void alph_shuffle();
	/*Преобразование текста заданным алфавитом*/
	static void text_convert(void);
	/*Очистка текста*/
	static void reset_text(void);
	/*Очитска алфавита*/
	static void reset_alph(void);
	/*Формирование алфавита из векторов ключей и значений*/
	static void make_alph(vector<char> &key, vector<char> &value);
	/*Перемешивание значений у ключей*/
	static void shuffle_kv(vector<char> &key, vector<char> &value);
};
#endif /*TEXT_METHODS_H*/