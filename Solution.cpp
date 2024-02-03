
#include <span>
#include <ranges>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    
    inline const static vector<vector<int>> NOT_POSSIBLE_TO_DIVIDE_THE_ARRAY;
    inline const static int SUBARRAY_LENGTH = 3;

public:
    vector<vector<int>> divideArray(const vector<int>& input, int maxDifference) const {

        //C++ versions prior to C++20: *max_element(input.begin(), input.end())
        int maxInputValue = *ranges::max_element(input);
        vector<int> frequency = createVectorFrequency(input, maxInputValue);

        return createDividedArray(frequency, input.size(), maxDifference);
    }

private:
    //C++ versions prior to C++20: ...(const vector<int>& input, ...)
    vector<int> createVectorFrequency(span<const int> input, int maxInputValue) const {
        vector<int> frequency(maxInputValue + 1);
        for (const auto& n : input) {
            ++frequency[n];
        }
        return frequency;
    }

    //C++ versions prior to C++20: ...(vector<int>& input, ...)
    vector<vector<int>> createDividedArray(span<int> frequency, int inputLength, int maxDifference) const {
        int indexArray = 0;
        int indexSubarray = 0;
        vector<vector<int>> dividedArray(inputLength / SUBARRAY_LENGTH, vector<int>(SUBARRAY_LENGTH));

        for (int value = 1; value < frequency.size(); ++value) {
            if (frequency[value] == 0) {
                continue;
            }

            dividedArray[indexArray][indexSubarray] = value;
            if (value - dividedArray[indexArray][0] > maxDifference) {
                return NOT_POSSIBLE_TO_DIVIDE_THE_ARRAY;
            }

            value -= (--frequency[value] > 0) ? 1 : 0;
            indexArray += (indexSubarray + 1) / SUBARRAY_LENGTH;
            indexSubarray = (indexSubarray + 1) % SUBARRAY_LENGTH;
        }
        return dividedArray;
    }
};
