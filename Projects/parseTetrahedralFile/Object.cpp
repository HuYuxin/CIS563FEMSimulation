//
// Created by linghan on 2/20/18.
//

#include "Object.h"

#include <fstream>

Object::Object(std::string fileName) {

    std::ifstream infile(fileName);
    std::string line;
    int totalPoints = -1;
    int totalTetra = -1;
    if(infile.fail()){
        infile.close();
    }

    while(std::getline(infile, line)){
        std::istringstream iss(line);
        if(totalPoints > 0){
            double x;
            iss >> x;
            double y;
            iss >> y;
            double z;
            iss >> z;
            particle p(x,y,z);
            particles.push_back(p);
            totalPoints --;
        }else if(totalTetra > 0){
            int totalP = 0;
            iss >> totalP;
            std::vector<int> edgeP;
            while(totalP > 0){
                int p = 0;
                iss>>p;
                edgeP.push_back(p+1); //the index stored in .vtk file stars counting from 0, where in .poly file index starts counting from 1
                totalP--;
            }
            tetrahedral Ti(0,0,0,0);
            for(unsigned int i=0; i<edgeP.size()-1; i++) {
                for (unsigned int j = i + 1; j < edgeP.size(); j++) {
                    edges.push_back(std::pair<int, int>(edgeP[i], edgeP[j]));
                }
                //tetrahedral.push_back(edgeP[i]);
                Ti.pIndex[i] = edgeP[i];
            }
            //***************TODO: Calculate Dm, DmInverse, and Volume of each tetrahedral****************//


            tetrahedrals.push_back(Ti);
            totalTetra--;
        }else{
            std::string firstWord = "";
            iss >> firstWord;
            if(firstWord == "POINTS"){
                iss >> totalPoints;
            }
            if(firstWord == "CELLS"){
                iss >> totalTetra;
            }else{
                continue;
            }
        }

    }
    infile.close();
}


Object::~Object() {
    std::vector<particle> particlesTemp;
    std::vector<std::pair<int, int>> edgesTemp;
    std::vector<tetrahedral> tetrahedralsTemp;

    particlesTemp.swap(particles);
    edgesTemp.swap(edges);
    tetrahedralsTemp.swap(tetrahedrals);
}

void Object::evaluateForce(){
    //TODO:evaluate force on each tetrahedral
}

void Object::updateParticles(float simulationTimeStep){
    //TODO: update particles position and velocity
}