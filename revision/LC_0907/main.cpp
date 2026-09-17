class Solution {
    vector<int> tree;

    void buildTree(int node,int l,int r,vector<int>& nums){
        if(l == r){
            tree[node] = l;
            return ;
        }

        int mid = l + (r-l)/2;
        int left = 2*node+1;
        int right = 2*node+2;

        buildTree(left,l,mid,nums);
        buildTree(right,mid+1,r,nums);

        if(nums[tree[left]] < nums[tree[right]]){
            tree[node] = tree[left];
        }else{
            tree[node] = tree[right];
        }
    }

    int query(int node,int ql,int qr,int l,int r,vector<int>& nums){
        if(ql > r || qr < l)    return -1;
        if(ql <= l && qr>= r)   return tree[node];

        int left_node = 2*node + 1;
        int right_node = 2*node + 2;


        int mid = l + (r-l)/2;
        int left = query(left_node,ql,qr,l,mid,nums);
        int right = query(right_node,ql,qr,mid+1,r,nums);

        if(left == -1)  return right;
        if(right == -1) return left;

        return (nums[left] < nums[right]) ? left : right;
    }

    int MOD = 1e9 + 7;
    int solve(int l,int r,vector<int>& nums){
        if(l>r) return 0;

        int min = query(0,l,r,0,nums.size()-1,nums);

        long long left_ele = min-l+1;
        long long right_ele = r-min+1;

        long long total = ((left_ele * right_ele)%MOD)*nums[min] %MOD;

        long long left = solve(l,min-1,nums);
        long long right = solve(min+1,r,nums);

        return (total + left + right)%MOD;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        tree.assign(4*n,0);

        buildTree(0,0,n-1,arr);
        return solve(0,n-1,arr);
    }
};