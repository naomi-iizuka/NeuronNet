#include "random.h"

RandomNumbers::RandomNumbers(unsigned long int s)
{
	if (s==0) {
		std::random_device rd;
		seed = rd();
	} else {
		seed = s;
	}
	rng = std::mt19937(seed);
}

void RandomNumbers::uniform_double(std::vector<double>& vec, double lower, double upper)
{
	std::uniform_real_distribution<> unif(lower, upper);
	for (size_t i = 0; i < vec.size(); i++) //->??
	{
		vec[i] = unif(rng);
	}
}

double RandomNumbers::uniform_double(double lower, double upper)
{
	std::uniform_real_distribution<> unif(lower, upper);
	return unif(rng);
}

void RandomNumbers::normal(std::vector<double>& vec, double mean, double sd)
{
	std::normal_distribution<> norm{mean, sd};
	for (size_t i = 0; i < vec.size(); i++) //->??
	{
		vec[i] = norm(rng);
	}
}

double RandomNumbers::normal(double mean, double sd)
{
	std::normal_distribution<> norm{mean, sd};
	return norm(rng);
}

void RandomNumbers::poisson(std::vector<int>& vec, double mean)
{
	std::poisson_distribution<> poiss(mean);
	for (size_t i = 0; i < vec.size(); i++) //->??
	{
		vec[i] = poiss(rng);
	}
}

int RandomNumbers::poisson(double mean)
{
	std::poisson_distribution<> poiss(mean);
	return poiss(rng);
}
