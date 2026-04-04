#include "../Utilities/utilities.h"
#include <iostream>
#include <stack>
#include <vector>

std::vector<int> nextGreaterElementToRight(const std::vector<int> &arr)
{
  std::vector<int> result(arr.size(), -1);
  std::stack<int> indexStack;

  indexStack.push(0);

  for (int i = 1; i < arr.size(); i++)
  {
    while (indexStack.size() > 0 && arr[indexStack.top()] < arr[i])
    {
      result[indexStack.top()] = arr[i];
      indexStack.pop();
    }
    indexStack.push(i);
  }

  return result;
}

int main()
{
  std::vector<int> arr = {2, 5, 9, 3, 1, 12, 6};
  std::vector<int> result = nextGreaterElementToRight(arr);
  printVector(result);
  return 0;
}