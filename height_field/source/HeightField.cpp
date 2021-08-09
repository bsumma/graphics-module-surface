#include "common.h"

#ifdef _WIN32
static
unsigned int lodepng_decode_wfopen(std::vector<unsigned char>& out, unsigned& w, unsigned& h,
  const std::string& filename,
  LodePNGColorType colortype = LCT_RGBA, unsigned bitdepth = 8)
{
  std::wstring wcfn;
  if (u8names_towc(filename.c_str(), wcfn) != 0)
    return 78;
  FILE* fp = _wfopen(wcfn.c_str(), L"rb");
  if (fp == NULL) { return 78; }

  std::vector<unsigned char> buf;
  fseek(fp, 0L, SEEK_END);
  long const size = ftell(fp);
  if (size < 0) {
    fclose(fp);
    return 78;
  }

  fseek(fp, 0L, SEEK_SET);
  buf.resize(size);
  fread(buf.data(), 1, size, fp);
  fclose(fp);

  return lodepng::decode(out, w, h, buf, colortype, bitdepth);
}
#endif //_WIN32

bool HeightField::loadImage(const char * path){

  //decode
#ifdef _WIN32
  unsigned error = lodepng_decode_wfopen(image, width, height, path);
#else
  unsigned error = lodepng::decode(image, width, height, path);
#endif //_WIN32

  //if there's an error, display it
  if(error){
      std::cout << "decoder error " << error;
      std::cout << ": " << lodepng_error_text(error) << std::endl;
    return false;}
    
  
  std::cout << "Image loaded: " << width << " x " << height << std::endl;
  std::cout << image.size() << " pixels.\n";
  std::cout << "Image has " << image.size()/(width*height) << "color values per pixel.\n";

  vec3 center = vec3(-(float)width/2.0, -(float)height/2.0, 0);
  double max_dim = (std::max)(width, height);

  model_view = RotateX(-45)*
               Scale(1.0/max_dim,
                     1.0/max_dim,
                     1.0/max_dim)*
                     Translate(center);  //Orient Model About Center

  return true;

}

//TODO
//Create a triangulated version of the image for rendering and populate
//the vertices array.
//I've found dividing the PNG value by 8 to be a good scaling factor for the
//height.
void HeightField::createMesh(){
    
}
  
//TODO
//Compute a triangle's normal
vec4 HeightField::triangleNormal(vec4 p1, vec4 p2, vec4 p3){

  /* TODO replace: */return vec4();

}

//TODO
//Populate the normal array with vertice normals for the triangle mesh
void HeightField::createNormals(){

}
