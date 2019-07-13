#include <iostream>
#define MAX2(a, b) (a) > (b) ? (a) : (b)

class Neuron
{
public:

	double w_;
	double b_;

	double input_, output_; // saved for back-prop

	Neuron()
		: w_(2.0), b_(1.0), input_(0.0), output_(0.0)
	{}
	
	double feedForward(const double& _input)
	{
		input_ = _input;

		const double sigma = w_ * input_ + b_;
		
		output_ = getAct(sigma);

		return output_; 
	}

	void propBackward(const double& target)  // to update weight and bias
	{
		const double alpha = 0.1;  // learning rate
		const double grad = (output_ - target) * getActGrad(output_);

		w_ = w_ - alpha * grad * input_;  // last input_ came from d(wx+b) / dw = x
		b_ = b_ - alpha * grad * 1.0;     // last 1.0 came from d(wx+b) / db = 1.0
	}

	double getAct(const double& x)
	{
		// if using linear or identity func.
		return x;

		// if using RELU func.
		//return MAX2(0.0, x);
	}

	double getActGrad(const double& x)
	{
		// if using linear or identity func.
		return 1.0;

		// RELU func. return if(x > 0) return 1.0; else return 0.0; 
	}

	void feedForwadAndPrint(const double& input)
	{
		printf("input = %f output = %f \n", input, feedForward(input));
	}
};

int main()
{
	Neuron my_neuron;

	for (int i = 1; i < 100; ++i)
	{
		std::cout << "Training num." << i << std::endl;
		// the updated weight and bias after training
		std::cout << "weight = " << my_neuron.w_ << " bias = " << my_neuron.b_ << std::endl;

		my_neuron.feedForwadAndPrint(1.0);
		my_neuron.propBackward(4.0);
	}

	return 0;
}