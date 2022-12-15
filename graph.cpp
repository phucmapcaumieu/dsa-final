//#include "base.h"
//
//int main()
//{
//	string file_name = "graph1.txt";
//
//	vector<vector<int>> adjMatrix = createAdjMatrix(file_name);
//
//	for (vector<int> line : adjMatrix)
//	{
//		for (int x : line)
//			cout << x << " ";
//		cout << endl;
//	}
//
//	cout << "--------------------------------------" << endl;
//	DFS(adjMatrix, 0);
//	cout << endl << "--------------------------------------" << endl;
//	BFS(adjMatrix, 0);
//}

#include "undoremap.h"

int main()
{
	vector<int> arr{ 3, 1, 2, 5, 7, 8, 7 };

	bool c = isMatch(arr, 14);

	cout << c << endl;

	
	
	return 0;

}