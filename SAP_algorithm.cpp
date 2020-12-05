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

class Person {
public:
	Person(Point point):
	point(point)
	{
	}
	
	int id;
	int xMin, xMax;
	Point point;
	const char* name;
};

std::vector<Person> SortByMinX(std::vector<Person>& v) {
	
	std::sort(v.begin(), v.end(),
		[](Person const & a, Person const & b) -> bool
	{ return a.point.Min < b.point.Min; });
	
	return  v;
}


void Algorithm(std::vector<Person>& axisList) {

	std::vector<Person> activeList; //temporary list

	for (auto i = 0; i < axisList.size(); ++i) {
		for (auto j = 0; j < activeList.size(); ++j) {
			cout << "comparing " << axisList[i].name << " and " << activeList[j].name << endl;
			if (axisList[i].point.Min > (activeList[j].point.Max)) {
				cout << " bitch is poped " << activeList[j].name << endl;
				activeList.erase(activeList.begin() + j);//////////////////////ÑÓÊÀ ÍÅÓÆÅËÈ İÒÎ ĞÀÁÎÒÀŞÙÈÉ ÂÀĞÈÀÍÒ ÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀ
				j--;
			}
			else {
				std::cout << " reported pair " << axisList[i].name << " and " << activeList[j].name << std::endl;
			}
		}
		cout << axisList[i].name << " is added to activeList  " << endl;
		activeList.push_back(axisList[i]);
	}

	for (auto m : activeList) {
		cout << m.name << endl;
	}
}

std::vector<std::vector<Person>> Algorithm1(std::vector<Person>& axisList) {
	//ñîçäàòü íîâûé âåêòîğ ãäå áóäóò õğàíèòüñÿ ïàğû
	std::vector<std::vector<Person>> allPairs;
	std::vector<Person> activeList; //temporary list

	for (auto i = 0; i < axisList.size(); ++i) {
		for (auto j = 0; j < activeList.size(); ++j) {
			cout << "comparing " << axisList[i].name << " and " << activeList[j].name << endl;
			if (axisList[i].point.Min > (activeList[j].point.Max)) {
				cout << " bitch is poped " << activeList[j].name << endl;
				activeList.erase(activeList.begin() + j);//////////////////////Ñ ÍÅÓÆÅËÈ İÒÎ ĞÀÁÎÒÀŞÙÈÉ ÂÀĞÈÀÍÒ ÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀ
				j--;
			}
			else {
				std::cout << " reported pair " << axisList[i].name << " and " << activeList[j].name << std::endl;
				std::vector<Person> mpair;
				mpair.push_back(axisList[i]);
				mpair.push_back(activeList[j]);
				allPairs.push_back(mpair);
				///ñîçäàòü íîâûé âåêòîğ ïàğû è äîáàâèòü åãî â âåêòîğ ïàğ
			}
		}
		cout << axisList[i].name << " is added to activeList  " << endl;
		activeList.push_back(axisList[i]);
	}

	return allPairs;
}


int main()
{
	Person A(Point(1, 10));
	A.id = 12;
	A.name = "A";

	Person B(Point(5, 31));
	B.id = 43;
	B.name = "B";

	Person C(Point(7, 13));
	C.id = 45;
	C.name = "C";

	Person D(Point(18, 25));
	D.id = 101;
	D.name = "D";

	std::vector<Person> vec { D, C, A, B};

	

	/*std::sort(vec.begin(), vec.end(),
		[](Person const & a, Person const & b) -> bool
	{ return a.id < b.id; });

	for (auto &i : vec) {
		cout << i.id << endl;
	}*/


	auto axisList = SortByMinX(vec);
	//Algorithm(axisList);

	
	std::vector <Person> pair1;
	pair1.push_back(D);
	pair1.push_back(A);

	std::vector <Person> pair2;
	pair2.push_back(B);
	pair2.push_back(C);

	std::vector <Person> pair3;
	pair3.push_back(D);
	pair3.push_back(D);

	
	std::vector<std::vector<Person>> vectorOfPairs;

	vectorOfPairs.push_back(pair2);
	vectorOfPairs.push_back(pair1);
	vectorOfPairs.push_back(pair3);


	//for (int i = 0; i < vectorOfPairs.size(); ++i) {
	//	cout << vectorOfPairs[i].capacity() << endl;
	//	if (vectorOfPairs[i].front().name == vectorOfPairs[i].back().name) {
	//		cout << "SAME SAME SAME " << vectorOfPairs[i].front().name << " and " << vectorOfPairs[i].back().name << endl;
	//	}
	//}


	auto check = Algorithm1(axisList);
	for (int i = 0; i < check.size(); ++i) {
	
		cout << check[i].front().name;
		cout << check[i].back().name;
		cout << " | ";
	}
}

