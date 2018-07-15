#include <math.h>

#ifndef __MATH2__
#define __MATH2__

float degtorad(float degtoconv);

float radtodeg(float radtoconv);

float point_direction(float x1, float y1, float x2, float y2);

float dsin(float dsinarg);

float dcos(float dcosarg);

float point_distance(float x1,float y1,float x2,float y2);

int clamp(int val,int min,int max);

float lengthdir_x(float len, float angle);

float lengthdir_y(float len, float angle);

float lerp(float v0, float v1, float t);

float clampfloat(float val,float min,float max);
#endif