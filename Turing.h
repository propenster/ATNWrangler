#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace Turing
{
	constexpr size_t POINT_LLAMA_SIZE = 59;

	extern const std::array<std::string, POINT_LLAMA_SIZE> _POINT_LLAMA;
	// these are the set randomization keys...they change daily
	enum Keys
	{
		SHIGATAKANAI_FLAT,
		ROBOCOP,
		OFFBYONE,
		SHIBETOSHI_NAKAMOTO,
		FABRICE_BELLARD,


		UNKNOWN
	};

	struct Number
	{

	public:
		Number() = default;
		Number(int one, int two, int three, int four, int five, int six, int seven, int eight, int nine) : one(one), two(two), three(three), four(four), five(five), six(six), seven(seven), eight(eight), nine(nine)
		{

		}
		int one, two, three, four, five, six, seven, eight, nine;
	};

	// This is the end of them all...
	// The prince of all my NUMBER-WRANGLING NUMBER-TWISTING ALGORTHITHMS
	// StepenWolf Turingian
	//@param key
	class Turing
	{
	public:
		Turing() = default;
		Turing(const std::string& seeds);

		void Wrangle();
		bool Verify(const std::string& seed, const Keys* key);
		std::string GetCurrentKey()
		{
			return EnumToString(m_defaultKey);
		}
		void DisplayTag()
		{
			std::cout <<
				"272 307 280\n" <<
				"151 340 570\n" <<
				"265 285 250\n" <<
				"200 325 350\n" <<
				"215 325 350\n" <<
				"320 410 193\n" <<
				"\nTraining on default TuringKey " << GetCurrentKey() <<
				"\n\n"

				"The Current Key in the Turing Wrangler is >> " << GetCurrentKey() << "\n";
			for (size_t i = 0; i < 63; i++) std::cout << "-";
			std::cout << "\n\n";
		}
		void ConfigureDefaultKey(Keys key);
		bool Predict(Number* seedNumber, const Keys* key);
		float InferenceA(const std::string& input);
		int InferenceB(const std::string& input);
		bool InferenceC(const std::string& input);
		bool InferenceD(const std::string& input);

		bool SequencePositionSimilarityInference(const std::string& input);

	private:
		Keys SetDefaultKey(const std::string& seed);
		std::vector<std::string> SplitString(const std::string& input, const std::string& delimiter);
		std::string EnumToString(Keys);
		Number& GenerateNumber(const std::string& input);

		Keys DeduceSeedKey(Number* seedNumber);

		


	private:
		Keys m_defaultKey = Keys::SHIGATAKANAI_FLAT; //use SHIGATAKANAI by default if no seed was passed...
	};


}
