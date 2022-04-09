#include "MeshIO.h"
MeshIO::MeshIO(string ifilePath) :filePath(ifilePath) {
	igl::readPLY(filePath, V, F);
}
void MeshIO::OutPutMesh(string outFolderPath, string outFileName) {
	if (_access(outFolderPath.c_str(), 0) == -1)	//����ļ��в�����
		_mkdir(outFolderPath.c_str());
	igl::writeOBJ(outFolderPath + "/" + outFileName, V, F);
}