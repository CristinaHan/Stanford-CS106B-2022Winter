/*
 * CS106B Section Handout Test Harness: Section 4
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified for Qt and Ed by Neel
 * Kishnani for Winter 2022.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
#include "set.h"
#include "map.h"
#include "vector.h"
using namespace std;

/*
 * Function: canVisitAllSites
 * ---------------------------
 * Write a function that takes as input a list of all the
 * sites you’d like to visit and an amount of free time
 * available to you and returns whether it’s possible to
 * visit all those sites in the allotted time (assume you’ve
 * already factored inthe cost of speaking at each site
 * and that you’re just concerned about the travel time.)
 */
double distanceBetween(const GPoint& one, const GPoint& two) {
    /* double dx = one.x() - two.x();
    double dy = one.y() - two.y();
    return sqrt(dx * dx + dy * dy);*/
    return 0;
}
bool canVisitAllSitesRec(const Vector<GPoint>& sites, double travelTimeAvailable,
                         const GPoint& last) {
    if (sites.isEmpty()) {
        return true;
    }
    else {
        for (int i = 0; i < sites.size(); i++) {
            double distance = distanceBetween(last, sites[i]);
            Vector<GPoint> remainSites = sites.subList(0, i) + sites.subList(i + 1);
            if (travelTimeAvailable >= distance &&
                canVisitAllSitesRec(remainSites, travelTimeAvailable - distance, sites[i])) {
                return true;
            }
        }
        return false;
    }
}
bool canVisitAllSites(const Vector<GPoint>& sites, double travelTimeAvailable) {
    if (sites.isEmpty()) {
        return true;
    }
    for (int i = 0; i < sites.size(); i++) {
        Vector<GPoint> remainSites = sites.subList(0, i) + sites.subList(i + 1);
        if (canVisitAllSitesRec(remainSites, travelTimeAvailable, sites[i])) {
            return true;
        }
    }
    return false;
}

/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Simple examples!") {
    Vector<GPoint> sites1 = {{0, 0}, {5, 5}};
    Vector<GPoint> sites2 = {{0, 0}, {2, 2}, {5, 5}};
    EXPECT_EQUAL(canVisitAllSites(sites1, 8), true);
    EXPECT_EQUAL(canVisitAllSites(sites2, 8), true);
}
