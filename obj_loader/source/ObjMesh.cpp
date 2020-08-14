#include "common.h"

//TODO read from file and set:
//
//std::vector < vec4 > vertices;
//std::vector < vec3 > normals;
//vec3 box_min;
//vec3 box_max;
//
//https://en.wikipedia.org/wiki/Wavefront_.obj_file

bool Mesh::loadOBJ(const char * path){
  
  //HERE
  
  center = box_min+(box_max-box_min)/2.0;
  scale = (std::max)(box_max.x - box_min.x, box_max.y-box_min.y);
  
  model_view = Scale(1.0/scale,           //Make the extents 0-1
                     1.0/scale,
                     1.0/scale)*
               Translate(-center);  //Orient Model About Center
  
  
  return true;
}
