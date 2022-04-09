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
#include "BasicStructure.h"
using namespace std;

class PlyReading
{
public:
    PlyReading(string ifilePath,int ifileNumber);
    ~PlyReading();

    void Readin();
    int GetFileNumber() { return fileNumber; }
    int GetPointNumber(int ifileNumber) { return pointNumber.at(ifileNumber); }
    int GetFaceNumber(int ifileNumber) { return faceNumber.at(ifileNumber); }
    vector<point3Df> GetModel(int fileID) { return points->at(fileID); }
    point3Df GetPoint(int fileID, int pointId) { return points->at(fileID).at(pointId); }
    fnode GetFace(int fileID, int faceId) { return faces->at(fileID).at(faceId); }
private:
    string filePath;
    int fileNumber;
    vector<vector<fnode>>* faces;
    vector<vector<point3Df>>* points;
    vector<vector<point3Df>>* normals;
    vector<int>faceNumber;
    vector<int>pointNumber;
};

