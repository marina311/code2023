#include <bits/stdc++.h>

using namespace std;

const int maxn = 501;

//https://ru.algorithmica.org/cs/matching/kuhn/

vector<int> g[maxn]; // будем хранить только рёбра из левой доли в правую
int mt[maxn]; // с какой вершиной сматчена вершина правой доли (-1, если ни с какой)
bool used[maxn]; // вспомогательный массив для поиска пути dfs-ом

// dfs возвращает, можно ли найти путь из вершины v
// в какую-нибудь вершину правой доли
// если можно, то ещё и проводит чередование
bool dfs(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int u: g[v]) {
        // если вершина свободна, то можно сразу с ней соединиться
        // если она занята, то с ней можно соединиться только тогда,
        // когда из её текущей пары можно найти какую-нибудь другую вершину
        if (mt[u] == -1 || dfs(mt[u])) {
            mt[u] = v;
            return true;
        }
    }
    return false;
}

int main() {
    int m, n;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        while (v != 0) {
            g[i].push_back(n + v - 1);
            cin >> v;
        }
    }
    int cnt = 0;
    memset(mt, -1, sizeof mt);
    for (int i = 0; i < n + m; i++) {
        memset(used, 0, sizeof used);
        if (dfs(i))
            cnt++;
    }
    cout << cnt << "\n";
    for (int i = n; i < n + m; ++i) {
        if (mt[i] != -1)
            cout <<  mt[i] + 1 << " " << i - n + 1 << "\n";

    }

}

