- Assuming Ubuntu Linux 14.04 / 16.04 LTS ( 64 Bit )
  [ Others may differ from following method but will have similar workaround ]

- Find whether 'freeglut' is already installed.

  $locate freeglut

  Or

  $apt list --installed | grep -i "freeglut"

  If list does not show you files in 'bin', 'include' or 'lib' directories,
  then it is not installed.

- Better way to download the source tarball of 'freeglut 3.0' 
  ( to be in line with Windows freeglut 3.0 ) From following location :

  http://prdownloads.sourceforge.net/freeglut/freeglut-3.0.0.tar.gz?download

- Extract It In Its Default Folder.

- From Terminal 'cd' To Its Path.

- FreeGLUT source building requires 'cmake'.
  [ before that first check whether it is already installed or not by 'locate' command ]

  $sudo apt-get install cmake

- Now start building freeglut 3.0 by using 'cmake'

  $cmake . [ NOTE : The Last Dot Is Important ]
  $make
  $sudo make install

  Above procedure will install freeglut headers, libraries and binaries in following locations.

- Confirm Following Locations  :
  ==============================
  * Header Files :
  ----------------
  /usr/local/include/GL

  freeglut.h
  freeglut_ext.h
  freeglut_std.h
  glut.h
  
  * Library Files :
  -----------------
  /usr/local/lib
  
  libglut.a
  libglut.so
  
  libglut.so.3
  libglut.so.3.10.0
  
========================================================================================

Compile & Link :
================

g++ -o OGL.o OGL.cpp -lGL -lGLU -lglu