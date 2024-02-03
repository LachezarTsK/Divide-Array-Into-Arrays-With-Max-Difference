
using System;

public class Solution
{
    static readonly int[][] NOT_POSSIBLE_TO_DIVIDE_THE_ARRAY = new int[0][];
    static readonly int SUBARRAY_LENGTH = 3;

    public int[][] DivideArray(int[] input, int maxDifference)
    {
        int maxInputValue = input.Max();
        int[] frequency = CreateArrayFrequency(input, maxInputValue);

        return CreateDividedArray(frequency, input.Length, maxDifference);
    }

    private int[] CreateArrayFrequency(int[] input, int maxInputValue)
    {
        int[] frequency = new int[maxInputValue + 1];
        foreach (int n in input)
        {
            ++frequency[n];
        }
        return frequency;
    }

    private int[][] CreateDividedArray(int[] frequency, int inputLength, int maxDifference)
    {
        int indexArray = 0;
        int indexSubarray = 0;
        int[][] dividedArray = new int[inputLength / SUBARRAY_LENGTH][];

        for (int value = 1; value < frequency.Length; ++value)
        {
            if (frequency[value] == 0)
            {
                continue;
            }
            if (indexSubarray == 0)
            {
                dividedArray[indexArray] = new int[SUBARRAY_LENGTH];
            }

            dividedArray[indexArray][indexSubarray] = value;
            if (value - dividedArray[indexArray][0] > maxDifference)
            {
                return NOT_POSSIBLE_TO_DIVIDE_THE_ARRAY;
            }

            value -= (--frequency[value] > 0) ? 1 : 0;
            indexArray += (indexSubarray + 1) / SUBARRAY_LENGTH;
            indexSubarray = (indexSubarray + 1) % SUBARRAY_LENGTH;
        }
        return dividedArray;
    }
}
