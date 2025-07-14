#include <iostream>
#include <queue>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;
using namespace std::chrono;

struct Call {
    int callerId;
    steady_clock::time_point timestamp;
    int duration; // in seconds
};

class RealTimeCallTracker {
private:
    queue<Call> callQueue;
    const int TIME_WINDOW = 60; // seconds
    ofstream logFile;

public:
    RealTimeCallTracker() {
        logFile.open("calls_log.txt", ios::out | ios::app);
        if (!logFile.is_open()) {
            cerr << "Error opening log file!" << endl;
            exit(1);
        }
        srand(time(0)); // Seed random generator once
    }

    ~RealTimeCallTracker() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    void receiveCall(int callerId, int duration) {
        auto now = steady_clock::now();
        callQueue.push({callerId, now, duration});
        cleanupOldCalls(now);
        logCall(callerId, now, duration);
    }

    int getRecentCallCount() {
        auto now = steady_clock::now();
        cleanupOldCalls(now);
        return callQueue.size();
    }

private:
    void cleanupOldCalls(steady_clock::time_point now) {
        while (!callQueue.empty() &&
               duration_cast<seconds>(now - callQueue.front().timestamp).count() > TIME_WINDOW) {
            callQueue.pop();
        }
    }

    void logCall(int callerId, steady_clock::time_point time, int duration) {
        auto timeNow = system_clock::now();
        time_t cTime = system_clock::to_time_t(timeNow);

        logFile << "Caller ID: " << callerId
                << ", Time: " << std::put_time(std::localtime(&cTime), "%F %T")
                << ", Duration: " << duration << "s\n";
    }
};

int main() {
    RealTimeCallTracker tracker;

    cout << "📞 Starting Real-Time Call Simulation with Random Caller IDs & Durations...\n";

    for (int i = 1; i <= 20; ++i) {
        // Simulate delay between calls
        int delay = 1 + rand() % 4;
        this_thread::sleep_for(seconds(delay));

        // Generate random caller ID and duration
        int randomCallerId = 1000 + rand() % 9000;
        int callDuration = 1 + rand() % 10; // 1 to 10 seconds

        tracker.receiveCall(randomCallerId, callDuration);

        cout << "📞 Call from ID #" << randomCallerId
             << " | Duration: " << callDuration << "s"
             << " | Delay: " << delay << "s\n";
        cout << "✅ Calls in last 60 seconds: " << tracker.getRecentCallCount() << "\n\n";
    }

    cout << "📄 Call tracking session ended. Check 'calls_log.txt' for full log.\n";
    return 0;
}