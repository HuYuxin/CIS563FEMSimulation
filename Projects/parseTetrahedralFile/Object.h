//
// Created by linghan on 2/20/18.
//

#include <Eigen/Core>
#include <Eigen/Dense>
#include <vector>

using Eigen::MatrixXd;

#ifndef CISPBA_OBJECT_H
#define CISPBA_OBJECT_H

class particle{
public:
    double posx;
    double posy;
    double posz;
    double mass;
    double velx;
    double vely;
    double velz;
    double fx;
    double fy;
    double fz;
    particle(double a, double b, double c):posx(a), posy(b), posz(c){
        mass = 0.01;
        velx = 0.0;
        vely = 0.0;
        velz = 0.0;
        fx = 0.0;
        fy = 0.0;
        fz = 0.0;
    }
};

class tetrahedral{
public:
    int pIndex[4];

    MatrixXd Dm;
    MatrixXd DmInverse;
    double volume;

    tetrahedral(int p1, int p2, int p3, int p4){
        pIndex[0] = p1;
        pIndex[1] = p2;
        pIndex[2] = p3;
        pIndex[3] = p4;
    }

};

class Object {

public:
    std::vector<particle> particles;
    std::vector<std::pair<int, int>> edges;
    std::vector<tetrahedral> tetrahedrals;

    Object(){}
    Object(std::string fileName);
    ~Object();

    void evaluateForce();
    void updateParticles(float simulationTimeStep);
};


#endif //CISPBA_OBJECT_H
