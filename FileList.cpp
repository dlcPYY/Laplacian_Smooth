#include "FileList.h"
FileList::FileList(string iffolderPath,string type) :folderPath(iffolderPath) {
	getFiles(folderPath, files, type);
	fileNumber = files.size();
}
void FileList::getFiles(string path, vector<string>& files,string type)
{/*
	string findPath = path + "*." + type;
	_finddata_t fileinfo;

	//第一次查找
	long handle = _findfirst(findPath.c_str(), &fileinfo);
	if (handle == -1)
	{
		printf("查找文件失败");
		return;
	}
	do
	{
		//打印出文件名
		printf("%s \n", fileinfo.name);
		files.push_back(fileinfo.name);
	} while (!_findnext(handle, &fileinfo));

	// 记得要关闭
	_findclose(handle);
	*/
	for (int i = 1; i <= 1000; i++) {
		string fileN = std::to_string(i) + ".ply";
		files.push_back(fileN);
	}
}