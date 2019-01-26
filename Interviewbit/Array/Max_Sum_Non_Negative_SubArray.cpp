vector<int> Solution::maxset(vector<int> &A) {
   
    long long int i;
    long long int sum;
    long long int max_sum;
    long long int start;
    long long int end;
    long long int s;
    long long int l;
    long long int ml;
    
    start = -1;
    end = start;
    l = 0;
    sum = 0;
    max_sum = INT_MIN;
    s = -1;
    
    for(i = 0; i < A.size(); i++) {
        
        if(A[i] >= 0) {
            
            if(start == -1) {
                
                start = i;
                end = i;
                sum += A[i];
                
            }else{
                
                end++;
                sum += A[i];
            }
            
        }else {
            
            if(max_sum < sum) {
                
                max_sum = sum;
                l = end-start+1;
                s = start;
                
            }else if(max_sum == sum) {
                
                if(end - start + 1 > l) {
                    
                    s = start;
                    l = end-start+1;
                    
                }else if(end - start + 1 == l) {
                    
                    if(start < s) {
                        
                        s = start;
                        
                    }
                }
                
                
            }
            
            
            sum = 0;
            start = -1;
            end = start;
        }

    }
    
    if(max_sum < sum) {
                
        max_sum = sum;
        l = end-start+1;
        s = start;
                
    }else if(max_sum == sum) {
                
        if(end - start + 1 > l) {
                    
            s = start;
            l = end-start+1;
                    
        }else if(end - start + 1 == l) {
                    
            if(start < s) {
                        
                s = start;
                        
            }
        }
                
                
    }

    vector<int> B;
    
    if(s != -1) {
        
        for(i = s; i < s+l; i++) {
            
            B.push_back(A[i]);
        }
        
        
    }
    
    return B;
}