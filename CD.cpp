#include <iostream>
using namespace std;

int main() {
    int N, M;
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) {
            break;
        }

        int jack_cds[100], jill_cds[100];
        bool common[100] = {false};

        for (int i = 0; i < N; i++) {
            cin >> jack_cds[i];
        }

        for (int i = 0; i < M; i++) {
            cin >> jill_cds[i];
        }

        int common_count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (jack_cds[i] == jill_cds[j] && !common[i]) {
                    common_count++;
                    common[i] = true;
                    break;
                }
            }
        }

        cout << common_count << endl;
    }

    return 0;
}

