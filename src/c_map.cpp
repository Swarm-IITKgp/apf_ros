//
//  create_map.cpp
//
//
//  Created by muskaan on 15/05/17.
//
//
#include <stdlib.h>
#include <vector>
#include "apf.h"
using namespace std;

void c_map::create_map(int mx,int my,vector <int> X,vector <int> Y,vector <int> SIGMA_X,vector <int> SIGMA_Y,vector <int> TYPE, double **map){


    Field F;
    int n = X.size();

    for(int j=0; j<n; j++){

        if(TYPE[j] == 0){
            F.rep_field(X[j],Y[j],SIGMA_X[j],SIGMA_Y[j],mx,my,map);


        }else if(TYPE[j] == 2){
           F.att_field(X[j],Y[j],mx,my,map);

        }
    }

}



void c_map::filter_map(int mx,int my,vector <int> X,vector <int> Y,vector <int> SIGMA_X,vector <int> SIGMA_Y,vector <int> TYPE, double **map){

    Field F;
    double **res = (double**)calloc(mx, sizeof(double*));
    for(int i=0; i<mx; i++)
        res[i] = (double*)calloc(my, sizeof(double));
    // double** res = new double*[mx];
    // for(int i = 0; i < mx; ++i)
    //     res[i] = new double[my];

    int n = 3;
    for(int j=0; j<n; j++){

        if(TYPE[j] == 0){
            F.rep_field(X[j],Y[j],SIGMA_X[j],SIGMA_Y[j],mx,my,res);
            for(int x=0; x<mx; x++)
                for(int y=0; y<my; y++)
                    map[x][y] += 2*res[x][y];



        }

    }
    for(int i=0; i<mx; i++)
        free(res[i]);
    free(res);
    // for(int i = 0; i < mx; ++i)
    //   delete [] res[i];
    // delete [] res;
    return ;

}
