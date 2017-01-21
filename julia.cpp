#include <fstream>
#include "vec3.h"

const int WIDTH = 1920;
const int HEIGHT = 1080;
const int MAX = 1000;

int main()
{
  float maxR = 2.0, minR = -2.0;  // Define max and min range on real axis 
  float maxI = 1.4, minI = -1.4;  // Define max and min range on imaginary axis
  float dr = float(maxR - minR)/float(WIDTH);   // The position on real axis of each pixel
  float di = float(maxI - minI)/float(HEIGHT);  // The position on imaginary axis of each pixel

  
  vec3 colors[MAX];
  for (int i = 0; i < MAX; ++i)
    {
      colors[i] = vec3(
		       0.2f + ((float(i)/float(100) * 0.6f)),  // Red 
		       0.2f + ((float(i)/float(100) * 0.1f)),  // Green 
		       0.2f + ((float(i)/float(100) * 0.1f))   // Blue
		       );
    }
  
  std::ofstream myfile;
  myfile.open("julia.ppm");
  myfile << "P3\n" << WIDTH << " " << HEIGHT << "\n" << "255" << std::endl;
  float c_re, c_im, zr, zi;
  int iter;
  // values for c_re and c_im were found at https://en.wikipedia.org/wiki/Julia_set
  c_re = -0.8;
  c_im = 0.156;
  for (int y = 0; y < HEIGHT; ++y)
    {
      for (int x = 0; x < WIDTH; ++x)
	{
	  // z^2 = zo^2 + c
	  zr = minR + x*dr;
	  zi = minI + y*di;
	  //zr = (x - WIDTH/2.0)*(4.0/WIDTH);
	  //zi = (y - HEIGHT/2.0)*(4.0/WIDTH);
	  iter = 0;
	  while (zr*zr+zi*zi < 4 && iter < MAX)
	    {
	      float zr_new = zr*zr-zi*zi + c_re;
	      float zi_new = 2*zr*zi + c_im;
	      zr = zr_new;
	      zi = zi_new;
	      iter += 1;	      
	    }

	  if (iter < MAX)
	    {
	      int ir = int(255.99 * colors[iter].r());
	      int ig = int(255.99 * colors[iter].g());
	      int ib = int(255.99 * colors[iter].b());
	      myfile << ir << " " << ig << " " << ib << "\t";
	    }
	  else myfile << 0.0f << " " << 0.0f << " " << 0.0f << "\t";
	}
      myfile << "\n";
    }
  
  return 0;  
}

