#include <iostream>
#include <exception>
#include <string>
using namespace std;

class TimeServer {
public:
    string GetCurrentTime() {
        string tmp;
        try
        {
        tmp = AskTimeServer();
        }
        catch (system_error &e) {
            return (last_fetched_time);
        }
        last_fetched_time = tmp;
        return (last_fetched_time);
    }

private:
    string last_fetched_time = "00:00:00";
};