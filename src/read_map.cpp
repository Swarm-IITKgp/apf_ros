#include<fstream>
#include<iostream>
#include<vector>

typedef struct Point{
  int x;
  int y;
}Point;

typedef struct element{
  Point P;
  short unsigned int type;
  int Sy, Sx;
}element;

int main(){
  Point map_s;
  element E;
    
  std::fstream fp;
    
  fp.open("map.txt", std::ios::in | std::ios::out | std::ios::trunc);
    
  std::cout<<"Reading Map..."<<std::endl<<"Enter the map size";
  std::cin>>map_s.x>>map_s.y;
  fp.write(reinterpret_cast<char*>(&map_s), sizeof(map_s));
  std::cout<<"Use the format:\tx\ty\ttype\tsigmax\tsigmay"<<std::endl
      <<"Obstacle: type=0\nInitial point: type=1\nDestination: type=2"<<std::endl
      <<"Program will terminate after reading destination\n";
  while(E.type!=2){
    std::cin>>E.P.x>>E.P.y>>E.type>>E.Sx>>E.Sy;
    fp.write((char*)&E, sizeof(E));
    std::cout<<"Hi\n";
  }
    
  fp.seekp(0);
    
  fp.read(reinterpret_cast<char*>(&map_s), sizeof(map_s));
  std::cout<<map_s.x<<"\t"<<map_s.y<<std::endl;
    
  while(true){
    fp.read((char*)&E, sizeof(E));
    if(fp.eof())
      break;
    std::cout<<"\t"<<E.P.x<<"\t"<<E.P.y<<"\t"<<E.type<<"\t"<<E.Sx<<"\t"<<E.Sy<<std::endl;
  }
  fp.close();
}
