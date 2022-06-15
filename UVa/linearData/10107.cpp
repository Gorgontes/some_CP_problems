#include <bits/stdc++.h>
#include <algorithm>
#include <ios>
#include <unistd.h>
using namespace std;
typedef vector<long long int> vi;
typedef long long int ll;

struct Node {
    int pre;
    ll value;
    Node(int pre, ll value) {
        this -> pre = pre;
        this -> value = value;
    }
};

bool sortNode(Node a, Node b) {
    return a.value < b.value;
}

int mapeado[10010];
int remapear(vector<Node> &v) {
    int ultimo;
    for(int i = 0; i < v.size() ; i++) {
        mapeado[v[i].pre + 1] = i;
    }
    for(int i = 0; i < v.size() ; i++) {
        if (v[i].pre == v.size() - 2)
            ultimo = i;
        v[i].pre = (v[i].pre != -1 ) ? mapeado[v[i].pre] : v[i].pre;
    }
    return ultimo;
}

struct Adj {
    int pre,nex;
};

void deleteAdj(int pos, vector<Adj> &v) {
    int pr = v[pos].pre;
    if(pr != -1)
        v[pr].nex = v[pos].nex;
    pr = v[pos].nex;
    if(pr != v.size())
        v[pr].pre =v[pos].pre;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /* freopen("neo.input", "r", stdin); */
    /* freopen("neo.output", "w", stdout); */

    int cont = 0;
    ll n;
    vector<ll> respuesta;
    respuesta.reserve(10011);
    vector<Node> nodes;
    nodes.reserve(10011);

    while(cin >> n) {
        nodes.emplace_back(cont - 1, n);
        cont++;
    };
    vector<Adj> adjs;
    adjs.resize(nodes.size() + 1);
    sort(nodes.begin(), nodes.end(), sortNode);
    int pos = remapear(nodes);
    for(int i = 0 ; i < nodes.size() ; ++i) {
        adjs[i].pre = i - 1;
        adjs[i].nex = i + 1;
    }
    bool odd =  nodes.size() % 2;
    int ptr = nodes.size() / 2;
    int ptl = (!odd) ? ptr - 1 : ptr;
    while(pos != -1){
        if(odd) respuesta.emplace_back(nodes[ptr].value);
        else respuesta.emplace_back((nodes[ptr].value + nodes[ptl].value) / 2);

        if (nodes[pos].pre != -1) {
            if(odd) {
                if(ptr != pos) {
                    deleteAdj(pos, adjs);
                    if(pos < ptr) {
                        ptr = adjs[ptr].nex;
                    } else {
                        ptl = adjs[ptl].pre;
                    }
                } else {
                    ptr = adjs[ptr].nex;
                    ptl = adjs[ptl].pre;
                    deleteAdj(pos, adjs);
                }
            } else {
                if(pos == ptr) {
                    ptr = adjs[ptr].pre;
                    deleteAdj(pos, adjs);
                } else if (pos == ptl) {
                    ptl = adjs[ptl].nex;
                    deleteAdj(pos, adjs);
                } else {
                    deleteAdj(pos, adjs);
                    if(pos > ptr) {
                        ptr = adjs[ptr].pre;
                    } else {
                        ptl = adjs[ptl].nex;
                    }
                }
            }
        }
        odd = !odd;
        pos = nodes[pos].pre;
    }
    for(int i = respuesta.size() - 1 ; i >= 0 ; --i) {
        cout << respuesta[i] << "\n";
    }
}
