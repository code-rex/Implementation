// https://www.quora.com/q/threadsiiithyderabad/String-Hashing-for-competitive-programming
// https://cp-algorithms.com/string/string-hashing.html

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
//Precomputing the powers of p might give a performance boost.
/*
where p and m are some chosen, positive numbers. It is called a polynomial rolling hash function.
