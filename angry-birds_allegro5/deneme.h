#include<allegro5\allegro.h>
#include<allegro5\allegro_primitives.h>
#include"vector.h"
#define pi 3.14
vector pos(100, 100);
vector vel(0,0);
class deneme {
private:
	float r = 15;
public:
	void show() {
		al_draw_filled_circle(pos.getX(),pos.getY(), r, al_map_rgb(0, 0, 0));
		pos.addTo(vel);
	}
	deneme(){}//def constructor
	void bla() {
		vel.setLength(2);
		vel.setAngle(pi / 3);
	}
};