class RecentCounter{
    private:
        queue<int>req;
    public:
        RecentCounter()  {}

        int ping(int t){
            int lowerBound = t - 3000;
            req.push(t);
            while (!req.empty() && req.front() < lowerBound){
                req.pop();
            }

            return req.size();
        }
};
