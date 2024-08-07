#include <iostream>
#include <vector>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> songs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> songs[i];
    }

    std::set<int> songSet;
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        while (songSet.count(songs[right])) {
            songSet.erase(songs[left]);
            ++left;
        }

        songSet.insert(songs[right]);

        maxLength = std::max(maxLength, right - left + 1);
    }

    std::cout << maxLength << std::endl;

    return 0;
}
