//
//  simulation.cpp
//
//
//  Created by muskaan on 15/05/17.
//
//
#include "ros/ros.h"
#include <stdio.h>
#include <iostream>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/core/core.hpp>
#include "geometry_msgs/Pose.h"
#include <sstream>

//using namespace cv;

#include <vector>
#include <stdlib.h>
#include <math.h>
#include "apf.h"

using namespace std;

int main(int argc, char **argv){

    ros::init(argc, argv, "motion_planner");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<geometry_msgs::Pose>("Bot", 100);
    ros::Rate loop_rate(10);
    int count = 0;

    simulate S;
    vector< vector<int> > A;
   A=S.simulation();

  // double **Map = (double**)calloc(500, sizeof(double*));
  // for(int i=0; i<500; i++)
  //     Map[i] = (double*)calloc(500, sizeof(double));

  // c_map MAP;
  // vector<int>  X,Y,SIGMA_X,SIGMA_Y,TYPE;
  // X.push_back(0);
  // Y.push_back(0);
  // SIGMA_X.push_back(0);
  // SIGMA_Y.push_back(0);
  // TYPE.push_back(0);
  // MAP.create_map(500, 500, X, Y,SIGMA_X,SIGMA_Y,TYPE, Map);

    while (ros::ok())
    {

      geometry_msgs::Pose poses;


      for(int i=0;i<sizeof(A);i++){
        // poses.position.x=A[i][0];
        // poses.position.y=A[i][1];
        poses.position.z=0;
        poses.orientation.x=0;
        poses.orientation.y=0;
        poses.orientation.z=0;
        poses.orientation.w=0;
        pub.publish(poses);
      }


      ros::spinOnce();

      loop_rate.sleep();
      ++count;
    }
    return 0;
}
