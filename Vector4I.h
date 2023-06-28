/*
Part of Newcastle University's Game Engineering source code.

Use as you see fit!

Comments and queries to: richard-gordon.davison AT ncl.ac.uk
https://research.ncl.ac.uk/game/
*/
#pragma once

namespace NCL::Maths {
	class Vector3;
	class Vector2;

	class Vector4i {

	public:
		union {
			struct {
				int x;
				int y;
				int z;
				int w;
			};
			int array[4];
		};

	public:
		constexpr Vector4i(void) : x(0), y(0), z(0), w(0) {}

		constexpr Vector4i(int xVal, int yVal, int zVal, int wVal) : x(xVal), y(yVal), z(zVal), w(wVal) {}

		Vector4i(const Vector3i& v3, int w = 0);
		Vector4i(const Vector2i& v2, int z = 0, int w = 0);

		~Vector4i(void) = default;

		constexpr int		GetMaxElement() const {
			int v = x;
			if (y > v) {
				v = y;
			}
			if (z > v) {
				v = z;
			}
			if (w > v) {
				v = w;
			}
			return v;
		}

		int		GetAbsMaxElement() const {
			int v = abs(x);
			if (abs(y) > v) {
				v = abs(y);
			}
			if (abs(z) > v) {
				v = abs(z);
			}
			if (abs(w) > v) {
				v = abs(w);
			}
			return v;
		}

		static constexpr Vector4i Clamp(const Vector4i& input, const Vector4i& mins, const Vector4i& maxs);

		inline Vector4i  operator+(const Vector4i&a) const {
			return Vector4i(x + a.x, y + a.y, z + a.z, w + a.w);
		}

		inline Vector4i  operator-(const Vector4i&a) const {
			return Vector4i(x - a.x, y - a.y, z - a.z, w - a.w);
		}

		inline Vector4i  operator-() const {
			return Vector4i(-x, -y, -z, -w);
		}

		inline Vector4i  operator*(int a)	const {
			return Vector4i(x * a, y * a, z * a, w * a);
		}

		inline Vector4i  operator*(const Vector4  &a) const {
			return Vector4i(x * a.x, y * a.y, z * a.z, w * a.w);
		}

		inline Vector4i  operator/(const Vector4  &a) const {
			return Vector4i(x / a.x, y / a.y, z / a.z, w / a.w);
		};

		inline Vector4i  operator/(float v) const {
			return Vector4i(x / v, y / v, z / v, w / v);
		};

		inline constexpr void operator+=(const Vector4i&a) {
			x += a.x;
			y += a.y;
			z += a.z;
			w += a.w;
		}

		inline void operator-=(const Vector4i&a) {
			x -= a.x;
			y -= a.y;
			z -= a.z;
			w -= a.w;
		}


		inline void operator*=(const Vector4i&a) {
			x *= a.x;
			y *= a.y;
			z *= a.z;
			w *= a.w;
		}

		inline void operator/=(const Vector4i&a) {
			x /= a.x;
			y /= a.y;
			z /= a.z;
			w /= a.w;
		}

		inline void operator*=(float f) {
			x *= f;
			y *= f;
			z *= f;
			w *= f;
		}

		inline void operator/=(float f) {
			x /= f;
			y /= f;
			z /= f;
			w /= f;
		}

		inline float operator[](int i) const {
			return array[i];
		}

		inline int& operator[](int i) {
			return array[i];
		}

		inline bool	operator==(const Vector4 &A)const { return (A.x == x && A.y == y && A.z == z && A.w == w) ? true : false; };
		inline bool	operator!=(const Vector4 &A)const { return (A.x == x && A.y == y && A.z == z && A.w == w) ? false : true; };

		inline friend std::ostream& operator<<(std::ostream& o, const Vector4i& v) {
			o << "Vector4i(" << v.x << "," << v.y << "," << v.z << "," << v.w << ")\n";
			return o;
		}
	};
}