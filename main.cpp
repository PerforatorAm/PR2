#include <iostream>

using namespace std;

struct a {
    long long b = 0;
    long long c = 0;
};

void d(const int e[], int f) {
    for (int g = 0; g < f; ++g) {
        cout << e[g] << " ";
    }
    cout << endl;
}

void h(const int e[], int i[], int f) {
    for (int g = 0; g < f; ++g) {
        i[g] = e[g];
    }
}

bool j(const int e[], int f) {
    for (int g = 0; g < f - 1; ++g) {
        if (e[g] > e[g + 1]) return false;
    }
    return true;
}

bool k(int l, long long m, long long n, const int o[], int p) {
    if (p != l) return false;

    long long q = 0;
    long long r = 0;
    for (int g = 0; g < p; ++g) {
        q += o[g];
        r += (long long)o[g] * o[g];
    }

    return (q == m && r == n);
}

a s(int e[], int f) {
    a t;
    for (int g = 1; g < f; ++g) {
        int u = e[g];
        t.c++;
        int v = g - 1;

        while (v >= 0) {
            t.b++;
            if (e[v] > u) {
                e[v + 1] = e[v];
                t.c++;
                v--;
            }
            else {
                break;
            }
        }
        e[v + 1] = u;
        t.c++;
    }
    return t;
}

a w(int e[], int f) {
    a t;
    for (int g = 0; g < f - 1; ++g) {
        int x = g;
        for (int v = g + 1; v < f; ++v) {
            t.b++;
            if (e[v] < e[x]) {
                x = v;
            }
        }
        if (x != g) {
            int y = e[g];
            e[g] = e[x];
            e[x] = y;
            t.c += 3;
        }
    }
    return t;
}

a z(int e[], int f) {
    a t;
    bool aa;
    for (int g = 0; g < f - 1; ++g) {
        aa = false;
        for (int v = 0; v < f - g - 1; ++v) {
            t.b++;
            if (e[v] > e[v + 1]) {
                int y = e[v];
                e[v] = e[v + 1];
                e[v + 1] = y;
                t.c += 3;
                aa = true;
            }
        }
        if (!aa) break;
    }
    return t;
}

struct ab {
    int ac[20];
    int ad;
    int ae[20];
    int af;
    const char* ag;
};

void ah() {
    cout << "\n NABIR AVTOMATYZHOVANYKH TESTIV \n";

    ab ai[12] = {
        {{}, 0, {}, 0, "Porozhniy masyv"},
        {{7}, 1, {7}, 1, "Odyn element"},
        {{1, 2, 3, 4, 5}, 5, {1, 2, 3, 4, 5}, 5, "Uzhe vporyadkovanyy"},
        {{5, 4, 3, 2, 1}, 5, {1, 2, 3, 4, 5}, 5, "Zvrotnyy poryadok"},
        {{4, 1, 5, 2, 3}, 5, {1, 2, 3, 4, 5}, 5, "Zmishanyy poryadok"},
        {{3, 1, 3, 2, 1}, 5, {1, 1, 2, 3, 3}, 5, "Povtoryuvani znachennya"},
        {{0, -5, 8, -2, 4}, 5, {-5, -2, 0, 4, 8}, 5, "Vid'yemni chysla i nul'"},
        {{6, 6, 6, 6}, 4, {6, 6, 6, 6}, 4, "Usi znachennya odnakovi"},
        {{2, 1}, 2, {1, 2}, 2, "Minimal'na perestanovka"},
        {{9, -1, 9, 0, -1, 5}, 6, {-1, -1, 0, 5, 9, 9}, 6, " Kombinovanyy vypadok"},
        {{10, -3, 25, 0, 15, -3}, 6, {-3, -3, 0, 10, 15, 25}, 6, "Vlasnyy test 1"},
        {{100, 50, 25, 10, 5}, 5, {5, 10, 25, 50, 100}, 5, "Vlasnyy test 2"}
    };

    int aj = 0;
    const char* ak[3] = { "Vstavky", "Vybir", "Bul'bashka" };

    for (int g = 0; g < 3; ++g) {
        int al = 0;
        for (int i = 0; i < 12; ++i) {
            int am[20];
            int an = ai[i].ad;
            h(ai[i].ac, am, an);

            if (g == 0) s(am, an);
            else if (g == 1) w(am, an);
            else if (g == 2) z(am, an);

            bool ao = true;
            if (an != ai[i].af) {
                ao = false;
            }
            else {
                for (int p = 0; p < an; ++p) {
                    if (am[p] != ai[i].ae[p]) {
                        ao = false;
                        break;
                    }
                }
            }

            if (ao) {
                al++;
            }
        }
        aj += al;
        cout << "Algorytm: " << ak[g] << " | Uspishno proydeno testiv: " << al << " / 12\n";
    }
    cout << "Zahal'nyy resultat: " << aj << " uspishnykh perevirok iz 36 mozhlyvykh.\n";
}

int main() {
    cout << " PIDHOTOVKA DANYKH (Variant 5) \n";
    const int ap = 10;
    int aq[ap] = { 21, 3, 28, 13, 7, 32, 10, 2, 25, 16 };

    cout << "Pochatkovyy masyv: ";
    d(aq, ap);

    long long ar = 0, as = 0;
    for (int g = 0; g < ap; ++g) {
        ar += aq[g];
        as += (long long)aq[g] * aq[g];
    }

    const char* ak[3] = { "Sortuvannya vstavkamy", "Sortuvannya vyborom", "ul'bashkove sortuvannya" };
    const char* at_names[3] = { "vstavkamy", "vyborom", "bul'bashkove" };

    for (int g = 0; g < 3; ++g) {
        int at[ap];
        h(aq, at, ap);
        a t;

        if (g == 0) t = s(at, ap);
        else if (g == 1) t = w(at, ap);
        else if (g == 2) t = z(at, ap);

        cout << "\n Sortuvannya " << at_names[g] << " \n";
        cout << "Vdysortovano: ";
        d(at, ap);
        cout << "Porivnyan': " << t.b << ", Peremishchen': " << t.c << "\n";

        bool au = j(at, ap);
        bool av = k(ap, ar, as, at, ap);

        if (au && av) {
            cout << "Perevirka: uspishno\n";
        }
        else {
            cout << "Perevirka: pomylka\n";
        }
    }

    ah();

    cout << "\n PORIVNYAL'NYY EKSPERYMENT (100 elementiv) \n";

    const int aw = 100;
    int ax[aw];
    int ay[aw];
    int az[aw];

    for (int g = 0; g < aw; ++g) {
        ax[g] = g + 1;
        ay[g] = aw - g;
        az[g] = (g * 37) % 101;
    }

    const char* ba[3] = { "Zrostannya", "Spadannya", "Zmishanyy" };
    const char* alg_short[3] = { "Vstavky", "Vybir", "Bul'bashka" };

    for (int g = 0; g < 3; ++g) {
        for (int bb = 0; bb < 3; ++bb) {
            int bc[aw];
            if (bb == 0) h(ax, bc, aw);
            else if (bb == 1) h(ay, bc, aw);
            else h(az, bc, aw);

            a t;
            if (g == 0) t = s(bc, aw);
            else if (g == 1) t = w(bc, aw);
            else t = z(bc, aw);

            bool bd = j(bc, aw);

            cout << alg_short[g] << " | " << ba[bb]
                << " | Porivnyan': " << t.b
                << " | Peremishchen': " << t.c
                << " | " << (bd ? "Uspishno" : "Pomylka") << "\n";
        }
    }

    return 0;
}
