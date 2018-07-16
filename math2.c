#include <math.h>
#include "math2.h"
#define _USE_MATH_DEFINES

float degtorad(float degtoconv) {
return ((degtoconv * M_PI) / 180);
}

float radtodeg(float radtoconv) {
return ((radtoconv * 180) / M_PI);
}

float point_direction(float x1, float y1, float x2, float y2) {
return radtodeg(atan2(y2-y1,x2-x1));
}

float dsin(float dsinarg) {
return sin(degtorad(dsinarg));
}

float dcos(float dcosarg) {
return cos(degtorad(dcosarg));
}

float point_distance(float x1,float y1,float x2,float y2) {

	float xdist = (x1-x2);
	xdist = xdist * xdist;

	float ydist = (y1-y2);
	ydist = ydist * ydist;

return sqrt(xdist + ydist);
}

int clamp(int val,int min,int max) {
	if (val < min) {
		val=min;
	}
	if (val > max) {
		val=max;
	}
return val;
}

float lengthdir_x(float len, float angle) {
return len * dcos(angle);
}

float lengthdir_y(float len, float angle) {
return len * dsin(angle);
}

float lerp(float v0, float v1, float t) {
  return (1 - t) * v0 + t * v1;
}

float clampfloat(float val,float min,float max) {
	if (val < min) {
		val=min;
	}
	if (val > max) {
		val=max;
	}
return val;
}