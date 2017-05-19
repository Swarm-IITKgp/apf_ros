//
//  Filter_waypoint.cpp
//
//
//  Created by muskaan on 15/05/17.
//
//

#include <vector>
using namespace std;
#include "apf.h"

vector<vector<int> > Filter_waypt::Filter_waypoint(vector <vector<int> > A, double **map, int mx, int my){


    int m = A.size();
/*
    Mat img(mx, my, CV_8UC3, Scalar(0,0,0));
    namedWindow("filtered path",WINDOW_NORMAL);
    imshow("filtered path",img);
  */
    while(1){
/*
        for(int i=0; i<m; i++){
            img = draw(img, A[i][0], A[i][1], 1, 255);
        }*/
        int count = 0, midx, midy;
        for(int i=0; i<m-2; i++){

            midx = (A[i][0] + A[i+2][0])/2;
            midy = (A[i][1] + A[i+2][1])/2;

            if(map[midx][midy] < map[A[i+1][0]][A[i+1][1]]){

                A[i+1][0] = midx;
                A[i+1][1] = midy;
                count += 1;
            }else if(map[midx][midy] == map[A[i+1][0]][A[i+1][1]]){

                if(midx != A[i+1][0] || midy != A[i+1][1] ){

                    A[i+1][0] = midx;
                    A[i+1][1] = midy;
                    count += 1;

                }

            }
        }
/*
        for(int i=0; i<m; i++){
            img = draw(img, A[i][0], A[i][1], 1, 0);
        }
        imshow("filtered path", img);
        waitKey(20);
*/
        if(count < m/10)
            break;
    }

/*    waitKey(0);
    destroyAllWindows();*/
    return A;
}
