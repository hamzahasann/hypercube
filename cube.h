#include<bits/stdc++.h>
using namespace std;
class Cube{
public:
	int dim;
	double length;
	vector<vector<double>>points,points2d;
	vector<pair<vector<double>,vector<double>>>edges,edges2d;

	void create(int n,double l){
		length=l;dim=n;
		points.resize((1<<n),vector<double>(n));
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<n;j++){
				if(i&(1<<j))points[i][j]=l;
				else points[i][j]=-l;
			}
		}points2d=points;
		for(auto p1:points){
			vector<double>p2=p1;
			for(int i=0;i<n;i++){
				if(p1[i]==l){
					p2[i]=-l;
					edges.push_back({p1,p2});
					p2[i]=l;
				}
			}
		}

		edges2d=edges;
	}
};
