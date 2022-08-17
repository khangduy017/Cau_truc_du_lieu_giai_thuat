#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_
#include<iostream>
using namespace std;
#include<fstream>
#include<vector>
#include<iomanip>
#include<string>
#pragma pack(1)

struct Node {
	string Name;
	int pointM;
	int pointP;
	int pointC;
	Node* next;
};

struct SinhVien {
	char name[50];
	int pointM;
	int pointP;
	int pointC;
};

void addNode(Node*& head, char name[], int math, int physic, int chemis);
void printLinkList(Node* head);
void searchStudentOnFN(Node* head, string fullName);
void calculateAverageScore(Node* head);
void deleteStudent(Node*& head, int index);
void deleteSdWithSameName(Node*& head);
void insertToEnd(Node*& head, char name[], int math, int physic, int chemis);
void insertToFirst(Node*& head, char name[], int math, int physic, int chemis);
void insertToAfterFirst(Node*& head, char name[], int math, int physic, int chemis);
void insertToAfterName(Node*& head, char name[], int math, int physic, int chemis, string NamE);
void topKStudentAverageScore(Node* head, int top);
#endif // !_FUNCTION_



