#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isMatch(vector<int> arr, int k)
{
	int size = arr.size();
	unordered_map<int, int> umap(size*2);

	for (int i : arr)
	{
		if (i != 0 && umap[i] != 0)
			umap[i] = i;
		else
			if (umap[i] == i)
				umap[i] = i + 1;
	}
	for (int i : arr)
		if (umap[k - i] != i && umap[k-i] != 0)
			return true;

	return false;
}