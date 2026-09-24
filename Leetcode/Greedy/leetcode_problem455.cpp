class Solution {
public:
    int findContentChildren(vector<int>& Student, vector<int>& Cookie) {
        int s = Student.size();
        int c = Cookie.size();

        sort(Cookie.begin(), Cookie.end());
        sort(Student.begin(), Student.end());

        int i = 0;
        int j = 0;

        while (i < s && j < c) {
            if (Student[i] <= Cookie[j]) {
                i++;
            }
            j++;
        }

        return i;
    }
};