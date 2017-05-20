# apf_ros
This is the ROS Package for Path Planning of Swarm Robots using Artificial Potential Field. The node motion_planner publishes waypoints from the initial point to the destination.

##### Prerequisites:
- Install ROS from [here](http://wiki.ros.org/indigo/Installation/Ubuntu).

##### To get started:
- Change to source space directory of your catkin workspace and clone the repo as:
```sh
$ git clone https://github.com/Swarm-IITKgp/apf_ros.git  apf
```
- To build the package:
```sh
$ cd ~/catkin_ws
$ catkin_make
```
- To run the publisher motion_planner:
```sh
$ rosrun apf motion_planner
```
