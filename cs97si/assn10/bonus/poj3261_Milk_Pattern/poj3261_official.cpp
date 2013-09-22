#include <fstream>
#include <algorithm>
#include <cstddef>
#include <hash_map>
#include <iostream>
#include <cassert>

using namespace std;
using namespace __gnu_cxx;

#define MAGIC 10000019
#define MAXV 1000000

struct range {
    int *s, *e;
    size_t h;
};

struct eq {
    bool operator()(const range &a, const range &b) const
    { return a.h == b.h && equal(a.s, a.e, b.s); }
};

struct hsh {
    size_t operator()(const range &a) const { return a.h; }
};

int main() {
    int N, K;
    int data[20001];
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> data[i];
        assert(data[i] >= 0 && data[i] <= MAXV);
    }

    int low = 1;
    int high = N;
    while (high - low > 1) {
        int l = (low + high) / 2;
        int s = 1;
        hash_map<range, int, hsh, eq> h;
        range cur = {data, data + l, 0};
        bool found = false;

        for (int i = 0; i < l; i++) {
            cur.h = cur.h * MAGIC + data[i];
            s *= MAGIC;
        }
        for (int i = 0; i + l <= N; i++) {
            if (++h[cur] >= K) { found = true; break; }
            cur.h = cur.h * MAGIC - s * data[i] + data[i + l];
            cur.s++;
            cur.e++;
        }

        if (found) low = l;
        else high = l;
    }
    cout << low << "\n";
    return 0;
}
