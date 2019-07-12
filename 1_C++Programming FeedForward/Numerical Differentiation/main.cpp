#include <iostream>

// the concept of numerical differentiation 

float getF(const float& x)
{
	const float a = 0.5;
	const float b = 0.1;

	return a * x + b;
}

float getFx(const float& x)
{
	const float a = 0.5;
	const float b = 0.1;

	return a;
}

int main()
{
	// forward differencing
	{
		const float x = 1.0;
		const float dx = 0.1;
		const float df = getF(x + dx) - getF(x);
		const float df_over_dx = df / dx;
	}

	// Extrapolation
	{
		// if we know only f(x) and dx_target without computing f(x + dx) directly, 
		// we can approximate the value of y_target

		const float x = 1.0;
		const float dx = 0.1;
		const float dx_target = 0.2;

		const float df = getF(x + dx) - getF(x);
		const float dfdx = df / dx;
			
		const float f_new = getF(x) + dfdx * dx_target;  // Euler integration

		std::cout << "f(1.2) = " << getF(x + dx_target) << std::endl;
		std::cout << "f(1) + dfdx * 0.2 = " << f_new << std::endl;
	}

	// what if we need to find dx_target?
	{
		// dx_target = (f_target - f(x)) / dfdx
		const float f_target = 0.7;
		const float x = 1.0;
		const float f = getF(x);
		const float dfdx = 0.5;  // if x = 1, dfdx = 0.5

		const float dx_target = (f_target - f) / dfdx;

		std::cout << "dx_target = " << dx_target << std::endl;
		std::cout << "f_target = " << f_target << std::endl;
		std::cout << "f(x + dx_target) = " << getF(x + dx_target) << std::endl;
	}

	// approximate the value of dx_target, using analytical differentiation 
	{
		const float x = 1.0;
		const float fx = getFx(x);

		const float f_target = 0.7;
		const float dx_target = (0.7 - getF(x)) / fx;

		std::cout << "f_target = " << f_target << std::endl;
		std::cout << "f(x + dx_target) = " << getF(x + dx_target) << std::endl;
	}

	return 0;
}