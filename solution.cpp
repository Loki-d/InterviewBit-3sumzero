vector<vector<int> > Solution::threeSum(vector<int> &A) {
    if(A.empty())
        return {};
    
    sort(A.begin(),A.end());
    int _min=INT_MAX;
    vector<vector<int> > v;

    for(int i=0;i<A.size();i++){
        int j=i+1,k=A.size()-1;
        while(j<k){
            int sum=A[i]+A[j]+A[k];
            
            if(sum==0) v.push_back({A[i],A[j],A[k]});
            
            if(sum<0)
                j++;
            else
                k--;
        }
    }
    
    if(v.empty())
        return v;
    
    sort(v.begin(),v.end());
    for(int i=0;i<v.size()-1;){
        if(equal(v[i].begin(),v[i].end(),v[i+1].begin()))
            v.erase(v.begin()+i+1);
        else
            i++;
    }
    return v;
}
