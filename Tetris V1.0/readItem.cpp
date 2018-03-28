#include <fstream>
#include <iostream>
#include  <string>
#include <cstdlib>
#include <vector>
#include "readItem.h"
using namespace std;

//ReadItem:: ReadItem(char lineSize, char fileName){
//	_lineSize=lineSize;
//	_fileName=fileName;
//}
ReadItem:: ~ReadItem(){}
ReadItem:: ReadItem(){
	_fileName="file.txt";
}
void ReadItem::ReadFile()
{
	ifstream in(_fileName);
	if(!in.is_open())
	{
		cout<< "Error opening file for read\n";
	}

	while (in) 
	{	
		in.getline(_line, 80);

		if(_line[0]!=' ')
		{
			std::vector<int> row; 
			for(unsigned int i=0;i<strlen(_line);++i)
			{
				row.push_back(_line[i] - '0'); 
			}
			_matrixInt.push_back(row);
		}
		if(_line[0]==' ')
		{
			ArrMatrixEl.push_back(_matrixInt);
			_matrixInt.clear();		
		}
	}
	in.close();
}