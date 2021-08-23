#include<bits/stdc++.h>
using namespace std;
vector<double>transform(vector<vector<double>>mat,vector<double>p){
	vector<double>q(p.size());
	for(int i=0;i<p.size();i++){
		for(int j=0;j<p.size();j++){
			q[i]+=mat[i][j]*p[j];
		}
	}return q;
}
void rotateXY(double angle,vector<double>&point){
	vector<vector<double>>mat={
		{cos(angle),-sin(angle),0,0,0},
		{sin(angle),cos(angle),0,0,0},
		{0,0,1,0,0},
		{0,0,0,1,0},
		{0,0,0,0,1}
	};point=transform(mat,point);
}void rotateZX(double angle,vector<double>&point){
	vector<vector<double>>mat={
		{cos(angle),0,sin(angle),0,0},
		{0,1,0,0,0},
		{-sin(angle),0,cos(angle),0,0},
		{0,0,0,1,0},
		{0,0,0,0,1}
	};point=transform(mat,point);
}void rotateYZ(double angle,vector<double>&point){
	vector<vector<double>>mat={
		{1,0,0,0,0},
		{0,cos(angle),-sin(angle),0,0},
		{0,sin(angle),cos(angle),0,0},
		{0,0,0,1,0},
		{0,0,0,0,1}
	};point=transform(mat,point);
}void rotateZW(double angle,vector<double>&point){
	vector<vector<double>>mat={
		{1,0,0,0,0},
		{0,1,0,0,0},
		{0,0,cos(angle),-sin(angle),0},
		{0,0,sin(angle),cos(angle),0},
		{0,0,0,0,1}
	};point=transform(mat,point);
}
void rotate(double angle,vector<vector<double>>&points,vector<pair<vector<double>,vector<double>>>&edges){
	for(auto &point:points){
		rotateXY(angle,point);
		rotateZX(angle,point);
		rotateYZ(angle,point);
		rotateZW(angle,point);
	}for(auto &edge:edges){
		rotateXY(angle,edge.first);
		rotateXY(angle,edge.second);
		rotateZX(angle,edge.first);
		rotateZX(angle,edge.second);
		rotateYZ(angle,edge.first);
		rotateYZ(angle,edge.second);
		rotateZW(angle,edge.first);
		rotateZW(angle,edge.second);
	}
}
