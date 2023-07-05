#pragma once

#include <cmath>
#include <tuple>

struct ImVec2;

struct Vec2
{
    Vec2() = default;

    Vec2(const Vec2&) = default;

    Vec2(float x_, float y_)
        : x(x_), y(y_){};

    /// NoDoc
    Vec2(std::pair<float, float> p)
        : x(p.first), y(p.second){};

    /// NoDoc
    Vec2(const ImVec2&);

    Vec2& rotate(float angle, float px, float py)
    {
        const float sin_a{std::sin(angle)};
        const float cos_a{std::cos(angle)};
        const Vec2 p{px, py};

        *this -= p;
        const Vec2 copy = *this;
        this->x = copy.x * cos_a - copy.y * sin_a;
        this->y = copy.y * cos_a + copy.x * sin_a;
        *this += p;
        return *this;
    }

    Vec2 operator+(const Vec2& a) const
    {
        return Vec2{x + a.x, y + a.y};
    }
    Vec2 operator-(const Vec2& a) const
    {
        return Vec2{x - a.x, y - a.y};
    }
    Vec2 operator-() const
    {
        return {-x, -y};
    }
    Vec2 operator*(const Vec2& a) const
    {
        return Vec2{x * a.x, y * a.y};
    }
    Vec2 operator*(float a) const
    {
        return Vec2{x * a, y * a};
    }
    Vec2 operator/(const Vec2& a) const
    {
        return Vec2{x / a.x, y / a.y};
    }
    Vec2 operator/(const float& a) const
    {
        return Vec2{x / a, y / a};
    }
    Vec2& operator+=(const Vec2& a)
    {
        x += a.x;
        y += a.y;
        return *this;
    }
    Vec2& operator-=(const Vec2& a)
    {
        x -= a.x;
        y -= a.y;
        return *this;
    }
    Vec2& operator++()
    {
        x++;
        y++;
        return *this;
    }
    Vec2 operator++(int)
    {
        Vec2 old = *this;
        operator++();
        return old;
    }
    Vec2& operator--()
    {
        x--;
        y--;
        return *this;
    }
    Vec2 operator--(int)
    {
        Vec2 old = *this;
        operator--();
        return old;
    }
    bool operator==(const Vec2& a) const
    {
        return x == a.x && y == a.y;
    }
    /*
    std::tuple<float, float> split()
    {} // just for the autodoc
    */
    operator std::pair<float, float>() const
    {
        return {x, y};
    }
    operator std::tuple<float, float>() const
    {
        return {x, y};
    }
    operator std::tuple<float&, float&>()
    {
        return {x, y};
    }

    float x{0};
    float y{0};
};

struct AABB
{
    /// Create a new axis aligned bounding box - defaults to all zeroes
    AABB() = default;

    /// Copy an axis aligned bounding box
    AABB(const AABB&) = default;
    /// NoDoc
    AABB(const std::tuple<float, float, float, float> tuple)
    {
        left = std::get<0>(tuple);
        top = std::get<1>(tuple);
        right = std::get<2>(tuple);
        bottom = std::get<3>(tuple);
    };

    AABB(const Vec2& top_left, const Vec2& bottom_right)
        : left(top_left.x), top(top_left.y), right(bottom_right.x), bottom(bottom_right.y){};

    /// Create a new axis aligned bounding box by specifying its values
    AABB(float left_, float top_, float right_, float bottom_)
        : left(left_), top(top_), right(right_), bottom(bottom_){};

    bool overlaps_with(const AABB& other) const
    {
        return left < other.right && other.left < right && bottom < other.top && other.bottom < top;
    }

    bool is_valid() const
    {
        return !(left == 0.0f && right == 0.0f && top == 0.0f && bottom == 0.0f);
    }

    /// Fixes the AABB if any of the sides have negative length
    AABB& abs()
    {
        if (left > right)
            std::swap(left, right);
        if (bottom > top)
            std::swap(bottom, top);
        return *this;
    }

    /// Grows or shrinks the AABB by the given amount in all directions.
    /// If `amount < 0` and `abs(amount) > right/top - left/bottom` the respective dimension of the AABB will become `0`.
    AABB& extrude(float amount)
    {
        return extrude(amount, amount);
    }
    /// Grows or shrinks the AABB by the given amount in each direction.
    /// If `amount_x/y < 0` and `abs(amount_x/y) > right/top - left/bottom` the respective dimension of the AABB will become `0`.
    AABB& extrude(float amount_x, float amount_y)
    {
        left -= amount_x;
        right += amount_x;
        if (left > right)
        {
            left = (left + right) / 2.0f;
            right = left;
        }

        bottom -= amount_y;
        top += amount_y;
        if (bottom > top)
        {
            bottom = (bottom + top) / 2.0f;
            top = bottom;
        }
        return *this;
    }
    /// Offsets the AABB by the given offset.
    AABB& offset(float off_x, float off_y)
    {
        left += off_x;
        bottom += off_y;
        right += off_x;
        top += off_y;
        return *this;
    }
    /// Same as offset
    AABB operator+(const Vec2& a) const
    {
        AABB new_aabb{*this};
        new_aabb.offset(a.x, a.y);
        return new_aabb;
    }
    /// Same as offset
    AABB operator-(const Vec2& a) const
    {
        AABB new_aabb{*this};
        new_aabb.offset(-a.x, -a.y);
        return new_aabb;
    }
    /// Compute area of the AABB, can be zero if one dimension is zero or negative if one dimension is inverted.
    float area() const
    {
        return width() * height();
    }
    /// Short for `(aabb.left + aabb.right) / 2.0f, (aabb.top + aabb.bottom) / 2.0f`.
    std::pair<float, float> center() const
    {
        return {(left + right) / 2.0f, (top + bottom) / 2.0f};
    }
    /// Short for `aabb.right - aabb.left`.
    float width() const
    {
        return (right - left);
    }
    /// Short for `aabb.top - aabb.bottom`.
    float height() const
    {
        return (top - bottom);
    }
    /// Checks if point lies between left/right and top/bottom
    bool is_point_inside(const Vec2 p)
    {
        AABB copy{*this};
        copy.abs();
        if (copy.left < p.x && copy.right > p.x && copy.bottom < p.y && copy.top > p.y)
            return true;

        return false;
    }
    bool is_point_inside(float x, float y)
    {
        AABB copy{*this};
        copy.abs();
        if (copy.left < x && copy.right > x && copy.bottom < y && copy.top > y)
            return true;

        return false;
    }
    /*
    std::tuple<float, float, float, float> split()
    {} // just for the autodoc
    */
    operator std::tuple<float, float, float, float>() const
    {
        return {left, top, right, bottom};
    }

    float left{0};
    float top{0};
    float right{0};
    float bottom{0};
};

struct Triangle
{
    Triangle() = default;
    Triangle(const Triangle&) = default;
    Triangle(const Vec2& _a, const Vec2& _b, const Vec2& _c)
        : A(_a), B(_b), C(_c){};
    Triangle(float ax, float ay, float bx, float by, float cx, float cy)
        : A(ax, ay), B(bx, by), C(cx, cy){};

    Triangle& offset(const Vec2& off)
    {
        A += off;
        B += off;
        C += off;
        return *this;
    }
    Triangle& offset(float x, float y)
    {
        return offset({x, y});
    }
    Triangle operator+(const Vec2& a) const
    {
        Triangle new_triangle{*this};
        new_triangle.offset(a);
        return new_triangle;
    }
    Triangle operator-(const Vec2& a) const
    {
        Triangle new_triangle{*this};
        new_triangle.offset(-a);
        return new_triangle;
    }
    /// Rotate triangle by an angle, the px/py are just coordinates, not offset from the center
    Triangle& rotate(float angle, float px, float py)
    {
        const float sin_a{std::sin(angle)};
        const float cos_a{std::cos(angle)};
        const Vec2 p{px, py};

        auto rotate_around_pivot = [=](Vec2 in) -> Vec2
        {
            in -= p;
            const Vec2 old = in;
            in.x = old.x * cos_a - old.y * sin_a;
            in.y = old.y * cos_a + old.x * sin_a;
            in += p;
            return in;
        };

        A = rotate_around_pivot(A);
        B = rotate_around_pivot(B);
        C = rotate_around_pivot(C);
        return *this;
    }
    /// Also known as centroid
    Vec2 center() const
    {
        return {(A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3};
    }
    /// Returns ABC, BCA, CAB angles in radians
    std::tuple<float, float, float> get_angles() const
    {
        Vec2 ab = B - A;
        Vec2 ac = C - A;
        Vec2 bc = C - B;
        float a_abc = std::abs(std::atan2(bc.y * ab.x - bc.x * ab.y, bc.x * ab.x + bc.y * ab.y));
        float a_bca = std::abs(std::atan2(ac.y * bc.x - ac.x * bc.y, ac.x * bc.x + ac.y * bc.y));
        float a_cab = std::abs(std::atan2(ab.y * ac.x - ab.x * ac.y, ab.x * ac.x + ab.y * ac.y));
        return {a_abc, a_cab, a_bca};
    }
    Triangle& scale(float scale)
    {
        Vec2 centroid = center();
        A = (A - centroid) * scale + centroid;
        B = (B - centroid) * scale + centroid;
        C = (C - centroid) * scale + centroid;
        return *this;
    }

    /*
    /// Returns the corners
    std::tuple<Vec2, Vec2, Vec2> split()
    {} // just for the autodoc
    */

    /// Returns the corners
    operator std::tuple<Vec2, Vec2, Vec2>() const
    {
        return {A, B, C};
    }

    Vec2 A;
    Vec2 B;
    Vec2 C;
};

struct Quad
{
    Quad() = default;

    Quad(const Quad&) = default;

    Quad(const Vec2& bottom_left_, const Vec2& bottom_right_, const Vec2& top_right_, const Vec2& top_left_)
        : bottom_left_x(bottom_left_.x), bottom_left_y(bottom_left_.y), bottom_right_x(bottom_right_.x), bottom_right_y(bottom_right_.y), top_right_x(top_right_.x), top_right_y(top_right_.y), top_left_x(top_left_.x), top_left_y(top_left_.y){};

    Quad(float _bottom_left_x, float _bottom_left_y, float _bottom_right_x, float _bottom_right_y, float _top_right_x, float _top_right_y, float _top_left_x, float _top_left_y)
        : bottom_left_x(_bottom_left_x), bottom_left_y(_bottom_left_y), bottom_right_x(_bottom_right_x), bottom_right_y(_bottom_right_y), top_right_x(_top_right_x), top_right_y(_top_right_y), top_left_x(_top_left_x), top_left_y(_top_left_y){};

    Quad(const AABB& aabb)
        : bottom_left_x(aabb.left), bottom_left_y(aabb.bottom), bottom_right_x(aabb.right), bottom_right_y(aabb.bottom), top_right_x(aabb.right), top_right_y(aabb.top), top_left_x(aabb.left), top_left_y(aabb.top){};

    /// Returns the max/min values of the Quad
    AABB get_AABB() const
    {
        AABB result;
        result.right = std::max({bottom_left_x, bottom_right_x, top_right_x, top_left_x});
        result.left = std::min({bottom_left_x, bottom_right_x, top_right_x, top_left_x});
        result.top = std::max({bottom_left_y, bottom_right_y, top_right_y, top_left_y});
        result.bottom = std::min({bottom_left_y, bottom_right_y, top_right_y, top_left_y});
        return result;
    }

    Quad& offset(float off_x, float off_y)
    {
        bottom_left_x += off_x;
        bottom_right_x += off_x;
        top_right_x += off_x;
        top_left_x += off_x;

        bottom_left_y += off_y;
        bottom_right_y += off_y;
        top_right_y += off_y;
        top_left_y += off_y;
        return *this;
    }
    /// Same as offset
    Quad operator+(const Vec2& a) const
    {
        Quad new_quad{*this};
        new_quad.offset(a.x, a.y);
        return new_quad;
    }
    /// Same as offset
    Quad operator-(const Vec2& a) const
    {
        Quad new_quad{*this};
        new_quad.offset(-a.x, -a.y);
        return new_quad;
    }
    bool is_null() const
    {
        return bottom_left_x == 0 && bottom_left_y == 0 && bottom_right_x == 0 && bottom_right_y == 0 /**/
               && top_left_x == 0 && top_left_y == 0 && top_right_x == 0 && top_right_y == 0;
    }

    /// Rotates a Quad by an angle, px/py are not offsets, use `:get_AABB():center()` to get approximated center for simetrical quadrangle
    Quad& rotate(float angle, float px, float py)
    {
        const float sin_a{std::sin(angle)};
        const float cos_a{std::cos(angle)};
        const Vec2 p{px, py};

        auto rotate_around_pivot = [=](Vec2 in) -> Vec2
        {
            in -= p;
            const Vec2 old = in;
            in.x = old.x * cos_a - old.y * sin_a;
            in.y = old.y * cos_a + old.x * sin_a;
            in += p;
            return in;
        };

        std::tie(bottom_left_x, bottom_left_y) = rotate_around_pivot({bottom_left_x, bottom_left_y});
        std::tie(bottom_right_x, bottom_right_y) = rotate_around_pivot({bottom_right_x, bottom_right_y});
        std::tie(top_left_x, top_left_y) = rotate_around_pivot({top_left_x, top_left_y});
        std::tie(top_right_x, top_right_y) = rotate_around_pivot({top_right_x, top_right_y});

        return *this;
    }

    Quad& flip_horizontally()
    {
        std::swap(top_left_x, top_right_x);
        std::swap(top_left_y, top_right_y);
        std::swap(bottom_left_x, bottom_right_x);
        std::swap(bottom_left_y, bottom_right_y);

        return *this;
    }

    Quad& flip_vertically()
    {
        std::swap(top_left_x, bottom_left_x);
        std::swap(top_left_y, bottom_left_y);
        std::swap(top_right_x, bottom_right_x);
        std::swap(top_right_y, bottom_right_y);

        return *this;
    }
    /*
    /// Returns the corners in order: bottom_left, bottom_right, top_right, top_left
    std::tuple<Vec2, Vec2, Vec2, Vec2> split()
    {} // just for the autodoc
    */

    /// Returns the corners in order: bottom_left, bottom_right, top_right, top_left
    operator std::tuple<Vec2, Vec2, Vec2, Vec2>() const
    {
        return {{bottom_left_x, bottom_left_y}, {bottom_right_x, bottom_right_y}, {top_right_x, top_right_y}, {top_left_x, top_left_y}};
    }

    float bottom_left_x{0};
    float bottom_left_y{0};
    float bottom_right_x{0};
    float bottom_right_y{0};
    float top_right_x{0};
    float top_right_y{0};
    float top_left_x{0};
    float top_left_y{0};
};

// get intersection point of two lines
Vec2 intersection(const Vec2 A, const Vec2 B, const Vec2 C, const Vec2 D);
