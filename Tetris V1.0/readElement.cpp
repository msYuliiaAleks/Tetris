#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "readElement.h"
using namespace std;

//ReadElement:: ReadElement(char lineSize, char fileName){
//	_lineSize=lineSize;
//	_fileName=fileName;
//}
ReadElement:: ~ReadElement(){}
ReadElement:: ReadElement(){
	_fileName="file.txt";
}
void ReadElement::ReadFile()
{
	ifstream in(_fileName);
	if(!in.is_open())
	{
		cout<< "Error opening file for read\n";
	}

	Point point;
	std::vector<Point> Element_points;
	int row =0;
	while (in) 
	{	
		in.getline(_line, 80);
		if(_line[0]!=' ')
		{
			for(unsigned int i=0;i<strlen(_line);++i)
			{
				if(_line[i]=='1')
				{
					point.x=i;
					point.y=row;
					Element_points.push_back(point);
				}
			}
			row++;
		}
		if(_line[0]==' ' ||  in.eof())
		{				
			ArrMatrixEl.push_back(Element_points);
			Element_points.clear();
			row =0;
			if(in.eof())
			{
				break;
			}
		}
	}
	in.close();
}



/*Point point;
Element Element_points;
int row =0;

while (in) 
{	
in.getline(_line, 80);
if(_line[0]!=' ')
{
for(unsigned int i=0;i<strlen(_line);++i)
{
if(_line[i]=='1')
{
point.x=i;
point.y=row;
Element_points.points.push_back(point);
}
}
row++;
Element_points.count_colls= strlen(_line);	
}

if(_line[0]==' ' ||  in.eof())
{				
Element_points.count_rows=row;	
ArrMatrixEl.push_back(Element_points);
Element_points.points.clear();
row =0;
if(in.eof())
{
break;
}
}
}
in.close();*/