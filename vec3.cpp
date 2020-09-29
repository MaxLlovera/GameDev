#include <iostream>
using namespace std;

template <class T>
class vec3
{
public:
	vec3() { _x = 0, _y = 0; _z = 0; }
	vec3(T x, T y, T z) 
	{ 
		_x = x; 
		_y = y; 
		_z = z; 
	}
	vec3(const vec3& vec) 
	{ 
		_x = vec._x;
		_y = vec._y;
		_z = vec._z;
	}

	vec3 operator+(const vec3& vec) const
	{
		return vec3(_x + vec._x, _y + vec._y, _z + vec._z);
	}
	vec3 operator-(const vec3& vec) const
	{
		return vec3(_x - vec._x, _y - vec._y, _z - vec._z);
	}
	vec3 operator+=(const vec3& vec) const
	{
		_x += vec._x;
		_y += vec._y;
		_z += vec._z;
	}
	vec3 operator-=(const vec3& vec) const
	{
		_x -= vec._x;
		_y -= vec._y;
		_z -= vec._z;
	}
	vec3 operator=(const vec3& vec) const
	{
		_x = vec._x;
		_y = vec._y;
		_z = vec._z;
	}

	bool operator ==(const vec3& vec) 
	{
		return vec._x == _x && vec._y == _y && vec._z == _z;
	}

	void Normalize()
	{
		// magnitud vec
		T magnitud = sqrt((_x * _x) + (_y * _y) + (_z * _z));

		// mentres no sigui zero
		if (magnitud != 0)
		{
			_x /= magnitud;
			_y /= magnitud;
			_z /= magnitud;
		}
	}

	void Zero()
	{
		_x = _y = _z = 0;
	}
	
	void isZero()
	{
		return _x == 0 && _y == 0 && _z == 0;
	}

	int DistanceTo(vec3 vec)
	{
		T distX, distY, distZ;
		distX = vec._x - _x;
		distY = vec._y - _y;
		distZ = vec._z - _z;

		return sqrt((distX * distX) + (distY * distY) + (distZ * distZ));
	}


private:
	T _x;
	T _y;
	T _z;

};


int main()
{
	vec3 <int> a;
	vec3 <int> b(1,2,3);
	vec3 <int> c(a);

	cout << a.DistanceTo(b) << endl;

	b.Zero();

	cout << a.DistanceTo(b) << endl;

	system("pause");
	return 0;

}