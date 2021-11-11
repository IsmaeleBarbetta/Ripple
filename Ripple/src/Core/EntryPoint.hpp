//
// Created by ismaele on 11/11/21.
//

#ifndef RIPPLE_ENTRYPOINT_HPP
#define RIPPLE_ENTRYPOINT_HPP

#include "Application.hpp"

int main(int argc, char* argv[]) {
    auto app = Ripple::Create();

    app->onCreate();
    app->Run();


}

#endif    //RIPPLE_ENTRYPOINT_HPP