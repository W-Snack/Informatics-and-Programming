#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Hex
{
private:
	int len;
	unsigned char *hex;
	std::string path;
public:
	Hex();
	Hex(int len);
	Hex(std::string num);
	void ShowHex();
	const Hex &operator=(const Hex&);
	void SetPath(std::string path);
	Hex operator+(unsigned char a);
	Hex operator-(unsigned char a);
	friend bool operator==(Hex& left, Hex& right);
	friend bool operator>=(Hex& left, Hex& right);
	friend bool operator<=(Hex& left, Hex& right);
	friend bool operator<(Hex& left, Hex& right);
	friend bool operator>(Hex& left, Hex& right);
	unsigned char& operator[] (int);
	friend std::ofstream& operator<<(std::ofstream out,Hex& hex);
	friend std::ifstream& operator>>(std::ifstream in,Hex& hex);
	~Hex();
};

