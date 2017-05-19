#ifndef __APF_H
#define __APF_H
#include <vector>

class c_map{
  public:
    void create_map(int mx,int my,std::vector <int> X,std::vector <int> Y,std::vector <int> SIGMA_X,std::vector <int> SIGMA_Y,std::vector <int> TYPE, double **map);
    void filter_map(int mx,int my,std::vector <int> X,std::vector <int> Y,std::vector <int> SIGMA_X,std::vector <int> SIGMA_Y,std::vector <int> TYPE, double **map);
};

class Field{
  public:
    void att_field(int px,int py,int mx,int my, double **res);
    void rep_field(int px,int py,int sx,int sy,int mx,int my, double **res);
    void guassian(int px,int py,int sx,int sy,int mx,int my, double **res);
};

class Filter_waypt{
  public:
    std::vector<std::vector<int> > Filter_waypoint(std::vector <std::vector<int> > A, double **map, int mx, int my);
};

class simulate{
  public:
    std::vector<std::vector<int> > simulation();
};

#endif
