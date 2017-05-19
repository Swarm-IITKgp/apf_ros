//
//  Field.cpp
//
//
//  Created by muskaan on 14/05/17.
//
//

#include <cmath>
#include "apf.h"


void Field::att_field(int px,int py,int mx,int my, double **res){

    double t,d;

    for(int x=0; x<mx; x++){
        for(int y=0; y<my; y++){

            t = 20;
            d = sqrt(pow((x-px),2) + pow((y-py),2));

            if(d > t)
                res[x][y] += 0.000001*(t*d - 0.5*pow(t, 2));
            else
                res[x][y] += 0.000001*(0.5*pow(d, 2));


        }
    }

}




void Field::rep_field(int px,int py,int sx,int sy,int mx,int my, double **res){

    double thr,d;


    for(int x=0; x<mx; x++){
        for(int y=0; y<my; y++){

            thr = 5;
            d = sqrt(pow((x-px), 2)/pow(sx, 2) + pow((y-py), 2)/pow(sy, 2));

            if(d < 1 && d != 0){

                if(pow((1 - 1/d), 2) < thr){
                    res[x][y] += 0.001*pow((1 - 1/d), 2);
                }
                else
                    res[x][y] += 0.001*thr;



            }
            else
                res[x][y] += 0;

        }
    }



    return;

}




void Field::guassian(int px,int py,int sx,int sy,int mx,int my, double **res){

    double d, pi = 3.14159,amp, e = 2.71828;

    for(int x=0; x<mx; x++){
        for(int y=0; y<my; y++){

           d = sqrt(pow((x-px), 2)/pow(sx, 2) + pow((y-py), 2)/pow(sy, 2));
            d *= -0.5;
            amp = 1/(2*pi*sx*sy);
            res[x][y] += 200*amp*pow(e, d);

        }
    }

    return;
}
