#include "Hex.h"


Hex::Hex(int size)
{
	len = (size > 0 ? size : 10);
	hex = new unsigned char[len];
	for (int i = 0; i < len; i++) {
		hex[i] = 0;
	}
}

const Hex &Hex::operator= (const Hex &right)
{
	if (&right != this)
	{
		if (len != right.len) {
			delete[] hex;
			len = right.len;
			hex = new unsigned char[len];
		}
		for (int i = 0; i < len; i++) {
			hex[i] = right.hex[i];
		}
	}
	return *this;
}

Hex::Hex()
{
	len = 10;
	hex = new unsigned char[len];
	for (int i = 0; i < len; i++) {
		hex[i] = 0;
	}
}

Hex::Hex(std::string num)
{
	len = num.length();
	hex = new unsigned char[len];
	for (int i = 0; i < len; i++) {
		hex[i] = 0;
	}
	for (int i = 0; i< len; i++) {
		hex[len-i-1] = num[i];
	}
}

void Hex::ShowHex()
{
	for (int i = 0; i < len; i++) {
		std::cout << hex[len - 1 - i];
	}
}

Hex Hex::operator+ (unsigned char a) {
	std::string str;
	std::string str2;
	std::string strs;
	str2[0] = a;
	for (int i = 0; i < len; i++) {
		str[i] = hex[len-1-i];
	}
	int num1 = std::stoi(str, 0, 16);
	int num2 = std::stoi(str2, 0, 16);
	int sum = num1 + num2;
	strs = std::to_string(sum);
	for (int i = 0; i < len; i++) {
		hex[len-i-1] = strs[i];
	}
	return *this;
}

Hex Hex::operator- (unsigned char a) {
	std::string str;
	std::string str2;
	std::string strs;
	str2[0] = a;
	for (int i = 0; i < len; i++) {
		str[i] = hex[len - 1 - i];
	}
	int num1 = std::stoi(str, 0, 16);
	int num2 = std::stoi(str2, 0, 16);
	int sum = num1 - num2;
	strs = std::to_string(sum);
	for (int i = 0; i < len; i++) {
		hex[len - i - 1] = strs[i];
	}
	return *this;
}

bool operator==(Hex left, Hex right) {
	std::string str;
	std::string str2;
	for (int i = 0; i < left.len; i++) {
		str[i] = left.hex[left.len - 1 - i];
	}
	for (int i = 0; i < right.len; i++) {
		str2[i] = right.hex[right.len - 1 - i];
	}
	int num1 = std::stoi(str, 0, 16);
	int num2 = std::stoi(str2, 0, 16);
	if (num1 == num2) return true;
	return false;
}

bool operator<=(Hex left, Hex right) {
	std::string str;
	std::string str2;
	for (int i = 0; i < left.len; i++) {
		str[i] = left.hex[left.len - 1 - i];
	}
	for (int i = 0; i < right.len; i++) {
		str2[i] = right.hex[right.len - 1 - i];
	}
	int num1 = std::stoi(str, 0, 16);
	int num2 = std::stoi(str2, 0, 16);
	if (num1 <= num2) return true;
	return false;
}

bool operator>=(Hex left, Hex right) {
	std::string str;
	std::string str2;
	for (int i = 0; i < left.len; i++) {
		str[i] = left.hex[left.len - 1 - i];
	}
	for (int i = 0; i < right.len; i++) {
		str2[i] = right.hex[right.len - 1 - i];
	}
	int num1 = std::stoi(str, 0, 16);
	int num2 = std::stoi(str2, 0, 16);
	if (num1 >= num2) return true;
	return false;
}

bool operator>(Hex left, Hex right) {
	std::string str;
	std::string str2;
	for (int i = 0; i < left.len; i++) {
		str[i] = left.hex[left.len - 1 - i];
	}
	for (int i = 0; i < right.len; i++) {
		str2[i] = right.hex[right.len - 1 - i];
	}
	int num1 = std::stoi(str, 0, 16);
	int num2 = std::stoi(str2, 0, 16);
	if (num1 > num2) return true;
	return false;
}

bool operator<(Hex left, Hex right) {
	std::string str;
	std::string str2;
	for (int i = 0; i < left.len; i++) {
		str[i] = left.hex[left.len - 1 - i];
	}
	for (int i = 0; i < right.len; i++) {
		str2[i] = right.hex[right.len - 1 - i];
	}
	int num1 = std::stoi(str, 0, 16);
	int num2 = std::stoi(str2, 0, 16);
	if (num1 < num2) return true;
	return false;
}

Hex::~Hex() 
{
	delete[] hex; 
}

unsigned char& Hex::operator[] (int subscript)
{
	if (subscript < 0 || subscript >= len)
	{
		std::cerr << "\n Index error: " << subscript << std::endl;
		exit(1); 
	}
	return hex[subscript]; 
}

std::ofstream& operator <<(std::ofstream out,Hex& num) {
	out.open(path);

	out << num.hex[i];
	return out;
}

std::ifstream& operator >>(std::ifstream in, std::string path) {
	std::string str;
	std::ifstream file(path);
	
	return file;
}