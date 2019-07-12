#include <iostream>

// identity function
float getIdentity(const float& x)
{
	return x;
}

// f prime x of indentity function
float getGradIdentity(const float& x)
{
	return 1.0;
}

// sigmoid function
float getSigmoid(const float x)
{
	return 1.0f / (1.0f + exp(-x));
}

// f prime x of sigmoid function
float getGradSigmoid(const float& x)
{
	const float f = getSigmoid(x);  // f(x)

	return f * (1.0 - f);
}

// ReLU function
float getReLU(const float& x)
{
	return x >= 0.0f ? x : 0.0f;
}

// f prime x of ReLU function
float getGradReLU(const float& x)
{
	return x >= 0.0f ? 1.0f : 0.0f;
}