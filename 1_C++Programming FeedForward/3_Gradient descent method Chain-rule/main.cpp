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
	MyFunction mf;

	// constrol only single a_, b_
	//{
	//	const float y_t0 = 1.0f;
	//	const float x_0 = 0.0f;
	//	const float alpha = 0.01f;

	//	for (int i = 0; i < 1000; i++)
	//	{
	//		const float squaredError = mf.squaredError(y_t0, x_0);
	//		std::cout << "Squared Error = " << squaredError << std::endl;  // 0.5 * error * error

	//		const float error = y_t0 - mf.getValue(x_0);
	//		const float Ea = error * -x_0;
	//		const float Eb = error * -1.0f;

	//		mf.a_ -= alpha * Ea;
	//		mf.b_ -= alpha * Eb;

	//		std::cout << "a_ = " << mf.a_ << " " << "b_ = " << mf.b_ << std::endl;
	//	}

	//	std::cout << mf.getValue(x_0) << std::endl; // check if y_target is 1.0
	//}
	
	//// multiple constraints
	//{
	//	const int num_const = 3;

	//	const float y_t[num_const] = { 1.0f, 1.5f, 2.0f };
	//	const float x[num_const] = { 0.0f, 0.5f, 1.0f };

	//	const float alpha = 0.01f;

	//	for (int i = 0; i < 1000; i++)
	//	{
	//		float sqr_error_sum = 0.0f;
	//		float Ea_sum = 0.0f;
	//		float Eb_sum = 0.0f;

	//		for (int c = 0; c < num_const; c++)
	//		{
	//			const float error = y_t[c] - mf.getValue(x[c]);
	//			const float Ea = error * -x[c];
	//			const float Eb = error * -1.0f;

	//			sqr_error_sum += error * error;
	//			Ea_sum += Ea;
	//			Eb_sum += Eb;
	//		}

	//		std::cout << "Squared Error = " << 0.5f * sqr_error_sum << std::endl;

	//		mf.a_ -= alpha * Ea_sum / (float)num_const;  // average
	//		mf.b_ -= alpha * Eb_sum / (float)num_const;

	//	}
	//	std::cout << "a_ = " << mf.a_ << " " << "b = " << mf.b_ << std::endl;

	//}

	// Stochastic Gradient Descent Method  : applying random
	{
		const int num_const = 3;
		const float y_t[num_const] = { 1.0f, 1.5f, 2.0f };
		const float x[num_const] = { 0.0f, 0.5f, 1.0f };

		const float alpha = 0.01f;

		for (int i = 0; i < 10000; i++)
		{
			int c = rand() % num_const;  // 0, 1, 2
			const float error = y_t[c] - mf.getValue(x[c]);
			float Ea = error * -x[c];
			float Eb = error * -1.0f;

			std::cout << "Squared Error = " << mf.squaredError(y_t[c], x[c]) << std::endl;

			mf.a_ -= alpha * Ea;
			mf.b_ -= alpha * Eb;
		}

		std::cout << mf.a_ << " " << mf.b_ << std::endl;
	}

	return 0;
}