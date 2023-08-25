#include "ofApp.h"
#include <iostream>
#include <vector>
#include <random>

// CORE APP LOGIC - these are the main loop that are implemented in the main.cpp init

ofColor red = ofColor(255, 0, 0);
ofColor blue = ofColor(0, 0, 255);

void ofApp::createParticles(int n1, int n2, ofColor color1, ofColor color2, int radius1, int radius2) {
    
    for (int i = 0; i < n1; ++i) {
        particle p;
        p.position = ofVec2f(ofRandomWidth(), ofRandomHeight());
        p.speed = ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1));
        p.color = color1;
        p.radius = radius1;
        pool.push_back(p);
    }

    for (int i = 0; i < n2; ++i) {
        particle p;
        p.position = ofVec2f(ofRandomWidth(), ofRandomHeight());
        p.speed = ofVec2f(0,0);
        p.color = color2;
        p.radius = radius2;
        pool.push_back(p);
    }
}

void ofApp::rules(int range, float gforce) {
    for (auto& currentParticle : pool) {

        for (auto& otherParticle : pool) {
            if (&currentParticle != &otherParticle) {
                float distance = currentParticle.position.distance(otherParticle.position);

                if (distance < range) {
                    ofVec2f orientation = otherParticle.position - currentParticle.position;
                    orientation.normalize();

                    float forceMagnitude = (gforce / (distance * distance));
                    ofVec2f force = forceMagnitude * orientation;

                    if (currentParticle.color == red && otherParticle.color == blue) {
                        currentParticle.speed += -force;
                    }

                    if (currentParticle.color == blue && otherParticle.color == red) {
                        currentParticle.speed += -force;
                    }

                    if (currentParticle.color == red && otherParticle.color == red) {
                        currentParticle.speed += force; 
                    }
                }
            }
        }
        currentParticle.speed.limit(2);
        currentParticle.speed *= 0.75;
        currentParticle.position += currentParticle.speed; // Update position after applying forces

        if (currentParticle.position.x > ofGetWidth() || currentParticle.position.x < 0) {
            currentParticle.position.x = ofClamp(currentParticle.position.x, 0, ofGetWidth());
            currentParticle.speed.x *= -1;
        }

        if (currentParticle.position.y > ofGetHeight() || currentParticle.position.y < 0) {
            currentParticle.position.y = ofClamp(currentParticle.position.y, 0, ofGetHeight());
            currentParticle.speed.y *= -1;
        }



    }
}



void ofApp::setup() {
    ofBackground(0, 0, 0);
	
    createParticles(200, 1000, red, blue, 2, 2);

}


void ofApp::update() {	

    rules(450, 50);

}


void ofApp::draw() {
    ofBackground(0, 0, 0);

    for (const auto& particle : pool) {
        ofSetColor(particle.color);
        ofDrawCircle(particle.position, particle.radius);
    }

}



















