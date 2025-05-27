/**
 * @file signalhandler.h
 * @brief This file contains a signal handler routine.
 * 
 * @author David Ferreira
 * @date 2025-05-27
 */

#include <iostream>
#include <signal.h>
#include <string>

using namespace std;

volatile sig_atomic_t flag = 1;

void sig_handler(int signum)
{
    if (signum == SIGINT) {
        cout << "Exiting..." << endl;
        flag = 0;
    }
}