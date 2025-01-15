Template:
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast_io std::ios::sync_with_stdio(0);std::cin.tie(0)
#define lli long long int
#define flush fflush(stdout)
#define new_line printf("\n")
#define yn(a, b) printf("%s\n", (a) >= (b) ? "Yes":"No")
#define amodm(a, M) (((a)%M+M)%M)
// #define int lli, signed main, testCases, TC
using pii = std::pair<int,int>;
const int MOD = 1000000007;
const int mxN = 200100;


Makefile:
CXX=g++
CXXFLAGS = -DLOCAL -std=c++20 -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
SRCDIRS := $(wildcard */)
TARGETS := $(patsubst %/,%,$(SRCDIRS))
all: $(TARGETS)
$(TARGETS):
    $(CXX) $(CXXFLAGS) -o $@/$@ $@/*.cpp
.PHONY: $(TARGETS)
clean:
    rm -f $(addsuffix /$(TARGETS), $(TARGETS))


RopeDS:
#include <ext/rope>
using namespace __gnu_cxx;  // SGI
rope<int> ds
ds.insert(pos, val)  // O(lgN), O(N)
ds.erase(pos, length)  // O(lgN)
ds.replace(pos, length, val)  // O(lgN)


BigInt:
#define BIGi __int128
BIGi read() {
    BIGi x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(BIGi x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
RandomNumGen:
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
inline lli gen_random(lli l, lli r) {
    return std::uniform_int_distribution<lli>(l, r)(rng);
}
// shuffle(v.begin(), v.end(), rng);  // permuation, v = {1...n}
// real number: double, uniform_real_dist
submaskGen:
for (int submask = mask; submask; submask = (submask-1)&mask) {
    for (int i = bit_lim; i >= 0; i--) {
        if (submask&(1<<i))  //
    }
}
cngJudgeStackSize:
#include <sys/resource.h>
#include <cerrno>
struct rlimit rlim; 
rlim.rlim_cur = 1073741824; // assign number of bytes you need
setrlimit(RLIMIT_STACK, &rlim);
incStackSize:
static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%rsp, (%0)\n"
        "mov %0, %%rsp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%rsp\n" : : "r"(send));
    free(stack);
}
// inside main: run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
