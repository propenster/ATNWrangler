// ATNWrangler.cpp : Defines the entry point for the application.
//

#include "ATNWrangler.h"
#include "Turing.h"
#include "BooleanNetworkModel.h"

using namespace std;


//Invert a given state for a field... now we could flesh this out to be more dynamic i.e according to rule method passed e.g[not][xor][and][or ]
//Recall: The expression level of a gene at a time step depends solely on the expression level
//of its regulators at the previous time step.
static const std::vector<int> UpdateRule(std::vector<int> x)
{
	return { !x[1], !x[0] };
}

int main(int*, char**)
{
	std::cout << "Size of string on my PC " << sizeof(std::string_view) << " bytes\n";
	int a = 28, b = 34;

	int sum = a + b;

	Turing::Turing turing("272 307 280; 151 340 570; 265 285 250; 200 325 350; 215 325 350; 320 410 193");
	//std::cout << "The Current Key in the Turing Wrangler is >>> " << turing.GetCurrentKey() << "\n";
	turing.DisplayTag();

	std::string input;
	const Turing::Keys key = Turing::Keys::OFFBYONE; //, SHIGATAKANAI_FLAT, Turing::Keys::SHIBETOSHI_NAKAMOTO;
	while (true)
	{
		std::cout << "Enter the score to verify via Turing Wrangler e.g: 272 307 280: ";
		if (!std::getline(std::cin, input))
		{
			std::cerr << "Error reading input or EOF reached" << std::endl;
			continue;
		}
		if (input == "") continue;
		if (input == "cls")
		{
			system("cls");
			turing.DisplayTag();
			continue;
		}
		if (input == "exit")
		{
			std::cout << "Exiting..." << std::endl;
			break;
		}

		/*bool result = turing.Verify(input, &key);
		std::cout << "Result of " << input << " DDXX " << (result ? "YES" : "NO") << "\n";*/

		/*float result = turing.InferenceA(input);
		std::cout << "Result of " << input << " is " << result << " DDXX " << (result < 0.05 ? "YES" : "NO") << "\n";*/

		int result = turing.InferenceB(input);
		std::cout << "Result of " << input << " is " << result << " DDXX " << (result >= 30 ? "YES" : "NO") << "\n";
	}

	std::vector<std::vector<int>> initialState = {
		{1, 1},
		{1, 0},
		{0, 1},
		{0, 0 }
	};
	std::function<std::vector<int>(const std::vector<int>)> myFunc = UpdateRule;
	BooleanNetworks::BooleanNetworkModel bn(initialState, myFunc);
	std::vector<std::vector<int>> states = bn.BuildBooleanNetwork();
	int i = 0;
	for (const auto& row : states)
	{
		std::cout << "x" << i << ": ";
		for (const auto& val : row)
		{
			std::cout << val << " ";
		}
		std::cout << "\n";
		i++;
	}



	std::cin.get();
	return 0;
}
