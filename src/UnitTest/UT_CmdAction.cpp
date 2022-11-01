#include <catch2/catch_all.hpp>
#include <catch2/catch_test_macros.hpp>
#include "DomainModel/CmdAction.h"
#include <rttr/type>

using namespace HZP;
using namespace rttr;

TEST_CASE("Domain Module Test","[CmdAction]") {

    string device = "CMW";

    std::shared_ptr<CmdAction> ptrCmdAction = std::make_shared<CmdAction>(device);
    type cmdActionType = type::get_by_name("CmdAction");


    string cmd = "IDN";
    variant rsObj = cmdActionType.get_method(cmd).invoke(ptrCmdAction);
    string rs = rsObj.get_value<CmdResult>().GetResult();
    REQUIRE(rs == "Rohde&Schwarz CMW");

    cmd = "PSC";
    vector<string> params;
    params.push_back("hello");
    params.push_back("reflection");
    rsObj = cmdActionType.get_method(cmd).invoke(ptrCmdAction, params);
    rs = rsObj.get_value<CmdResult>().GetResult();
    REQUIRE(rs== "Run PSC Cmd CMW");
}