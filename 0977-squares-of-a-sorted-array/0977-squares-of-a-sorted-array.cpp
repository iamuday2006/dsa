class Solution {
public:
    vector<int> doSquare(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            arr[i] *= arr[i];
        }
        return arr;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg, pos;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }

        if (neg.size() == 0) {
            return doSquare(pos);
        }

        doSquare(neg);
        sort(neg.begin(), neg.end());
        doSquare(pos);
        int i = 0, j = 0, id = 0;
        vector<int> finalResult(neg.size() + pos.size());

        while (i < neg.size() && j < pos.size()) {
            if (neg[i] <= pos[j]) {
                finalResult[id] = neg[i];
                id++;
                i++;
            } else {
                finalResult[id] = pos[j];
                id++;
                j++;
            }
        }

        while (i < neg.size()) {
            finalResult[id] = neg[i];
            id++;
            i++;
        }
        while (j < pos.size()) {
            finalResult[id] = pos[j];
            id++;
            j++;
        }
        return finalResult;
    }
};