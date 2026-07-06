class Solution {
    // Map each course to its prerequisites
    unordered_map<int, vector<int>> preMap;
    // Store all courses along the current DFS path
    unordered_set<int> visiting;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //make a map with empty set and put courses
        //fill the prerqeuisist for all those courses
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }
        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        //loop through all courses perform dfs
        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }

        return true;
    }

    //DFS -> Base condition if visited return false
    // if there map is empty return true
    //mark visited
    //loop through it edges and do dfs
    //remove from visited
    //make the array empty

    bool dfs(int crs) {
        if (visiting.count(crs)) {
            // Cycle detected
            return false;
        }
        if (preMap[crs].empty()) {
            return true;
        }

        visiting.insert(crs);
        for (int pre : preMap[crs]) {
            if (!dfs(pre)) {
                return false;
            }
        }
        visiting.erase(crs);
        preMap[crs].clear();
        return true;
    }
};
