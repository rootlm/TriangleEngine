#ifndef __MATH2H__
#define __MATH2H__
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

unsigned long clamp_u(unsigned long val,unsigned long min,unsigned long max);

//#define MAKESHORT(val1,val2) return ((val1 << 8) | val2)

#endif