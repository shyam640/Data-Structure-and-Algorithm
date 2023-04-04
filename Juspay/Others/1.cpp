/*

You are given a forest (it may contain a single tree or more than one tree) with N nodes.

Each node is given an integer value 0 to (N­-1).

You have to find:

===================

The depth of forest at which maximum number of nodes are present.

N can be very large. Aim for an algorithm with a time complexity of O(N).

INPUT FORMAT

=================

An integer T, denoting the number of testcases, followed by 2T lines, as each testcase will contain 2 lines.

First line of each testcase has the value of N.

Second line of each testcase has list of N values where the number at index i is the parent of node i. The parent of root is -1. ( The index has the range [0, N­-1] ).

OUTPUT FORMAT

===============

For each testcase given, output a single line that has the depth of forest at which maximum number of nodes are present. If multiple depths has same number of nodes, then deepest depth should be selected.

SAMPLE INPUT

==============

2

6

5 -1 1 1 5 2

13

4 3 -1 -1 1 2 7 3 1 4 2 1 2

SAMPLE OUTPUT

====================

3

1

*/




static bool cmp(pair < int, int > a, pair < int, int > b) {
  if (a.first > b.first) {
    return 1;
  } else if (a.first == b.first) {
    if (a.second > b.second) {
      return 1;
    } else {
      return 0;
    }
  }
  return 0;

}

void solve() {
  int n;
  cin >> n;
  vector < vector > adjlist(n + 1);
  queue q1;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == -1) {
      q1.push(i);
    } else {
      adjlist[x].pb(i);
    }

  }
  vector < pair < int, int >> vp;
  vectorvis(n + 1, 0);
  queueq2;
  while (q1.size()) {
    int val = q1.front();
    q1.pop();
    q2.push(val);
    int level = 0;
    while (q2.size()) {
      int cnt = q2.size();
      for (int i = 0; i < cnt; i++) {

        int data = q2.front();
        q2.pop();
        vis[data] = 1;
        for (auto it: adjlist[data]) {
          if (vis[it] == 0) {
            q2.push(it);
            vis[it] = 1;
          }
        }

      }

      vp.push_back({
        cnt,
        level
      });
      level++;

    }
  }

  sort(vp.begin(), vp.end(), cmp);

  for (auto it: vp) {
    cout << it.first << " " << it.second << endl;
  }

}