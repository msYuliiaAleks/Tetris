#include <fstream>
#include <iostream>
#include  <string>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

struct Item
{
	std::vector<Point> points;
	int count_rows;
	int count_colls;
};
class ReadItem
{
public:
	std::vector< Item* > ArrMatrixEl;
//	ReadItem(char _lineSize, char _fileName);
	ReadItem();
	char _line[256];
	const char *_fileName;
	void ReadFile();
	MatrixInt _matrixInt;
	~ReadItem();

};
struct Point
{
	int x;
	int y;
};

