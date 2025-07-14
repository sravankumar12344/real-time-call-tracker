# real-time-call-tracker
# 📞 Real-Time Call Tracker (DSA-Based Simulation)

A C++ project simulating a real-time call center environment using **queue data structure** and **sliding time window logic**. This program keeps track of incoming calls, filters out older ones beyond 60 seconds, and logs call metadata efficiently — demonstrating the use of **DSA in time-sensitive systems**.

---

## 🚀 Features

- Real-time call tracking simulation
- Uses queue to manage recent calls in the last 60 seconds
- Generates random caller IDs and call durations
- Cleans up old calls using a sliding time window
- Logs all calls to a `calls_log.txt` file with timestamps
- Console output shows current active call count

---

## 📂 Technologies Used

- C++
- Standard Template Library (STL)
- `queue`, `chrono`, `thread`, `fstream`, `iomanip`

---

## 🧠 Data Structures & Concepts

- Queue for FIFO call handling
- Sliding window algorithm
- Timestamps using `chrono` library
- Randomization and thread delay for real-time effect

---

## 🛠️ How to Run

### Prerequisites
- C++17 or later
- Compatible OS: Linux / Windows / Mac

### Compile

```bash
g++ -std=c++17 -o call_tracker main.cpp
Run
bash
Copy
Edit
./call_tracker
📸 Sample Output
sql
Copy
Edit
📞 Starting Real-Time Call Simulation with Random Caller IDs & Durations...
📞 Call from ID #1892 | Duration: 6s | Delay: 3s
✅ Calls in last 60 seconds: 3
📄 Output
Real-time updates on the terminal

Full logs saved in calls_log.txt

📁 Folder Structure
pgsql
Copy
Edit
real-time-call-tracker/
├── main.cpp
├── calls_log.txt       # Generated after running
├── README.md
├── LICENSE             # (optional, recommended)
🏷️ GitHub Topics
cpp
Copy
Edit
c++ dsa queue realtime-simulation sliding-window call-tracker chrono thread file-logging
🧑‍💻 Author
K Sravan 
Third Year B.Tech CSE | Cloud Computing
LinkedIn | GitHub

📜 License
This project is licensed under the MIT License - see the LICENSE file for details.

✅ Suggested Git Commit Messages
vbnet
Copy
Edit
init: added call tracker simulation with queue
feat: added sliding window cleanup logic
fix: improved call log formatting
docs: created README.md with full project overview
✅ Next Steps
Create a new GitHub repo: real-time-call-tracker

Upload:

main.cpp

README.md

.gitignore (optional; example below)

(Optional) Add a LICENSE file (MIT recommended)

Push and share your project!

📂 Optional .gitignore
gitignore
Copy
Edit
calls_log.txt
*.exe
*.out
yaml
Copy
Edit
