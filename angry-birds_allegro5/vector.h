#include<math.h>
class vector {
public:
	int _x = 0;
	int _y = 1;
	vector(int x, int y) {
		_x = x;
		_y = y;
	}
	vector create(int x, int y) {
		vector obj;
		obj.setX(x);
		obj.setY(y);
		return obj;
	}
	vector(){}// def
	void setY(int value) {
		_y = value;
	}
	void setX(int value) {
		_x = value;
	}
	int getX() {
		return _x;
	}
	int getY() {
		return _y;
	}
	void  setAngle(int angle) {
		float length = getLength();
		_x = cos((double)angle)*length;
		_y = sin((double)angle)*length;
	}
	float getAngle() {
		return atan2((double)_x,(double)_y);
	}
	void setLength(int length) {
		float angle = getAngle();
		_x = cos((double)angle)*length;
		_y = sin((double)angle)*length;
	}
	float getLength() {
		return sqrt(_x*_x + _y*_y);
	}
	void addTo(vector v2) {
		_x += v2.getX();
		_y += v2.getY();
	}
	vector add(vector v2) {
		vector v;
		return v.create(_x + v2.getX(), _y + v2.getY());
	}
	vector subtract(vector v2) {
		vector v;
		return v.create(_x - v2.getX(), _y - v2.getY());
	}
	vector multiply(float val) {
		vector v;
		return v.create(_x * val, _y * val);
	}
	vector divide(float val) {
		vector v;
		return v.create(_x / val, _y / val);
	}
	void multiplyBy(float val) {
		_x *= val;
		_y *= val;
	}
	void divideBy(float val) {
		_x /= val;
		_y /= val;
	}
};