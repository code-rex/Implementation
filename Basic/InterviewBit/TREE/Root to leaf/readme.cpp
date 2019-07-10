/*
1) Passing reference(e.g. vector) to function will reflect back the changes happend in function i.e Pass by Reference.
2) During Recursion(i.e Call stack function) additional memory is used .
   a) Passing reference to recursive function will reflect back changes in original array.
   b) Passing value to recursive function(i.e call by value) will make copies of the array everytime function call itself.

3) In Backtracking, we recur back to the desired location which is not directing to answer.(and then pop back that element in case of
    vector, and reference is passed)
 
*/
