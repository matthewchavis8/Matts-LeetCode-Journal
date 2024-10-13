#include <iostream>
#include <unordered_map>
#include <chrono>

class Test {
    public:
        int climbStairs (int top) {
            std::unordered_map<int,int> memo;
            return dp(top, memo);
            
        }

        int dp (int top, std::unordered_map<int,int> &memo) {
            if (top == 1 || top == 0) return 1;

            //check if the computation does not exist in our cache if it does not we can add in
            //if computation does exist then no need to recompute saves time
            if (memo.find(top) == memo.end()) memo[top] = dp(top - 1, memo) + dp(top - 2, memo);

            return memo[top];
        }
        //brute force approach
        int dfs (int n) {
            if (n == 0 || n == 1) return 1;     //n == 1 stops when we are only 1 step away from the top
            return dfs(n - 2) + dfs (n - 1);    //n == 0 stops when we are already at the top
        }
        
};

//Test Case
int main () {
    Test test;
    int steps{100};

    auto start = std::chrono::high_resolution_clock::now();

    int ways = test.climbStairs(steps);

    std::cout << "There are " << steps << " steps in the staircase\n";
    std::cout << "There are " << ways << " to climb " 
    << steps << " steps\n";

    auto end = std::chrono::high_resolution_clock::now();

    auto nanoSecondsTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    auto millisecondsSecondsTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    auto secondsTime = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();



    
    std::cout << "ClimbStairs executed in " << nanoSecondsTime << " nanosecond's time\n";
    std::cout << "ClimbStairs executed in " << millisecondsSecondsTime << " millisecond's time\n";
    std::cout << "ClimbStairs executed in " << secondsTime << " second's time\n";
    return 0;
}