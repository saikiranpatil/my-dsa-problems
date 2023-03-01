class Solution {
public:
    public:
    void merge(vector<int>& arr, int l, int m, int r)
    {
         // Your code here
        int l1=m-l+1;
       int l2=r-m;
       int first[l1];
       int second[l2];
       int k=l;
       for(int i=0;i<l1;i++){
           first[i]=arr[k];
           k++;
       }
       for(int i=0;i<l2;i++){
           second[i]=arr[k];
           k++;
       }
       int i=0;
       int j=0;
       k=l;
       while(i<l1 && j<l2){
           if(first[i]<second[j]){
               arr[k]=first[i];
               k++;
               i++;
               
           }
           else{
               arr[k]=second[j];
               j++;
               k++;
           }
       }
       while(i<l1){
           arr[k]=first[i];
           k++;
           i++;
       }
       while(j<l2){
           arr[k]=second[j];
           j++;
           k++;
       }
       return ;
   }
    public:
    void mergeSort(vector<int>& arr, int l, int r)
    {
        //code here
        if(r>l){
            int m=l+(r-l)/2;
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,r);
            merge(arr,l,m,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};