// Author: Adrian Kuegel
// Date: 31. 5. 2007


#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <assert.h>
using namespace std;

const double PI_2 = acos(0.0)*4;

double get_volume(double r, double h) {
	return r*r*PI_2/2 * h;
}

int main() {
	int w, h;
	freopen("cylinder.in","r",stdin);
	while(scanf("%d %d",&w,&h) == 2 && (w || h)) {
		assert(1 <= w && w <= 100 && 1 <= h && h <= 100);
		assert(w <= h);
		// first case: use w as height of cylinder
		// in this case, we want to maximize the radius of the circle
		// r <= w/2 && 2*r*PI <= h-2*r -> r <= min(w/2, h/(2*PI+2))
		double r1 = min(w/2.0, h/(PI_2+2));
		double res = get_volume(r1, w);

		// second case:
		// use h-2*r as height of cylinder
		// r <= w/2 && 2*r*PI <= w -> r <= w / (2*PI)
		double r2 = w / PI_2;
		// maximize r*r*PI*(h-2*r), subject to 0 <= r <= r2
		// 2*r*PI*h - 6*r*r*PI = 0
		// 2*h = 6*r -> r = h/3
		// since we know w <= h, r2 <= h / (2*PI) <= h / 3
		// it follows the maximum occurs at r2
		res = max(res, get_volume(r2, h-2*r2));
		printf("%.3f\n",res);
	}
//	assert(w == 0 && h == 0);
	return 0;
}