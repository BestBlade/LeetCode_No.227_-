/* ------------------------------------------------------------------|
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

整数除法仅保留整数部分。

 

示例 1：

输入：s = "3+2*2"
输出：7
示例 2：

输入：s = " 3/2 "
输出：1
示例 3：

输入：s = " 3+5 / 2 "
输出：5
 

提示：

1 <= s.length <= 3 * 105
s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
s 表示一个 有效表达式
表达式中的所有整数都是非负整数，且在范围 [0, 231 - 1] 内
题目数据保证答案是一个 32-bit 整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/basic-calculator-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	单队列法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了99.44%的用户
*	内存消耗：8.4 MB, 在所有 C++ 提交中击败了72.88%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int calculate(string s) {
    deque<int> num;
    num.emplace_back(0);
    int sign = 1;
    int flag = 0;

    int n = s.size();
    int i = 0;
    while (i < n) {
        if (s[i] == ' ') {
            i++;
        }
        else if (s[i] == '+') {
            sign = 1;
            i++;
        }
        else if (s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (s[i] == '*') {
            flag = 1;
            i++;
        }
        else if (s[i] == '/') {
            flag = -1;
            i++;
        }
        else {
            long tmp = 0;
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                tmp = tmp * 10 + s[i] - '0';
                i++;
            } 
            if (flag == 1) {
                num.back() *= tmp;
                flag = 0;
            }
            else if (flag == -1) {
                num.back() /= tmp;
                flag = 0;
            }
            else {
                num.emplace_back(sign * tmp);
            }
        }
    }

    int res = 0;
    while (!num.empty()) {
        res += num.front();
        num.pop_front();
    }
    return res;
}

int main() {
    string s = "-3+2*2";
    calculate(s);
}