#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Twitter {
private:
    int timeStamp;

    struct Tweet {
        int tweetId;
        int time;
        Tweet(int id, int t) : tweetId(id), time(t) {}
    };

    // userId -> list of their tweets
    unordered_map<int, vector<Tweet>> userTweets;
    
    // userId -> set of followeeIds
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // Assign current global timestamp and increment it for the next tweet
        userTweets[userId].push_back(Tweet(tweetId, timeStamp++));
    }
    
    vector<int> getNewsFeed(int userId) {
        // Min-heap to store pairs of {timestamp, tweetId}
        // std::greater makes it a Min-Heap (smallest timestamp at the top)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // 1. Collect tweets from the user themselves (up to the last 10)
        if (userTweets.find(userId) != userTweets.end()) {
            const auto& tweets = userTweets[userId];
            int count = 0;
            for (auto it = tweets.rbegin(); it != tweets.rend() && count < 10; ++it, ++count) {
                minHeap.push({it->time, it->tweetId});
                if (minHeap.size() > 10) {
                    minHeap.pop(); // Remove the oldest timestamp
                }
            }
        }

        // 2. Collect tweets from all followees
        if (following.find(userId) != following.end()) {
            for (int followeeId : following[userId]) {
                if (followeeId == userId) continue; // Skip self if already included

                if (userTweets.find(followeeId) != userTweets.end()) {
                    const auto& tweets = userTweets[followeeId];
                    int count = 0;
                    for (auto it = tweets.rbegin(); it != tweets.rend() && count < 10; ++it, ++count) {
                        minHeap.push({it->time, it->tweetId});
                        if (minHeap.size() > 10) {
                            minHeap.pop();
                        }
                    }
                }
            }
        }

        // 3. Extract elements from the heap into a result vector
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        // Reverse to get newest-to-oldest order
        reverse(result.begin(), result.end());
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};