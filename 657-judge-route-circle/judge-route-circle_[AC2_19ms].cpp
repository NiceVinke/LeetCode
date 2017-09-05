// Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place. 
//
//
//
// The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
//
//
// Example 1:
//
// Input: "UD"
// Output: true
//
//
//
// Example 2:
//
// Input: "LL"
// Output: false


class Solution {
    int x, y;
    void move(char direct) {
        switch (direct) {
            case 'U': ++y;
                break;
            case 'D': --y;
                break;
            case 'L': --x;
                break;
            case 'R': ++x;
                break;
            default:
                break;
        }
    }
public:
    bool judgeCircle(string moves) {
        x = 0, y = 0;
        for (const auto &c : moves)
            move(c);
        return x == 0 && y == 0;
    }
};
