#pragma once

#include "ofMain.h"

// Particle Life Simulation 2023 - Antonio Logarzo CC License

class particle {

public:

	ofVec2f position;
	ofVec2f speed;
	int radius;
	ofColor color;

};

class ofApp : public ofBaseApp{

	std::vector<particle> pool;

	public:
		void setup();
		void update();
		void draw();
		void createParticles(int n1, int n2, ofColor color1, ofColor color2, int radius1, int radius2);
		void rules(int range, float gforce); 



};
