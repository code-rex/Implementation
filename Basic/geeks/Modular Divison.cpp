/*
Modular Divison: (a - b) mod p = ((a mod p - b mod p) + p) mod p

(a / b) mod p = ((a mod p) * (b^(-1) mod p)) mod p
	Where b^(-1) mod p is the modular inverse of b mod p. 
		For p = prime, b^(-1) mod p = b^(p - 2) mod p.
		
	(a / b) mod p = ((a mod p) * (b^(p-2) mod p)) mod p

*/

#define int long long
#define MOD  1000000007
#define ll long long 
int powm(int base,int exp,int mod=MOD) {int ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
ll mulmod(ll a, ll b, ll mod) 
{ 
    ll res = 0; // Initialize result 
    a = a % mod; 
    while (b > 0) 
    { 
        // If b is odd, add 'a' to result 
        if (b % 2 == 1) 
            res = (res + a) % mod; 
  
        // Multiply 'a' with 2 
        a = (a * 2) % mod; 
  
        // Divide b by 2 
        b /= 2; 
    } 
  
    // Return result 
    return res % mod; 
}
int main()
{
  //Ex: k*(k+1)/2;
  int count1=mulmod(k,k+1,MOD); //multiply of k*(k+1)
	int p=powm(2,MOD-2,MOD); //replace 2 with divisor
	int count2=mulmod(p,count1,MOD);  //here k*(k+1)/2
  return 0;
}
