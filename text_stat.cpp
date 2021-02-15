#include "text_stat.h"
void text_stat::make_stat(const int &max_size)
{
	string temp;
	for (int k = 0; k < max_size; ++k)
		for (int i = 0; i < text.size() - k; ++i,temp.clear())
		{
			for (int j = 0; j <= k; ++j)
				temp.push_back(text[i + j]);
			stat[temp] += float(1) / (float(text.size() - k));
		}
}