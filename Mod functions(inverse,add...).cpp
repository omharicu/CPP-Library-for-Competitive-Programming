const int N=1e5 + 5;// can be 1e6 + 5. here 1e6 + 5 isnt giving output
const int MOD = 1e9 + 7;
 
vector<long long> factorial(N, 1);// initialized with 1
 
inline long long add(long long x, long long y) {
	return ((x % MOD) + (y % MOD))% MOD;
}
 
inline long long subtract(long long x, long long y) {
	x = x % MOD;
	y = y % MOD;
 
	if(x >= y) return x - y;
	else return x - y + MOD;
}
 
inline long long multiply(long long x, long long y) {
	return ((x % MOD) * (y % MOD)) % MOD;
}
 
inline long long power(long long x, long long y) {
	long long res = 1;
	x = x % MOD;
 
	while(y > 0) {
		if(y & 1) {
			res = multiply(res, x);
		}
		y = y / 2;
		x = multiply(x, x);
	}
 
	return res;
}

// you can find inverse of x by calling divide(1,x)
inline long long divide(long long x, long long y) {
	return multiply(x, power(y, MOD-2));
}
 
inline long long nCr(long long n, long long r) {
	if(n < r or r < 0 or n < 0) return 0;
	return divide(factorial[n], multiply(factorial[r], factorial[n-r]));
}


// warning this is slow, only use when n is huge else use the precomputing method 
// in nCr, if n is huge like 1e9 we can use this instead of pre computing the factorial method
inline long long nCm(long long x,long long y){
    if (x < y)
        return 0;
    long long res = 1;
    for (long long i = 0; i < y; i++) { 
        res *= (x - i);res%=MOD; 
        res *= power(i + 1,MOD-2);
        res%=MOD; 
    }
    return res;
}
 
void precompute() {
	for(int i = 1; i < N-1; i++) {
		factorial[i] = multiply(factorial[i-1], i);
	}
}


