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
#include <ctime>
using namespace std;
struct matrix3f
{
    float element[3][3];
 //   matrix3f operator + (const point3Df& b) { return point3Df{ this->x + b.x,this->y + b.y ,this->z + b.z }; }
 //   point3Df operator - (const point3Df& b) { return point3Df{ this->x - b.x,this->y - b.y ,this->z - b.z }; }
    matrix3f operator * (const matrix3f& b) {
        matrix3f temp;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                //this的第一行，b的第一列
                temp.element[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    temp.element[i][j] += this->element[i][k] * b.element[k][j];
                }
            }
        }
        return temp;
    }
    
};
struct point3Df
{
    float x, y, z;
    point3Df operator + (const point3Df& b) { return point3Df{ this->x + b.x,this->y + b.y ,this->z + b.z }; }
    point3Df operator - (const point3Df& b) { return point3Df{ this->x - b.x,this->y - b.y ,this->z - b.z }; }
    float operator * (const point3Df& b) { return this->x * b.x + this->y * b.y + this->z * b.z; }
    point3Df operator / (const float& b) { return point3Df{ this->x / b,this->y / b ,this->z / b }; }
    bool operator == (const point3Df& b) {
        return fabs(this->x - b.x < 0.001) && fabs(this->y - b.y < 0.001) && fabs(this->z - b.z < 0.001);
    }

};
struct fnode {
    int pointNumber;
    vector<int>pointId;
};

struct colorRGB {
    int R, G, B;
};
struct triEdge {
    int pointId1, pointId2;
};