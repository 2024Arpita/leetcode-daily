#include <bits/stdc++.h>
using namespace std;
struct Node {
  int val;
  Node *left;
  Node *right;
  Node(int val) {
    this->val = val;
    left = NULL;
    right = NULL;
  }
};
pair<int, int> findans(Node *node, int c) {
  if (node == NULL) {
    return {0, 0};
  }
  auto l = findans(node->left, c);
  auto r = findans(node->right, c);

  // case 1 -take curnode
  int take = node->val;
  if (node->left != NULL && node->right != NULL) {
    take -= c;
  }
  take += l.second + r.second;
  // case 2 - not curnode then we can take either left either right either none;
  int none = l.second + r.second;
  int take1 = l.first + r.second;
  int take2 = r.first + l.second;
  int finnottake = max({none, take1, take2});
  return {take, finnottake};
}
int solve(vector<int> &lvl, int c) {
  if (lvl[0] == -1) {
    return 0;
  }
  Node *node = new Node(lvl[0]);
  queue<Node *> q;
  q.push(node);
  int n = lvl.size();
  int i = 1;
  while (i < n && !q.empty()) {
    Node *cur = q.front();
    q.pop();

    if (i < n) {
      if (lvl[i] == -1) {
        cur->left = NULL;
      } else {
        Node *l = new Node(lvl[i]);
        cur->left = l;
        q.push(l);
      }
    }
    i++;
    if (i < n) {
      if (lvl[i] == -1) {
        cur->right = NULL;
      } else {
        Node *r = new Node(lvl[i]);
        cur->right = r;
        q.push(r);
      }
      i++;
    }
  }
  auto it = findans(node, c);
  return max(it.second, it.first);
}
int main() {
  int n;
  cin >> n;
  vector<int> lvl(n);
  for (int i = 0; i < n; i++) {
    cin >> lvl[i];
  }
  int c;
  cin >> c;
  cout << solve(lvl, c) << endl;
}
