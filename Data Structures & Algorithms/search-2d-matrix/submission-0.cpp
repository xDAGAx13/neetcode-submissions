class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(target>matrix[mid].back())left=mid+1;
            else if(target<matrix[mid][0])right=mid-1;
            else{
                int m = 0;
                int n = matrix[0].size()-1;
                while(m<=n){
                    int rmid = m + (n-m)/2;
                    if(target==matrix[mid][rmid])return true;
                    else if(target>matrix[mid][rmid])m=rmid+1;
                    else n=rmid-1;
                }
                return false;
            }
        }
        return false;
    }
};
