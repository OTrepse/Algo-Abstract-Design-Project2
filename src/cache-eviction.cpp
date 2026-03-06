#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_set>
#include <unordered_map>
using namespace std;

const int INF = 1000000000;
int simulateFIFO(int k, const vector<int>& req) {
    unordered_set<int> cache;
    queue<int> order;
    int misses = 0;

    for (int x : req) {
        if (cache.count(x)) continue;

        misses++;
        if ((int)cache.size() < k) {
            cache.insert(x);
            order.push(x);
        } else {
            while (!order.empty() && !cache.count(order.front())) order.pop();
            int victim = order.front(); order.pop();
            cache.erase(victim);

            cache.insert(x);
            order.push(x);
        }
    }
    return misses;
}

int simulateLRU(int k, const vector<int>& req) {
    list<int> lru; 
    unordered_map<int, list<int>::iterator> where;
    int misses = 0;

    for (int x : req) {
        if (where.count(x)) {
            lru.erase(where[x]);
            lru.push_front(x);
            where[x] = lru.begin();
        } else {
            misses++;
            if ((int)where.size() == k) {
                int victim = lru.back();
                lru.pop_back();
                where.erase(victim);
            }
            lru.push_front(x);
            where[x] = lru.begin();
        }
    }
    return misses;
}

int simulateOPTFF(int k, const vector<int>& req) {
    int m = (int)req.size();
    unordered_map<int, queue<int>> pos;
    for (int i = 0; i < m; i++) pos[req[i]].push(i);

    unordered_set<int> cache;
    int misses = 0;

    for (int i = 0; i < m; i++) {
        int x = req[i];
        pos[x].pop();

        if (cache.count(x)) continue;

        misses++;
        if ((int)cache.size() < k) {
            cache.insert(x);
            continue;
        }
        int victim = -1;
        int farthest = -1;

        for (int c : cache) {
            int nextUse = pos[c].empty() ? INF : pos[c].front();
            if (nextUse > farthest) {
                farthest = nextUse;
                victim = c;
            }
        }

        cache.erase(victim);
        cache.insert(x);
    }

    return misses;
}

int runSim() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, m;
    cin >> k >> m;

    vector<int> req(m);
    for (int i = 0; i < m; i++) cin >> req[i];

    int fifo = simulateFIFO(k, req);
    int lru  = simulateLRU(k, req);
    int opt  = simulateOPTFF(k, req);

    cout << "FIFO  : " << fifo << "\n";
    cout << "LRU   : " << lru  << "\n";
    cout << "OPTFF : " << opt  << "\n";
    return 0;
}