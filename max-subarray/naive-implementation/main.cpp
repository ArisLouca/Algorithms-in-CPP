#include<iostream>
#include<vector>

/*

The maximum subarray problem finds a contiguos subarray with the largest possible 
sum within a one-dimensional array of numbers. This is the naive (brute-force) implementaion
of the algorithm. 

*/

std::vector<int> maxSubarray (std::vector<int> array)
{
  int maxDiff = 0; 
  std::vector<int> res { 0, 0 };

  for (int i { 0 }; i < (array.size() - 1); ++i) 
  { 
    for (int j { i+1 }; j < array.size(); ++j)
    {
      int diff = array.at(j) - array.at(i); 
      if (diff > maxDiff) {
        maxDiff = diff; 
        res = { i, j }; 
      } 
    }
  }

  return res; 
}

int main (void)
{
  std::vector<int> array = { 0, -4, 5, -3, 9, -1 }; 

  std::vector<int> res = maxSubarray(array);

  std::cout << "Start: " << res.at(0) << "\n" << "End: " << res.at(1) << "\n" << "Diff: " << array.at(res.at(1)) - array.at(res.at(0)) << "\n";

  return 0; 
}
