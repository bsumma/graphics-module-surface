//http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/


#ifndef __HEIGHTFIELD__
#define __HEIGHTFIELD__

#include "common.h"

using namespace Angel;

class HeightField{
public:
  unsigned int width, height;
  std::vector<unsigned char> image;
  
  std::vector < vec4 > vertices;
  std::vector < vec3 > normals;
  
  mat4 model_view;
  
  HeightField(const char * path) : model_view(){
    if(loadImage(path)){
      createMesh();
      createNormals();
    }
  }
  
  unsigned int getNumTri(){ return vertices.size()/3; }

  bool loadImage(const char * path);
  
  void createMesh();
  vec4 triangleNormal(vec4 p1, vec4 p2, vec4 p3);
  void createNormals();

  
  friend std::ostream& operator << ( std::ostream& os, const HeightField& v ) {
    os << "Vertices:\n";
    for(unsigned int i=0; i < v.vertices.size(); i++){
      os << "\t\t" << v.vertices[i] << "\n";
    }
    os << "Normals:\n";
    for(unsigned int i=0; i < v.normals.size(); i++){
      os << "\t\t" << v.normals[i] << "\n";
    }
 
    return os;
  }
  
};


#endif  //#ifndef __OBJLOADER__
