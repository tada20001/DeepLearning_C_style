#include <iostream>
#include "NeuralNetwork.h"

int main()
{
	VectorND<D> x(2);
	x[0] = 0.0; x[1] = 0.0;

	VectorND<D> y_target(1);
	y_target[0] = 0.3f;

	VectorND<D> y_temp(1); // allocate the memory of output for forward propagation

	NeuralNetwork nn_;
	nn_.initialize(2, 1, 1);  // input 2, output 1, hidden layer 1
	nn_.alpha_ = 0.1;

	for (int i = 0; i < 1000; i++)
	{
		nn_.setInputVector(x);
		nn_.propForward();

		nn_.copyOutputVector(y_temp);
		std::cout << y_temp << std::endl;

		nn_.propBackward(y_target); // training
	}

	return 0;
}