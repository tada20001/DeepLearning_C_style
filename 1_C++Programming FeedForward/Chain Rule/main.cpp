#include <iostream>
#include <random>

// Linear Function Example
class MyFunction
{
public:
	float a_, b_;

	MyFunction()
		: a_(0.0f), b_(0.0f)
	{}

	float getValue(const float& x)
	{
		return a_ * x + b_;
	}

	// we need to update a, b for minimizing Error. Repeat until error becomes small enough
	float squaredError(const float& y_target, const float& x)
	{
		const float error = 0.5f * (y_target - getValue(x)) * (y_target - getValue(x));

		return error;
	}
};

int main()
{
	MyFunction mf, mg;

	// initialize parameters
	mf.a_ = (float)rand() / RAND_MAX;  // 0.0~1.0
	mf.b_ = (float)rand() / RAND_MAX;
	mg.a_ = (float)rand() / RAND_MAX;
	mg.b_ = (float)rand() / RAND_MAX;

	const float x_0 = 0.0f;
	const float y_t0 = 1.0f;
	const float alpha = 0.01f;

	std::cout << "Before training y = " << mf.getValue(mg.getValue(x_0)) << std::endl;

	for (int i = 0; i < 10000; i++)
	{
		const float error = y_t0 - mf.getValue(mg.getValue(x_0));
		const float sqr_error = mf.squaredError(y_t0, mg.getValue(x_0));
		//const float sqr_error_0 = 0.5 * error * error;

		if (sqr_error < 1e-5) break;

		//if(i % 100 == 0)
			std::cout << "Training num." << i << "  Squared Error = " << sqr_error << std::endl;

		const float Eaf = -error * mg.getValue(x_0);
		const float Ebf = -error * 1.0f;

		const float Eag = -error * mf.a_ * x_0;
		const float Ebg = -error * mf.a_ * 1.0f;

		mf.a_ -= alpha * Eaf;
		mf.b_ -= alpha * Ebf;
		mg.a_ -= alpha * Eag;
		mg.b_ -= alpha * Ebg;
	}

	std::cout << "After training y = " << mf.getValue(mg.getValue(x_0)) << std::endl;

}