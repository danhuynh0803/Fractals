#ifndef HSV2RGB_H
#define HSV2RGB_H

#include "vec3.h"

vec3 hsv2rgb(float h, float s, float v )
{
  int i;
  float f, p, q, t;

  if( s == 0 ) {
    // achromatic (grey)
    return vec3(v, v, v);
  }

  h /= 60;			// sector 0 to 5
  i = floor( h );
  f = h - i;			// factorial part of h
  p = v * ( 1 - s );
  q = v * ( 1 - s * f );
  t = v * ( 1 - s * ( 1 - f ) );

  vec3 color;
  switch( i ) {
  case 0: // red
    color = vec3(v, t, p);
    break;
  case 1: // yellow
    color = vec3(q, v, p);
    break;
  case 2: // green
    color = vec3(p, v, t);
    break;
  case 3: // cyan
    color = vec3(p, q, v);
    break;
  case 4: // blue
    color = vec3(t, p, v);
    break;
  default: // magenta
    color = vec3(v, p, q);
    break;
  }
  
  return color;
}

#endif
