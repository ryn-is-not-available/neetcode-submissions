#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();
        
        vector<tuple<string, int, string>> visits;
        visits.reserve(n);
        for (int i = 0; i < n; ++i) {
            visits.push_back({username[i], timestamp[i], website[i]});
        }
        
        sort(visits.begin(), visits.end(), [](const auto& a, const auto& b) {
            if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
            return get<1>(a) < get<1>(b);
        });

        unordered_map<string, vector<string>> userHistories;
        for (const auto& [user, time, web] : visits) {
            userHistories[user].push_back(web);
        }

        map<vector<string>, int> patternScores;

        for (const auto& [user, history] : userHistories) {
            int sz = history.size();
            if (sz < 3) continue;

            set<vector<string>> uniquePatternsForUser;

            for (int i = 0; i < sz - 2; ++i) {
                for (int j = i + 1; j < sz - 1; ++j) {
                    for (int k = j + 1; k < sz; ++k) {
                        uniquePatternsForUser.insert({history[i], history[j], history[k]});
                    }
                }
            }

            for (const auto& pattern : uniquePatternsForUser) {
                patternScores[pattern]++;
            }
        }

        vector<string> bestPattern;
        int maxScore = 0;

        for (const auto& [pattern, score] : patternScores) {
            if (score > maxScore) {
                maxScore = score;
                bestPattern = pattern;
            } else if (score == maxScore) {
                if (bestPattern.empty() || pattern < bestPattern) {
                    bestPattern = pattern;
                }
            }
        }

        return bestPattern;
    }
};