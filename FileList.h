#pragma once
#include <vector>
#include <iostream>
#include <cstdio>
#include<io.h>
#include <cstring>
#include <string>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include <ctime>
using namespace std;
class FileList
{
public:
	FileList(string iffolderPath, string type);
	int GetFileNumber() { return fileNumber; };
	string GetFolderName() { return folderPath; };
	string GetFileName(int i) { return files.at(i); };
	void getFiles(string path, vector<string>& files, string type);
	static string GetConfig() {
		std::ifstream in("./config");
		if (!in.is_open())
		{
			std::cout << "Error opening Configure file!";
			return "ERROR";
		}
		char buffer[256];//��ȡ�ļ�����
		std::string inputBuffer;//Ϊ�˶����ļ��ı��ڸ�ʽת��
		in.getline(buffer, 200);
		in.close();
		inputBuffer = buffer;
		return inputBuffer;
	}
private:
	int fileNumber;
	string folderPath;
	vector<string> files;
};

