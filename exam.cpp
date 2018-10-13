#include "Point.h"
#include "romans.h"
int main()
{
	std::cout << "Starting the Romans numbers tests ...." << std::endl;

	std::map<std::string, double> romantests;
	romantests["MDCCLXXVI"] = 1776;
	romantests["MCMLIV"] = 1954;
	romantests["MCMXC"] = 1990;
	romantests["MMXIV"] = 2014;
	romantests["XXXIX"] = 39;
	romantests["CCXLVI"] = 246;

	for(std::map<std::string,double>::iterator rn=romantests.begin();rn!=romantests.end();++rn)
	{
		std::cout << "generating roman number for " << rn->second << std::endl;
		auto roman1 = DecimalToRoman(rn->second);
		if (roman1 != rn->first)
		{
			std::cout << "error: expected is"<<rn->first<< "but computed is "<<roman1 << std::endl;
		}
		else
		{
			std::cout << "success: roman is " << roman1 << std::endl;
		}
	}
		
	std::cout << "****************************************" << std::endl;

	std::cout << "Starting the quadrant points tests ...." << std::endl;

	std::vector<std::pair<std::vector<Point>,SHAPES>> pointssets;
	pointssets.push_back(std::make_pair(std::vector<Point>{ Point(0,0),Point(0,1),Point(1,1),Point(1,0) },SHAPES::SQUARE));
	pointssets.push_back(std::make_pair(std::vector<Point>{ Point(0,0),Point(0,10),Point(1,10),Point(1,0) }, SHAPES::RECTANGLE));
	pointssets.push_back(std::make_pair(std::vector<Point>{ Point(-155,-155),Point(155,155),Point(155,-155),Point(-155,155) }, SHAPES::SQUARE));
	pointssets.push_back(std::make_pair(std::vector<Point>{ Point(0, 0), Point(0, 1.0001), Point(1, 1), Point(1, 0) }, SHAPES::NONE));
	pointssets.push_back(std::make_pair(std::vector<Point>{ Point(-190, 0), Point(90, 0), Point(1.87, 112), Point(1, 0) }, SHAPES::NONE));

	for(auto st:pointssets)
	{
		auto shape = WhatShape(st.first);
		if(st.second==shape)
		{
			std::cout << "success: expected shape is " << st.second << " and detected " << shape << std::endl;
		}
		else
		{
			std::cout << "error: expected shape is " << st.second << " and detected " << shape << std::endl;
		}
	}
	return 0;
}