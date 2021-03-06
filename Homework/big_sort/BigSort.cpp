// BigSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<ctime>

int main()
{
	double start_t = clock();
	std::vector<double> V(1000000000);
	std::default_random_engine generator(time(NULL));
	std::uniform_real_distribution<double> distribution(0.0, 0.1);
	for (size_t i = 0; i < V.size(); ++i)
		V[i] = distribution(generator);
	sort(V.begin(), V.end());
	double end_t = clock();
	std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60) << " minutes" << std::endl;
	system("pause");
    return 0;
}

