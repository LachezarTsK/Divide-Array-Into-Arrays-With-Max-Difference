
import java.util.Arrays;

public class Solution {

    private static final int[][] NOT_POSSIBLE_TO_DIVIDE_THE_ARRAY = new int[0][0];
    private static final int SUBARRAY_LENGTH = 3;

    public int[][] divideArray(int[] input, int maxDifference) {
        int maxInputValue = Arrays.stream(input).max().getAsInt();
        int[] frequency = createArrayFrequency(input, maxInputValue);

        return createDividedArray(frequency, input.length, maxDifference);
    }

    private int[] createArrayFrequency(int[] input, int maxInputValue) {
        int[] frequency = new int[maxInputValue + 1];
        for (int n : input) {
            ++frequency[n];
        }
        return frequency;
    }

    private int[][] createDividedArray(int[] frequency, int inputLength, int maxDifference) {
        int indexArray = 0;
        int indexSubarray = 0;
        int[][] dividedArray = new int[inputLength / SUBARRAY_LENGTH][SUBARRAY_LENGTH];

        for (int value = 1; value < frequency.length; ++value) {
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
}
