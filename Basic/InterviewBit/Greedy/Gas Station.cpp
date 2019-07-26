//https://www.interviewbit.com/problems/gas-station/

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    /*
    As we know that the Total(Gas) >= Total(Cost) for soln. to exist, so while traversing, let us say that the index j gives negative 
    sum difference value i.e.Total(Gas)<Total(Cost) (Total only till index j). Now, we start traversing again from index j+1 making 
    the previous totals (both Total(Gas) and Total(Cost)) as 0, now let us assume that from index j+1 to end of array we don’t find 
    any negative sum difference value. What does that mean?

    index --> 0 1 2 3 4…j j+1 j+2 … n-1
    values–>(— -ve —) (---- +ve -----)

    That means that j+1 index is the soln., because even if we continue taking sum after index n-1 i.e. from 0 we are bound to 
    get +ve value because the overall Total(Gas) >= Total(Cost) exist.
    Hence, your answer.
    */
    
    int start =0, i=0,def=0, temp =0;
    while(start<A.size()&&i<A.size()){
        temp +=A[i]-B[i];
        def+=A[i]-B[i];
        if(temp<0){
            start=i+1;
            temp=0;
        }
        i++;
    }
    if(def>=0)
            return start;
    else
            return -1;
}
