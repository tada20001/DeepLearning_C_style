#include <iostream>
#include "NeuralNetwork.h"

// XOR-problem
// if x1 = 0, x2 = 0, y=0
// if x1 = 0, x2 = 1, y = 1
// if x1 = 1, x2 = 0, y = 1
// if x1 = 1, x2 = 1, y = 0

class Example
{
public:
	VectorND<D> x_, y_;
};


int main()
{
	Example xor_problem[4];   // 4 case

	// initialize x, y
	for (int e = 0; e < 4; e++)
	{
		xor_problem[e].x_.initialize(2);
		xor_problem[e].y_.initialize(1);
	}

	xor_problem[0].x_[0] = 0.0; xor_problem[0].x_[1] = 0.0; xor_problem[0].y_[0] = 0.0;
	xor_problem[1].x_[0] = 0.0; xor_problem[1].x_[1] = 1.0; xor_problem[1].y_[0] = 1.0;
    xor_problem[2].x_[0] = 1.0; xor_problem[2].x_[1] = 0.0; xor_problem[2].y_[0] = 1.0;
	xor_problem[3].x_[0] = 1.0; xor_problem[3].x_[1] = 1.0; xor_problem[3].y_[0] = 0.0;

	//VectorND<D> x(2);
	//x[0] = 0.0; x[1] = 0.0;

	//VectorND<D> y_target(1);
	//y_target[0] = 0.3f;

	VectorND<D> y_temp(1); // allocate the memory of output for forward propagation

	NeuralNetwork nn_;
	nn_.initialize(2, 1, 1);  // input 2, output 1, hidden layer 1
	nn_.alpha_ = 0.1;

	for (int i = 0; i < 1000; i++)
	{
		for (int e = 0; e < 4; e++)
		{
			nn_.setInputVector(xor_problem[e].x_);
			nn_.propForward();

			nn_.copyOutputVector(y_temp);
			std::cout << xor_problem[e].y_ << " " <<  y_temp << std::endl;

			nn_.propBackward(xor_problem[e].y_); // training
		}
		std::cout << std::endl;
		
	}

	return 0;
}