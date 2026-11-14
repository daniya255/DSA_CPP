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
    Twitter() { timeStamp = 0; }

    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back(Tweet(tweetId, timeStamp++));
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;

        if (userTweets.find(userId) != userTweets.end()) {
            const auto& tweets = userTweets[userId];
            int count = 0;
            for (auto it = tweets.rbegin(); it != tweets.rend() && count < 10;
                 ++it, ++count) {
                minHeap.push({it->time, it->tweetId});
                if (minHeap.size() > 10) {
                    minHeap.pop(); // Remove the oldest timestamp
                }
            }
        }

        if (following.find(userId) != following.end()) {
            for (int followeeId : following[userId]) {
                if (followeeId == userId)
                    continue; // Skip self if already included

                if (userTweets.find(followeeId) != userTweets.end()) {
                    const auto& tweets = userTweets[followeeId];
                    int count = 0;
                    for (auto it = tweets.rbegin();
                         it != tweets.rend() && count < 10; ++it, ++count) {
                        minHeap.push({it->time, it->tweetId});
                        if (minHeap.size() > 10) {
                            minHeap.pop();
                        }
                    }
                }
            }
        }
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

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

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */