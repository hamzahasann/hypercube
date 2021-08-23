#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include "cube.h"
#include "rotate.h"
using namespace std;

const float WIDTH=800,HEIGHT=800;
const double camDistance=500;
const double M=400;
sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT),"Hypercube",sf::Style::Default);


void draw(vector<vector<double>>&points2d,vector<pair<vector<double>,vector<double>>>&edges2d){
	for(auto point:points2d){
		sf::CircleShape circle(3.f);
		circle.setPosition(WIDTH/2+point[0]-3,HEIGHT/2-point[1]-3);
		window.draw(circle);
	}for(auto edge:edges2d){
		sf::Vertex line[]={
			sf::Vertex(sf::Vector2f(WIDTH/2+edge.first[0],HEIGHT/2-edge.first[1])),
			sf::Vertex(sf::Vector2f(WIDTH/2+edge.second[0],HEIGHT/2-edge.second[1]))
		};
		window.draw(line,2,sf::Lines);
	}
}
void lowdim(vector<double>&point){
	for(int i=0;i<point.size()-1;i++){
		point[i]/=(camDistance+point[point.size()-1])/M;
	}point.pop_back();
}
void project2d(vector<vector<double>>&points,vector<pair<vector<double>,vector<double>>>&edges,vector<vector<double>>&points2d,vector<pair<vector<double>,vector<double>>>&edges2d){
	int i=0;
	for(auto point:points){
		while(point.size()>2)lowdim(point);
		points2d[i]=point;i++;
	}i=0;
	for(auto edge:edges){
		while(edge.first.size()>2)lowdim(edge.first);
		while(edge.second.size()>2)lowdim(edge.second);
		edges2d[i].first=edge.first;
		edges2d[i].second=edge.second;
		i++;
	}
}
int main(){
	double angle=0.01;
	Cube cube;
	cube.create(4,100);
	window.setFramerateLimit(60);
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type==sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				window.close();
			}
		}
		window.clear(sf::Color(0,0,0));
		rotate(angle,cube.points,cube.edges);
		project2d(cube.points,cube.edges,cube.points2d,cube.edges2d);
		draw(cube.points2d,cube.edges2d);
		window.display();
	}


}
