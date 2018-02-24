//
// Created by linghan on 2/23/18.
//

#ifndef CISPBA_EULER_H
#define CISPBA_EULER_H

void updateParticlesFE(std::vector<particle>& particles, float dT){
    //TODO: update particles position and velocity

    for(particle p : particles) {
        // update position (x_new = x_old + dT * v_old)
        p.posx = p.posx + dT * p.velx;
        p.posy = p.posy + dT * p.vely;
        p.posz = p.posz + dT * p.velz;

        // update velocity (v_new = v_old + dT * f / m)
        p.velx = p.velx + dT * p.fx * (1.0 / p.mass);
        p.vely = p.vely + dT * p.fy * (1.0 / p.mass);
        p.velz = p.velz + dT * p.fz * (1.0 / p.mass);
    }


}

void updateParticlesBE(std::vector<particle>& particles, float dT){
    //TODO: update particles position and velocity
}

#endif //CISPBA_EULER_H
