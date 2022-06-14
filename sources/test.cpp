#include "doctest.h"
#include "Leauge.hpp"


TEST_CASE("Team"){

    Team t {0.5, "noam's warriors"};
    Team t2 {0.15, "dan's"};
    Team t3 {0.135, "flare"};
    Team t4 {0.515, "fun"};

    Game g1 {&t, &t2};
    if(g1.winner){
        CHECK(t2.pointsDiff() > 0);
        CHECK(t.pointsDiff() < 0);
    }

    Game g2{&t3, &t4};

    if(g2.winner){
        CHECK(t2.pointsDiff() > 0);
        CHECK(t.pointsDiff() < 0);
    }


    Leauge lig; //generate 20 random teams
    CHECK_THROWS(lig.botTeams(5));
    CHECK_THROWS(lig.botTeams(10));
    CHECK_THROWS(lig.topTeams(10));
    CHECK_THROWS(lig.topTeams(5));

    lig.start();
    CHECK_NOTHROW(lig.botTeams(5));
    CHECK_NOTHROW(lig.topTeams(5));
    CHECK_NOTHROW(lig.longestLoseStreak());
    CHECK_NOTHROW(lig.longestWinStreak());
    CHECK_NOTHROW(lig.negetiveBalnce());
    CHECK_NOTHROW(lig.positiveBalnce());

    
}
