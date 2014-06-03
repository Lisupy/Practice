#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

#define EPS 1e-12
#define FUZZY_EQ(x, y) (std::abs((x) - (y)) <= EPS)
#define STEP_SIZE 0.001
   
struct AnsComp {

    bool operator()(const std::pair<long double, long double> &a, const std::pair<long double, long double> &b) const {
        if(std::abs(a.first - b.first) < 0.01) {
            return a.second > b.second;
        }

        if(a.first < b.first) {
            return true;
        }

        if(a.first > b.first) {
            return false;
        }
    }

};

long double radarToReal(long double a) {
    return -(M_PI * a / 180.0) + M_PI / 2.0;
}

long double getPlaneX(long double a, long double d) {
    return d * std::cos(radarToReal(a));
}

long double getPlaneY(long double a, long double d) {
    return d * std::sin(radarToReal(a));
}

long double normalizeAngleDegrees(long double a) {
    while(a <= 0) {
        a += 360.0;
    }

    while(a > 360.0) {
        a -= 360.0;
    }

    return std::abs(a);
}

long double normalizeAngleRadians(long double a) {
    while(a < 0) {
        a += 2.0 * M_PI;
    }

    while(a >= 2.0 * M_PI) {
        a -= 2.0 * M_PI;
    }

    return a;
}

long double f(long double a, long double t0, long double x0, long double vx, long double y0, long double vy) {
    long double t = a / 180.0;
    long double x = x0 + (t - t0) * vx;
    long double y = y0 + (t - t0) * vy;
    return (std::cos(M_PI * t) * x - std::sin(M_PI * t) * y) / 2.0;
}

long double d(long double a, long double t0, long double x0, long double vx, long double y0, long double vy) {
    return normalizeAngleRadians(std::atan2(y0 + ((a / 180.0) - t0) * vy, x0 + ((a / 180.0) - t0) * vx)) - normalizeAngleRadians(radarToReal(a));
}

long double bisectSearch(long double start, long double end, long double t0, long double x0, long double vx, long double y0, long double vy) {
    long double startVal = f(start, t0, x0, vx, y0, vy);
    while(true) {
        long double mid = (start + end) / 2.0;
        long double midVal = f(mid, t0, x0, vx, y0, vy);
        if(FUZZY_EQ(midVal, 0.0)) {
#ifdef DEBUG
            std::cout << "Found " << mid << std::endl;
#endif
            return mid;
        }
        if((midVal <= 0 && startVal <= 0) || (midVal >= 0 && startVal >= 0)) {
            start = mid;
            startVal = midVal;
        } else {
            end = mid;
        }
    }
}


long double searchLinear(long double startAngle, long double stepSize, long double t0, long double x0, long double vx, long double y0, long double vy) {
    long double prev = f(startAngle + stepSize, t0, x0, vx, y0, vy);
    long double prevAngle = startAngle + stepSize;
    long double cur = f(startAngle + 2.0 * stepSize, t0, x0, vx, y0, vy);
    long double curAngle = startAngle + 2.0 * stepSize;

#ifdef DEBUG
    std::cout << "    Linear searching for next intercept after " << startAngle << std::endl;
#endif

    while(true) {
        if((prev <= 0 && cur >= 0) || (prev >= 0 && cur <= 0) || FUZZY_EQ(cur, 0)) {
            // Potential solution; triangle area is 0, so either radar is facing plane, is 180 degrees away, or plane is on top.  Ignore all but the first case.
            long double dPrevVal = d(prevAngle, t0, x0, vx, y0, vy);
            long double dCurVal = d(curAngle, t0, x0, vx, y0, vy);

#ifdef DEBUG
            std::cout << "      Found a triangleArea root at " << curAngle << ", precise answer is " << dPrevVal << "/" << dCurVal << std::endl;
#endif
            if(std::abs(dPrevVal) < stepSize || std::abs(dCurVal) < stepSize) {
#ifdef DEBUG
                std::cout << "        Bisect searching between " << prev << "@" << prevAngle << " and " << cur << " @ " << curAngle << std::endl;
#endif
                long double a = FUZZY_EQ(cur, 0) ? curAngle : bisectSearch(prevAngle, curAngle, t0, x0, vx, y0, vy);
                // Make sure we are not on top of the station
                long double x = x0 + ((a / 180.0) - t0) * vx;
                long double y = y0 + ((a / 180.0) - t0) * vy;

#ifdef DEBUG
                std::cout << "        Found " << a << "; plane location at answer: (" << x << ", " << y << ")" << std::endl;
#endif
                if(!FUZZY_EQ(x, 0) || !FUZZY_EQ(y, 0)) {
                    return a;
                }
            }
        } /*else {
            long double mid = d((prevAngle + curAngle) / 2.0, t0, x0, vx, y0, vy);
            if((mid >= 0 && mid < stepSize && mid < prev && mid < cur) ||
               (mid <= 0 && mid > -stepSize && mid > prev && mid > cur)) {

                std::cout << "Possible tangent found!" << std::endl;
            }
            }*/

        prevAngle = curAngle;
        curAngle += stepSize;
        prev = cur;
        cur = f(curAngle, t0, x0, vx, y0, vy);
    }
}

std::pair<long double, long double> getAnswer(long double pos, long double t0, long double x0, long double vx, long double y0, long double vy) {
    long double t = pos / 180.0;
    long double x = x0 + (t - t0) * vx;
    long double y = y0 + (t - t0) * vy;
    long double dist = std::sqrt(x*x + y*y);
    return std::make_pair(normalizeAngleDegrees(pos), dist);
}

int main(int arc, char **argv) {
    while(true) {
        long double a1, d1, a2, d2;
        if(!(std::cin >> a1 >> d1 >> a2 >> d2)) {
            break;
        }

        long double x0 = getPlaneX(a1, d1);
        long double y0 = getPlaneY(a1, d1);
        long double t0 = a1 / 180.0;

        long double x1 = getPlaneX(a2, d2);
        long double y1 = getPlaneY(a2, d2);
        long double t1 = a2 / 180.0;

        std::vector<std::pair<long double, long double> > ans;

        if(a2 <= a1) {
            t1 += 2.0;
            a2 += 360.0;
        }

        long double vx = (x1 - x0) / (t1 - t0);
        long double vy = (y1 - y0) / (t1 - t0);
        long double a3 = searchLinear(a2, STEP_SIZE, t0, x0, vx, y0, vy);
        ans.push_back(getAnswer(a3, t0, x0, vx, y0, vy));

        t1 += 2.0;
        a2 += 360.0;

        vx = (x1 - x0) / (t1 - t0);
        vy = (y1 - y0) / (t1 - t0);
        long double a2Pos = searchLinear(a1, STEP_SIZE, t0, x0, vx, y0, vy);
        if(std::abs(a2Pos - a2) < STEP_SIZE) {
            long double a3 = searchLinear(a2, STEP_SIZE, t0, x0, vx, y0, vy);
            ans.push_back(getAnswer(a3, t0, x0, vx, y0, vy));
        }

        std::sort(ans.begin(), ans.end(), AnsComp());

        for(int i = 0; i < (int) ans.size(); i++) {
            if(i == (int) ans.size() - 1 || !FUZZY_EQ(ans[i].first, ans[i + 1].first) || !FUZZY_EQ(ans[i].second, ans[i + 1].second)) {
                std::cout << std::fixed << std::setprecision(2) << ans[i].first + 1e-7 << " " << ans[i].second + 1e-7;
                if(i != ans.size() - 1) {
                    std::cout << " ";
                }
            }
        }
        std::cout << "\n";
    }
    return 0;
}
