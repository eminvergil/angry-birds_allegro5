#include<allegro5\allegro.h>
#include<allegro5\allegro_primitives.h>
#include"particles.h"
#define pi 3.14
#define w 666
#define h 666

vector springP(w / 7, 555);
particles weight(rand() % w, rand() % h, 50, rand() * pi * 180);
class yapi {
private:
	float k = 0.08;
public:
	int rd = 25;
	int xx = 50;
	int yy = 30;
	int oldx = 40;
	int oldy = 20;
	float bounce = 0.9;
	float gravity = 0.5;
	float friction = 0.99999999999;
	bool drag = false;
	bool stop = false;
	vector dist;

	void setup(){
	
	}
	void draw(){
		weight.radius = 20;
		al_draw_filled_circle(xx, yy, rd, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(weight._position.getX(), weight._position.getY(), weight.radius, al_map_rgb(15, 15, 15));
		al_draw_filled_circle(springP.getX(), springP.getY(), 5, al_map_rgb(15, 15, 15)); 
		al_draw_line(weight._position.getX(), weight._position.getY(), springP.getX(), springP.getY(), al_map_rgb(15, 15, 15), 2);
	}
	void update() {
		updatePoints();
		if (drag) {
			weight.friction =0.99;
			dist = springP.subtract(weight._position);//////////
			vector springForce = dist.multiply(k);
			weight._velocity.addTo(springForce);
			if (weight._position.getX() + weight.radius> springP.getX() + 5) {
				weight._velocity.multiplyBy(1.15);
			}
		}
		weight.update();								/////////////SPRING FORCE


		draw();
	}
	void updatePoints() {
		int vx = (xx - oldx)*friction;
		int vy = (yy - oldy)*friction;

		oldx = xx;
		oldy = yy;
		xx += vx;
		yy += vy;
		yy += gravity;

		if (xx > w) {
			xx = w;
			oldx = xx + vx*bounce;
		}else if (xx < 0) {
			xx = 0;
			oldx = xx + vx*bounce;
		}else if (yy > h) {
			yy = h;
			oldy = yy + vy*bounce;
		}else if (yy < 0) {
			yy = 0;
			oldy = yy + vy*bounce;
		}
	}
};
