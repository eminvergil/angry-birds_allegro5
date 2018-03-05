#include"vector.h"
class particles {
public:
	vector _velocity;
	vector _position;
	vector _gravity;
	float mass = 1;
	float radius;
	float bounce = 0.9;
	float friction = 1;

	particles(int x, int y, float speed, float direction) {
		vector obj(x, y);
		vector velocity(0, 0);
		_position = obj;
		_velocity = velocity;
		_velocity.setLength(speed);
		_velocity.setAngle(direction);
	}
	void accelerate(vector accel) {
		_velocity.addTo(accel);
	}
	void update() {
		_velocity.multiplyBy(friction);
		_velocity.addTo(_gravity);
		_position.addTo(_velocity);
		if (_position._x > 666) {
			_position._x = 666;
			_velocity.multiplyBy(bounce);
		}
		else if (_position._x < 0) {
			_position._x = 0;
			_velocity.multiplyBy(bounce);
		}
		else if (_position._y  > 666) {
			_position._y = 666;
			_velocity.multiplyBy(bounce);
		}
		else if (_position._y  < 0) {
			_position._y = 0;
			_velocity.multiplyBy(bounce);
		}
	}
	float angleTo(particles p2) {
		return atan2(p2._position.getY() - _position.getY(), p2._position.getX() - _position.getX());
	}
	float distanceTo(particles p2) {
		float dx = p2._position.getX() - _position.getX();
		float dy = p2._position.getY() - _position.getY();
		return sqrt(dx*dx + dy*dy);
	}
	float gravityTo(particles p2) {
		vector grav(0, 0);
		float dist = distanceTo(p2);
		
		grav.setLength(p2.mass / (dist*dist));
		grav.setAngle(angleTo(p2));
		_velocity.addTo(grav);
	}
};