class Solution {
public:
    int xorSum(vector<int>& nums){
        int sum=0;
        for(auto element:nums){
            sum^=element;
        }
        return sum;
    }
    long long findLSB(long long num){
        return num & (~(num-1));
    }
    int firstNum(vector<int>& nums,int check,int xorSum){
        int num1=0;
        for(auto element:nums){
            if(check & element){
                num1^=element;
            }
        }
        return num1;
    }
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int sum=xorSum(nums);
        int check=findLSB(sum);
        int num1=firstNum(nums,check,sum);
        ans.push_back(num1);
        ans.push_back(num1^sum);
        return ans;
    }
};