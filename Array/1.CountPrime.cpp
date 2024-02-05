/* count prime less than n */

// TC = O(n log log n), SC = o(n)
class CountPrimes {
public:
    int countPrimes(int n) {
        int ans = 0;
        if (n < 2) return ans;
        vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (sieve[i]) {
                for (int j = i * i; j < n; j += i)
                    sieve[j] = false;
            }
        }

        for (int i = 2; i < n; i++) {
            if(sieve[i]) ans++;
        }

        return ans;
    }
};