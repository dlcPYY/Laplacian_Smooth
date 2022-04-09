#pragma once
#include"MeshIO.h"
class LaplacianSmooth
{
public:
	static void Smooth(MatrixXd& V, MatrixXi& F, int t) {
		std::vector < vector<int >>linkList(V.rows());
		for (int i = 0; i < F.rows(); i++) {
			int pointID0 = F(i, 0);
			int pointID1 = F(i, 1);
			int pointID2 = F(i, 2);
			linkList.at(pointID0).push_back(pointID1); linkList.at(pointID1).push_back(pointID0);
			linkList.at(pointID1).push_back(pointID2); linkList.at(pointID2).push_back(pointID1);
			linkList.at(pointID2).push_back(pointID0); linkList.at(pointID0).push_back(pointID2);
		}
		for (int i = 0; i < t; i++) {
			vector<float > tempPoint[3];
			for (int j = 0; j < V.rows(); j++) {
				float x = V(j, 0);
				float y = V(j, 1);
				float z = V(j, 2);
				for (int k = 0; k < linkList.at(j).size(); k++) {
					x += V(linkList.at(j).at(k), 0);
					y += V(linkList.at(j).at(k), 1);
					z += V(linkList.at(j).at(k), 2);
				}
				x /= (linkList.at(j).size() + 1);
				y /= (linkList.at(j).size() + 1);
				z /= (linkList.at(j).size() + 1);
				tempPoint[0].push_back(x);
				tempPoint[1].push_back(y);
				tempPoint[2].push_back(z);
			}
			for (int j = 0; j < V.rows(); j++) {
				V(j, 0) = tempPoint[0].at(j);
				V(j, 1) = tempPoint[1].at(j);
				V(j, 2) = tempPoint[2].at(j);
			}
		}
	}
};

