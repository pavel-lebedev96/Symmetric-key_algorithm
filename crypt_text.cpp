#include "crypt_text.h"
crypt_text::crypt_text(const string &file_name, const set<string> &stat_files, int max_size)
{
	mk_def_stat(stat_files,max_size);
	mk_dest_stat(file_name,max_size);
}
void crypt_text::mk_def_stat(const set<string> &stat_files,int max_size)
{
	text_methods::reset_text();
	for (auto i : stat_files)
		text_methods::text_of(i);
	def.make_stat(max_size);
}
void crypt_text::mk_dest_stat(const string &file_name,int max_size)
{
	text_methods::reset_text();
	text_methods::text_of(file_name);
	dest.make_stat(max_size);
}
void crypt_text::decrypt(int n)
{
	multimap<float,char> def_l_stat, dest_l_stat;
	multimap<float, char>::iterator it1, it2;
	map<char, char>best_alph;
	vector<char> tkey,tvalue,key,value;
	float temp,best_sum = 100000000;
	/*составл¤ем сортированные по возрастанию статистики отдельных букв*/
	/*дл¤ стандартной статистики*/
	for (auto i : def.stat)
		if (i.first.size() == 1)
			def_l_stat.insert(pair<float, char>(i.second, i.first[0]));
	/*дл¤ зашифрованного текста*/
	for (auto i : dest.stat)
		if (i.first.size() == 1)
			dest_l_stat.insert(pair<float, char>(i.second, i.first[0]));
	/*создаем векторы ключей и значений, сопоставл¤¤ получившиес¤ стат-ки:
	ключ - буквы из стат-ки зашифр. текста,
	значение - занимающие соответствующие места буквы из станд. стат-ки*/
	it1 = dest_l_stat.end();
	it2 = def_l_stat.end();
	while (it1!=dest_l_stat.begin())
	{
		--it1;
		--it2;
		key.push_back(it1->second);
		value.push_back(it2->second);
	}
	/*будем перемешивать получившиес¤ векторы, пока 
	сумма отклонений не будет минимальной*/
	for (int i = 0; i < n; ++i)
	{
		tkey = key;
		tvalue = value;
		text_methods::reset_alph();
		/*перемешать значени¤*/
		text_methods::shuffle_kv(tkey, tvalue);
		/*создать алфавит из векторов*/
		text_methods::make_alph(tkey, tvalue);
		temp = calc_sum();
		if (temp < best_sum)
		{
			best_alph = alph;
			best_sum = temp;
		}
	}
	alph = best_alph;
}

float crypt_text::calc_sum()
{
	float result = float(0);
	string temp;
	map<string, float>::iterator it;
	for (auto i: dest.stat)
	{
		temp=i.first;
		for (int j = 0; j < temp.size(); ++j)
			temp[j] = alph[temp[j]];
		it = def.stat.find(temp);
		if (it==def.stat.end()) result+=i.second;
		else result += abs(i.second - it->second);
	}
	return result;
}