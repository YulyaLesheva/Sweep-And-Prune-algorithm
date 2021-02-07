#include "pch.h"
#include <iostream>
#include "cmath"
#include <vector>
#include <algorithm>
#include <array>
using namespace std;


class Point {
public:
	Point(int x1, int x2):
	Min(x1),
	Max(x2)
	{
	}
	int Min, Max;
};

class Quad {
public:
	Quad(Point point, const char * name):
	point(point),
		name(name)
	{
	}
	Quad* create(Point pos, const char*  name) {
		return new Quad(pos, name);
	}
	int id;
	Point point;
	const char * name;
};

std::vector<Quad*> SortByMinX(std::vector<Quad*>& v) {
	
	std::sort(v.begin(), v.end(),
		[=](Quad  * a, Quad * b) -> bool
	{ return a->point.Min < b->point.Min; });
	
	return  v;
}

std::vector<std::vector<Quad*>> Algorithm(std::vector<Quad*>& axisList) {
	
	axisList = SortByMinX(axisList);
	
	std::vector<std::vector<Quad*>> allPairs;
	std::vector<Quad*> activeList; //temporary list

	for (auto i = 0; i < axisList.size(); ++i) {
		for (auto j = 0; j < activeList.size(); ++j) {
			cout << "comparing " << axisList[i]->name << " and " << activeList[j]->name << endl;
			if (axisList[i]->point.Min > (activeList[j]->point.Max)) {
				cout << " object is poped " << activeList[j]->name << endl;
				activeList.erase(activeList.begin() + j);
				j--;
			}
			else {
				std::cout << " reported pair " << axisList[i]->name << " and " << activeList[j]->name << std::endl;
				std::vector<Quad*> mpair;
				mpair.push_back(axisList[i]);
				mpair.push_back(activeList[j]);
				allPairs.push_back(mpair);
			}
		}
		cout << axisList[i]->name << " is added to activeList  " << endl;
		activeList.push_back(axisList[i]);
	}

	return allPairs;
}

int main()
{
	Quad* A(0);
	A = A->create(Point(1, 10), "A");

	
	Quad* B(0);
	B = B->create(Point(5, 31), "B");
	
	Quad* C(0);
	C = C->create(Point(7, 13), "C");

	
	Quad* D(0);
	D = D->create(Point(18, 25), "D");

	std::vector<Quad*> vectorToCheck{B, D, A, C};
	
	auto check = Algorithm(vectorToCheck);
	
	for (int i = 0; i < check.size(); ++i) {
	
		cout << check[i].front()->name;
		cout << check[i].back()->name;
		cout << " | ";
	}
}

