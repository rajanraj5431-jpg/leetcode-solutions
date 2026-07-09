long long check(long long base, int k, long long limit) {
    long long res = 1;

    for (int i = 0; i < k; i++) {
        if (res > limit / base)
            return 0;   // base^k > limit (or overflow)
        res *= base;
    }

    return 1;   // base^k <= limit
}

long long kthRoot(long long x, int k) {
    if (x == 0)
        return 0;

    long long low = 1, high = x, ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (check(mid, k, x)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int countKthRoots(int l, int r, int k) {
    if (l == 0)
        return (int)(kthRoot(r, k) + 1);
    return (int)(kthRoot(r, k) - kthRoot((long long)l - 1, k));
}