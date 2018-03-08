//
// Created by yuxinhu on 3/3/18.
//
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

bool parsePlyFile(std::string fileName, std::vector<Eigen::Vector3d>& particlePos, std::vector<std::vector<int>>& faceIndex){
    bool result = false;
    std::ifstream infile(fileName);
    std::string line;
    std::string firstWord;
    std::string secondWord;

    int vertexNum = 0;
    int faceNum = 0;
    if(infile.fail()){
        infile.close();
        return result;
    }

    //read file line by line
    bool startReadingProperty = false;
    while(std::getline(infile, line)){
        std::istringstream iss(line);
        if(!startReadingProperty){
            iss>>firstWord;
            if(firstWord == "element") {
                iss >> secondWord;
                if (secondWord == "vertex") {
                    iss >> vertexNum;
                }
                if (secondWord == "face") {
                    iss >> faceNum;
                }
            }else if(firstWord == "end_header"){
                startReadingProperty = true;
            }
        }else{
            if(vertexNum > 0){
                double x = 0.0;
                iss >> x;
                double y = 0.0;
                iss >> y;
                double z = 0.0;
                iss >> z;
                Eigen::Vector3d pos;
                pos<<x,y,z;
                particlePos.push_back(pos);
                vertexNum --;
            }else if(faceNum > 0){
                int faceVerticeNum = 0;
                iss >> faceVerticeNum;
                std::vector<int> faceVerticeIndice;
                while(faceVerticeNum > 0){
                    int index = 0;
                    iss >> index;
                    faceVerticeIndice.push_back(index);
                    faceVerticeNum--;
                }
                faceIndex.push_back(faceVerticeIndice);
                faceNum --;
            }else{
                std::cout<<"extra vertice and faces found!!"<<std::endl;
            }
        }

    }
    infile.close();
    result = true;
    return result;
}

bool parseObjFile(std::string fileName, std::vector<Eigen::Vector3d>& particlePos, std::vector<std::vector<int>>& faceIndex){
    bool result = false;
    std::ifstream infile(fileName);
    std::string line;
    std::string firstWord;

    if(infile.fail()){
        infile.close();
        return result;
    }

    //read file line by line
    while(std::getline(infile, line)){
        std::istringstream iss(line);
        iss>>firstWord;
        if(firstWord == "v"){
            double x = 0.0;
            iss >> x;
            double y = 0.0;
            iss >> y;
            double z = 0.0;
            iss >> z;
            Eigen::Vector3d pos;
            pos<<x,y,z;
            particlePos.push_back(pos);
        }else if(firstWord == "f"){
            std::string secondWord;
            std::vector<int> faceVerticeIndice;
            while(iss >> secondWord){
                int idx = secondWord.find("/");
                int faceIdx = stoi(secondWord.substr(0,idx));
                faceVerticeIndice.push_back(faceIdx);
            }
            faceIndex.push_back(faceVerticeIndice);
        }else{
            //do nothing skip the line
        }
    }
    infile.close();
    result = true;
    return result;
}

bool writePolyFile(std::string fileName, std::vector<Eigen::Vector3d>& verticePos, std::vector<std::vector<int>>& faces){
    bool result = false;
    std::ofstream myfile;
    myfile.open (fileName);
    if(myfile.fail()){
        myfile.close();
        return result;
    }

    int verticeNum = verticePos.size();
    int faceNum = faces.size();
    myfile<<verticeNum<<" "<<3<<" "<<0<<" "<<0<<"\n";
    myfile<<"\n";

    for(unsigned int i=0; i<verticePos.size(); i++){
        myfile << i+1
               <<" "<<verticePos[i](0)
               <<" "<<verticePos[i](1)
               <<" "<<verticePos[i](2)<<"\n";
    }
    myfile<<"\n";

    myfile<<faceNum<<" "<<0<<"\n";
    for(unsigned int i=0; i<faces.size(); i++){
        myfile<<1<<"\n";
        std::vector<int> currentFace = faces[i];
        int currentFaceVertNum = currentFace.size();
        myfile<<currentFaceVertNum;
        for(int j = 0; j<currentFaceVertNum; j++){
            myfile<<" "<<currentFace[j];
        }
        myfile<<"\n";
    }
    myfile<<0<<"\n";
    myfile<<0<<"\n";
    myfile.close();
    result = true;
    return result;
}

int main(int argc, char* argv[]){
    std::vector<Eigen::Vector3d> verticePos;
    std::vector<std::vector<int>> faceVertIndice;
    /*if(!parsePlyFile("dragon_vrip_res4.ply",verticePos, faceVertIndice)){
        std::cout<<"parse error!"<<std::endl;
    }*/
    if(!parseObjFile("werewolfRemesh.obj", verticePos, faceVertIndice)){
        std::cout<<"parse obj file error!"<<std::endl;
    }

    //std::cout<<"number of vertice: "<<verticePos.size()<<std::endl;
    //std::cout<<"number of faces: "<<faceVertIndice.size()<<std::endl;

    if(!writePolyFile("werewolf.poly",verticePos,faceVertIndice)){
        std::cout<<"write poly file error!"<<std::endl;
    }

    return 0;
}
