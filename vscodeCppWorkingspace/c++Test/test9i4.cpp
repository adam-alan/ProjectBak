#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>
#include <queue>

int main()
{
    std::vector<int> nums(30);
    std::iota(std::begin(nums), std::end(nums),0);
    std::queue<int> que;
    for (auto iter = nums.begin(); iter != nums.end();iter++){
        que.push(*iter);
    }

    while (!que.empty()){
        std::cout << que.front() << " ";
        que.pop();
    }
    std::cout << std::endl;
    return 0;
}
