#include "text_methods.h"
void text_methods::text_if(const string &file_name)
{
	ofstream file(file_name);
	file << text;
	file.close();
}
void text_methods::text_of(const string &file_name)
{
	ifstream file(file_name);
	char c;
	while (file.get(c)) text.push_back(c);
	file.close();
}
void text_methods::text_convert()
{
	map<char, char>::iterator it;
	string temp = text;
	reset_text();
	for (auto i : temp)
	{
		it = alph.find(i);
		if (it != alph.end()) text.push_back(it->second);
	}
}
text_methods::text_methods(const string &alph_file, const set<string> &files)
{
	string s = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
	for (auto i : s)
		alph[i] = '*';
	alph_of(alph_file);
	for (auto i: files)
		text_of(i);
	text_convert();
}
text_methods::text_methods(const set<string> &files)
{
	string s1 = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
	string s2 = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	s2 = s2 + s1;
	s1 += s1;
	for (int i = 0; i < s2.size(); ++i)
		alph[s2[i]] = s1[i];
	alph['Ё'] = alph['е'];
	alph['ё'] = alph['е'];
	for (auto i: files)
		text_of(i);
	text_convert();
}

void text_methods::alph_of(const string & file_name)
{
	ifstream file(file_name);
	char temp, c1, c2;
	while (file.get(c1))
	{
		file.get();
		file.get(c2);
		file.get();
		alph[c1] = c2;
	}
}
void text_methods::alph_if(const string & file_name)
{
	ofstream file(file_name);
	for (auto i : alph)
		file << i.first << "-" << i.second << endl;
	file.close();
}

void text_methods::alph_shuffle()
{
	map <char, char>::iterator it1, it2;
	char temp;
	for (it1 = alph.begin(); it1 != alph.end(); it1++)
	{
		it2 = alph.begin();
		/*сдвиг итератора от начала*/
		advance(it2, rand() % alph.size());
		temp = it1->second;
		it1->second = it2->second;
		it2->second = temp;
	}
}
void text_methods::reset_text()
{
	text.clear();
}
void text_methods::reset_alph()
{
	alph.clear();
}

void text_methods::make_alph(vector<char> &key, vector<char> &value)
{
	for (int i = 0; i < 32; ++i)
		alph[key[i]] = value[i];
}
void text_methods::shuffle_kv(vector<char> &key, vector<char> &value)
{
	int k,n,i;
	char temp;
	set<int> used;
	/*количество замен*/
	n= rand() % key.size();
	while (n)
	{
		/*i-позиция 1 случайного эл-та из вектора значений*/
		/*k-позиция 2 случайного эл-та из вектора значений*/
		/*|i-k|<=3*/
		/*i - не должны повторяться*/
		do i = rand() % key.size();
		while (used.find(i) != used.end());
		used.insert(i);
		if (i <= 2)
			k = i + rand() % 4;
		else
			if (i >= key.size()-3)
				k = i - 3 + rand() % 4;
			else
				k = i - 3 + rand() % 7;
		temp = value[i];
		value[i] = value[k];
		value[k] = temp;
		--n;
	}
}
string text_methods::text;
map<char, char> text_methods::alph;
