#include <iostream>

#define MAX2(a, b) ((a) > (b) ? (a) : (b))

class Neuron
{
public:
	double w_;   // weight of one input
	double b_;	 // bias

	Neuron()
		: w_(0), b_(0)
	{}

	double getAct(const double& x)
	{
		// if using indenty function
		return x;

		// if using ReLU activation function
		/*return MAX2(0.0, x);*/
	}

	double feedForward(const double& input)
	{
		const double sigma = w_ * input + b_;
		
		return getAct(sigma);
	}
};


void main()
{
	Neuron my_neuron;
	
	my_neuron.w_ = 2.0;
	my_neuron.b_ = 1.0;

	std::cout << "Input = 0.0    " << my_neuron.feedForward(0.0) << std::endl;
	std::cout << "Input = 1.0    " << my_neuron.feedForward(1.0) << std::endl;
	std::cout << "Input = 2.0    " << my_neuron.feedForward(2.0) << std::endl;
	std::cout << "Input = 3.0    " << my_neuron.feedForward(3.0) << std::endl;
}