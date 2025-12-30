#pragma once
// Segment is a small structure to hold the coordinates of a point on the board.
// it is used for snake body parts, food, and poison positions.
struct Segment {
    int x;
    int y;

    Segment() : x(0), y(0) {}
    Segment(int px, int py) : x(px), y(py) {}
};
#pragma once
