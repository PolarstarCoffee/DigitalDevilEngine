#include <iostream>

//Study code for programming with math concepts used for game development 


//==Vector Class==
class vector
{
public:
	vector() {}
	vector(float X, float Y, float Z)
	{
		x = X;
		y = Y;
		z = Z;
	}
	float length() const;
	float lengthsqr() const;
	float DotProduct(const vector& a, const vector& b);
	vector operator+(const vector&)const;
	vector operator-(const vector&)const;
	vector operator*(float s) const;
	vector operator/(float s) const;
	vector normalized() const;

	float x, y, z;
};

//==Point Class==
class point
{
public:
	point() {}
	point(float X, float Y, float Z)
	{
		x = X;
		y = Y;
		z = Z;
	}
	point AddVector(vector v);
	float x, y, z;
};


vector vector::operator+(const vector& v) const
{
	vector r;
	r.x = x + v.x;
	r.y = y + v.y;
	r.z = z + v.z;

	return r;

}
vector vector::operator-(const vector& v) const
{
	return vector(x - v.x, y - v.y, z - v.z);
}


vector vector::normalized() const
{
	vector normalized;
	normalized = (*this) / length();
	return normalized;
}

float vector::length() const
{
	float length;
	length = sqrt(x * x + y * y + z * z);
		return length;
}
float vector::lengthsqr() const
{
	float length;
	length = (x * x + y * y + z * z);
	return length;
}
float vector::DotProduct(const vector& a, const vector& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
point point::AddVector(vector v)
{
	point p2;
	p2.x = x + v.x;
	p2.y = y + v.y;
	p2.z = z + v.z;
	return p2;

}

// OPERATOR OVERLOADS =======================
vector vector::operator*(float s) const 
{
	vector scaled;
	scaled.x = x * s;
	scaled.y = y * s;
	scaled.z = z * s;
	return scaled;
}
vector vector::operator/(float s) const
{
	vector scaled;
	scaled.x = x / s;
	scaled.y = y / s;
	scaled.z = z / s;
	return scaled;

}
vector operator-(point a, point b)
{
	vector v;
	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return v;
}
class EulerAngle
{
public:
	EulerAngle()
	{
		p = y = r = 0;
	}

	EulerAngle(float pitch, float yaw, float roll)
	{
		p = pitch;
		y = yaw;
		r = roll;
	}

public:
	vector ToVector() const;
	void normalize();

public:
	float p;
	float y;
	float r;
};

//convert euler angle to vector
vector EulerAngle::ToVector() const
{
	vector result;
	result.x = cos(y) * cos(p);
	result.y = sin(p);
	result.z = sin(y) * cos(p);
}

//keeps pitch value between -90 and +90 and yaw value between -180 and +180
void EulerAngle::normalize()
{
	if (p > 89)
		p = 89;
	if (p < -89)
		p = -89;

	while (y < -180)
		y += 360;
	while (y > 180)
		y -= 360;
}




// MAIN ==============================

int main(int argc, char** args)
{
	//UNIT LENGTH VECTOR EXAMPLE (Normalized vectors)
	
	point i(1, 2, 3);

	point p(3, 2, 3);

	// VECTOR SCALING EXAMPLE (SPEED / SLOWING DOWN)
	//vector v(2, 5, 3);
	//std::cout << "v's inital speed : " << v.length() << "\n";

	//vector doubled;
	//doubled = v * 2;
	//std::cout << "v's doubled speed is : " << doubled.length() << "\n";

	//vector halved;
	//halved = v / 2;
	//std::cout << "v's halved speed is : " << halved.length() << "\n"

	//VECTOR ADDITION/SUBTRACTION 
	vector R(4,0,1);
	vector D(0,-5,0);

	vector v = R + D;

	return 0;
}


