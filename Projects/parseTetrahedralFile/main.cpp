//
// Created by yuxinhu on 2/19/18.
//

#include <Eigen/Core>
#include <Eigen/Dense>

#include <fstream>
#include <iostream>

#include "Object.h"

using Eigen::MatrixXd;


//Write the parse result into .poly file so we can load it into Houdini to check the tetrahedral result
bool writePolyFile(std::string fileName, std::vector<particle>& particles, std::vector<std::pair<int, int>>& edges){
    bool result = false;
    std::ofstream myfile;
    myfile.open (fileName);
    if(myfile.fail()){
        myfile.close();
        return result;
    }
    myfile << "POINTS\n";
    for(unsigned int i=0; i<particles.size(); i++){
        myfile << std::to_string(i+1)<<":"
               <<" "<<particles[i].posx
               <<" "<<particles[i].posy
               <<" "<<particles[i].posz<<"\n";
    }
    myfile<<"POLYS\n";
    for(unsigned int i=0; i<edges.size(); i++){
        myfile<<std::to_string(i+1)<<":";
        myfile << " "<<std::to_string(edges[i].first);
        myfile << " "<<std::to_string(edges[i].second);
        myfile<<"\n";

    }
    myfile<<"END\n";
    myfile.close();
    result = true;
    return result;
}

void writeBgeoFile(std::vector<particle>& particles, std::string fileName){
   //TODO: write the particle position and velocity in bgeo file
}

int main(int argc, char* argv[]) {

    Object cube("cubeTest.1.vtk");

    //Write the parse result into .poly file so we can load it into Houdini to check the tetrahedral result
    if(!writePolyFile("cubeTestOutput.poly", cube.particles, cube.edges)){
        std::cout<<"write poly file error!! check the .poly file"<<std::endl;
    }


    //Start Simulation
    //Simulate 24 frames per second, let's run 10 seconds, so 240 frames in total.
    //For each frame, we take 10 timeStep, total of 2400 timeStep
    int simulationTime = 30; //Seconds
    int framesPerSecond = 24;
    int timeStepCountPerFrame = 30;
    float simulationTimeStep = (1.0/framesPerSecond)/simulationTime;
    int totalTimeStep = timeStepCountPerFrame * framesPerSecond * simulationTime;
    int frameNum = 0;
    for(int i=0; i < totalTimeStep; i=i + timeStepCountPerFrame){
        for(int j=i; j < i+timeStepCountPerFrame; j++){
            //*************TODO: eveluate force on each tetrahedral************//
            cube.evaluateForce();



            //*************TODO: update particle velocity and position*********//
            cube.updateParticles(simulationTimeStep);


            //*************TODO: boundary and collision checking************//


        }

        //*************TODO: write the particle position and velocity in bgeo file***********//
        writeBgeoFile(cube.particles, "femsimulation"+std::to_string(frameNum)+".bgeo");
        frameNum++;
    }
    return 0;
}