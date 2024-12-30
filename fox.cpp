#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>

using namespace std;

void process_test_case(const vector<string>& recording, const unordered_set<string>& known_sounds) {
    vector<string> fox_sounds;
    for (const string& sound : recording) {
        if (known_sounds.find(sound) == known_sounds.end()) {
            fox_sounds.push_back(sound);
        }
    }
    for (size_t i = 0; i < fox_sounds.size(); ++i) {
        if (i > 0) cout << " ";
        cout << fox_sounds[i];
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    
    while (T--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<string> recording;
        string sound;
        
        while (ss >> sound) {
            recording.push_back(sound);
        }
        
        unordered_set<string> known_sounds;
        
        while (true) {
            getline(cin, line);
            if (line == "what does the fox say?") {
                break;
            }
            stringstream sound_mapping(line);
            string animal, goes, animal_sound;
            sound_mapping >> animal >> goes >> animal_sound;
            known_sounds.insert(animal_sound);
        }
        
        process_test_case(recording, known_sounds);
    }
    
    return 0;
}

