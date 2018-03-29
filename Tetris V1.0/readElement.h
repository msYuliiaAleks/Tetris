#pragma once
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "utils.h"
using namespace std;

class ReadElement
{
public:
	std::vector< std::vector<Point>> ArrMatrixEl;
//	ReadElement(char _lineSize, char _fileName);
	ReadElement();
	char _line[256];
	const char *_fileName;
	void ReadFile();
	//MatrixInt _matrixInt;
	~ReadElement();
	int randEl;

};


/*struct Element
{
std::vector<Point> points;
int count_rows;
int count_colls;
Element(){
count_colls=0;
count_rows=0;
}
};
class ReadElement
{
public:
std::vector< Element> ArrMatrixEl;
//	ReadElement(char _lineSize, char _fileName);
ReadElement();
char _line[256];
const char *_fileName;
void ReadFile();
//MatrixInt _matrixInt;
~ReadElement();


};
*/