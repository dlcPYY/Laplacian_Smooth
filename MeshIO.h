#pragma once
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <io.h>
#include <direct.h>
#include <string>

#include <igl/avg_edge_length.h>
#include <igl/cotmatrix.h>
#include <igl/invert_diag.h>
#include <igl/massmatrix.h>
#include <igl/parula.h>
#include <igl/per_corner_normals.h>
#include <igl/per_face_normals.h>
#include <igl/per_vertex_normals.h>
#include <igl/principal_curvature.h>
#include <igl/read_triangle_mesh.h>
#include <igl/opengl/glfw/Viewer.h>
#include <igl/cotmatrix.h>
#include <igl/massmatrix.h>
#include <igl/invert_diag.h>
#include <igl/gaussian_curvature.h>
#include <igl/massmatrix.h>
#include <igl/invert_diag.h>
#include <igl/readOFF.h>
#include <igl/readSTL.h>
#include <igl/readMESH.h>

using namespace std;
using namespace Eigen;

class MeshIO
{
public:
	MeshIO(string ifilePath);//文件夹路径，文件个数
	void OutPutMesh(string outFolderPath, string outFileName);
	MatrixXd& GetLibiglPoint() { return V; }
	MatrixXi& GetLibiglFaces() { return F; }
	MatrixXd& GetLibiglNormals() { return N; }
private:
	string filePath;
	MatrixXd V;
	MatrixXi F;
	MatrixXd N;
};

