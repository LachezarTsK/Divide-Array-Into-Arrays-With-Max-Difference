
/**
 * @param {number[]} input
 * @param {number} maxDifference
 * @return {number[][]}
 */
var divideArray = function (input, maxDifference) {
    this.NOT_POSSIBLE_TO_DIVIDE_THE_ARRAY = [];
    this.SUBARRAY_LENGTH = 3;

    const maxInputValue = Math.max(...input);
    const frequency = createArrayFrequency(input, maxInputValue);

    return createDividedArray(frequency, input.length, maxDifference);
};

/**
 * @param {number[]} input
 * @param {number} maxInputValue
 * @return {number[]}
 */
function createArrayFrequency(input, maxInputValue) {
    const frequency = new Array(maxInputValue + 1).fill(0);
    for (let n of input) {
        ++frequency[n];
    }
    return frequency;
}

/**
 * @param {number[]} frequency
 * @param {number} inputLength
 * @param {number} maxDifference
 * @return {number[][]}
 */
function createDividedArray(frequency, inputLength, maxDifference) {
    let indexArray = 0;
    let indexSubarray = 0;
    const dividedArray = Array
            .from(new Array(Math.floor(inputLength / this.SUBARRAY_LENGTH)),
                    () => new Array(this.SUBARRAY_LENGTH));

    for (let value = 1; value < frequency.length; ++value) {
        if (frequency[value] === 0) {
            continue;
        }

        dividedArray[indexArray][indexSubarray] = value;
        if (value - dividedArray[indexArray][0] > maxDifference) {
            return this.NOT_POSSIBLE_TO_DIVIDE_THE_ARRAY;
        }

        value -= (--frequency[value] > 0) ? 1 : 0;
        indexArray += Math.floor((indexSubarray + 1) / SUBARRAY_LENGTH);
        indexSubarray = (indexSubarray + 1) % SUBARRAY_LENGTH;
    }
    return dividedArray;
}
