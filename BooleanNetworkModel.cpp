#include "BooleanNetworkModel.h"
#include <iostream>

namespace BooleanNetworks
{

	BooleanNetworkModel::BooleanNetworkModel(std::vector<std::vector<int>>& initialState, const std::function<std::vector<int>(const std::vector<int>&)>& updateRuleFnCallback, int timeSteps, bool debug)
		: initialState(initialState), updateRuleFn(updateRuleFnCallback), timeSteps(timeSteps), debug(debug)
	{
	}

	std::function<std::vector<int>(const std::vector<int>)> BooleanNetworkModel::GetRuleFunction()
	{
		std::cout << "Retrieving rule function in BN model" << std::endl;
		return updateRuleFn;
	}

	std::vector<std::vector<int>> BooleanNetworkModel::BuildBooleanNetwork()
	{
		std::vector<std::vector<int>> outputStates;
		std::function<std::vector<int>(const std::vector<int>&)> myFunc = GetRuleFunction();
		for (const auto xi : initialState)
		{
			std::vector<int> state = GenerateTransition(xi, updateRuleFn);
			outputStates.push_back(state);
		}
		return outputStates;
	}

	std::vector<int> BooleanNetworkModel::GenerateTransition(
		const std::vector<int>& x,
		const std::function<std::vector<int>(const std::vector<int>&)>& ruleFunction
	)
	{
		if (!ruleFunction)
		{
			throw std::invalid_argument("ruleFunction cannot be null");
		}

		// Generate array of rows = timeSteps + 1, columns = x.size(), initialized with zeros
		size_t w = x.size();
		std::vector<std::vector<int>> attractorState(timeSteps + 1, std::vector<int>(w, 0));

		// Set the initial state
		attractorState[0] = x;

		// Generate states for each timestep
		for (int i = 0; i < timeSteps; i++)
		{
			const std::vector<int>& currentState = attractorState[i];
			std::vector<int> newState = ruleFunction(currentState);
			attractorState[i + 1] = newState;
		}

		return attractorState[timeSteps];
	}

}