#pragma once
#include <vector>
#include <functional>
#include <memory>



namespace BooleanNetworks
{
	class BooleanNetworkModel
	{

	public:
		BooleanNetworkModel() = default;
		BooleanNetworkModel(std::vector<std::vector<int>>& initialState, const std::function<std::vector<int>(const std::vector<int>&)>& updateRuleFnCallback, int timeSteps = 10, bool debug = true);


		std::vector<std::vector<int>> BuildBooleanNetwork();

	private:
		std::vector<int> GenerateTransition(
			const std::vector<int>& x,
			const std::function<std::vector<int>(const std::vector<int>&)>& ruleFunction
		);
		std::function<std::vector<int>(const std::vector<int>)> GetRuleFunction();


		std::vector<std::vector<int>> initialState;
		std::function<std::vector<int>(const std::vector<int>&)> updateRuleFn;
		int timeSteps = 10;
		bool debug = true;



	};
}

