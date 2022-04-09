#include"BasicStructure.h"
#include"FileList.h"
#include "LaplacianSmooth.h"
#include"MeshIO.h"

#include <fstream>
#include <vector>

int main() {
	
	FileList* fileList = new FileList(FileList::GetConfig(),"ply");
	for (int i = 0; i < fileList->GetFileNumber(); i++) {
		MeshIO* meshIO = new MeshIO(fileList->GetFolderName() + fileList->GetFileName(i));
		LaplacianSmooth::Smooth(meshIO->GetLibiglPoint(),meshIO->GetLibiglFaces(), 3);
		meshIO->OutPutMesh(fileList->GetFolderName() + "Smooth", std::to_string(i+1)+".obj");
		cout << i << endl;
	}
	return 0;
}