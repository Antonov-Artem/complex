#include <cmath>

class Complex {
  double r, i;

public:
  Complex(const double r, const double i) : r(r), i(i) {}

  [[nodiscard]] double re() const {
    return r;
  }

  [[nodiscard]] double im() const {
    return i;
  }

  [[nodiscard]] double mod() const {
    return sqrt(r * r + i * i);
  }

  [[nodiscard]] double arg() const {
    return atan(i / r);
  }

  [[nodiscard]] Complex conj() const {
    return Complex(r, -i);
  }

  Complex operator-() const {
    return Complex(-r, -i);
  }

  Complex operator+(const Complex& z) const {
    return Complex(r + z.re(), i + z.im());
  }

  Complex operator*(const Complex& z) const {
    return Complex(r * z.re() - i * z.im(), i * z.re() + r * z.im());
  }

  Complex operator+=(const Complex& z) {
    r += z.re();
    i += z.im();

    return *this;
  }

  Complex operator*=(const Complex& z) {
    r = r * z.re() - i * z.im();
    i = r * z.im() + i * z.re();

    return *this;
  }
};
