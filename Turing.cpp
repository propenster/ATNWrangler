#include <string>
#include "Turing.h"
#include <iostream>
#include <unordered_map>
#include <array>
#include <algorithm>

namespace Turing
{

	Turing::Turing(const std::string& seeds) : m_defaultKey(SetDefaultKey(seeds))
	{
		//std::cout << "Training on default TuringKey " << EnumToString(m_defaultKey) << "\n\n";
	}

	void Turing::ConfigureDefaultKey(Keys key)
	{
		m_defaultKey = key;
	}
	static const std::array<std::string, POINT_LLAMA_SIZE> _POINT_LLAMA = {
		"200 325 370",
		"235 320 275",
		"191 310 400"
		"275 340 210",
		"189 340 390",
		"285 285 260",
		"168 333 540",
		"230 310 310",
		"285 390 200",
		"215 340 340",
		"333 310 225",
		"205 340 330",
		"164 380 440",
		"167 360 580",
		"325 320 220",
		"340 300 230",
		"154 400 550",
		"215 350 320",
		"285 350 235",
		"177 350 460",
		"220 325 330",
		"234 360 260",
		"168 340 520",
		"149 450 540",
		"215 310 325",
		"147 400 700",
		"260 300 270",
		"185 350 450",
		"255 340 245",
		"200 300 425",
		"200 325 340",
		"176 370 340",
		"420 380 167",
		"163 370 410",
		"189 390 320",
		"176 410 350",
		"166 360 400",
		"141 440 520",
		"235 275 325",
		"184 360 380",
		"165 360 500",
		"158 375 580",
		"210 350 300",
		"450 450 157",
		"145 450 460",
		"300 440 174",
		"478 344 189",
		"200 380 333",
		"174 375 350",
		
		
		/*"245 295 285",
		"275 295 255",
		"260 310 260",
		"255 320 255",
		"260 300 260",
		"255 310 255",
		"260 370 230",
		"240 360 250",
		"250 330 275",
		"230 350 285",
		"245 380 245",
		"260 330 245",
		"245 375 220",
		"245 370 245",
		"220 350 280",
		"245 350 245",*/

		"215 350 310",
		"215 350 300",

		"161 350 530",
		"155 340 510",
		"235 290 330",
		"192 320 380",
		"119 660 1250",
		"153 425 470",
		"245 300 300",
		"240 310 310",




	};
	void Turing::Wrangle()
	{
	}
	//Takes a single line of scores for verification....
	//We run the numbers through the Wrangler to get the exact key or match of the number....
	bool Turing::Verify(const std::string& seed, const Keys* key)
	{
		Number number = GenerateNumber(seed);

		if (key != nullptr)
		{
			ConfigureDefaultKey(*key);
			return Predict(&number, key);
		}

		switch (DeduceSeedKey(&number))
		{
		case SHIGATAKANAI_FLAT:
		case ROBOCOP:
		case OFFBYONE:
			return true;
		default:
			return false;
		}
	}
	float Turing::InferenceA(const std::string& input)
	{
		std::vector<std::string> nums = Turing::Turing::SplitString(input, " ");
		if (nums.empty()) return -1;
		float sum = 0;
		for (const auto& item : nums)
		{
			sum += std::stof(item);
		}
		return (float)1 / sum;
	}
	int Turing::InferenceB(const std::string& input)
	{
		std::vector<std::string> nums = Turing::Turing::SplitString(input, " ");
		if (nums.empty()) return -1;
		std::vector<float> parsed;
		float sum = 0;
		for (const auto& item : nums)
		{
			//sum += std::stof(item);
			parsed.push_back(std::stof(item));
		}

		float firstSum = parsed[0] + parsed[1] + parsed[2];
		float secondSum = parsed[3] + parsed[4] + parsed[5];

		float denum = firstSum / secondSum;

		std::cout << "Sum of the constituents >>> " << denum << "\n";

		float dnum = floorf(denum * 1000000) / 1000000;

		std::string intermediate = std::to_string(dnum);
		std::string part = Turing::Turing::SplitString(intermediate, ".")[1];
		int partSum = 0;
		for (const char& c : part)
		{
			std::string x(1, c);
			partSum += std::stoi(x);
		}

		return partSum;
		//return (float)1 / sum;
	}
	bool Turing::InferenceC(const std::string& input)
	{
		std::vector<std::string> nums = Turing::Turing::SplitString(input, " ");
		if (nums.empty()) return -1;
		std::vector<float> parsed;
		float sum = 0;
		for (const auto& item : nums)
		{
			//sum += std::stof(item);
			parsed.push_back(std::stof(item));
		}

		float firstSum = parsed[0] + parsed[1] + parsed[2];
		float secondSum = parsed[3] + parsed[4] + parsed[5];

		float denum = firstSum / secondSum;

		std::cout << "Sum of the constituents >>> " << denum << "\n";

		float dnum = floorf(denum * 1000000) / 1000000;

		if (dnum < 0.4) return false;

		std::string intermediate = std::to_string(dnum);
		std::string part = Turing::Turing::SplitString(intermediate, ".")[1];

		if (part[0] != part[2]) return false;

		return true;
		/*int partSum = 0;
		std::string first(1, part[0]);
		std::string second(1, part[part.length() - 1]);

		return std::stod(first) + std::stod(second);*/
	}
	bool Turing::InferenceD(const std::string& input)
	{
		std::vector<std::string> nums = Turing::Turing::SplitString(input, " ");
		if (nums.empty()) return -1;
		std::vector<float> parsed;
		float sum = 0;
		for (const auto& item : nums)
		{
			//sum += std::stof(item);
			parsed.push_back(std::stof(item));
		}

		float firstSum = parsed[0] + parsed[1] + parsed[2];
		float secondSum = parsed[3] + parsed[4] + parsed[5];

		float denum = firstSum / secondSum;

		std::cout << "Sum of the constituents >>> " << denum << "\n";

		/*float dnum = floorf(denum * 1000000) / 1000000;

		if (dnum < 0.4) return false;*/

		std::string intermediate = std::to_string(denum);
		std::string part = Turing::Turing::SplitString(intermediate, ".")[1];

		std::array<std::string, 12> caches = { "865","677","65","67","57","494","595","574", "464", "74", "75", "76" };
		for (const auto& item : caches)
		{
			if (part.find(item) == std::string::npos) continue;

			return true;
		}
		return false;
	}
	bool Turing::SequencePositionSimilarityInference(const std::string& input)
	{
		int totalScore = 0;
		std::vector<std::string> target = SplitString(input, " ");
		if (target.empty() || target.size() > 3) return false;


		for (size_t i = 0; i < POINT_LLAMA_SIZE; i++)
		{
			//search this guy...
			std::string reference = _POINT_LLAMA[i];
			std::vector<std::string> refCollection = SplitString(reference, " ");
			for (size_t j = 0; j < target.size(); j++)
			{
				auto item = std::find(refCollection.begin(), refCollection.end(), target[j]);
				if (item != refCollection.end()) //&& std::distance(refCollection.begin(), item) == j
				{
					size_t pos = std::distance(refCollection.begin(), item);
					auto s = std::find(target.begin(), target.end(), target[j]);
					size_t post_s = std::distance(target.begin(), s);
					if (pos != post_s) continue;

					totalScore++;
				}
			}
			//std::cout << "Total Score >>> " << totalScore << "\n";

			if (totalScore < 2) //if after evaluating this particular seed, we don't get at least 2 matches, we zero totalScore, and let it go on to another seed
			{
				totalScore = 0;
			}
			if (totalScore >= 2)
			{
				std::cout << "Total Score >>> " << totalScore << "\n";
				break;
			}
		}
		return totalScore >= 2;
	}
	std::string Turing::EnumToString(Keys key)
	{
		static const std::unordered_map<Keys, std::string> keyToString{
		{Keys::SHIGATAKANAI_FLAT, "SHIGATAKANAI_FLAT"},
		{Keys::ROBOCOP, "ROBOCOP"},
		{Keys::OFFBYONE, "OFFBYONE"},
		{Keys::UNKNOWN, "UNKNOWN"},
		};

		auto it = keyToString.find(key);
		if (it != keyToString.end())
			return it->second;

		return "UNKNOWN";
	}
	//Guess the key of a particular seedNumber... is it SHIGATAKANAI or OFFBYONE or 
	bool Turing::Predict(Number* seedNumber, const Keys* key)
	{
		if (!seedNumber) return false;
		bool isShigata, isRoboCop, isOffByOne, isShibetoshi, isFabrice = false;
		bool result = true;

		switch (*key)
		{
		case SHIGATAKANAI_FLAT:
			isShigata = (seedNumber->four + seedNumber->five == seedNumber->two) //350 325 185 -> 3 + 2 = 5 or 195 360 325 -> 3 + 6 = 9 or 163 420 510
				|| (seedNumber->four + seedNumber->six == seedNumber->eight + seedNumber->nine) //
				|| (seedNumber->one + seedNumber->six == seedNumber->two + seedNumber->three) // 255 338 277 -> 2 + 8 = 5 + 5 Or 261 305 295 ->2=5=6+1
				|| (seedNumber->one + seedNumber->two == seedNumber->five) // 265 285 250 2 + 6 = 8 Or 200 325 350 2 + 0 = 2
				;
			if (!isShigata) result = false;
			break;

		case ROBOCOP:
			//320 410 193 3 -1 = 2+0 / 
			isRoboCop = std::abs(seedNumber->one + seedNumber->five) == std::abs(seedNumber->two + seedNumber->three) //225 350 285 -> 2+5=2+5
				|| std::abs(seedNumber->one + seedNumber->five) == std::abs(seedNumber->two - seedNumber->three) //215 325 350 ->2+2=1-5
				|| std::abs(seedNumber->one - seedNumber->five) == std::abs(seedNumber->two + seedNumber->three); //320 410 193 ->3-1=2+0
			//|| std::abs(seedNumber->one - seedNumber->five) == std::abs(seedNumber->two - seedNumber->three)
			if (!isRoboCop) result = false;
			break;

		case OFFBYONE:
			isOffByOne = (std::abs(seedNumber->four - seedNumber->five) == std::abs(seedNumber->seven)) //260 310 260 -> 3-1=2 /210 300 370 -> 3-0=3
				|| (std::abs(seedNumber->one - seedNumber->two) == std::abs(seedNumber->seven)
					&& (seedNumber->one + seedNumber->two + seedNumber->seven) != seedNumber->five) //310 400 205 -> 3-1=2 and not 430 380 171
				|| (std::abs(seedNumber->four + seedNumber->five) == std::abs(seedNumber->nine)) //370 360 189 ->3+6=9

				//285 285 265
				|| (((seedNumber->one, seedNumber->two, seedNumber->three) == (seedNumber->four, seedNumber->five, seedNumber->six)) && ((seedNumber->seven + seedNumber->eight) == seedNumber->five) && ((seedNumber->seven + seedNumber->eight) == seedNumber->two))

				//730 420 144 -> 3+4+2=1+4+4
				|| (seedNumber->two + seedNumber->four + seedNumber->five == seedNumber->seven + seedNumber->eight + seedNumber->nine)
				//205 333 390 -> 3+3+3=9
				|| (seedNumber->four + seedNumber->five + seedNumber->six == seedNumber->eight)
				//205 310 390
				|| (seedNumber->one + seedNumber->two + seedNumber->four == seedNumber->three && seedNumber->three + seedNumber->four + seedNumber->five == seedNumber->eight)

				//230 280 325 ->2+8=3+2+5
				//260 340 250 -> 3+4=2+5+0
				|| ((seedNumber->four + seedNumber->five == seedNumber->seven + seedNumber->eight + seedNumber->nine) || (seedNumber->seven + seedNumber->nine == seedNumber->five))

				|| ((seedNumber->one + seedNumber->four == seedNumber->seven) || (seedNumber->one + seedNumber->four + seedNumber->five == seedNumber->eight) || (seedNumber->one + seedNumber->four + seedNumber->five == seedNumber->eight + seedNumber->nine))

				//225 340 290 -> 2+2+5=9+0
				//AND not 205 360 325 2+0+5=2+5 which is 7 bad luck in this case...
				|| ((seedNumber->one + seedNumber->two + seedNumber->three == seedNumber->eight + seedNumber->nine) && (seedNumber->one + seedNumber->two + seedNumber->three != 7));

			//TODO: 330 390 193 -> 3 + 3 = abs|3-6|

			;
			if (!isOffByOne) result = false;
			break;

		case SHIBETOSHI_NAKAMOTO:
			//730 420 144 -> 3+4+2=1+4+4
			isShibetoshi = (seedNumber->two + seedNumber->four + seedNumber->five == seedNumber->seven + seedNumber->eight + seedNumber->nine)
				//205 333 390 -> 3+3+3=9
				|| (seedNumber->four + seedNumber->five + seedNumber->six == seedNumber->eight)
				//205 310 390
				|| (seedNumber->one + seedNumber->two + seedNumber->four == seedNumber->three && seedNumber->three + seedNumber->four + seedNumber->five == seedNumber->eight);
			if (!isShibetoshi) result = false;
			break;



		case FABRICE_BELLARD:
			isFabrice = (
				(seedNumber->one + seedNumber->four + seedNumber->five == seedNumber->eight && seedNumber->one + seedNumber->four == seedNumber->seven)

				|| (seedNumber->two == seedNumber->four + seedNumber->five + seedNumber->seven && seedNumber->one == seedNumber->four + seedNumber->seven)

				);


			if (!isFabrice) result = false;
			break;


		default:
			result = false;
			break;
		}
		return result;
	}
	//Guess the key of a particular seedNumber... is it SHIGATAKANAI or OFFBYONE or 
	Keys Turing::DeduceSeedKey(Number* seedNumber)
	{
		if (!seedNumber) return Keys::UNKNOWN;

		bool isShigata = (seedNumber->four + seedNumber->five == seedNumber->two) //350 325 185 -> 3 + 2 = 5 or 195 360 325 -> 3 + 6 = 9 or 163 420 510
			|| (seedNumber->four + seedNumber->six == seedNumber->eight + seedNumber->nine) //
			|| (seedNumber->one + seedNumber->six == seedNumber->two + seedNumber->three) // 255 338 277 -> 2 + 8 = 5 + 5 Or 261 305 295 ->2=5=6+1
			|| (seedNumber->one + seedNumber->two == seedNumber->five) // 265 285 250 2 + 6 = 8 Or 200 325 350 2 + 0 = 2
			;
		if (isShigata) return Keys::SHIGATAKANAI_FLAT;


		//320 410 193 3 -1 = 2+0 / 
		bool isRoboCop = std::abs(seedNumber->one + seedNumber->five) == std::abs(seedNumber->two + seedNumber->three) //225 350 285 -> 2+5=2+5
			|| std::abs(seedNumber->one + seedNumber->five) == std::abs(seedNumber->two - seedNumber->three) //215 325 350 ->2+2=1-5
			|| std::abs(seedNumber->one - seedNumber->five) == std::abs(seedNumber->two + seedNumber->three); //320 410 193 ->3-1=2+0

		//|| std::abs(seedNumber->one - seedNumber->five) == std::abs(seedNumber->two - seedNumber->three)
		if (isRoboCop) return Keys::ROBOCOP;

		bool isOffByOne = std::abs(seedNumber->four - seedNumber->five) == seedNumber->seven;
		if (isOffByOne) return Keys::OFFBYONE;

		return UNKNOWN;
	}
	Keys Turing::SetDefaultKey(const std::string& seed)
	{
		int shiga = 0;
		int robo = 0;
		int off = 0;

		std::vector<std::string> seeds = SplitString(seed, ";");
		Keys key;

		// observe pattern in the input seed...
		for (const auto& item : seeds) //each row...
		{
			//split 265 285 350 by space making and generate Number object
			Number number = GenerateNumber(item);
			key = DeduceSeedKey(&number);
			if (key == UNKNOWN) continue;
			if (key == SHIGATAKANAI_FLAT) shiga++;
			else if (key == ROBOCOP) robo++;
			else off++;
		}

		// decide on which KEY the oracle is running with today or at this instant...
		int max = std::max({ shiga, robo, off });
		if (shiga == max) return m_defaultKey = SHIGATAKANAI_FLAT;
		else if (robo == max) return ROBOCOP;
		else return OFFBYONE;

		return UNKNOWN;
	}
	Number& Turing::GenerateNumber(const std::string& input)
	{
		std::vector<std::string> sets = SplitString(input, " "); //split 265 285 350 by space making
		std::vector<int> j;
		for (size_t i = 0; i < sets.size(); i++)
		{
			//one number e.g 230
			for (const char c : sets[i])
			{
				std::string y(1, c);
				j.push_back(std::stoi(y)); //so many allocations man
			}
		}

		Number result(j.at(0), j.at(1), j.at(2), j.at(3), j.at(4), j.at(5), j.at(6), j.at(7), j.at(8));
		return result;
	}
	std::vector<std::string> Turing::SplitString(const std::string& input, const std::string& delimiter)
	{
		std::vector<std::string> result;
		std::string token;
		size_t start = 0, end = delimiter.length();
		while ((end = input.find(delimiter, start)) != std::string::npos)
		{
			token = input.substr(start, end - start);
			start = end + delimiter.size();
			result.push_back(token);
		}
		result.push_back(input.substr(start));
		return result;
	}



}