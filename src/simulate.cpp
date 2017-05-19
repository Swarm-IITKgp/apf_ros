#include "ros/ros.h"
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "apf.h"

using namespace std;



typedef struct Pointp{
    int x;
    int y;
}Pointp;

typedef struct element{
    Pointp P;
    short unsigned int type;
    int Sy, Sx;
}element;



vector<vector<int> > simulate::simulation(){
    vector < vector<int> > points;
//    vector <int> coordinates(2), X, Y, TYPE, SIGMA_X, SIGMA_Y;

    vector <int> coordinates(2);
    int alpha = 90000;
    vector<int> X; X.push_back(200); X.push_back(55); X.push_back(400);
    vector<int> Y; Y.push_back(200); Y.push_back(62); Y.push_back(350);
    vector<int> SIGMA_X; SIGMA_X.push_back(30); SIGMA_X.push_back(100); SIGMA_X.push_back(100);
    vector<int> SIGMA_Y; SIGMA_Y.push_back(30); SIGMA_Y.push_back(100); SIGMA_Y.push_back(100);
    vector<int> TYPE; TYPE.push_back(0); TYPE.push_back(1); TYPE.push_back(2);
    int map_sx = 500;
    int map_sy = 500;

//    int map_sx , map_sy;

    Pointp map_s;

    element E;
    ROS_INFO("sfufwufwugwulfgleglwfglw");

/*    fstream fp;
    fp.open("map.txt", ios::in | ios::out);

    char flag='Y';


    fp.read(reinterpret_cast<char*>(&map_s), sizeof(map_s));
       map_sx = map_s.x;
    map_sy = map_s.y;

    while(fp){

        fp.read(reinterpret_cast<char*>(&E), sizeof(E));
        if(fp.eof())
            break;

        X.push_back(E.P.x);
        Y.push_back(E.P.y);
        TYPE.push_back(E.type);
        SIGMA_X.push_back(E.Sx);
        SIGMA_Y.push_back(E.Sy);


    }
    fp.close();
*/



    int m = sizeof(X);

    int x, y, x1, y1, temp0, temp1, Dx ,Dy;

    double **Map = (double**)calloc(map_sx, sizeof(double*));
    for(int i=0; i<map_sx; i++)
        Map[i] = (double*)calloc(map_sy, sizeof(double));

    c_map MAP;
    MAP.create_map(map_sx, map_sy ,X, Y,SIGMA_X,SIGMA_Y,TYPE, Map);

    for(int i=0; i<m; i++){

        if(TYPE[i] == 2){

             Dx = X[i];
             Dy = Y[i];

        }
        if(TYPE[i] == 1){

            x = x1 = X[i];
            y = y1 = Y[i];

        }

    }

    coordinates[0] = x;
    coordinates[1] = y;
    points.push_back(coordinates);
       int count = 0;

    while( abs(x-Dx) > 5 or abs(y-Dy) > 5 ){

//        img = draw(img, x, y, 0, 0);
//        imshow("path",img);
//        waitKey(10);

        //checking if bot is stationary for long
        if(abs(x - x1)<1 and abs(y - y1) < 1)
            count += 1;
        else
            count = 0;

        //to avoid local minima

        if(count > 10){

            int m = 100000;
            for(int i=-10; i<=11; i++){
                for(int j=-10; j<=11; j++){

                    if(i != 0 || j != 0 ){

                        if(Map[x+i][y+j] - Map[x][y] < m){

                            m = Map[x+i][y+j] - Map[x][y];
                            temp0 = x - 1.5*alpha*m;
                            temp1 = y - 1.5*alpha*m;
                        }
                    }
                }
            }

            x = temp0;
            y = temp1;
            count = 0;
            coordinates[0] = x;
            coordinates[1] = y;
            points.push_back(coordinates);
                        continue;

        }

        x1 = x;
        y1 = y;
        temp0 = x - alpha*(Map[x+3][y] - Map[x][y]);
        temp1 = y - alpha*(Map[x][y+3] - Map[x][y]);
        x = temp0;
        y = temp1;
        coordinates[0] = x;
        coordinates[1] = y;
        points.push_back(coordinates);
    }
//    waitKey(1000);

    for(int i=0; i<map_sx; i++){
        for(int j=0; j<map_sy; j++){

            Map[i][j] = 0;

        }

    }

    MAP.filter_map(map_sx, map_sy, X, Y, SIGMA_X, SIGMA_Y, TYPE, Map);

    Filter_waypt F;
    points=F.Filter_waypoint(points, Map, map_sx, map_sy);
    for(int i=0; i< map_sx; i++)
        free(Map[i]);
    free(Map);
    // for(int i = 0; i < map_sx; ++i)
    //   delete [] Map[i];
    // delete [] Map;

    return points;

}
