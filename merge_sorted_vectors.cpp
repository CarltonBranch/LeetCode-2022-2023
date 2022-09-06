//This function:
// 1. removes trailing zeroes from the first array
// 2. finds the index to merge the two arrays (matching values)
// 3. merges the second array into the first while preserving the sorted order

class Solution {

public:

  int findMergeIndex(vector<int>nums1, vector<int>nums2) {
    //check if nums2 has values
	  if (nums2.size() == 0)
		  return 0;  
    
    //find the merge point
    //the start of the second array will be the target value in the first (make sure it is the last instance)
    int i = 0;
    while (i < nums1.size() && nums1[i] <= nums2[0])
    {
        ++i;
    }
    return i-1;
  }    
    
  void remove_trailing_zeroes(vector<int>& arr, int count){
   	while (arr.size() > count)
		  arr.pop_back();
  }
    
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    remove_trailing_zeroes(nums1, m);
    int merge_index = findMergeIndex(nums1, nums2);
    vector<int>::iterator itr1 = nums1.begin() + merge_index;
    vector<int>::iterator itr2 = nums2.begin();
    int combined_size = nums2.size() + nums1.size();

    while(nums1.size() < combined_size)
    {
        if (merge_index == nums1.size() - 1 || itr1+1 == nums1.end())
        {
            while (nums1.size() < combined_size)
                nums1.push_back(*itr2++);
        }
        else if (*(itr1 + 1) > *itr2) {
            itr1 = nums1.insert(itr1 + 1, *itr2);
            ++itr2;
        }
        else
            ++itr1;
    }
  }
};
