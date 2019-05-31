#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>

int main()
{
    std::vector<int> nums(20);
    std::iota(std::begin(nums), std::end(nums),0);
    std::copy(std::begin(nums), std::end(nums), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
