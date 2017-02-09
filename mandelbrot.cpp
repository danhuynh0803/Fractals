#include <fstream>
#include "vec3.h"

const int WIDTH = 1920;
const int HEIGHT = 1080;
const int MAX = 4096;

vec3 colorPixel(int iter)
{
  vec3 color;
  if (iter == MAX) {
    color = vec3(0.0f, 0.0f, 0.0f);
  }
  else if (iter < 64) {
    color = vec3(iter * 1.0f, iter * 2.5f, iter* 4.0f);
  }
  else if (iter < 128) {
    color =  vec3
      (
       (((iter - 64.0f) * 128.0f) / 126.0f) + 128.0f,
       (((iter - 64.0f) * 128.0f) / 126.0f) + 128.0f,
       (((iter - 64.0f) * 50.0f) / 126.0f) + 128.0f
       );   
  }
  else if (iter < 256) {
    color =  vec3
      (
       (((iter - 128.0f) * 62.0f) / 127.0f) + 193.0f,
       193.0f,
       193.0f
       );   
  }
  else if (iter < 512) {
    color =  vec3
      (
       (((iter - 256.0f) * 62.0f) / 255.0f) + 1.0f,
       (((iter - 256.0f) * 62.0f) / 255.0f) + 1.0f,
       50.0f
       );   
  }
  else if (iter < 1024) {
    color =  vec3
      (
       (((iter - 512.0f) * 63.0f) / 511.0f) + 64.0f,
       (((iter - 512.0f) * 63.0f) / 511.0f) + 64.0f,
       50.0f);   
  }
  else if (iter < 2048) {
    color =  vec3
      ((((iter - 1024.0f) * 63.0f) / 1023.0f) + 128.0f,
       (((iter - 1024.0f) * 63.0f) / 1023.0f) + 128.0f,
       150.0f);  
  }
  else if (iter < 4096) {
    color =  vec3
      ((((iter - 2048.0f) * 63.0f) / 2047.0f) + 192.0f,
       (((iter - 2048.0f) * 63.0f) / 2047.0f) + 192.0f,
       255.0f);  
  }
  else {
    color = vec3(255.0f, 255.0f, 0.0f);
  }
  return color;
}

int main()
{
  float maxR = 1.2, minR = -2.5;  // Define max and min range on real axis 
  float maxI = 1.2, minI = -1.2;  // Define max and min range on imaginary axis
  float dr = float(maxR - minR)/float(WIDTH);   // The position on real axis of each pixel
  float di = float(maxI - minI)/float(HEIGHT);  // The position on imaginary axis of each pixel

  // TODO: Fixes width by adjusting image size using desired aspect ratio
  // float aspectRatio = 16.0/9.0;
  // int width = maxR - minR;
  // int height = maxI - minI;
  // int newWidth = aspectRatio * height;
  // int difference = newWidth - width;
  // minR -= float(difference) / 2.0;
  // maxR += float(difference) / 2.0;
  
  vec3 colors[MAX];
  for (int i = 0; i < MAX; ++i)
    {
      colors[i] = vec3(
		       0.2f + ((float(i)/float(100) * 1.0f)),  // Red 
		       0.2f + ((float(i)/float(100) * 0.3f)),  // Green 
		       0.2f + ((float(i)/float(100) * 0.3f))   // Blue
		       );
    }
  
  std::ofstream myfile;
  myfile.open("mandelbrot.ppm");
  myfile << "P3\n" << WIDTH << " " << HEIGHT << "\n" << "255" << std::endl;
  float c_re, c_im, zr, zi;
  int iter;
  vec3 color;
  for (int y = HEIGHT; y > 0; --y)
    {
      for (int x = 0; x < WIDTH; ++x)
	{
	  // z = zo^2 + c
	  c_re = (minR + x*dr);
	  c_im = (minI + y*di);
	  zr = zi = iter = 0;
	  while (zr*zr+zi*zi < 4 && iter < MAX)
	    {
	      float zr_new = zr*zr - zi*zi + c_re;
	      float zi_new = 2*zr*zi + c_im;
	      zr = zr_new;
	      zi = zi_new;
	      iter += 1;	      
	    }

	  if (iter < MAX)
	    {
	      color = colorPixel(iter);
	      int ir = color.r();
	      int ig = color.g();
	      int ib = color.b();

	      // int ir = int(255.99 * colors[iter].r());
	      // int ig = int(255.99 * colors[iter].g());
	      // int ib = int(255.99 * colors[iter].b());
	      myfile << ir << " " << ig << " " << ib << "\t";
	    }
	  else myfile << 0.0f << " " << 0.0f << " " << 0.0f << "\t";
	}
      myfile << "\n";
    }
  
  return 0;  
}

