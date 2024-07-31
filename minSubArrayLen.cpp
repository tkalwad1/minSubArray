#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int sum = 0;
        int counter = 1000000;
        int temp = 0;
        int right = nums.size() - 1;
        int left = 0;

        while(left < right){
            sum += nums[left];
            sum += nums[right];
            left++;
            right--;
        }

        if(sum < target){
            return 0;
        }else{
            sum = 0;
        }

        while(sum < target){
            sum += nums[end];
            if(end < nums.size() - 1){
                end++;
            }else{
                break;
            }
        }

        while(end <= nums.size()){
            while(sum > target){
                sum -= nums[start];
                start++;
                if(end == (nums.size() - 1)){
                    temp = (end - start) + 1;
                }else{
                    temp = end - start;
                }
            }

            while(sum < target){
                sum += nums[end];
                if(end < nums.size() - 1){
                    end++;
                }
                start++;
                temp = end - start;
            }

            while(sum == target && temp < counter){
                counter = temp;
                start++;
                if(start == end){
                    return counter;
                }else{
                    start++;
                    if(start == end){
                        return counter;
                    }else{
                        sum += nums[start];
                    }
                }
            }

        }
        return 0;
    }