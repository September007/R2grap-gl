#include <iostream>
#include <string>
#include <memory>
#include "opengl/r2grapgl.h"
#if(WIN32)
#include "directx/d3dApp.h"
#endif

int main(int argc, char *argv[]){
  if(argc > 2 || argc == 1) return 0;

#if(WIN32)
  HINSTANCE hInstance = GetModuleHandle(NULL);
#endif

  //auto grap = new R2grap::R2grapGl(std::string(argv[1]));
  //grap->run();

  R2grap::R2grapGl grapgl(argv[1]);
  grapgl.run();
}

