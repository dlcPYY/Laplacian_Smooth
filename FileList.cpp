#include "FileList.h"
FileList::FileList(string iffolderPath,string type) :folderPath(iffolderPath) {
	getFiles(folderPath, files, type);
	fileNumber = files.size();
}
void FileList::getFiles(string path, vector<string>& files,string type)
{/*
	string findPath = path + "*." + type;
	_finddata_t fileinfo;

	//��һ�β���
	long handle = _findfirst(findPath.c_str(), &fileinfo);
	if (handle == -1)
	{
		printf("�����ļ�ʧ��");
		return;
	}
	do
	{
		//��ӡ���ļ���
		printf("%s \n", fileinfo.name);
		files.push_back(fileinfo.name);
	} while (!_findnext(handle, &fileinfo));

	// �ǵ�Ҫ�ر�
	_findclose(handle);
	*/
	for (int i = 1; i <= 1000; i++) {
		string fileN = std::to_string(i) + ".ply";
		files.push_back(fileN);
	}
}