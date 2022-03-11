'use strict';

function gridTraveller(width, height, memo = {}) {

    function cacheResult(width, height, result) {

        if (!memo[width]) {

            memo[width] = {};
        }

        memo[width][height] = result;
    };

    function getCacheResult(width, height) {

        if (memo[width] && memo[width][height]) {
            return memo[width][height];
        }
    };

    const cachedResult = getCacheResult(width, height);

    if (cachedResult) {
        return cachedResult;
    }

    if (width === 1 && height === 1) {
        return 1;
    } else if (width === 0 || height === 0) {
        return 0;
    }

    const result = gridTraveller(width - 1, height, memo) + gridTraveller(width, height - 1, memo);

    cacheResult(width, height, result);

    return result;
};

console.log(gridTraveller(1, 1));
console.log(gridTraveller(2, 3));
console.log(gridTraveller(3, 2));
console.log(gridTraveller(3, 3));
console.log(gridTraveller(16, 16));
console.log(gridTraveller(18, 18));
