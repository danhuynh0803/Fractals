#ifndef COLORPALETTES_H
#define COLORPALETTES_H

#include "vec3.h"

vec3 colorPixelBlue(int iter)
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


vec3 colorPixelRed(int iter)
{
  vec3 color;
  if (iter == MAX) {
    color = vec3(0.0f, 0.0f, 0.0f);
  }
  else if (iter < 64) {
    color = vec3(iter * 2.0f, 0.0f, 0.0f);
  }
  else if (iter < 128) {
    color =  vec3
      (
       (((iter - 64.0f) * 128.0f) / 126.0f) + 128.0f,
	0.0f,
	0.0f
       );    /* 0x0080 to 0x00C0 */
  }
  else if (iter < 256) {
    color =  vec3((((iter - 128.0f) * 62.0f) / 127.0f) + 193.0f, 0.0f, 0.0f);    /* 0x00C1 to 0x00FF */
  }
  else if (iter < 512) {
    color =  vec3(150.0f, (((iter - 256.0f) * 62.0f) / 255.0f) + 1.0f, 0.0f);    /* 0x01FF to 0x3FFF */
  }
  else if (iter < 1024) {
    color =  vec3(150.0f, (((iter - 512.0f) * 63.0f) / 511.0f) + 64.0f, 0.0f);   /* 0x40FF to 0x7FFF */
  }
  else if (iter < 2048) {
    color =  vec3(150.0f, (((iter - 1024.0f) * 63.0f) / 1023.0f) + 128.0f, 0.0f);   /* 0x80FF to 0xBFFF */
  }
  else if (iter < 4096) {
    color =  vec3(150.0f, (((iter - 2048.0f) * 63.0f) / 2047.0f) + 192.0f, 0.0f);   /* 0xC0FF to 0xFFFF */
  }
  else {
    color = vec3(255.0f, 255.0f, 0.0f);
  }
  return color;
}

#endif
